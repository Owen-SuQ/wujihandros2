# WujiHand ROS2 技术设计文档

## 修改记录

| 版本 | 日期 | 修改内容 |
|-----|------|---------|
| v0.1.0 | 2024-12-10 | 初始版本：基于 ros2_control 框架设计 |
| v1.0.0 | 2024-12-10 | 重构：移除 ros2_control，改用发布/订阅模式；诊断独立线程；QoS 兼容修复 |

---

## 1. 概述

WujiHand 是一款五指灵巧手，具有 20 个自由度（每根手指 4 个关节）。本项目为 WujiHand 提供 ROS2 驱动支持。

**设计原则：**
- 简洁的发布/订阅架构，不使用 ros2_control
- 高频路径避免阻塞操作
- 使用标准 sensor_msgs/JointState 作为控制接口
- 兼容 ROS2 Humble / Jazzy / Kilted

## 2. 系统架构

```
┌─────────────────────────────────────────────────────────────┐
│                      用户应用层                              │
│    用户节点  /  MoveIt2  /  RViz  /  wave_demo.py           │
└──────────────────────────┬──────────────────────────────────┘
                           │
┌──────────────────────────▼──────────────────────────────────┐
│                      ROS2 通信层                             │
│  Topics:                                                    │
│    /joint_commands (sensor_msgs/JointState)  ← 控制命令     │
│    /joint_states   (sensor_msgs/JointState)  → 状态发布     │
│    /hand_diagnostics (HandDiagnostics)       → 诊断信息     │
│  Services:                                                  │
│    /set_enabled, /reset_error                               │
│  Parameters:                                                │
│    handedness, firmware_version, joint_limits (只读)        │
└──────────────────────────┬──────────────────────────────────┘
                           │
┌──────────────────────────▼──────────────────────────────────┐
│                   wujihand_driver_node                      │
│  ┌────────────┐  ┌────────────┐  ┌────────────┐            │
│  │ 状态发布   │  │ 诊断发布   │  │ 命令订阅   │            │
│  │ 1000Hz     │  │ 10Hz(线程) │  │            │            │
│  └─────┬──────┘  └─────┬──────┘  └─────┬──────┘            │
│        │               │               │                    │
│  ┌─────▼───────────────▼───────────────▼─────┐             │
│  │           wujihandcpp SDK                  │             │
│  │  realtime_controller (PDO) + SDO 读写      │             │
│  └─────────────────────┬─────────────────────┘             │
└────────────────────────┼────────────────────────────────────┘
                         │ USB
┌────────────────────────▼────────────────────────────────────┐
│                    WujiHand 硬件                             │
│  ┌─────┐  ┌─────┐  ┌─────┐  ┌─────┐  ┌─────┐               │
│  │ F1  │  │ F2  │  │ F3  │  │ F4  │  │ F5  │               │
│  │拇指 │  │食指 │  │中指 │  │无名 │  │小指 │               │
│  │4DOF │  │4DOF │  │4DOF │  │4DOF │  │4DOF │               │
│  └─────┘  └─────┘  └─────┘  └─────┘  └─────┘               │
└─────────────────────────────────────────────────────────────┘
```

## 3. 数据流设计

| 数据类型 | 频率 | 路径 | 说明 |
|---------|------|------|------|
| 位置状态 | 1000Hz | 实时控制器缓存 | 无 USB 通信，快速读取 |
| 控制命令 | 100Hz默认 | PDO 写入 | 触发位置反馈更新 |
| 诊断数据 | 10Hz | SDO 读取(独立线程) | 避免阻塞主循环 |

**关键实现细节：**

1. **位置更新机制**：SDK 的 realtime_controller 只在发送命令时更新位置反馈，因此驱动内置 100Hz 默认命令定时器保持 PDO 通信活跃

2. **QoS 兼容性**：joint_states 使用 SensorDataQoS (BEST_EFFORT)，与 robot_state_publisher 兼容

3. **线程安全**：诊断读取在独立线程执行，使用 mutex 保护 SDK 访问，调用 `disable_thread_safe_check()` 允许多线程访问

## 4. 包结构

```
wujihand-ros2/
├── wujihand_msgs/              # 消息和服务定义
│   ├── msg/HandDiagnostics.msg
│   └── srv/{SetEnabled,ResetError}.srv
├── wujihand_driver/            # 核心驱动节点
│   ├── include/wujihand_driver/wujihand_driver_node.hpp
│   └── src/{wujihand_driver_node,main}.cpp
├── wujihand_description/       # URDF 模型
│   └── urdf/wujihand.urdf.xacro
├── wujihand_bringup/           # 启动文件和演示
│   ├── launch/{wujihand,wujihand_rviz}.launch.py
│   └── scripts/wave_demo.py
└── docs/DESIGN.md
```

## 5. 接口规范

### 5.1 话题

| 话题名 | 类型 | 方向 | 频率 | QoS |
|-------|-----|------|-----|-----|
| /joint_commands | sensor_msgs/JointState | 订阅 | 用户定 | 默认 |
| /joint_states | sensor_msgs/JointState | 发布 | 1000Hz | SensorDataQoS |
| /hand_diagnostics | HandDiagnostics | 发布 | 10Hz | 默认 |

### 5.2 服务

| 服务名 | 类型 | 说明 |
|-------|-----|------|
| /set_enabled | SetEnabled | 启用/禁用关节 (finger_id=255 表示全部) |
| /reset_error | ResetError | 重置错误状态 |

### 5.3 参数

**可配置参数：**

| 参数名 | 类型 | 默认值 | 说明 |
|-------|-----|-------|------|
| serial_number | string | "" | 设备序列号，空则连接第一个设备 |
| publish_rate | double | 1000.0 | 状态发布频率 (Hz) |
| filter_cutoff_freq | double | 10.0 | 低通滤波截止频率 (Hz) |
| diagnostics_rate | double | 10.0 | 诊断发布频率 (Hz) |

**只读参数（启动时从硬件读取）：**

| 参数名 | 类型 | 说明 |
|-------|-----|------|
| handedness | string | "left" 或 "right" |
| firmware_version | string | 固件版本号 |
| joint_upper_limits | double[20] | 关节位置上限 |
| joint_lower_limits | double[20] | 关节位置下限 |

## 6. 消息定义

### HandDiagnostics.msg

```
std_msgs/Header header
string handedness               # "left" 或 "right"
float32 system_temperature      # 系统温度 (°C)
float32 input_voltage           # 输入电压 (V)
float32[20] joint_temperatures  # 关节温度 (°C)
uint32[20] error_codes          # 错误码
bool[20] enabled                # 启用状态
```

### SetEnabled.srv

```
uint8 finger_id      # 0-4, 或 255=所有手指
uint8 joint_id       # 0-3, 或 255=所有关节
bool enabled
---
bool success
string message
```

### ResetError.srv

```
uint8 finger_id      # 0-4, 或 255=所有手指
uint8 joint_id       # 0-3, 或 255=所有关节
---
bool success
string message
```

## 7. 关节命名规范

```
finger{1-5}_joint{1-4}

手指编号:
  finger1 = 拇指, finger2 = 食指, finger3 = 中指
  finger4 = 无名指, finger5 = 小指

关节编号:
  joint1 = 侧摆 (abduction)
  joint2 = 掌指关节 (MCP)
  joint3 = 近端指间关节 (PIP)
  joint4 = 远端指间关节 (DIP)

数组索引: index = (finger-1) * 4 + (joint-1)
  例: finger2_joint3 = (2-1)*4 + (3-1) = 6
```

## 8. 依赖

### 系统依赖

- ROS2 Humble / Jazzy / Kilted
- wujihandcpp SDK (deb 包安装)

### 包依赖关系

```
wujihand_msgs          (无依赖)
       │
       ▼
wujihand_driver        (依赖 wujihand_msgs, wujihandcpp)
       │
       ▼
wujihand_bringup       (依赖 wujihand_driver, wujihand_description)

wujihand_description   (无依赖)
```

## 9. 使用示例

```bash
# 启动驱动
ros2 launch wujihand_bringup wujihand.launch.py

# 启动驱动 + RViz 可视化
ros2 launch wujihand_bringup wujihand_rviz.launch.py

# 运行波浪演示
ros2 run wujihand_bringup wave_demo.py

# 查看状态
ros2 topic echo /joint_states

# 发送命令
ros2 topic pub /joint_commands sensor_msgs/msg/JointState \
  "{position: [0,0.5,0.5,0.5, 0,0.5,0.5,0.5, 0,0.5,0.5,0.5, 0,0.5,0.5,0.5, 0,0.5,0.5,0.5]}"

# 禁用所有关节
ros2 service call /set_enabled wujihand_msgs/srv/SetEnabled \
  "{finger_id: 255, joint_id: 255, enabled: false}"
```

# WujiHand ROS2

WujiHand 灵巧手 ROS2 驱动包，采用简洁的发布/订阅架构。

## 支持的平台

| Ubuntu | ROS2 版本 | 状态 |
|--------|----------|------|
| 22.04 | Humble | 支持 |
| 24.04 | Kilted | 支持 |

## 目录结构

```
wujihand-ros2/
├── wujihand_ws/                    # 主工作空间
│   └── src/wujihand/
│       ├── wujihand_msgs/          # 消息和服务定义
│       ├── wujihand_driver/        # 驱动节点
│       └── wujihand_description/   # URDF 模型
└── example/                        # 示例程序
    └── src/wujihand_example/
```

## 依赖

- ROS2 Humble (22.04) 或 Kilted (24.04)
- wujihandcpp SDK

## 编译

```bash
cd wujihand-ros2

# 设置 ROS2 环境
# Ubuntu 22.04:
source /opt/ros/humble/setup.bash
# Ubuntu 24.04:
source /opt/ros/kilted/setup.bash

# 编译主工作空间
cd wujihand_ws
colcon build

# 编译示例程序
cd ../example
source ../wujihand_ws/install/setup.bash
colcon build
```

## 快速开始

### 1. 启动驱动

```bash
# 设置环境 (根据系统选择 humble 或 kilted)
source /opt/ros/humble/setup.bash  # 或 kilted
source wujihand_ws/install/setup.bash

ros2 run wujihand_driver wujihand_driver_node
```

启动成功后会看到：
```
[wujihand_driver]: Connected to WujiHand
[wujihand_driver]: WujiHand driver started (rate: 100.0 Hz)
```

### 2. 运行示例

在新终端中：

```bash
source /opt/ros/humble/setup.bash  # 或 kilted
source wujihand_ws/install/setup.bash
source example/install/setup.bash

ros2 run wujihand_example wujihand_example
```

示例功能：
- 波浪运动：食指、中指、无名指、小指做正弦波运动 (100Hz)
- 状态读取：每秒打印所有关节位置

### 3. 带 RViz 可视化运行

```bash
source /opt/ros/humble/setup.bash  # 或 kilted
source wujihand_ws/install/setup.bash
source example/install/setup.bash

ros2 launch wujihand_example example_with_rviz.launch.py
```

这会同时启动：
- `robot_state_publisher` - 发布 TF
- `wujihand_example` - 波动示例
- `rviz2` - 可视化

### 4. 手动发送命令

```bash
# 所有关节归零
ros2 topic pub /hand_command wujihand_msgs/msg/HandCommand \
  "{target_positions: [0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0]}"

# 握拳
ros2 topic pub /hand_command wujihand_msgs/msg/HandCommand \
  "{target_positions: [0,1.5,1.5,1.5, 0,1.5,1.5,1.5, 0,1.5,1.5,1.5, 0,1.5,1.5,1.5, 0,1.5,1.5,1.5]}"
```

## ROS2 接口

### Topics

| Topic | 类型 | 方向 | 频率 | 说明 |
|-------|-----|------|-----|------|
| `/hand_command` | wujihand_msgs/HandCommand | Sub | - | 位置命令 |
| `/hand_state` | wujihand_msgs/HandState | Pub | 100Hz | 手部状态 |
| `/joint_states` | sensor_msgs/JointState | Pub | 100Hz | RViz 兼容 |

### Services

| Service | 类型 | 说明 |
|---------|-----|------|
| `/get_hand_info` | wujihand_msgs/GetHandInfo | 获取设备信息 |
| `/set_enabled` | wujihand_msgs/SetEnabled | 启用/禁用关节 |
| `/reset_error` | wujihand_msgs/ResetError | 重置错误 |

### 关节顺序

20 个关节按以下顺序排列：

| 索引 | 关节名 | 说明 |
|-----|-------|------|
| 0-3 | finger1_joint1, finger1_joint2, finger1_joint3, finger1_joint4 | 拇指 (F1) |
| 4-7 | finger2_joint1, finger2_joint2, finger2_joint3, finger2_joint4 | 食指 (F2) |
| 8-11 | finger3_joint1, finger3_joint2, finger3_joint3, finger3_joint4 | 中指 (F3) |
| 12-15 | finger4_joint1, finger4_joint2, finger4_joint3, finger4_joint4 | 无名指 (F4) |
| 16-19 | finger5_joint1, finger5_joint2, finger5_joint3, finger5_joint4 | 小指 (F5) |

每根手指的关节顺序：joint1 (侧摆), joint2 (屈曲), joint3 (近端指间), joint4 (远端指间)

## URDF 模型

支持左右手模型：

| 文件 | 说明 |
|-----|------|
| `urdf/left-ros.urdf` | 左手 (ROS 格式) |
| `urdf/right-ros.urdf` | 右手 (ROS 格式) |
| `urdf/left.urdf` | 左手 (通用格式) |
| `urdf/right.urdf` | 右手 (通用格式) |

## 驱动参数

| 参数 | 默认值 | 说明 |
|-----|-------|------|
| `serial_number` | "" | 设备序列号（空则自动连接） |
| `publish_rate` | 100.0 | 状态发布频率 (Hz) |
| `filter_cutoff_freq` | 10.0 | 低通滤波截止频率 (Hz) |

```bash
# 带参数启动
ros2 run wujihand_driver wujihand_driver_node --ros-args \
  -p serial_number:=XXXXX \
  -p publish_rate:=200.0
```

## 服务调用示例

```bash
# 获取设备信息
ros2 service call /get_hand_info wujihand_msgs/srv/GetHandInfo

# 禁用所有关节
ros2 service call /set_enabled wujihand_msgs/srv/SetEnabled \
  "{finger_id: 255, joint_id: 255, enabled: false}"

# 启用所有关节
ros2 service call /set_enabled wujihand_msgs/srv/SetEnabled \
  "{finger_id: 255, joint_id: 255, enabled: true}"

# 重置所有错误
ros2 service call /reset_error wujihand_msgs/srv/ResetError \
  "{finger_id: 255, joint_id: 255}"
```

## 消息定义

### HandCommand.msg
```
std_msgs/Header header
float64[20] target_positions    # 目标位置 (弧度)
```

### HandState.msg
```
std_msgs/Header header
string handedness               # "left" 或 "right"
float32 system_temperature      # 系统温度
float32 input_voltage           # 输入电压
float64[20] actual_positions    # 实际位置
float64[20] target_positions    # 目标位置
float32[20] joint_temperatures  # 关节温度
uint32[20] error_codes          # 错误码
bool[20] enabled                # 启用状态
```

## 常见问题

### WSL2 DDS 通信问题

```bash
# 清理 DDS 缓存
rm -rf ~/.ros/ros2_daemon/
rm -rf /dev/shm/fastrtps*

# 重启 daemon
ros2 daemon stop
ros2 daemon start
```

### 硬件连接失败

1. 检查 USB 连接
2. 确认 wujihandcpp SDK 正确安装
3. 检查是否有其他程序占用设备

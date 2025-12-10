# WujiHand ROS2

WujiHand 灵巧手 ROS2 驱动包，采用简洁的发布/订阅架构。

## 支持的平台

| Ubuntu | ROS2 版本 | 状态 |
|--------|----------|------|
| 22.04 | Humble | 支持 |
| 24.04 | Jazzy | 支持 |
| 24.10 | Kilted | 支持 |

## 目录结构

```
wujihand-ros2/
├── wujihand_bringup/       # 启动文件和配置
├── wujihand_driver/        # 驱动节点
├── wujihand_msgs/          # 消息和服务定义
├── wujihand_description/   # URDF 模型
└── docs/                   # 文档
```

## 安装

### 方式一：Deb 包安装（推荐）

#### 1. 安装 wujihandcpp SDK

从 [wujihandpy releases](https://github.com/Wuji-Technology-Co-Ltd/wujihandpy/releases) 下载对应架构的 deb 包：

```bash
# AMD64
wget https://github.com/Wuji-Technology-Co-Ltd/wujihandpy/releases/download/v1.3.0/wujihandcpp-1.3.0-amd64.deb
sudo dpkg -i wujihandcpp-1.3.0-amd64.deb

# ARM64
wget https://github.com/Wuji-Technology-Co-Ltd/wujihandpy/releases/download/v1.3.0/wujihandcpp-1.3.0-arm64.deb
sudo dpkg -i wujihandcpp-1.3.0-arm64.deb
```

#### 2. 安装 wujihand-ros2

从 [wujihand-ros2 releases](https://github.com/Wuji-Technology-Co-Ltd/wujihand-ros2/releases) 下载对应版本的 deb 包：

```bash
# Kilted (Ubuntu 24.10)
sudo dpkg -i ros-kilted-wujihand_0.1.0-1_amd64.deb

# Jazzy (Ubuntu 24.04)
sudo dpkg -i ros-jazzy-wujihand_0.1.0-1_amd64.deb

# Humble (Ubuntu 22.04)
sudo dpkg -i ros-humble-wujihand_0.1.0-1_amd64.deb
```

### 方式二：源码编译

#### 1. 安装 wujihandcpp SDK

同上。

#### 2. 克隆仓库

```bash
git clone https://github.com/Wuji-Technology-Co-Ltd/wujihand-ros2.git
cd wujihand-ros2
```

#### 3. 编译

```bash
# 设置 ROS2 环境
source /opt/ros/${ROS_DISTRO}/setup.bash

# 编译
colcon build

# 设置工作空间环境
source install/setup.bash
```

### 构建 Deb 包

如果需要自行构建 deb 包：

```bash
cd wujihand-ros2

# 构建指定 ROS 版本的 deb 包
./build_deb.sh kilted   # 生成 ros-kilted-wujihand_*.deb
./build_deb.sh jazzy    # 生成 ros-jazzy-wujihand_*.deb
./build_deb.sh humble   # 生成 ros-humble-wujihand_*.deb
```

生成的 deb 包位于上级目录。

## 快速开始

### 1. 启动驱动

```bash
ros2 launch wujihand_bringup wujihand.launch.py
```

启动成功后会看到：
```
[wujihand_driver]: Connected to WujiHand (right)
[wujihand_driver]: WujiHand driver started (state: 1000.0 Hz, diagnostics: 10.0 Hz)
```

### 2. 带 RViz 可视化启动

```bash
ros2 launch wujihand_bringup wujihand_rviz.launch.py
```

### 3. 发送控制命令

```bash
# 所有关节归零
ros2 topic pub /joint_commands sensor_msgs/msg/JointState \
  "{position: [0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0]}"

# 握拳
ros2 topic pub /joint_commands sensor_msgs/msg/JointState \
  "{position: [0,1.5,1.5,1.5, 0,1.5,1.5,1.5, 0,1.5,1.5,1.5, 0,1.5,1.5,1.5, 0,1.5,1.5,1.5]}"
```

### 4. 查看状态

```bash
# 查看关节状态 (1000Hz)
ros2 topic echo /joint_states

# 查看诊断信息 (10Hz)
ros2 topic echo /hand_diagnostics
```

## ROS2 接口

### Topics

| Topic | 类型 | 方向 | 频率 | 说明 |
|-------|-----|------|-----|------|
| `/joint_commands` | sensor_msgs/JointState | Sub | 用户定 | 目标位置命令 |
| `/joint_states` | sensor_msgs/JointState | Pub | 1000Hz | 实际关节位置 |
| `/hand_diagnostics` | wujihand_msgs/HandDiagnostics | Pub | 10Hz | 诊断信息 |

### Services

| Service | 类型 | 说明 |
|---------|-----|------|
| `/set_enabled` | wujihand_msgs/SetEnabled | 启用/禁用关节 |
| `/reset_error` | wujihand_msgs/ResetError | 重置错误 |

### Parameters (只读)

连接硬件后自动设置的只读参数：

| 参数 | 类型 | 说明 |
|-----|------|------|
| `handedness` | string | 左手 "left" 或右手 "right" |
| `firmware_version` | string | 固件版本，如 "1.0.1" |
| `joint_upper_limits` | double[20] | 关节上限 (弧度) |
| `joint_lower_limits` | double[20] | 关节下限 (弧度) |

### 关节顺序

20 个关节按以下顺序排列：

| 索引 | 关节名 | 说明 |
|-----|-------|------|
| 0-3 | finger1_joint1 ~ finger1_joint4 | 拇指 (F1) |
| 4-7 | finger2_joint1 ~ finger2_joint4 | 食指 (F2) |
| 8-11 | finger3_joint1 ~ finger3_joint4 | 中指 (F3) |
| 12-15 | finger4_joint1 ~ finger4_joint4 | 无名指 (F4) |
| 16-19 | finger5_joint1 ~ finger5_joint4 | 小指 (F5) |

每根手指的关节顺序：joint1 (侧摆), joint2 (屈曲), joint3 (近端指间), joint4 (远端指间)

## 驱动参数

| 参数 | 默认值 | 说明 |
|-----|-------|------|
| `serial_number` | "" | 设备序列号（空则自动连接） |
| `publish_rate` | 1000.0 | 状态发布频率 (Hz) |
| `filter_cutoff_freq` | 10.0 | 低通滤波截止频率 (Hz) |
| `diagnostics_rate` | 10.0 | 诊断发布频率 (Hz) |

```bash
# 带参数启动
ros2 launch wujihand_bringup wujihand.launch.py \
  serial_number:=XXXXX \
  publish_rate:=500.0
```

## 服务调用示例

```bash
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

## 参数查询示例

```bash
# 查看设备信息
ros2 param get /wujihand_driver handedness
ros2 param get /wujihand_driver firmware_version

# 查看关节限位
ros2 param get /wujihand_driver joint_upper_limits
ros2 param get /wujihand_driver joint_lower_limits
```

## 消息定义

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

## URDF 模型

支持左右手模型：

| 文件 | 说明 |
|-----|------|
| `urdf/left-ros.urdf` | 左手 (ROS 格式) |
| `urdf/right-ros.urdf` | 右手 (ROS 格式) |

## 常见问题

### 硬件连接失败 (ERROR_BUSY)

如果看到错误 `Failed to claim interface: -6 (ERROR_BUSY)`，说明有其他进程正在占用设备：

```bash
# 查找占用进程
ps aux | grep wujihand

# 杀掉相关进程
pkill -f wujihand_driver_node
pkill -f robot_state_publisher
pkill -f "ros2 launch"

# 然后重新启动
ros2 launch wujihand_bringup wujihand.launch.py
```

其他检查项：
1. 检查 USB 连接是否正常
2. 检查是否安装 wujihandcpp deb 包
3. 在 WSL2 中需要使用 usbipd 转发 USB 设备

### ros2 topic list 卡住 / DDS 通信问题

在 WSL2 环境中，ROS2 的 DDS 通信可能会出现问题，表现为 `ros2 topic list` 或 `ros2 topic echo` 命令卡住无响应。

**解决步骤：**

```bash
# 1. 检查 daemon 状态
ros2 daemon status

# 2. 如果 daemon 未运行，启动它
ros2 daemon start

# 3. 如果仍有问题，停止并重启 daemon
ros2 daemon stop
ros2 daemon start

# 4. 清理 DDS 缓存（如果上述步骤无效）
rm -rf ~/.ros/ros2_daemon/
rm -rf /dev/shm/fastrtps*
ros2 daemon start

# 5. 可选：切换到 CycloneDDS（更稳定）
sudo apt install ros-${ROS_DISTRO}-rmw-cyclonedds-cpp
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
```

### RViz 无法显示模型 / No TF data

如果 RViz 报错 "No tf data" 或模型无法显示：

1. **检查 joint_states 话题是否正常发布：**
   ```bash
   ros2 topic echo /joint_states --once
   ```

2. **检查 robot_state_publisher 是否运行：**
   ```bash
   ros2 node list | grep robot_state_publisher
   ```

3. **确保 Fixed Frame 设置正确：**
   - 在 RViz 左侧面板中，确保 `Fixed Frame` 设置为 `palm_link`

### deb 包安装冲突

如果安装 wujihandcpp deb 包时与 libgtest-dev 冲突：

```bash
sudo dpkg -i --force-overwrite wujihandcpp-*.deb
```

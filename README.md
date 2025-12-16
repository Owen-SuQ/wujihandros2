# WujiHand ROS2

WujiHand 灵巧手 ROS2 驱动包。

## 支持的平台

| Ubuntu | ROS2 版本 |
|--------|----------|
| 22.04 | Humble |
| 24.04 | Kilted |

---

## 方式一：源码编译

### 1. 环境准备

#### Ubuntu 22.04 (Humble)

```bash
# 安装 ROS2 Humble
sudo apt update
sudo apt install -y ros-humble-ros-base ros-humble-robot-state-publisher \
    ros-humble-rviz2 ros-humble-sensor-msgs ros-humble-std-msgs \
    ros-humble-xacro ros-humble-foxglove-bridge

# 安装编译工具
sudo apt install -y python3-colcon-common-extensions python3-rosdep

# 下载并安装 wujihandcpp SDK
wget https://github.com/Wuji-Technology-Co-Ltd/wujihandpy/releases/download/v1.3.0/wujihandcpp-1.3.0-amd64.deb
sudo dpkg -i wujihandcpp-1.3.0-amd64.deb
```

#### Ubuntu 24.04 (Kilted)

```bash
# 安装 ROS2 Kilted
sudo apt update
sudo apt install -y ros-kilted-ros-base ros-kilted-robot-state-publisher \
    ros-kilted-rviz2 ros-kilted-sensor-msgs ros-kilted-std-msgs \
    ros-kilted-xacro ros-kilted-foxglove-bridge

# 安装编译工具
sudo apt install -y python3-colcon-common-extensions python3-rosdep

# 下载并安装 wujihandcpp SDK
wget https://github.com/Wuji-Technology-Co-Ltd/wujihandpy/releases/download/v1.3.0/wujihandcpp-1.3.0-amd64.deb
sudo dpkg -i wujihandcpp-1.3.0-amd64.deb
```

### 2. 编译

```bash
cd wujihandros2

# 配置环境 (根据你的 ROS2 版本选择)
source /opt/ros/humble/setup.bash   # Ubuntu 22.04
# 或
source /opt/ros/kilted/setup.bash   # Ubuntu 24.04

# 编译
colcon build

# 加载编译结果
source install/setup.bash
```

### 3. 测试驱动

```bash
# 启动驱动
ros2 launch wujihand_bringup wujihand.launch.py

# 新终端验证
source /opt/ros/<distro>/setup.bash  # humble 或 kilted
source install/setup.bash
ros2 topic echo /joint_states --once
```

启动成功后会看到：
```
[wujihand_driver]: Connected to WujiHand (right)
[wujihand_driver]: WujiHand driver started (state: 1000.0 Hz, diagnostics: 10.0 Hz)
```

### 4. 测试脚本

```bash
# 运行波浪演示
ros2 run wujihand_bringup wave_demo.py
```

---

## 方式二：Deb 包安装

### Ubuntu 22.04 (Humble)

```bash
# 安装 ROS2 依赖
sudo apt update
sudo apt install -y ros-humble-ros-base ros-humble-robot-state-publisher \
    ros-humble-sensor-msgs ros-humble-std-msgs

# 下载并安装 wujihandcpp SDK
wget https://github.com/Wuji-Technology-Co-Ltd/wujihandpy/releases/download/v1.3.0/wujihandcpp-1.3.0-amd64.deb
sudo dpkg -i wujihandcpp-1.3.0-amd64.deb

# 安装 WujiHand ROS2 驱动
sudo dpkg -i ros-humble-wujihand-ros2_0.1.0_amd64.deb
```

### Ubuntu 24.04 (Kilted)

```bash
# 安装 ROS2 依赖
sudo apt update
sudo apt install -y ros-kilted-ros-base ros-kilted-robot-state-publisher \
    ros-kilted-sensor-msgs ros-kilted-std-msgs

# 下载并安装 wujihandcpp SDK
wget https://github.com/Wuji-Technology-Co-Ltd/wujihandpy/releases/download/v1.3.0/wujihandcpp-1.3.0-amd64.deb
sudo dpkg -i wujihandcpp-1.3.0-amd64.deb

# 安装 WujiHand ROS2 驱动
sudo dpkg -i ros-kilted-wujihand-ros2_0.1.0_amd64.deb
```

### 测试驱动

```bash
# 配置环境
source /opt/ros/<distro>/setup.bash  # humble 或 kilted

# 启动驱动
ros2 launch wujihand_bringup wujihand.launch.py

# 新终端验证
ros2 topic echo /joint_states --once
```

### 测试脚本

```bash
ros2 run wujihand_bringup wave_demo.py
```

---

## 启动方式

| 命令 | 说明 |
|-----|------|
| `ros2 launch wujihand_bringup wujihand.launch.py` | 仅驱动 |
| `ros2 launch wujihand_bringup wujihand_rviz.launch.py` | 驱动 + RViz |
| `ros2 launch wujihand_bringup wujihand_foxglove.launch.py` | 驱动 + Foxglove |

## 基础使用

### 发送控制命令

```bash
# 所有关节归零
ros2 topic pub /joint_commands sensor_msgs/msg/JointState \
  "{position: [0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0]}" --once

# 握拳
ros2 topic pub /joint_commands sensor_msgs/msg/JointState \
  "{position: [0,1.5,1.5,1.5, 0,1.5,1.5,1.5, 0,1.5,1.5,1.5, 0,1.5,1.5,1.5, 0,1.5,1.5,1.5]}" --once
```

### 查看状态

```bash
# 关节状态 (1000Hz)
ros2 topic echo /joint_states

# 诊断信息 (10Hz)
ros2 topic echo /hand_diagnostics
```

### 服务调用

```bash
# 使能/失能手指
ros2 service call /set_enabled wujihand_msgs/srv/SetEnabled "{finger_id: 0, enabled: true}"

# 重置错误
ros2 service call /reset_error wujihand_msgs/srv/ResetError "{finger_id: 0}"
```

## 更多文档

- [API 参考](docs/API.md) - Topics、Services、Parameters、错误处理

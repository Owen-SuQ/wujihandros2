# ROS2 命令行工具参考

本文档介绍 ROS2 常用命令行工具的使用方法，帮助快速上手 WujiHand ROS2 驱动的调试和开发。

---

## 目录

- [背景知识](#背景知识)
- [ros2 topic](#ros2-topic)
- [ros2 service](#ros2-service)
- [ros2 node](#ros2-node)
- [ros2 param](#ros2-param)
- [ros2 launch](#ros2-launch)
- [ros2 run](#ros2-run)
- [ros2 interface](#ros2-interface)
- [ros2 daemon](#ros2-daemon)
- [实用技巧](#实用技巧)

---

## 背景知识

### ROS2 通信模型

ROS2 基于 DDS（Data Distribution Service）实现分布式通信：

| 概念 | 说明 |
|------|------|
| **Node** | 节点，ROS2 程序的基本单元 |
| **Topic** | 话题，节点间异步通信的通道（发布/订阅模式） |
| **Service** | 服务，同步请求/响应模式 |
| **Parameter** | 参数，节点运行时的配置项 |
| **Namespace** | 命名空间，用于隔离和组织节点/话题 |

### 命名规范

```
/{namespace}/{topic_name}
/{namespace}/{node_name}
/{namespace}/{service_name}
```

示例（WujiHand）：
```
/hand_0/joint_states      # 话题
/hand_0/wujihand_driver   # 节点
/hand_0/set_enabled       # 服务
```

---

## ros2 topic

话题是 ROS2 中最常用的通信方式，用于发布和订阅数据。

### 常用命令

```bash
# 列出所有话题
ros2 topic list

# 列出话题及其类型
ros2 topic list -t

# 查看话题信息（类型、发布者、订阅者数量）
ros2 topic info /hand_0/joint_states

# 查看话题发布频率
ros2 topic hz /hand_0/joint_states

# 查看话题带宽
ros2 topic bw /hand_0/joint_states

# 查看话题延迟（需要消息带 header）
ros2 topic delay /hand_0/joint_states
```

### ros2 topic echo

订阅并打印话题消息。

```bash
# 基本用法：持续输出
ros2 topic echo /hand_0/joint_states

# 只输出一条消息
ros2 topic echo /hand_0/joint_states --once

# 只输出特定字段
ros2 topic echo /hand_0/joint_states --field effort
ros2 topic echo /hand_0/joint_states --field position

# 输出为 CSV 格式
ros2 topic echo /hand_0/joint_states --csv

# 输出为 YAML 格式（默认）
ros2 topic echo /hand_0/joint_states --yaml

# 不截断数组输出
ros2 topic echo /hand_0/joint_states --full-length

# 限制输出消息数量
ros2 topic echo /hand_0/joint_states -n 5

# 不输出消息头
ros2 topic echo /hand_0/joint_states --no-arr
```

**常用参数：**

| 参数 | 说明 |
|------|------|
| `--once` | 只输出一条消息后退出 |
| `--field <name>` | 只输出指定字段 |
| `--csv` | CSV 格式输出 |
| `--yaml` | YAML 格式输出（默认） |
| `--full-length` | 不截断数组 |
| `-n <count>` | 输出指定数量后退出 |
| `--no-daemon` | 不使用 daemon，直接查询 |

### ros2 topic pub

向话题发布消息。

```bash
# 发布一次
ros2 topic pub /hand_0/joint_commands sensor_msgs/msg/JointState \
  "{position: [0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0]}" --once

# 持续发布（默认 1Hz）
ros2 topic pub /hand_0/joint_commands sensor_msgs/msg/JointState \
  "{position: [0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0]}"

# 指定发布频率（10Hz）
ros2 topic pub /hand_0/joint_commands sensor_msgs/msg/JointState \
  "{position: [0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0]}" -r 10

# 发布指定次数
ros2 topic pub /hand_0/joint_commands sensor_msgs/msg/JointState \
  "{position: [0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0]}" -t 5
```

**常用参数：**

| 参数 | 说明 |
|------|------|
| `--once` | 只发布一次 |
| `-r <rate>` | 发布频率（Hz） |
| `-t <times>` | 发布次数 |
| `-w <count>` | 等待指定数量订阅者后再发布 |

---

## ros2 service

服务用于同步的请求/响应通信。

### 常用命令

```bash
# 列出所有服务
ros2 service list

# 列出服务及其类型
ros2 service list -t

# 查看服务类型
ros2 service type /hand_0/set_enabled

# 查找特定类型的服务
ros2 service find wujihand_msgs/srv/SetEnabled
```

### ros2 service call

调用服务。

```bash
# 禁用所有关节
ros2 service call /hand_0/set_enabled wujihand_msgs/srv/SetEnabled \
  "{finger_id: 255, joint_id: 255, enabled: false}"

# 启用所有关节
ros2 service call /hand_0/set_enabled wujihand_msgs/srv/SetEnabled \
  "{finger_id: 255, joint_id: 255, enabled: true}"

# 重置所有错误
ros2 service call /hand_0/reset_error wujihand_msgs/srv/ResetError \
  "{finger_id: 255, joint_id: 255}"
```

**参数说明：**

| 参数 | 值 | 含义 |
|------|------|------|
| `finger_id` | 0-4 | 拇指、食指、中指、无名指、小指 |
| `finger_id` | 255 | 所有手指 |
| `joint_id` | 0-3 | 单个关节 |
| `joint_id` | 255 | 所有关节 |

---

## ros2 node

节点管理命令。

```bash
# 列出所有节点
ros2 node list

# 查看节点详细信息
ros2 node info /hand_0/wujihand_driver

# 查看节点的发布话题
ros2 node info /hand_0/wujihand_driver | grep "Publishers"

# 查看节点的订阅话题
ros2 node info /hand_0/wujihand_driver | grep "Subscribers"

# 查看节点的服务
ros2 node info /hand_0/wujihand_driver | grep "Service"
```

---

## ros2 param

参数管理命令。

```bash
# 列出节点所有参数
ros2 param list /hand_0/wujihand_driver

# 获取参数值
ros2 param get /hand_0/wujihand_driver publish_rate

# 设置参数值（运行时）
ros2 param set /hand_0/wujihand_driver publish_rate 500.0

# 导出所有参数到文件
ros2 param dump /hand_0/wujihand_driver

# 从文件加载参数
ros2 param load /hand_0/wujihand_driver params.yaml
```

---

## ros2 launch

启动文件管理。

```bash
# 启动 launch 文件
ros2 launch wujihand_bringup wujihand.launch.py

# 带参数启动
ros2 launch wujihand_bringup wujihand_foxglove.launch.py hands:=auto

# 查看 launch 文件参数
ros2 launch wujihand_bringup wujihand.launch.py --show-args

# 打印 launch 文件描述
ros2 launch wujihand_bringup wujihand.launch.py --print-description
```

**WujiHand Launch 参数：**

| 参数 | 默认值 | 说明 |
|------|--------|------|
| `hands` | `auto` | 设备配置（auto/SN/name:SN） |
| `publish_rate` | `1000.0` | 状态发布频率 (Hz) |
| `filter_cutoff_freq` | `10.0` | 滤波截止频率 (Hz) |
| `diagnostics_rate` | `10.0` | 诊断发布频率 (Hz) |

**hands 参数格式：**

```bash
# 自动检测所有连接设备
hands:=auto

# 指定单个设备序列号
hands:=347B38773433

# 指定多个设备
hands:=347B38773433,337238733233

# 自定义命名
hands:=left:347B38773433,right:337238733233
```

---

## ros2 run

运行单个节点。

```bash
# 运行节点
ros2 run wujihand_bringup wave_demo.py

# 带命名空间运行
ros2 run wujihand_bringup wave_demo.py --ros-args -r __ns:=/hand_0

# 带参数运行
ros2 run wujihand_driver wujihand_driver_node --ros-args \
  -p serial_number:=347B38773433

# 重映射话题
ros2 run wujihand_bringup wave_demo.py --ros-args \
  --remap /hand_0/joint_commands:=/left_hand/joint_commands
```

**--ros-args 常用选项：**

| 选项 | 说明 |
|------|------|
| `-r __ns:=<ns>` | 设置命名空间 |
| `-p <name>:=<value>` | 设置参数 |
| `--remap <from>:=<to>` | 重映射话题/服务 |
| `-r __node:=<name>` | 重命名节点 |

---

## ros2 interface

查看消息/服务/动作定义。

```bash
# 列出所有消息类型
ros2 interface list -m

# 列出所有服务类型
ros2 interface list -s

# 查看消息定义
ros2 interface show sensor_msgs/msg/JointState

# 查看服务定义
ros2 interface show wujihand_msgs/srv/SetEnabled

# 查看包的所有接口
ros2 interface package wujihand_msgs
```

**sensor_msgs/msg/JointState 定义：**

```
std_msgs/Header header
string[] name
float64[] position
float64[] velocity
float64[] effort
```

---

## ros2 daemon

ROS2 daemon 管理。daemon 用于加速节点发现。

```bash
# 查看 daemon 状态
ros2 daemon status

# 停止 daemon
ros2 daemon stop

# 启动 daemon
ros2 daemon start

# 重启 daemon（解决话题/服务列表不完整问题）
ros2 daemon stop && ros2 daemon start
```

**何时需要重启 daemon：**
- `ros2 topic list` 显示不完整
- `ros2 service list` 找不到服务
- 节点已退出但仍显示在列表中

---

## 实用技巧

### 1. 快速验证 effort 字段

```bash
# 查看 effort 是否有数据
ros2 topic echo /hand_0/joint_states --once --field effort
```

### 2. 监控多个话题

```bash
# 使用 rqt_topic
rqt

# 或者开多个终端
ros2 topic echo /hand_0/joint_states --field position &
ros2 topic echo /hand_1/joint_states --field position &
```

### 3. 录制和回放

```bash
# 录制话题
ros2 bag record /hand_0/joint_states /hand_0/hand_diagnostics

# 回放
ros2 bag play rosbag2_*/

# 查看 bag 信息
ros2 bag info rosbag2_*/
```

### 4. 绘制数据曲线

```bash
# 使用 rqt_plot
ros2 run rqt_plot rqt_plot /hand_0/joint_states/effort[0]

# 多个数据
ros2 run rqt_plot rqt_plot \
  /hand_0/joint_states/effort[0] \
  /hand_0/joint_states/effort[1] \
  /hand_0/joint_states/position[0]
```

### 5. 查看 USB 设备序列号

```bash
# 方法1：udevadm（推荐）
for dev in /dev/ttyACM*; do
  echo "$dev: $(udevadm info -q property -n $dev | grep ID_SERIAL_SHORT | cut -d= -f2)"
done

# 方法2：lsusb
sudo lsusb -v 2>/dev/null | grep -E "iSerial|WUJIHAND"
```

### 6. 清理残留进程

```bash
# 停止所有 WujiHand 相关进程
pkill -f wujihand_driver_node
pkill -f robot_state_publisher
pkill -f foxglove_bridge

# 重启 daemon
ros2 daemon stop && ros2 daemon start
```

### 7. 环境变量

```bash
# 查看 ROS2 环境
printenv | grep ROS

# 常用环境变量
echo $ROS_DISTRO          # ROS2 发行版（humble/kilted）
echo $ROS_DOMAIN_ID       # DDS 域 ID（默认 0）
echo $RMW_IMPLEMENTATION  # DDS 实现
```

---

## 参考链接

- [ROS2 CLI 官方文档](https://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools.html)
- [sensor_msgs/JointState](https://docs.ros2.org/latest/api/sensor_msgs/msg/JointState.html)
- [Foxglove Studio](https://foxglove.dev/)

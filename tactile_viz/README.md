# Tactile Visualization

触觉数据三维可视化节点，将 Wujihand 触觉传感器的 36 个点的 XYZ 力矢量在 RViz 中显示。

## 依赖

- ROS2 Kilted
- wujihandcpp (已编译)
- rviz2

## 编译

```bash
cd ~/Public/wujihandros2
source /opt/ros/kilted/setup.bash
colcon build --packages-select tactile_viz
```

## 启动

### 方法一：使用 launch 文件（推荐）

同时启动节点和 RViz：

```bash
cd ~/Public/wujihandros2
source /opt/ros/kilted/setup.bash
source install/setup.bash
export LD_LIBRARY_PATH=~/Public/wujihandcpp/build:$LD_LIBRARY_PATH
ros2 launch tactile_viz tactile_viz.launch.py
```

### 方法二：分别启动

**终端 1 - 启动节点：**
```bash
cd ~/Public/wujihandros2
source /opt/ros/kilted/setup.bash
source install/setup.bash
export LD_LIBRARY_PATH=~/Public/wujihandcpp/build:$LD_LIBRARY_PATH
ros2 run tactile_viz tactile_viz_node
```

**终端 2 - 启动 RViz：**
```bash
source /opt/ros/kilted/setup.bash
source ~/Public/wujihandros2/install/setup.bash
rviz2 -d ~/Public/wujihandros2/install/tactile_viz/share/tactile_viz/rviz/tactile_display.rviz
```

## 监听 Topic

```bash
# 查看消息内容
ros2 topic echo /tactile_markers

# 查看发布频率
ros2 topic hz /tactile_markers

# 查看 topic 信息
ros2 topic info /tactile_markers
```

## 可视化说明

| 元素 | 说明 |
|------|------|
| 蓝色球体 | 触觉点位置（力小） |
| 绿色球体 | 触觉点位置（力中） |
| 红色球体 | 触觉点位置（力大） |
| 彩色箭头 | 力矢量方向和大小 |
| 黄色箭头 | 合力矢量 |

## 参数配置

点位置配置文件：`config/point_positions.yaml`

```yaml
tactile_viz:
  ros__parameters:
    frame_id: "tactile_frame"
    publish_rate: 10.0
    grid_rows: 6
    grid_cols: 6
    grid_spacing: 0.005
    force_scale: 0.001
```

## 故障排除

### ERROR_BUSY
```
[error] Failed to claim interface: -6 (ERROR_BUSY)
```
其他进程占用 USB 设备，查找并终止：
```bash
ps aux | grep tactile_viz
kill <PID>
```

### USB 权限错误
```bash
sudo chmod 666 /dev/bus/usb/<BUS>/<DEVICE>
```
或添加 udev 规则：
```bash
echo 'SUBSYSTEM=="usb", ATTR{idVendor}=="0483", MODE="0666"' | sudo tee /etc/udev/rules.d/99-wujihand.rules
sudo udevadm control --reload-rules
```

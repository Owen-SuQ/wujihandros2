# Tactile Visualization

触觉数据三维可视化节点，将 Wujihand 触觉传感器的 36 个点的 XYZ 力矢量在 RViz 中显示。

## 依赖

- ROS2 Humble / Kilted
- wujihandcpp (已编译或已安装 deb 包)
- rviz2
- foxglove_bridge (可选，用于 Foxglove/Lichtblick 可视化)
- matplotlib, numpy (用于绘图脚本)

## 编译

### 前提条件

wujihandcpp 库必须先安装，支持两种方式：

**方式一：使用 deb 包（推荐）**
```bash
sudo dpkg -i wujihandcpp_*.deb
```

**方式二：从源码编译**
```bash
cd ~/Public/wujihandcpp
mkdir build && cd build
cmake ..
make -j$(nproc)
```

### 编译 tactile_viz

```bash
cd ~/Public/wujihandros2

# 加载环境（自动检测 ROS2 版本，自动设置 LD_LIBRARY_PATH）
source env.sh

# 编译所有包
colcon build

# 或仅编译 tactile_viz
colcon build --packages-select tactile_viz

# 重新加载环境
source env.sh
```

### CMake 查找路径

CMakeLists.txt 会在以下位置查找 wujihandcpp：
- 库文件: `/usr/lib` 或 `~/Public/wujihandcpp/build`
- 头文件: `/usr/include` 或 `~/Public/wujihandcpp/include`

### 生成的可执行文件

| 可执行文件 | 说明 |
|-----------|------|
| `tactile_viz_node` | 主可视化节点，发布 MarkerArray |
| `tactile_stats_node` | 统计分析节点，输出 CSV |
| `filter_demo_node` | 滤波效果演示节点 |

## 启动

### 方法一：Foxglove/Lichtblick 可视化（推荐）

启动节点和 Foxglove Bridge，通过 WebSocket 连接可视化：

```bash
cd ~/Public/wujihandros2
source env.sh
ros2 launch tactile_viz tactile_viz_foxglove.launch.py
```

然后打开 Foxglove Studio 或 Lichtblick，连接到 `ws://127.0.0.1:8765`：
1. 添加 **3D** 面板
2. 在左侧 Topics 中勾选 `/tactile_markers`
3. 缩放视角查看触觉点网格

**Launch 参数：**
| 参数 | 默认值 | 说明 |
|------|--------|------|
| `port` | 8765 | Foxglove Bridge WebSocket 端口 |

### 方法二：RViz 可视化

同时启动节点和 RViz：

```bash
cd ~/Public/wujihandros2
source env.sh
ros2 launch tactile_viz tactile_viz.launch.py
```

### 方法三：分别启动

**终端 1 - 启动节点：**
```bash
cd ~/Public/wujihandros2
source env.sh
ros2 run tactile_viz tactile_viz_node
```

**终端 2 - 启动 RViz：**
```bash
cd ~/Public/wujihandros2
source env.sh
rviz2 -d install/tactile_viz/share/tactile_viz/rviz/tactile_display.rviz
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

### 基本参数

| 参数 | 默认值 | 说明 |
|------|--------|------|
| `frame_id` | "tactile_frame" | TF 坐标系名称 |
| `publish_rate` | 10.0 | 发布频率 (Hz) |
| `grid.rows` | 6 | 网格行数 |
| `grid.cols` | 6 | 网格列数 |
| `grid.spacing` | 0.005 | 网格间距 (m) |
| `arrow_scale` | 0.001 | 力到箭头长度的缩放因子 |
| `sphere_radius` | 0.002 | 球体半径 (m) |
| `arrow_shaft_diameter` | 0.001 | 箭头杆直径 (m) |
| `arrow_head_diameter` | 0.002 | 箭头头直径 (m) |

### 滤波参数

| 参数 | 默认值 | 说明 |
|------|--------|------|
| `smoothing_alpha` | 0.3 | EMA 平滑因子 (0-1, 越小越平滑) |
| `force_threshold_show` | 5.0 | 显示箭头的力阈值 (N) |
| `force_threshold_hide` | 2.0 | 隐藏箭头的力阈值 (N, 滞回) |
| `max_slope` | 500.0 | 最大允许斜率 (N/s), 超过此值的变化被限制 |
| `slope_filter_enabled` | true | 启用斜率滤波 |

### 运行时调参示例

```bash
ros2 run tactile_viz tactile_viz_node --ros-args \
  -p smoothing_alpha:=0.1 \
  -p force_threshold_show:=10.0 \
  -p force_threshold_hide:=5.0 \
  -p max_slope:=200.0 \
  -p slope_filter_enabled:=true
```

## 统计分析工具

`tactile_stats_node` 收集触觉数据并输出统计信息，用于分析传感器噪声特性。

### 运行

```bash
cd ~/Public/wujihandros2
source env.sh
ros2 run tactile_viz tactile_stats_node
```

### 参数

| 参数 | 默认值 | 说明 |
|------|--------|------|
| `collection_duration` | 30.0 | 采集时长 (秒) |
| `sample_rate` | 100.0 | 采样频率 (Hz) |
| `output_dir` | tactile_viz/log | 输出目录 |
| `quiet` | false | 静默模式，不打印每点详情 |

### 输出文件

- `stats_YYYYMMDD_HHMMSS.csv` - 统计摘要 (均值、标准差、最小/最大值等)
- `raw_YYYYMMDD_HHMMSS.csv` - 原始采样数据

## 故障排除

### /tactile_markers 话题未发布

节点启动但话题不发布，通常是因为无法获取触觉数据：

```bash
# 检查设备连接
lsusb | grep 0483

# 检查是否有其他进程占用
pkill -f tactile_viz_node
pkill -f wujihand_driver_node

# 查看详细日志
ros2 run tactile_viz tactile_viz_node --ros-args --log-level debug
```

### Foxglove 连接失败

```
Check that the rosbridge WebSocket server at ws://localhost:8765 is reachable.
```

1. **使用 127.0.0.1 而非 localhost**：snap 版 Foxglove 可能有网络沙箱限制
2. **端口被占用**：
   ```bash
   # 检查端口占用
   lsof -i :8765
   # 杀掉旧进程
   pkill -f foxglove_bridge
   ```

### ERROR_BUSY
```
[error] Failed to claim interface: -6 (ERROR_BUSY)
```
其他进程占用 USB 设备，查找并终止：
```bash
ps aux | grep tactile_viz
kill <PID>
```

### libwujihandcpp.so 找不到

```
error while loading shared libraries: libwujihandcpp.so: cannot open shared object file
```

设置库路径：
```bash
export LD_LIBRARY_PATH=~/Public/wujihandcpp/build:$LD_LIBRARY_PATH
```

或安装 wujihandcpp deb 包到系统目录。

### USB 权限错误
```bash
sudo chmod 666 /dev/bus/usb/<BUS>/<DEVICE>
```
或添加 udev 规则：
```bash
echo 'SUBSYSTEM=="usb", ATTR{idVendor}=="0483", MODE="0666"' | sudo tee /etc/udev/rules.d/99-wujihand.rules
sudo udevadm control --reload-rules
```

## 绘图脚本

### plot_filter_effect.py

可视化滤波效果的 Python 脚本，对比原始数据与滤波后数据。

**功能：**
- 绘制前 6 个触觉点的原始 vs 滤波力矢量
- 绘制合力的原始 vs 滤波对比
- 计算并显示噪声降低百分比
- 自动保存 PNG 图片

**依赖安装：**
```bash
pip install matplotlib numpy
```

**使用方法：**

```bash
# 方式一：自动使用最新的 filter_demo CSV 文件
python3 ~/Public/wujihandros2/tactile_viz/scripts/plot_filter_effect.py

# 方式二：指定 CSV 文件
python3 ~/Public/wujihandros2/tactile_viz/scripts/plot_filter_effect.py <csv_file>

# 示例
python3 ~/Public/wujihandros2/tactile_viz/scripts/plot_filter_effect.py \
    ~/Public/wujihandros2/tactile_viz/log/filter_demo_20251220_170501.csv
```

**生成滤波数据：**

先运行 `filter_demo_node` 采集数据：
```bash
source env.sh
ros2 run tactile_viz filter_demo_node
# 等待采集完成，数据保存到 tactile_viz/log/filter_demo_*.csv
```

**输出：**
- 终端显示交互式图表窗口
- 自动保存 `filter_demo_*_plot.png` 到同一目录

<p align="center">
  <b>简体中文</b> &nbsp;|&nbsp;
  <a href="#繁體中文">繁體中文</a> &nbsp;|&nbsp;
  <a href="#English">English</a>
</p>

---

# TrafficMonitor 已提交内存插件

TrafficMonitor 插件：在任务栏/悬浮窗显示 Windows **已提交内存（Committed Memory）** 的占用百分比与数值。

解决官方一直没做的需求（GitHub issue [#483](https://github.com/zhongyang219/TrafficMonitor/issues/483) / [#1934](https://github.com/zhongyang219/TrafficMonitor/issues/1934)）：物理内存占用率并不能反映真实内存压力——当已提交内存（物理内存 + 页面文件）接近提交限制时，程序会提示"内存不足"甚至崩溃，而任务栏显示的内存占用还很低。

## 功能

- **已提交内存百分比**：`提交: 45.2%`（已提交 / 提交限制，与任务管理器"提交"口径一致）
- **已提交内存量**：`提交量: 37.5/43.4 GB`（已提交 / 提交限额，单位后置，一位小数）
- 支持任务栏资源占用图（百分比曲线）
- 每秒刷新
- 仅依赖 `GetPerformanceInfo`（kernel32），无 MFC 依赖，DLL 约 150 KB

## 安装

1. 下载 `Release/PluginCommited.dll`
2. 放入 TrafficMonitor 程序目录下的 `plugins\` 文件夹（不存在则创建）
3. 重启 TrafficMonitor
4. 右键任务栏窗口或悬浮窗 → 选项 → 勾选「已提交内存百分比」/「已提交内存量」

> 验证加载：重启后 `config.ini` 会出现 `[plugin_display_str_taskbar_window]` 段（`commited_mem_percent`、`commited_mem_amount` 键），即表示加载成功。

## 兼容性

- TrafficMonitor **v1.8.6**（API 版本 7）实测通过；v1.8x 及更新版本理论上兼容
- 仅支持 x64 架构

## 文件

```
Release/PluginCommited.dll   编译好的插件（直接下载安装）
PluginCommited.cpp           插件源码
inc/PluginInterface.h        官方插件接口头文件（V1.86）
LICENSE.txt                  MIT 许可证
```

---

<h2 id="繁體中文">繁體中文</h2>

# TrafficMonitor 已提交記憶體插件

TrafficMonitor 插件：在工作列/懸浮窗顯示 Windows **已提交記憶體（Committed Memory）** 的佔用百分比與數值。

解決官方一直未實作的需求（GitHub issue [#483](https://github.com/zhongyang219/TrafficMonitor/issues/483) / [#1934](https://github.com/zhongyang219/TrafficMonitor/issues/1934)）：實體記憶體佔用率並不能反映真實記憶體壓力——當已提交記憶體（實體記憶體 + 分頁檔）接近提交限制時，程式會提示「記憶體不足」甚至崩潰，而工作列顯示的記憶體佔用還很低。

## 功能

- **已提交記憶體百分比**：`提交: 45.2%`（已提交 / 提交限制，與工作管理員「提交」口徑一致）
- **已提交記憶體量**：`提交量: 37.5/43.4 GB`（已提交 / 提交限制，單位後置，一位小數）
- 支援工作列資源佔用圖（百分比曲線）
- 每秒重新整理
- 僅依賴 `GetPerformanceInfo`（kernel32），無 MFC 依賴，DLL 約 150 KB

## 安裝

1. 下載 `Release/PluginCommited.dll`
2. 放入 TrafficMonitor 程式目錄下的 `plugins\` 資料夾（不存在則建立）
3. 重新啟動 TrafficMonitor
4. 在工作列視窗或懸浮窗按右鍵 → 選項 → 勾選「已提交記憶體百分比」/「已提交記憶體量」

> 驗證載入：重新啟動後 `config.ini` 會出現 `[plugin_display_str_taskbar_window]` 段（`commited_mem_percent`、`commited_mem_amount` 鍵），即表示載入成功。

## 相容性

- TrafficMonitor **v1.8.6**（API 版本 7）實測通過；v1.8x 及更新版本理論上相容
- 僅支援 x64 架構

## 檔案

```
Release/PluginCommited.dll   編譯好的插件（直接下載安裝）
PluginCommited.cpp           插件原始碼
inc/PluginInterface.h        官方插件介面標頭檔（V1.86）
LICENSE.txt                  MIT 許可證
```

---

<h2 id="English">English</h2>

# TrafficMonitor Committed Memory Plugin

A TrafficMonitor plugin that displays the Windows **committed memory** usage percentage and amount in the taskbar / floating window.

This addresses a long-standing request upstream (GitHub issue [#483](https://github.com/zhongyang219/TrafficMonitor/issues/483) / [#1934](https://github.com/zhongyang219/TrafficMonitor/issues/1934)): physical memory usage does not reflect real memory pressure — when the committed memory (physical memory + page file) approaches the commit limit, programs report "out of memory" or crash even though the taskbar shows low memory usage.

## Features

- **Committed memory percentage**: `提交: 45.2%` (committed / commit limit, same basis as Task Manager's "Committed")
- **Committed memory amount**: `提交量: 37.5/43.4 GB` (committed / commit limit, unit at the end, one decimal)
- Taskbar resource usage graph (percentage curve)
- Refreshed every second
- Uses only `GetPerformanceInfo` (kernel32), no MFC dependency, DLL ~150 KB

## Install

1. Download `Release/PluginCommited.dll`
2. Put it into the `plugins\` folder under the TrafficMonitor program directory (create it if missing)
3. Restart TrafficMonitor
4. Right-click the taskbar window or floating window → Options → check 「已提交内存百分比」/「已提交内存量」

> Verify load: after restart, `config.ini` will contain a `[plugin_display_str_taskbar_window]` section (keys `commited_mem_percent` / `commited_mem_amount`), meaning the plugin was loaded successfully.

## Compatibility

- TrafficMonitor **v1.8.6** (API version 7) tested; v1.8x and newer theoretically compatible
- x64 only

## Files

```
Release/PluginCommited.dll   compiled plugin (download and install directly)
PluginCommited.cpp           plugin source code
inc/PluginInterface.h        official plugin interface header (V1.86)
LICENSE.txt                  MIT License
```

---

## License

MIT

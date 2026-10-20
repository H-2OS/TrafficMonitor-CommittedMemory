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

- **已提交内存百分比**：显示已提交 / 提交限制的百分比（与任务管理器"提交"口径一致）
- **已提交内存量**：`已提交: 37.5/43.4 GB`（已提交 / 提交限额，单位后置，一位小数）
- 每秒刷新
- 仅依赖 `GetPerformanceInfo`（kernel32），无 MFC 依赖，DLL 约 150 KB

## 版本说明（A / B / C）

三个版本 dll 任选**其一**，放入 `plugins\` 使用：

| 版本 | 文件 |  显示效果示例 |
|------|------|----------|
| **A** | `PluginCommitedA.dll` | `提交: 45.2%  已提交: 37.5/43.4 GB` |
| **B** | `PluginCommitedB.dll` | `提交: 45%  已提交: 37.5/43.4 GB` |
| **C** | `PluginCommitedC.dll` | `内存: 45%  已提交: 37.5/43.4 GB` |

源码在 `src/` 下对应 `PluginCommitedA/B/C.cpp`。

## 安装

1. 从上表选一版，在本页右侧 **Releases（发行版）** 处下载对应 dll
2. 放入 TrafficMonitor 程序目录下的 `plugins\` 文件夹（不存在则创建）
3. 重启 TrafficMonitor
4. 右键任务栏窗口或悬浮窗 → 选项 → 勾选「已提交内存百分比」/「已提交内存量」

> 验证加载：重启后 `config.ini` 会出现 `[plugin_display_str_taskbar_window]` 段（`commited_mem_percent`、`commited_mem_amount` 键），即表示加载成功。

## 撤换（切换版本）

想换成另一版时：

1. **退出 TrafficMonitor**（右键悬浮窗/通知区图标 → 退出，或任务管理器结束）
2. 删除 `plugins\` 下旧的插件 dll（如 `PluginCommitedA.dll`）
3. 把新一版 dll（如 `PluginCommitedC.dll`）复制到 `plugins\`
4. 重新启动 TrafficMonitor

> 三版共用相同的插件 ID（`commited_mem_percent` / `commited_mem_amount`），**不能同时放入 `plugins\`**——同时存在时主程序只认先加载的一个。想换版就删旧放新，无需动其他配置。

## 兼容性

- TrafficMonitor **v1.8.6**（API 版本 7）实测通过；v1.8x 及更新版本理论上兼容
- 仅支持 x64 架构

## 文件

```
src/
  PluginCommitedA.cpp    A 版源码
  PluginCommitedB.cpp    B 版源码
  PluginCommitedC.cpp    C 版源码
inc/PluginInterface.h    官方插件接口头文件（V1.86）
LICENSE.txt              MIT 许可证
```

---

<h2 id="繁體中文">繁體中文</h2>

# TrafficMonitor 已提交記憶體插件

TrafficMonitor 插件：在工作列/懸浮窗顯示 Windows **已提交記憶體（Committed Memory）** 的佔用百分比與數值。

解決官方一直未實作的需求（GitHub issue [#483](https://github.com/zhongyang219/TrafficMonitor/issues/483) / [#1934](https://github.com/zhongyang219/TrafficMonitor/issues/1934)）：實體記憶體佔用率並不能反映真實記憶體壓力——當已提交記憶體（實體記憶體 + 分頁檔）接近提交限制時，程式會提示「記憶體不足」甚至崩潰，而工作列顯示的記憶體佔用還很低。

## 功能

- **已提交記憶體百分比**：顯示已提交 / 提交限制的百分比（與工作管理員「提交」口徑一致）
- **已提交記憶體量**：`已提交: 37.5/43.4 GB`（已提交 / 提交限制，單位後置，一位小數）
- 每秒重新整理
- 僅依賴 `GetPerformanceInfo`（kernel32），無 MFC 依賴，DLL 約 150 KB

## 版本說明（A / B / C）

三個版本 dll 任選**其一**，放入 `plugins\` 使用：

| 版本 | 檔案 | 顯示效果範例 |
|------|------|----------|
| **A** | `PluginCommitedA.dll` | `提交: 45.2%  已提交: 37.5/43.4 GB` |
| **B** | `PluginCommitedB.dll` | `提交: 45%  已提交: 37.5/43.4 GB` |
| **C** | `PluginCommitedC.dll` | `内存: 45%  已提交: 37.5/43.4 GB` |

原始碼在 `src/` 下對應 `PluginCommitedA/B/C.cpp`。

## 安裝

1. 從上表選一版，在本頁右側 **Releases（發行版）** 處下載對應 dll
2. 放入 TrafficMonitor 程式目錄下的 `plugins\` 資料夾（不存在則建立）
3. 重新啟動 TrafficMonitor
4. 在工作列視窗或懸浮窗按右鍵 → 選項 → 勾選「已提交記憶體百分比」/「已提交記憶體量」

> 驗證載入：重新啟動後 `config.ini` 會出現 `[plugin_display_str_taskbar_window]` 段（`commited_mem_percent`、`commited_mem_amount` 鍵），即表示載入成功。

## 撤換（切換版本）

想換成另一版時：

1. **退出 TrafficMonitor**（在懸浮窗/通知區圖示按右鍵 → 退出，或工作管理員結束）
2. 刪除 `plugins\` 下舊的插件 dll（如 `PluginCommitedA.dll`）
3. 把新一版 dll（如 `PluginCommitedC.dll`）複製到 `plugins\`
4. 重新啟動 TrafficMonitor

> 三版共用相同的插件 ID（`commited_mem_percent` / `commited_mem_amount`），**不能同時放入 `plugins\`**——同時存在時主程式只認先載入的一個。想換版就刪舊放新，無需動其他設定。

## 相容性

- TrafficMonitor **v1.8.6**（API 版本 7）實測通過；v1.8x 及更新版本理論上相容
- 僅支援 x64 架構

## 檔案

```
src/
  PluginCommitedA.cpp    A 版原始碼
  PluginCommitedB.cpp    B 版原始碼
  PluginCommitedC.cpp    C 版原始碼
inc/PluginInterface.h    官方插件介面標頭檔（V1.86）
LICENSE.txt              MIT 許可證
```

---

<h2 id="English">English</h2>

# TrafficMonitor Committed Memory Plugin

A TrafficMonitor plugin that displays the Windows **committed memory** usage percentage and amount in the taskbar / floating window.

This addresses a long-standing request upstream (GitHub issue [#483](https://github.com/zhongyang219/TrafficMonitor/issues/483) / [#1934](https://github.com/zhongyang219/TrafficMonitor/issues/1934)): physical memory usage does not reflect real memory pressure — when the committed memory (physical memory + page file) approaches the commit limit, programs report "out of memory" or crash even though the taskbar shows low memory usage.

## Features

- **Committed memory percentage**: committed / commit limit (same basis as Task Manager's "Committed")
- **Committed memory amount**: `已提交: 37.5/43.4 GB` (committed / commit limit, unit at the end, one decimal)
- Refreshed every second
- Uses only `GetPerformanceInfo` (kernel32), no MFC dependency, DLL ~150 KB

## Versions (A / B / C)

Pick **one** of the three DLLs and put it into `plugins\`:

| Version | File | Display example |
|---------|------|----------|
| **A** | `PluginCommitedA.dll` | `提交: 45.2%  已提交: 37.5/43.4 GB` |
| **B** | `PluginCommitedB.dll` | `提交: 45%  已提交: 37.5/43.4 GB` |
| **C** | `PluginCommitedC.dll` | `内存: 45%  已提交: 37.5/43.4 GB` |

Sources under `src/` as `PluginCommitedA/B/C.cpp`.

## Install

1. Pick a version above and download the matching DLL from **Releases** (right sidebar of this page)
2. Put it into the `plugins\` folder under the TrafficMonitor program directory (create it if missing)
3. Restart TrafficMonitor
4. Right-click the taskbar window or floating window → Options → check 「已提交内存百分比」/「已提交内存量」

> Verify load: after restart, `config.ini` will contain a `[plugin_display_str_taskbar_window]` section (keys `commited_mem_percent` / `commited_mem_amount`), meaning the plugin was loaded successfully.

## Switching Versions

To switch to another version:

1. **Quit TrafficMonitor** (right-click the floating window / tray icon → Exit, or end it in Task Manager)
2. Delete the old plugin DLL from `plugins\` (e.g. `PluginCommitedA.dll`)
3. Copy the new version's DLL (e.g. `PluginCommitedC.dll`) into `plugins\`
4. Restart TrafficMonitor

> All three versions share the same plugin IDs (`commited_mem_percent` / `commited_mem_amount`), so **never place more than one of them in `plugins\` at the same time** — the host only recognizes the first one loaded. To switch, just delete the old and drop in the new; no other configuration changes needed.

## Compatibility

- TrafficMonitor **v1.8.6** (API version 7) tested; v1.8x and newer theoretically compatible
- x64 only

## Files

```
src/
  PluginCommitedA.cpp    version A source
  PluginCommitedB.cpp    version B source
  PluginCommitedC.cpp    version C source
inc/PluginInterface.h    official plugin interface header (V1.86)
LICENSE.txt              MIT License
```

---

## License

MIT

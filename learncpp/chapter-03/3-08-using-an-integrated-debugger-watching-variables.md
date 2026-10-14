# 3.8 Using an integrated debugger: Watching variables

> 原文：https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-watching-variables/

## 核心概念

> 本节原文以 **Visual Studio** 的界面为主要示例（同时给出 Code::Blocks 与 VS Code 的对应操作）。

### 单步之外

- 单步能追踪执行走了哪条路径，但那只是调试器价值的一半；它还能在不改动源码的情况下查看变量值。
- **Warning**：项目必须用 **debug 配置**编译；release 配置下调试器的功能可能表现异常（见第 0.9 课"构建配置"）。
- **监视变量（watching a variable）**：在程序于调试器下运行时检查变量的值；多数调试器提供多种方式。
- 本节示例程序打印 `1 3 6`。先 Run to cursor 到第 6 行；此时 `x` 已存在，值为 1。

### 悬停查看（Hover）

- 最简单的办法（适用于简单变量）：把鼠标指针停在变量名上。部分现代调试器支持。
- **Code::Blocks 的悬停默认关闭**：*Settings > Debugger…* → 在 *GDB/CDB debugger* 节点下选择 *Default* 配置 → 勾选 "Evaluate expression under cursor"。
- 可在变量的**任意出现处**悬停，不限于当前执行行；例如悬停第 12 行上的 `x` 会显示相同的值。

### QuickWatch（Visual Studio）

- 选中变量名，右键 → "QuickWatch"，会弹出一个子窗口显示当前值。

### 逐步观察

- 步过两次（Step Over × 2），或 Run to cursor 到第 9 行，`x` 应变为 `3`。

### 监视窗口（Watch window）

- 定义：一个窗格，放入你想**持续观察**的变量，每次单步它们的值都会刷新。悬停/QuickWatch 每次都要重新选择，用起来不方便。
- 打开方式：通常在 IDE 的窗口命令里，多数在 *View* 或 *Debug* 菜单下；调试模式下它可能已经是可见的。
  - **Visual Studio**：*Debug > Windows > Watch > Watch 1*——需要处于调试模式，所以先步入程序。拖动标签可改变停靠位置。
  - **Code::Blocks**：*Debug > Debugging windows > Watches*——通常作为独立窗口打开，可拖回去停靠。
  - **VS Code**：调试模式下出现在左侧，停靠在调用栈上方。
- 向监视窗口添加变量的两种方式：
  1. 在监视窗口最左列直接输入变量名；
  2. 在代码中右键变量 → *Add Watch*（Visual Studio）或 *Watch x*（Code::Blocks，`x` 替换为实际变量名）。
- 确认监视生效：把 `x` 加入监视列表，步过两次或 Run to cursor 到第 12 行，值应从 3 更新为 6。

### 超出作用域的变量

- 变量超出作用域后仍留在监视窗口里，通常标为 "not available" 或灰显并显示最后已知值；当变量重新进入作用域时，其值会再次显示。把它留在列表里没有问题。

- **推荐用法**：监视是跟踪某个变量值随时间变化的最佳方式。

### 在变量上设断点

- 有些调试器允许按**变量**而非按行设断点：只要该变量的值发生改变，执行就暂停。对上面的 `x`，会在第 8 行和第 11 行之后停下。
  - **Visual Studio**：确保该变量已被监视，步入程序，在监视窗口中右键它 → "Break when value changes"。**每个调试会话开始时都需要重新启用**。

### 监视窗口中的表达式

- 可在监视窗口求简单表达式的值；例如在第 12 行输入 `x + 2`，应得 `8`。
- 也可以在代码中高亮一个表达式，通过悬停查看，或经右键菜单把它加进去。
- **Warning**：被求值的标识符取其**当前值**，所以若想要某表达式的真实值，要先 Run to cursor 到相关的那一行。

### 局部变量监视（Locals）

- 查看当前作用域内所有局部变量是常见的调试需求，很多调试器提供了快捷方式：
  - **Visual Studio**：*Locals* 窗口（*Debug > Windows > Locals*，需要活动的调试会话）。
  - **Code::Blocks**：集成在 *Watch* 窗口的 *Locals* 节点下；若为空，要么没有局部变量，要么需要展开该节点。
  - **VS Code**：调试模式下左侧停靠的 *VARIABLES* 区；*Locals* 节点可能需要展开。
- 实用建议：如果只需要某个局部变量的值，先看 locals 窗口——它大概率已经列在那里了。

## 最佳实践

本节原文没有 Best practice 或 Author's note 标注，但包含以下 Warning：

- **Warning（构建配置）**：使用 debug 构建配置编译，否则调试器的功能可能无法正常工作（见第 0.9 课）。
- **Warning（表达式的当前值）**：被监视的表达式使用标识符的当前值，若需要该表达式的实际求值结果，请先 Run to cursor 到相应位置。

## 代码示例

> 说明：本节原文直接给出了完整代码，本文件为其忠实复制。

- [3-08-example1.cpp](3-08-example1.cpp) — 监视 `x` 在三次赋值中从 1 → 3 → 6 的变化（Run to cursor 到第 6 / 9 / 12 行观察）。

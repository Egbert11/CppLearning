# 3.7 Using an integrated debugger: Running and breakpoints

> 原文：https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-running-and-breakpoints/

## 核心概念

> 本节原文以 **Visual Studio** 的界面为主要示例（同时给出 Code::Blocks 与 VS Code 的对应操作）。

- **动机**：逐行单步很有用，但在大程序里太慢；调试器提供了更快的代码行进方式。

### Run to cursor（运行到光标处）

- 定义：执行程序直到到达光标所选的语句，然后把控制权交还，让你可以从那里开始调试。
- 调用方式：
  - **Visual Studio**：右键某条语句 → *Run to Cursor*，或按 **Ctrl-F10**。
  - **Code::Blocks**：右键 → *Run to cursor*，或 *Debug 菜单 > Run to cursor*，或按 **F4**。
  - **VS Code**：仅在已在调试时可用——右键语句 → *Run to Cursor*。
- 执行后标记会移动到所选行；程序已执行到该点并等待下一步命令（此时可继续单步、Continue，或再运行到别处）。
- 边界情况：若目标行永远不会被执行，该命令会让程序一直运行到结束。

### Continue（继续）与 Start（开始）

- **Continue**：恢复正常执行，直到程序结束、或某个事件（例如断点）把控制权交还给你。
  - Visual Studio：*Debug > Continue* 或 **F5**；Code::Blocks：*Debug > Start / Continue* 或 **F8**；VS Code：*Run > Continue* 或 **F5**。
- **Start**：与 Continue 类似，但从程序开头开始；仅当尚未处于调试会话时可用。
  - Visual Studio：*Debug > Start Debugging* 或 **F5**；Code::Blocks：*Debug > Start / Continue* 或 **F8**；VS Code：*Run > Start Debugging* 或 **F5**。
- 对示例程序而言，Start 会一次跑完且不中断；但 VS Code 例外，因为上一节设置了 `stopAtEntry: true`。

### Breakpoint（断点）

- 定义：一个特殊标记，指示调试器在调试模式下运行到该点时暂停执行。
- 调用方式：
  - **Visual Studio**：*Debug > Toggle Breakpoint*、右键 → *Toggle Breakpoint*、按 **F9**，或点击行号左侧；显示为**红色圆点**。
  - **Code::Blocks**：*Debug > Toggle breakpoint*、右键 → *Toggle breakpoint*、按 **F5**，或点击行号右侧；显示为**红色八角形**（停车标志形状）。
  - **VS Code**：*Run > Toggle Breakpoint*、按 **F9**，或点击行号左侧。
- 断点行为：选 Start 后，程序会停在断点处而不是一路跑完，执行标记落在断点图标上——效果类似于在那里做了 Run to cursor。
- **断点相对 Run to cursor 的优势**：(a) 每次遇到该行都会交还控制权；(b) 断点会一直保留直到你移除它，而 Run to cursor 每次都要重新定位。
- **规则**：位于不在执行路径上的行的断点不会让程序暂停。

### Set next statement（设置下一条语句）

- 定义：把执行点改到另一条语句上（俗称"跳转"），可以向前跳过代码，也可以向后重跑已执行过的代码。
- 调用方式：
  - **Visual Studio**：右键 → *Set next statement*，或 **Ctrl-Shift-F10**（仅在调试上下文可用）。
  - **Code::Blocks**：*Debug > Set next statement* 或右键 → *Set next statement*（无键盘快捷键）。
  - **VS Code**：右键 → *Jump to cursor*（仅在调试上下文可用）。
- 用途一：跳过某个函数调用。若想测试某函数是否与 bug 有关，不必把它注释掉，直接在调试器里跳过去即可——这是调试器中最简单的做法。
- 用途二：向后跳，重新观察刚执行过的函数的行为。
- 与 Step back 的区别：Step back 会**撤销**程序状态，如同你从未经过该点（是对单步的"后悔药"）；而 Set next statement 向后跳只是**移动执行点**，不撤销任何东西。

## 最佳实践

本节原文没有 Best practice 或 Author's note 标注，但包含以下 Warning：

- **Warning（跳转不改变状态）**：*Set next statement* 只改变执行点，不改变程序状态。变量会保留先前的值，因此跳转后的值、结果或行为可能与正常执行不同；请谨慎使用，尤其是**向后跳**时。
- **Warning（不要跨函数跳转）**：不要用 *Set next statement* 把执行移到另一个函数内部；这可能导致未定义行为，并且很可能崩溃。

## 代码示例

> 说明：本节示例代码为**按原文示例重建**（原文长代码块无法被逐字抓取，故按描述与站点标准示例忠实重建，语义一致、可编译）。

- [3-07-example1.cpp](3-07-example1.cpp) — 单次调用程序，用于演示 Run to cursor / Continue / Start / 断点。
- [3-07-example2.cpp](3-07-example2.cpp) — 三次调用版本，用于对比断点与 Run to cursor，并演示 Set next statement 的向前/向后跳转。

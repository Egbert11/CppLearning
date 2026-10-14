# 3.6 Using an integrated debugger: Stepping

> 原文：https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-stepping/

## 核心概念

> 本节原文以 **Visual Studio** 的界面为主要示例（同时给出 Code::Blocks 与 VS Code 的对应操作）。

### 程序状态与调试的动机

- **程序状态（program state）**：程序运行到某一时刻时记录的全部信息——当前用到的变量值、调用过哪些函数（以便返回时知道回到哪里）、以及当前执行点。
- 用打印/日志来调试的缺点：它会改动代码、耗时、可能引入新 bug，还会把代码弄乱。
- 我们平时有个未言明的假设：代码一旦运行就会一路执行到结束，中途没有机会介入查看结果。调试器打破了这一点。
- **调试器（debugger）**：一个让程序员能够控制另一个程序如何执行、并检查其程序状态的程序。
- 调试器的两大能力：对执行流程的精确控制，加上查看（必要时修改）程序状态的能力。
- 历史上调试器先是命令行程序（gdb）或独立的图形前端（Turbo Debugger），后来才被集成进 IDE。
- **集成调试器（integrated debugger）**：与代码编辑器使用同一界面的调试器，可以在写代码的同一环境里调试。命令行调试器至今仍在无图形界面处（如嵌入式系统）广泛使用。
- 各 IDE 的菜单位置和快捷键并不一致，但功能是标准的。

### 使用前：构建配置（规则）

- 必须使用 **debug（调试）构建配置**编译项目。若用 release 构建，调试器可能出错——例如"步入"会直接变成"运行"。

### Code::Blocks 配置步骤

1. 打开 *Settings > Debugger…*。
2. 展开 *GDB/CDB debugger* 树，选择 *Default*。
3. 若 "Executable path" 处出现红条，点 *…* 按钮，定位到 `gdb32.exe`（例如 `C:\Program Files (x86)\CodeBlocks\MinGW\bin\gdb32.exe`），然后点 *OK*。
- 已知问题：GDB 对含空格或非英文字符的文件路径可能识别困难。

### VS Code 配置步骤

1. 按 *Ctrl+Shift+P*，选 "C/C++: Add Debug Configuration"。
2. 选 "C/C++: g++ build and debug active file"，这会创建/打开 `launch.json`。
3. 设置 `"stopAtEntry": true,`。
4. 打开 `main.cpp`，用 *F5* 或 *Ctrl+Shift+P > "Debug: Start Debugging and Stop on Entry"* 开始调试。

### 单步执行（Stepping）

- **单步（stepping）**：一组相关的调试器功能，让我们一条语句一条语句地执行（step through）代码。

#### Step Into（步入）

- 执行正常执行路径上的下一条语句，然后暂停，以便检查程序状态；若该语句中含有函数调用，则跳到被调用函数的顶部再暂停。
- 首次执行调试命令时：必要时会重新编译；程序开始运行并打开一个（空的）控制台窗口；IDE 可能弹出诊断窗口（如 "Diagnostic Tools"、"Call Stack"、"Watch"），暂时可以忽略。
- `main` 左花括号左侧会出现一个标记：Visual Studio 是**黄色箭头**，Code::Blocks 是**黄色三角**，用来指示下一条将执行的语句。
- 逐步走示例代码时，会依次经过第 9、10 行，进入 `printValue` 的第 4 行，再到第 5、6 行。
- 走到函数的闭合花括号时，箭头看似又指回调用处——那是调试器在提示"即将返回"，不是又调用了一次。
- 结束：许多调试器会自动结束会话；否则用 "Stop Debugging"（Visual Studio 中是 *Debug > Stop Debugging*）。**Stop Debugging 在任意时刻都可用**，用来结束会话。
- 快捷键：Visual Studio *Debug > Step Into* 或 **F11**；Code::Blocks *Debug > Step into* 或 **Shift-F7**；VS Code *Run > Step Into*。

#### Step Over（步过）

- 执行下一条语句，但把整个函数一次性跑完，等函数返回后再交还控制权。适合跳过你信任、或暂时不想深入查看的函数。
- 快捷键：Visual Studio *Debug > Step Over* 或 **F10**；Code::Blocks 中该命令叫 *Next line*（*Debug > Next line*，**F7**）；VS Code *Run > Step Over* 或 **F10**。

#### Step Out（步出）

- 跑完当前函数中剩余的代码，函数返回后交还控制权。最常用于"不小心步入了某个函数"之后。
- 快捷键：Visual Studio *Debug > Step Out* 或 **Shift-F11**；Code::Blocks *Debug > Step out* 或 **Ctrl-F7**；VS Code *Run > Step Out* 或 **Shift+F11**。

#### 越步与反向调试

- **越步规则**：单步通常只能向前。若走过了目标位置，通常只能停止并重新开始调试，这次更小心一些。
- **Step back / 反向调试**：回退上一步以恢复先前的状态，适合走过头之后或想重看某条语句时。它要求调试器为每一步记录一份独立的程序状态，因此没有标准化、因调试器而异；截至 2019 年 1 月，Visual Studio 社区版和当时最新的 Code::Blocks 都不支持。

## 最佳实践

本节原文没有 Best practice 标注，但包含以下 Tip 与 Warning：

- **Tip**：只有当 IDE/集成调试器是活动窗口时，调试快捷键才有效。
- **Tip**：不要跳过学习调试器。随着程序变复杂，学习它所花的时间远小于它帮你找到并修复问题所节省的时间。
- **Warning**：在开始本节及其后的调试器课程前，确保项目使用 **debug 构建配置**。在 release 配置下调试器可能无法正确工作——例如"步入"程序时它可能直接运行过去。
- **Warning**：用于输出的 `operator<<` 本身是以函数形式实现的，因此 IDE 可能步入标准库的实现里。若发生这种情况，关掉新打开的那个文件，改用 *step out*。
- **Tip**：因为 `std::cout` 是带缓冲的，值 `5` 可能不会立刻显示；`std::unitbuf` 语句可强制立即输出（调试完记得移除，以保证性能）。
- **Tip**：后续的调试命令可能要求调试器已经在运行；如果命令灰显，先步入你的代码启动调试器再重试。
- **Warning（Code::Blocks）**：有报告称 Code::Blocks 的 GDB 调试器在含空格或非英文字符的路径下可能表现异常，这可能解释调试过程中的某些奇怪行为。

## 代码示例

> 说明：本节示例代码为**按原文示例重建**（原文长代码块无法被抓取工具逐字返回，故按描述与站点标准示例忠实重建，语义一致、可编译）。

- [3-06-example1.cpp](3-06-example1.cpp) — 双函数程序，用于在调试器中演示 Step Into / Step Over / Step Out（运行打印 `5`）。
- [3-06-example2.cpp](3-06-example2.cpp) — 用 `std::unitbuf` 强制 `std::cout` 立即刷新（含 `#ifdef DEBUG` 条件编译写法）。

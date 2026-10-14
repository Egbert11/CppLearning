# 3.4 Basic debugging tactics

> 原文：https://www.learncpp.com/cpp-tutorial/basic-debugging-tactics/

## 核心概念

### 手法 #1：注释掉代码（Commenting out code）

- 通过把程序的某些部分注释掉再重新运行，来缩小搜索范围；如果故障行为**没有变化**，那么被注释掉的代码很可能不是罪魁祸首。
- 注释掉一段代码后会得到三种结果之一：
  - **bug 消失了** → 说明刚注释掉的那部分（通常是某个函数）与问题有关；
  - **bug 照旧** → 说明该函数很可能是清白的，可以把它放到一边（但仍不知道故障在那段代码之前还是之后）；
  - **变成了另一个问题** → 说明有其他代码依赖于你禁用掉的东西；此时应把它恢复，再换别处试试。
- **警告（Warning）**：很容易忘记自己注释掉了什么。忘了恢复某处代码，就可能"修好一个 bug、又制造出别的 bug"。借助版本控制系统与主分支做 diff，可以方便地发现残留的调试性改动。

### 手法 #2：验证代码流程（Validating code flow）

- 当某个函数运行得太频繁、太少、或根本没运行时，可以在每个函数的开头插入一条打印函数名的语句，这样运行日志就能显示到底执行了哪些函数。
- **调试输出应使用 `std::cerr` 而不是 `std::cout`**：`std::cout` 可能是带缓冲的，若程序紧接着崩溃，刚请求输出的内容可能还没显示出来，从而误导你对故障位置的判断；`std::cerr` 不带缓冲、会立刻写出，同时它也能表明该信息是诊断用途而非正常程序输出。

### 手法 #3：打印值（Printing values）

- 输出变量、参数和表达式的值，验证被计算和传递的值确实符合预期，然后逐步缩小"值第一次出错"的位置。

### 临时调试语句的格式

- 让临时调试语句**不缩进**，以后更容易一眼找到并删除；使用 clang-format 时，可以用 `// clang-format off` 与 `// clang-format on` 把调试语句包起来，阻止自动缩进。

### 打印语句调试的缺点

- 会弄乱源码、弄乱程序输出；添加和删除时都要改代码（有引入新 bug 的风险）；而且事后必须删掉，因而**不可复用**。

## 最佳实践

本节原文没有 Best practice 标注，但包含以下 Warning 与 Tip：

- **Warning**：不要忘记自己注释掉了哪些函数，它们需要被恢复。撤销调试改动时这些编辑很容易被忽略；建议用版本控制系统与主分支 diff，确认所有这类改动都已还原后再提交。
- **Tip（让调试输出可复用）**：与其反复添加/删除调试语句，不如借助第三方库——例如 header-only 的 `dbg` 库，可以把调试语句留在源码中，并在发布构建里通过预处理宏（`DBG_MACRO_DISABLE`）把它们编译掉。
- **Tip（`std::cerr` 对比 `std::cout`）**：调试输出应写入 `std::cerr`。因为 `std::cout` 有缓冲，崩溃前一刻请求输出的文本可能尚未显示，会让你误判故障位置；而 `std::cerr` 会立即写出，并且也能表明该信息与错误情形相关、而非正常运行信息。
- **Tip（调试语句的格式）**：临时调试语句不缩进时更容易被定位和删除；clang-format 的自动缩进可用 `// clang-format off` / `// clang-format on` 抑制。

## 代码示例

- [3-04-example1.cpp](3-04-example1.cpp) — 手法 #1 的初始程序：`main()` 里包含 `doMaintenance()` 调用。
- [3-04-example2.cpp](3-04-example2.cpp) — 手法 #1：把 `doMaintenance()` 注释掉后的同一程序。
- [3-04-example3.cpp](3-04-example3.cpp) — 有 bug 的程序：调用 `getValue` 时漏写括号 `()`，打印的是函数指针。该文件含原文故意保留的 bug。
- [3-04-example4.cpp](3-04-example4.cpp) — 同一程序加上"打印函数名"的调试语句（`std::cerr`）。
- [3-04-example5.cpp](3-04-example5.cpp) — 修复版：补上 `getValue()` 的括号。
- [3-04-example6.cpp](3-04-example6.cpp) — 有 bug 的加法程序：传了错误的实参 `add(x, 5)`。该文件含原文故意保留的 bug。
- [3-04-example7.cpp](3-04-example7.cpp) — 在 `main` 中打印 `x`、`y`、`z` 的值以定位问题。
- [3-04-example8.cpp](3-04-example8.cpp) — 在 `add()` 内部加调试输出，暴露出错误的实参。
- [3-04-example9.cpp](3-04-example9.cpp) — 第二个有 bug 的程序：`return --x;` 里多写了一个 `--`。该文件含原文故意保留的 bug。
- [3-04-example10.cpp](3-04-example10.cpp) — 对示例 9 全面加装调试语句。
- [3-04-example11.cpp](3-04-example11.cpp) — 再在 `getUserInput` 内部加一条调试语句，检查其局部值。
- [3-04-example12.cpp](3-04-example12.cpp) — 修复版：去掉 `--` 运算符。

# 2.10 Introduction to the preprocessor

> 原文：https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/

## 核心概念

- **预处理发生在编译之前**：每个 `.cpp` 文件先经过一个"预处理"阶段，由**预处理器（preprocessor）**对代码文本做各种修改。
- **不会改动原文件**：预处理器并不真的修改原始代码文件，改动发生在内存或临时文件里。历史上预处理器是独立程序，现代编译器里它可能已内建。
- **大部分预处理很平常**：去掉注释、保证文件以换行结尾等。
- **它的核心工作是处理 `#include`**：预处理器负责展开 `#include` 指令。
- **翻译单元（translation unit）**：预处理的结果称为翻译单元，随后被编译器编译。预处理 + 编译 + 链接统称**翻译（translation）**；预处理覆盖标准翻译阶段 1–4，编译覆盖 5–7。
- **预处理指令（preprocessor directive）**：以 `#` 开头、以**换行**（不是分号）结束的指令。它只做文本处理，**不理解 C++ 语法**。
- **关键点**：预处理器的最终输出里**不再有任何指令**，只有被处理后产生的内容传给编译器。
- **`#include` 的行为**：该指令被替换为被包含文件的全部内容，这些内容会被递归预处理（可能又引入更多 `#include`），然后再继续处理本文件其余部分。因此一个翻译单元 ≈ 一个 `.cpp` 文件 + 它递归包含的所有头文件。
- **宏（macro）**：`#define` 创建宏，即"把输入文本转换为替换文本的规则"。分**对象式宏**和**函数式宏**两类。函数式宏用起来像函数，但一般被认为不安全，且几乎都能用普通函数替代。
- **对象式宏两种形式**：`#define IDENTIFIER` 或 `#define IDENTIFIER substitution_text`，都不以分号结尾。
- **命名规则**：与普通标识符相同（字母、数字、下划线，不能以数字开头，不应以下划线开头）；约定全大写、单词间用下划线。
- **带替换文本的对象式宏**：标识符绑定到替换文本，之后出现的宏标识符（除其它预处理命令内部）都会被替换。它在 C 里用于命名字面量，C++ 有更好选择（如内联变量，见 7.10），现在主要见于老代码。
- **不带替换文本的对象式宏**：出现处被"替换为空"，不能用于替换，但可用于条件编译等其它用途，一般可接受。
- **条件编译指令**：最常见的是 `#ifdef`、`#ifndef`、`#endif`。`#ifdef` 检查某标识符是否曾被 `#define`；`#ifndef` 则相反（未被定义时成立）。等价的新式写法是 `#if defined(X)` 与 `#if !defined(X)`。
- **`#if 0`**：把一段代码排除在编译之外，改成 `#if 1` 即可重新启用。多行注释不能嵌套，所以用 `#if 0` 来注释掉本来就含块注释的代码很方便。
- **指令里的宏替换**：通常宏标识符出现在另一个预处理命令内部时**不会**被替换；例外是大多数形式的 `#if` 和 `#elif` 会替换。
- **`#define` 的作用范围**：指令在编译前自上而下、逐文件解析。宏不受函数作用域约束——写在函数里和写在函数外效果一样（因为预处理器不认识函数），建议写在函数外以免混淆。被 `#include` 的文件里的指令会按顺序并入当前文件。文件预处理结束后，该文件里定义的所有标识符都被丢弃——指令只在"从定义处到文件末尾"有效，除非被 `#include`，否则不影响其它文件。

## 最佳实践

- 宏名使用全大写字母，单词间用下划线分隔。
- 除非别无更好选择，避免使用带替换文本的宏。

## 代码示例

- [2-10-example1.cpp](2-10-example1.cpp)：原文 Example 1——`#include <iostream>` 在预处理时被替换为头文件全部内容。
- [2-10-example2.cpp](2-10-example2.cpp)：原文 Example 2——带替换文本的对象式宏 `MY_NAME`，输出 `My name is: Alex`。
- [2-10-example4.cpp](2-10-example4.cpp)：原文 Example 4——不带替换文本的对象式宏 `#define USE_YEN`，用 `#ifdef` 控制编译。
- [2-10-example5.cpp](2-10-example5.cpp)：原文 Example 5——`#ifdef PRINT_JOE`/`#ifdef PRINT_BOB`，只输出 `Joe`。
- [2-10-example6.cpp](2-10-example6.cpp)：原文 Example 6——`#ifndef PRINT_BOB`，输出 `Bob`。
- [2-10-example7.cpp](2-10-example7.cpp)：原文 Example 7——`#if 0` 排除 Bob、Steve，只输出 `Joe`。
- [2-10-example8.cpp](2-10-example8.cpp)：原文 Example 8——用 `#if 0` 包裹含块注释的代码，只输出 `Joe`。
- [2-10-example9.cpp](2-10-example9.cpp)：原文 Example 9——改成 `#if 1`，重新编译 Bob、Steve。
- [2-10-example10.cpp](2-10-example10.cpp)：原文 Example 10——指令内部的 `PRINT_JOE` 不被替换，输出 `Joe`。
- [2-10-example11.cpp](2-10-example11.cpp)：原文 Example 11——`#define FOO 9`：指令里的 `FOO` 不替换，普通代码里的替换为 9，输出 `9`。
- [2-10-example12.cpp](2-10-example12.cpp)：原文 Example 12——在函数内部写 `#define` 与在外部等价，输出 `My name is: Alex`。
- [2-10-example13/Alex.h](2-10-example13/Alex.h) + [2-10-example13/main.cpp](2-10-example13/main.cpp)：原文 Example 13——头文件里的 `#define` 被 `#include` 复制进来。
- [2-10-example14/main.cpp](2-10-example14/main.cpp) + [2-10-example14/function.cpp](2-10-example14/function.cpp)：原文 Example 14——宏只在其所在文件内有效，输出 `Not printing!`。

> 说明：原文 Example 3（"预处理之后"的展开版本）只是对 Example 2 结果的示意，并非可编译源码，故未生成文件。

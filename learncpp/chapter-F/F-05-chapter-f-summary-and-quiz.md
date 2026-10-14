# F.x Chapter F summary and quiz

> 原文：https://www.learncpp.com/cpp-tutorial/chapter-f-summary-and-quiz/
>
> 注：本小节的官方编号为 **F.X**（章节总结与测验）。按仓库命名约定，正文小节 F.1–F.4 占 YY=01–04，此处顺延取 YY=05。

## 核心概念

- **constexpr 函数**：一种被允许在常量表达式中调用的函数；在返回类型前加上 `constexpr` 关键字即可创建。
- **何时保证编译期求值**：constexpr 函数**只有在要求常量表达式的语境中**才保证编译期求值；其他情形下它可能编译期求值（若具备能力）也可能运行期求值。
- **隐式 inline**：constexpr 函数自动带内联链接；要做编译期调用，编译器必须能看到函数的完整定义。
- **consteval 函数**：一种**必须**在编译期运行的函数。除此之外，"consteval 函数遵循与 constexpr 函数相同的规则"。
- **I/O 不能是 constexpr**：执行输入/输出的函数不能设为 constexpr，因为用于 I/O 的 `operator<<` / `operator>>` 不支持 constexpr。
- **纯计算函数可以 constexpr**：如果一个函数只是根据输入算出值并返回（不调用非 constexpr 函数），就可以设为 constexpr。
- **运行期还是编译期取决于实参**：当实参是 constexpr 时，constexpr 函数可以是编译期调用；否则是运行期调用。
- **尽可能 constexpr**：解答给出的经验法则是 —— "If a function can be made constexpr, it should be."（一个函数只要能设为 constexpr，就应该设为 constexpr。）
- **形参不是 constexpr**：即便在 constexpr 函数内部，形参本身也不是 constexpr 值。
- **const 与 constexpr 用于变量**：初值不是常量表达式的局部变量或 main 作用域变量可以是 `const`，但不能是 `constexpr`。

## 最佳实践

本节无独立的 Best practice / Warning 提示框；指导性内容以解答中的行内注释形式出现：

- "This function should not be made constexpr because output and input can only be done at runtime."
- "If a function can be made constexpr, it should be."
- "Remember: function parameters are not constexpr, even in a constexpr function"
- "Reminder: A constexpr function can be evaluated at compile-time or runtime."

## 本章知识速览

- constexpr 函数**可以**用于常量表达式；consteval 函数**必须**在编译期求值（immediate function）。
- 编译期求值只在"要求常量表达式"的语境中被**保证**；在运行期，constexpr 函数与普通函数无异。
- 函数形参（即便在 constexpr 函数中）不是 constexpr，不能用于函数内部的常量表达式。
- constexpr/consteval 函数隐式 inline，需让编译器看到完整定义，通常放在头文件中。
- `std::is_constant_evaluated()`（C++20）/ `if consteval`（C++23）用于判断是否处于常量求值语境。
- 做 I/O 的函数不能 constexpr；只做纯计算的函数应 constexpr。
- 变量：初值是常量表达式 ⇒ 可用 `constexpr`；初值不是常量表达式 ⇒ 只能用 `const`。

## 测验

- **第 1 题**：给下面的程序加上合适的 `const` 和/或 `constexpr`。
  - 程序：从用户读取塔高，用公式 `s = u*t + (a*t^2)/2`（此处 `u`=0、`a`=9.8）计算小球 0–5 秒时距地面的高度并逐秒打印。
  - 涉及函数：`double getTowerHeight()`、`double calculateBallHeight(double towerHeight, int seconds)`、`void printBallHeight(double ballHeight, int seconds)`、`void printCalculatedBallHeight(double towerHeight, int seconds)`。
  - 解答见 [F-05-quiz1.cpp](F-05-quiz1.cpp)（已应用：`calculateBallHeight` 设为 constexpr；`gravity` 用 constexpr；I/O 函数保持非 constexpr；`distanceFallen`/`currentHeight`/`ballHeight`/`towerHeight` 用 const）。

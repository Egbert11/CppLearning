# F.1 Constexpr functions

> 原文：https://www.learncpp.com/cpp-tutorial/constexpr-functions/

## 核心概念

- **常量表达式中不能调用普通函数**：一个能在编译期求值的表达式里若出现普通函数调用，就不再是常量表达式，因而不能用在要求常量表达式的地方。
- **constexpr 函数的定义**：为了让函数能出现在常量表达式里，需要在函数的返回类型之前加上 `constexpr` 关键字。
- **Key insight**：`constexpr` 关键字的作用是告诉编译器和其他程序员 —— 这个函数可以用于常量表达式。
- **编译期求值规则**：在"必须"是常量表达式的语境中（例如 constexpr 变量的初始化器），其中的 constexpr 函数调用**必须**在编译期求值。
- **编译器的处理方式**：编译器在编译期算出返回值，并把这次函数调用直接替换成该值。
- **编译期求值的两个额外要求**：调用时所有实参必须在编译期已知；函数体内的每一条语句和表达式都必须在编译期可求值。
- **嵌套调用**：当某个 constexpr（或 consteval）函数在编译期运行时，它内部调用的任何函数也必须在编译期求值，否则无法得到编译期结果。
- **For advanced readers**：还存在少数不常见的判据，详见 cppreference 的 constexpr 页面。
- **也允许运行期求值**：constexpr 函数同样可以在运行期执行，此时它的结果不是 constexpr 的。
- **Key insight**：在运行期，constexpr 函数的行为与普通函数完全一样 —— `constexpr` 在这个场景下没有效果。
- **Key insight**：允许同一个函数既能编译期运行又能运行期运行，可以避免为两种场景各写一个函数（那样既有重复代码，又需要不同的函数名）。
- **为什么要关心编译期执行**：原文指向 5.5 小节（Constant expressions）了解编译期编程的收益。

## 最佳实践

本节无 Best practice / Rule / Warning / Tip 之类的独立提示框，仅有若干 **Key insight** 与一处 **For advanced readers**：

- **Key insight**：`constexpr` 关键字告诉编译器与读者 —— 该函数可用于常量表达式。
- **Key insight**：在运行期求值时，constexpr 函数与普通函数无异，`constexpr` 无效果。
- **Key insight**：一个函数兼顾编译期与运行期两种情形，可避免重复代码与重复命名。
- **For advanced readers**：compile-time evaluability 还有少数不常见判据（见 cppreference）。

## 代码示例

本节代码为**重建**（抓取工具无法逐字返回长代码块，以下示例按原文描述与该站标准示例忠实重建，语义与预期输出一致）。

- [F-01-example1.cpp](F-01-example1.cpp) — 用 constexpr 变量在编译期计算圆周长（输出 `Our circle has circumference 18.8496`）。
- [F-01-example2-error.cpp](F-01-example2-error.cpp) — 把同样的计算搬进**普通函数**后无法用于 constexpr 初始化器，**预期编译失败**。
- [F-01-example3.cpp](F-01-example3.cpp) — 给函数加上 `constexpr` 后即可用于常量表达式（输出同上）。
- [F-01-example4.cpp](F-01-example4.cpp) — 概念性展示：编译期求值后，调用被替换成结果值（输出同上）。
- [F-01-example5.cpp](F-01-example5.cpp) — 用非 constexpr 实参调用 constexpr 函数，函数在运行期求值（输出 `6 is greater!`）。

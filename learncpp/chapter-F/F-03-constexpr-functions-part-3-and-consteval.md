# F.3 Constexpr functions (part 3) and consteval

> 原文：https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-3-and-consteval/

## 核心概念

- **不存在"优先编译期"的指令**：无法告诉编译器"只要可能就在编译期求值"，例如当返回值被用于非常量表达式时。
- **强制编译期求值**：若一个 constexpr 函数具备编译期求值能力，可通过让它的返回值出现在**要求常量表达式**的地方来强制其真正编译期求值 —— 而且必须逐次调用地安排。
- **常用技巧**：最常见做法是用 constexpr 变量接收结果。原文指出，这会为了强制求值而额外引入一个变量，"ugly and reduces code readability"（丑陋且降低可读性）。
- **`consteval`（C++20）**：被标记 `consteval` 的函数**必须**在编译期求值，否则编译错误；这类函数称为 **immediate function（立即函数）**。
- **形参仍不是 constexpr**：奇怪的是，即便 consteval 函数只在编译期运行，它的形参也不是 constexpr；原文说这是"出于一致性"的取舍。
- **检测编译期/运行期求值**：当前 C++ 没有可靠机制判断某次 constexpr 调用到底在编译期还是运行期执行。
- **`std::is_constant_evaluated()`**：定义于 `<type_traits>`，返回 `bool`，表示**当前函数是否在"常量求值语境（constant-evaluated context，简称 constant context）"中执行** —— 即某处要求常量表达式，例如初始化 constexpr 变量。
- **它并不等于"这次是编译期求值"**：在**不要求**常量表达式的语境中，编译器也可能选择编译期求值，此时该函数返回 `false`，尽管求值确实发生在编译期。所以它的含义是"编译器正被迫在编译期求值"。
- **为什么这样设计（Key insight）**：其一，标准并未真正区分"编译期"与"运行期"，围绕该区分定义行为改动过大；其二，优化不得改变可观察行为 —— 若该 trait 对任何编译期求值都返回 `true`，那么"选择编译期求值"就会因优化级别不同而改变程序行为。
- **`if consteval`（C++23）**：是 `if (std::is_constant_evaluated())` 的替代写法，语法更好并修复了一些其他问题，但求值方式相同。
- **consteval 的缺点**：consteval 函数无法在运行期求值，因此不如 constexpr 灵活。
- **用 consteval 强制 constexpr 编译期求值**：因为 consteval 函数的实参总是在 manifestly constant evaluated 语境中，把一个 constexpr 函数调用作为 consteval 函数的实参传入，就会强制该 constexpr 函数编译期求值；consteval 函数再把结果返回给调用方。
- **按值返回**：这个 consteval 函数按值返回。对昂贵类型（如 `std::string`）而言，运行期拷贝可能低效；但在编译期语境中无所谓，因为整个调用会被替换成算好的值。

## 最佳实践

- **Best practice**：如果一个函数出于某种原因必须在编译期求值（例如它做了只能在编译期完成的事），就使用 `consteval`。
- **Key insight**：`std::is_constant_evaluated()` 的行为看似奇怪，但有两个理由 —— 标准不区分"编译期/运行期"，且优化不得改变可观察行为（否则优化级别会改变程序行为）。
- **For advanced readers（变通方案）**：曾有多种"hacky"办法试图避免每次为强制编译期求值而引入 constexpr 变量；C++20 提供了更好的变通方案（本节稍后给出）。
- **For advanced readers（宏）**：`CONSTEVAL` 示例使用可变参数预处理宏（`#define`、`...`、`__VA_ARGS__`）定义"立即调用的 consteval lambda"；原文给出可变参数宏与 lambda（20.6 小节）的链接。
- **For advanced readers（auto）**：非宏版本依赖 `auto` 返回类型（10.9 小节）与 auto 形参的缩写函数模板（11.8 小节）。

## 代码示例

本节代码为**重建**（抓取工具无法逐字返回长代码块，以下示例按原文描述与该站标准示例忠实重建，语义与预期输出一致）。原文未给出各示例的预期输出；下述输出为实测结果。

- [F-03-example1-error.cpp](F-03-example1-error.cpp) — consteval `greater()`，用非 constexpr 实参调用即出错，**预期编译失败**。
- [F-03-example2.cpp](F-03-example2.cpp) — 用 `std::is_constant_evaluated()` 在函数内分支（输出 `1 2`；原文的 `doSomething()/doSomethingElse()` 为占位名，此处补定义以便编译）。
- [F-03-example3.cpp](F-03-example3.cpp) — `CONSTEVAL` 宏（立即调用的 consteval lambda）强制编译期求值（输出 `5`、`5`、`6`）。
- [F-03-example4.cpp](F-03-example4.cpp) — 非宏版本：`consteval auto CONSTEVAL(auto value)` 缩写函数模板（输出 `6`）。

> 注：`F-03-example3.cpp` / `F-03-example4.cpp` 中第三/唯一一行依赖于「编译期求值 → 取较大值，运行期 → 取较小值」的技巧；实测 GCC 15.2 在 `-O0` 与 `-O2` 下结果一致（`-O2` 下亦未把 `compare(5, 6)` 提升为编译期求值）。原文另提示 GCC 14+ 在开启优化时 `F-03-example4.cpp` 可能给出错误答案，本环境未复现。

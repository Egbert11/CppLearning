# 11.9 Non-type template parameters

> 原文：https://www.learncpp.com/cpp-tutorial/non-type-template-parameters/

## 核心概念

- **类型模板参数回顾**：类型模板参数是一个占位符，代表作为模板实参传入的实际类型。
- **非类型模板参数（non-type template parameter）定义**：一个具有固定类型的模板参数，作为占位符，"for a constexpr value passed in as a template argument"。
- **允许作为非类型模板参数的类型**：整型；枚举类型；`std::nullptr_t`；浮点类型（C++20 起）；对象指针或引用；函数指针或引用；成员函数指针或引用；字面量类类型（C++20 起）。
- **之前见过的第一个例子**：`std::bitset<8>`；`<8>` 就是非类型模板参数，告诉 bitset 存多少位。
- **自己定义**：`template <int N>` 声明一个名为 `N` 的 int 非类型参数；调用 `print<5>()` 时编译器实例化出一个 `print<5>` 函数，其中 `N` 为 `5`。
- **命名约定**：`N` 是 int 非类型模板参数的惯用名（就像第一个类型参数惯用 `T`）。
- **为什么有用**：截至 C++20，函数形参不能是 `constexpr`——普通函数、`constexpr` 函数乃至 `consteval` 函数都一样。因为 `static_assert` 需要常量表达式，所以形参不能用在 `static_assert` 中。
- **变通办法**：把函数形参转成非类型模板参数，就能在编译期对该值做 `static_assert` 检查（例如 `template <double D>`，需要 C++20）。
- **Key insight**：非类型参数主要用于"pass constexpr values to functions (or class types)"，以便这些值能出现在需要常量表达式的地方；`std::bitset` 需要它，因为位数必须是 constexpr。
- **非类型模板实参的隐式转换**：允许某些 constexpr 转换，使实参匹配不同类型的非类型参数；该列表"less permissive than the type of implicit conversions allowed for list initialization"（例如 `constexpr int` 实参不会转换成 `double` 非类型参数）。
- **允许的转换（最常见的）**：整型提升（`char` 到 `int`）；整型转换（`char` 到 `long`，`int` 到 `char`）；用户定义转换（自定义类到 `int`）；左值到右值转换（变量 `x` 到它的值）。
- **重载匹配并不精细**：与普通函数不同，函数模板匹配不会按所需转换来排优先级，因此针对不同类型的非类型参数做重载"can very easily result in an ambiguous match"（甚至 `print<5>()` 配 `int` 与 `char` 重载也会歧义）。
- **`auto` 推导非类型参数（C++17）**：写 `template <auto N>` 让编译器从模板实参推导非类型参数（`print<5>()` 推导 `int`；`print<'c'>()` 推导 `char`）。
- **进阶：歧义与命名**：编译器先查歧义匹配，只有在无歧义时才实例化模板；只有一个模板时不可能歧义。实例化出的特化名为 `print<5>` / `print<'c'>`，而不是 `print<int>` / `print<char>`。

## 最佳实践

- **Best practice**：用 `N` 作为 int 非类型模板参数的名字。
- **Key insight**：非类型模板参数主要用于把 constexpr 值传给函数（或类类型），以便它们能用于要求常量表达式的语境；`std::bitset` 需要它来确定位数。
- **Author's note**：仅仅为了绕开"函数形参不能是 constexpr"这一限制而被迫使用非类型模板参数并不理想；已有若干提案试图解决，作者预期未来标准会给出更好的方案。
- **For advanced readers**：先检查歧义、仅在无歧义时才实例化；只有一个模板时无歧义可言，生成的特化按实参值命名（`print<5>`），而不是按推导出的类型（`print<int>`）。

## 代码示例

- [11-09-example1.cpp](11-09-example1.cpp)：`std::bitset<8>` 用非类型模板参数表示位数。
- [11-09-example2.cpp](11-09-example2.cpp)：带 `int N` 非类型参数的函数模板 `print()`，调用 `print<5>()`，输出 `5`。
- [11-09-example3.cpp](11-09-example3.cpp)：运行期 `assert` 版 `getSqrt`（在运行期而非编译期断言；未开 `-DNDEBUG` 时对负参数会中止）。
- [11-09-example4-error.cpp](11-09-example4-error.cpp)：`template <double D>` 的 `static_assert` 版，`getSqrt<-5.0>()` 触发编译失败（需 C++20）。
- [11-09-example5.cpp](11-09-example5.cpp)：`char` 实参隐式转换为 `int` 非类型参数，输出 `5` 与 `99`。
- [11-09-example6-error.cpp](11-09-example6-error.cpp)：`int` 与 `char` 非类型参数重载，`print<5>()`/`print<'c'>()` 均歧义，预期编译失败。
- [11-09-example7.cpp](11-09-example7.cpp)：C++17 起 `template <auto N>` 通过实参推导非类型参数，输出 `5` 与 `c`。
- [11-09-quiz1.cpp](11-09-quiz1.cpp)：测验解——`constexpr` 阶乘模板（可通过三条 `static_assert`）。
- [11-09-quiz1-error.cpp](11-09-quiz1-error.cpp)：测验解加 `factorial<-3>()`，`static_assert(N >= 0)` 触发编译失败。

> 说明：以上代码为按原文描述重建的可编译完整程序（本抓取工具对长代码块有逐字引用上限）。

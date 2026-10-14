# 10.8 Type deduction for objects using the auto keyword

> 原文：https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/

## 核心概念

- **显式类型有时是冗余的**：当变量的声明类型与初始化式类型一致时，同一份类型信息实际上写了两遍。
- **类型推导 / 类型推断（type deduction / type inference）**：一种让编译器从对象的初始化式推断对象类型的特性。用 `auto` 替代变量的类型名即可触发。
- **从字面量、表达式、变量推导**：编译器使用字面量的类型、表达式的结果类型，或另一个变量已推导出的类型。
- **C++17 之前的初始化列表陷阱**：旧行为下，用 double 字面量的花括号 `auto` 会推导出 `std::initializer_list<double>`；C++17 修正了这一点，并被 gcc、Clang 等回溯修复。若在 C++14 或更早的编译器上示例编译失败，可用拷贝初始化 `auto d = 5.0` 变通。
- **可用于函数调用**：因为函数调用是表达式，非 void 返回值可作为初始化式。
- **字面量后缀影响推导类型**：`f` 得到 `float`，`u` 得到 `unsigned int`。
- **可与其他限定符同用**：声明可以与 `const` 或 `constexpr` 组合。
- **必须有东西可推导**：没有初始化式、空初始化式、或 `void`/不完整类型的初始化式都会导致推导失败。
- **auto 的价值随类型复杂度上升**：对基础类型省得不多，但对冗长或难以确定的类型收益显著（少按键、少打错）。
- **指针与引用需单独讲解**：那里的规则更复杂，见 12.14。
- **推导会丢弃 const**：推导一般会丢弃顶层 `const`；想要 `const` 就得自己加回。
- **字符串字面量的类型很怪**：从字符串字面量推导得到 `const char*`，而不是 `std::string`。想得到 `std::string` 或 `std::string_view` 要用 `s` 或 `sv` 字面量后缀（5.7 / 5.8）。
- **`constexpr` 无法被推导**：它"不属于类型系统"。`constexpr` 变量隐含 const，该 const 在推导时被丢弃，之后可手动或用 `constexpr` 重新施加。
- **好处**：连续声明更好的垂直对齐/可读性；强制初始化（避免变量意外未初始化）；保证没有意外的、有性能代价的转换（例如避免 `std::string_view` → `std::string` 转换）。
- **坏处**：类型信息被隐藏在代码里，基于类型的错误更易发生（如本想要 `double` 却写了 `int` 字面量、意外的整数除法、被掩盖的 `unsigned` 类型）；且若初始化式类型改变，推导出的变量类型也随之改变。
- **总体共识**：对对象而言类型推导通常被认为是安全的，能通过淡化类型信息、突出逻辑来提升可读性。

## 最佳实践

- **Best practice**：当对象的类型不重要时，用类型推导来声明变量。反之，当需要与初始化式不同的具体类型、或让类型一目了然有用时，用显式类型。
- **Author's note**：在展示类型有助于解释概念或示例时，后续小节会继续使用显式类型而非推导。
- **Warning（关于 C++17）**：C++17 之前 `auto d{ 5.0 };` 推导为 `std::initializer_list<double>`，C++17 修正并由多个编译器回溯。在 C++14 或更早的编译器上若示例无法编译，改用拷贝初始化 `auto d = 5.0`。
- **Related content**：字面量类型判定见 5.2；指针/引用推导规则见 12.14；`s` 与 `sv` 后缀见 5.7、5.8。

## 代码示例

- [10-08-example1.cpp](10-08-example1.cpp)：从字面量、表达式、变量推导类型（原示例 1、2）。
- [10-08-example2.cpp](10-08-example2.cpp)：从函数调用推导类型（原示例 3）。
- [10-08-example3.cpp](10-08-example3.cpp)：字面量后缀影响推导类型（原示例 4）。
- [10-08-example4.cpp](10-08-example4.cpp)：`auto` 与 `const` / `constexpr` 组合（原示例 5）。
- [10-08-example5-error.cpp](10-08-example5-error.cpp)：各种无法推导的写法，预期编译失败（原示例 6）。
- [10-08-example6.cpp](10-08-example6.cpp)：推导丢弃 `const`，以及手动加回 `const`（原示例 7、8）。
- [10-08-example7.cpp](10-08-example7.cpp)：字符串字面量推导为 `const char*` 而非 `std::string`（原示例 9）。
- [10-08-example8.cpp](10-08-example8.cpp)：用 `s` / `sv` 后缀得到 `std::string` / `std::string_view`（原示例 10）。
- [10-08-example9.cpp](10-08-example9.cpp)：`constexpr` 与推导的交互（原示例 11）。
- [10-08-example10.cpp](10-08-example10.cpp)：可读性/对齐对比（原示例 12）。
- [10-08-example11-error.cpp](10-08-example11-error.cpp)：`auto y;` 无初始化式，预期编译失败（原示例 13）。
- [10-08-example12.cpp](10-08-example12.cpp)：`auto` 避免不必要的转换（原示例 14）。
- [10-08-example13.cpp](10-08-example13.cpp)：意外的 int 字面量与隐藏的整数除法（原示例 15、16）。
- [10-08-example14.cpp](10-08-example14.cpp)：初始化式类型改变导致推导类型"漂移"（原示例 17）。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。示例中类型判定用 `std::is_same_v` 静态断言来精确校验（比 `typeid().name()` 的实现相关输出更可靠）。

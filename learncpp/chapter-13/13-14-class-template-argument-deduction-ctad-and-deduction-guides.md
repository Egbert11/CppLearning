# 13.14 Class template argument deduction (CTAD) and deduction guides

> 原文：https://www.learncpp.com/cpp-tutorial/class-template-argument-deduction-ctad-and-deduction-guides/

## 核心概念

- **类模板实参推导（CTAD），C++17**：从 C++17 起，实例化对象时编译器可根据初始化器的类型推断出类模板的模板类型。
- **CTAD 要求不写模板实参列表**：仅当你**不提供**模板实参列表时才会推导；对两参数模板写 `std::pair<>` 或 `std::pair<int>` 是错误（"too few template arguments"）。
- **Author's note**：本站后续很多小节使用 CTAD；用 C++14 或更早编译会报 "missing template arguments"，需显式补上实参。
- **字面量后缀影响推导**：由于 CTAD 是类型推导的一种，`f`、`u` 等后缀会改变推导结果。
- **推导指引（deduction guide），C++17**：通常 CTAD 开箱即用，但有时编译器需要帮助；推导指引告诉编译器如何推导某类模板的实参。
- **聚合类模板在 C++17 下 CTAD 失败**：用户自定义的聚合 `Pair` 在 C++17 无法推导（报 "class template argument deduction failed"、"cannot deduce template arguments" 或 "No viable constructor or deduction guide"）；在 C++20 则可以。
- **推导指引怎么写**：重复类的模板类型定义，箭头右侧是推导出的类型、左侧是要匹配的声明模式；参数名不用时可省略。
- **单模板类型示例**：`Pair(T, T) -> Pair<T>;` 把两个同类型实参的 `Pair` 映射为 `Pair<T>`。
- **Tip：C++20 自动生成聚合推导指引**：因此推导指引只在需要 C++17 兼容时才写。
- **标准库的指引**：`std::pair` 等标准库模板自带预定义推导指引，所以 `std::pair` 示例在 C++17 下也能编译。
- **For advanced readers：非聚合**：C++17 下非聚合不需要推导指引，因为构造函数起到了同样作用。
- **带默认值的类型模板参数**：与函数参数类似，模板参数可有默认值，在未显式指定且无法推导时使用。
- **CTAD 与非静态成员初始化**：用非静态成员初始化来初始化类类型成员时 CTAD 不工作，所有模板实参都必须显式给出。
- **CTAD 与函数参数**：CTAD 是**实参**推导而非**形参**推导，因此不能用于函数参数；应改用函数模板。

## 最佳实践

本节无 Best practice / Rule / Warning 条目。相关 callout：

- **Author's note**：本站后续很多小节使用 CTAD；用 C++14 或更早编译相关示例会报缺模板实参的错误，需显式补上。
- **Tip**：C++20 允许编译器为聚合自动生成推导指引，因此指引仅用于 C++17 兼容——去掉指引的 `Pair` 版本在 C++20 下应能编译。
- **For advanced readers**：非聚合在 C++17 下无需推导指引，因为构造函数已起到同样作用。

## 代码示例

- [13-14-example1.cpp](13-14-example1.cpp)：`std::pair` 显式实参 vs CTAD 推导（原 Example 1）。
- [13-14-example2-error.cpp](13-14-example2-error.cpp)：写了模板实参列表时 CTAD 不生效 —— 预期编译失败（原 Example 2）。
- [13-14-example3.cpp](13-14-example3.cpp)：字面量后缀 `f`、`u` 改变推导出的类型（原 Example 3）。
- [13-14-example4.cpp](13-14-example4.cpp)：聚合 `Pair` 的 CTAD；C++17 下失败、C++20 下成功（原 Example 4）。
- [13-14-example5.cpp](13-14-example5.cpp)：为 `Pair` 写推导指引，使其在 C++17 下也能 CTAD（原 Example 5、6）。
- [13-14-example6.cpp](13-14-example6.cpp)：单模板类型的 `Pair` 及其推导指引（原 Example 7）。
- [13-14-example7.cpp](13-14-example7.cpp)：类型模板参数的默认值，用于无法推导时（原 Example 8）。
- [13-14-example8-error.cpp](13-14-example8-error.cpp)：非静态成员初始化中不能使用 CTAD —— 预期编译失败（原 Example 9）。
- [13-14-example9-error.cpp](13-14-example9-error.cpp)：函数参数中不能使用 CTAD —— 预期编译失败（原 Example 10）。
- [13-14-example10.cpp](13-14-example10.cpp)：用函数模板解决上一例（原 Example 11）。

> 说明：本节代码为按原文清单与站点标准写法重建。注意 example4 的教学点是"C++17 下失败"，本仓库统一用 `-std=c++20` 编译，故可正常通过，文件头已注明。

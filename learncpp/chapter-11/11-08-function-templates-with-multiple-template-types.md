# 11.8 Function templates with multiple template types

> 原文：https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/

## 核心概念

- **一个模板参数 = 所有形参同一种类型**：在 `T max(T x, T y)` 中，两个形参必须推导为同一个实际类型。
- **实参类型不匹配会失败**：调用 `max(2, 3.5)` 混用 `int` 与 `double`；编译器先找非模板匹配，找不到。
- **随后推导失败**：`T` 只能代表单一类型，没有任何 `T` 能同时满足两个形参，于是编译错误（如 "template parameter 'T' is ambiguous"）。
- **推导期间不做转换**：编译器不会实例化 `max<double>(double, double)` 再把 `int` 转换过去；"type conversion is done only when resolving function overloads, not when performing template argument deduction."
- **这一限制是刻意的**：它让匹配保持简单（要么精确匹配，要么不匹配），也让你能强制多个形参共享同一类型。
- **方案 A —— `static_cast`**：由调用方转换实参使两者匹配；既笨拙又难读。
- **方案 B —— 显式模板实参**：写 `max<double>(2, 3.5)` 禁用推导，之后常规隐式转换会把 `int` 转换过去。可读性更好，但仍需写类型名。
- **方案 C —— 两个模板类型参数**：声明 `template <typename T, typename U>` 和 `T max(T x, U y)`，让每个实参独立推导。
- **Key insight**：由于 `T` 与 `U` 相互独立，它们"can resolve to different types, or they can resolve to the same type"。
- **新问题——返回时窄化**：条件运算符按常规算术转换得到公共类型（这里 `double`，值 3.5），但声明返回类型是 `T`（= `int`），会窄化成 `3`。把返回类型换成 `U` 只是把 bug 挪个位置（如 `max(3.5, 2)`）。
- **修复——返回类型推导**：用 `auto` 让编译器从 return 语句推导返回类型。注意：这种函数必须先完整定义再使用，仅前置声明不够。
- **进阶替代——尾置返回类型**：需要可前置声明的代码，用 `-> std::common_type_t<T, U>`（来自 `<type_traits>`）作显式返回类型。
- **C++20 缩写函数模板（abbreviated function templates）**：把普通函数形参类型写成 `auto`，该函数就变成模板，每个 `auto` 形参成为独立的类型模板参数。期望独立类型时，`auto max(auto x, auto y)` 更简洁，是首选写法。
- **限制**：没有简洁的缩写形式来要求两个 `auto` 形参必须同类型。
- **模板重载**：函数模板可以按不同数量的模板类型或不同形参重载。
- **部分排序（partial ordering）**：对 `add(1.2, 3.4)`，编译器优先选 `add<T>(T, T)` 而非 `add<T, U>(T, U)`；更受限/更专用的模板胜出。若没有更专用的模板，则报歧义匹配。

## 最佳实践

- **Best practice**：在 C++20 及以上标准下，优先使用"带单个 auto 形参的缩写函数模板"；当每个 `auto` 形参应是各自独立的类型时也用这种写法。
- **Key insight**：`T` 与 `U` 是独立的模板参数，各自独立解析类型，可能解析为不同类型，也可能解析为同一类型。
- **For advanced readers**：需要前置声明的函数必须有显式返回类型；由于结果应为两个形参的公共类型，可用 `std::common_type_t<T, U>` 作尾置返回类型。

## 代码示例

- [11-08-example1.cpp](11-08-example1.cpp)：单类型 `max<T>` 用匹配的 `(int, int)`、`(double, double)` 调用，可编译。
- [11-08-example2-error.cpp](11-08-example2-error.cpp)：同一模板调用 `max(2, 3.5)`，模板参数 `T` 有歧义，预期编译失败。
- [11-08-example3.cpp](11-08-example3.cpp)：用 `static_cast<double>` 修正，实例化为 `max(double, double)`。
- [11-08-example4.cpp](11-08-example4.cpp)：非模板 `double max(double, double)` 接受 `max(2, 3.5)`，普通重载决议会做转换。
- [11-08-example5.cpp](11-08-example5.cpp)：显式模板实参 `max<double>(2, 3.5)` 禁用推导后再做转换。
- [11-08-example6-narrowing.cpp](11-08-example6-narrowing.cpp)：两个模板参数但返回类型为 `T`，把 3.5 窄化成 `3`。
- [11-08-example7.cpp](11-08-example7.cpp)：同前但返回类型用 `auto`，推导出正确公共类型。
- [11-08-example8.cpp](11-08-example8.cpp)：进阶：用 `-> std::common_type_t<T, U>` 作尾置返回类型，可前置声明。
- [11-08-example9.cpp](11-08-example9.cpp)：C++20 缩写函数模板 `auto max(auto x, auto y)`。
- [11-08-example10.cpp](11-08-example10.cpp)：重载 `add` 模板，分别有 1、2、3 个模板参数。

> 说明：以上代码为按原文描述重建的可编译完整程序（本抓取工具对长代码块有逐字引用上限）。

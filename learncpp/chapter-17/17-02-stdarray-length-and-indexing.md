# 17.2 std::array length and indexing

> 原文：https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing/

## 核心概念

- **无符号长度/下标问题延续**：`std::array` 与 `std::vector` 一样是标准库容器，长度与下标都用无符号值，因此继承了此前讨论过的相关问题。
- **模板声明**：`std::array` 是模板结构体，表示长度的非类型模板参数 `N` 声明为 `std::size_t`——"一种大的无符号整型"。
- **长度实参的要求**：长度模板实参必须是 `std::size_t` 或可转换为它；由于它必须是 constexpr，有符号整型会在编译期转换，不算窄化。
- **C++23 字面量后缀（旁注）**：C++23 之前没有 `std::size_t` 的字面量后缀；该后缀主要服务于类型推导，因为 `constexpr auto x { 0 }` 得到的是 `int` 而非 `std::size_t`（对比 `0` 与 `0UZ`）。
- **`size_type` 别名**：`std::array` 定义了嵌套的 `size_type`，它**始终**是 `std::size_t` 的别名，用于长度与下标。
- **模板为何直接用 `std::size_t`**：长度非类型模板参数声明为 `std::size_t` 而非 `size_type`，因为 `size_type` 是 `std::array` 的成员，此处尚未定义；这是唯一显式使用 `std::size_t` 的地方。
- **获取长度的三种方式**：成员 `size()`（返回 `size_type`）；非成员 `std::size()`（C++17，调用 `size()`）；非成员 `std::ssize()`（C++20，返回大的**有符号**类型，通常是 `std::ptrdiff_t`——唯一的带符号方案）。
- **只有 `size()`**：与同时拥有 `length()` 和 `size()` 的 `std::string`/`std::string_view` 不同，`std::array` 与大多数容器只有 `size()`。
- **长度是 constexpr**：三个函数都返回 constexpr 长度值，即使数组对象本身不是 constexpr，也能用于常量表达式；到 `int` 的隐式转换不是窄化。
- **Warning——语言缺陷**：对按 (const) 引用传递的 `std::array` 函数形参调用这些函数会返回非 constexpr 值，导致编译错误。C++23 的 P2280 已处理，但当时很少有编译器支持。变通办法：把函数写成模板，用非类型模板参数捕获长度。
- **下标访问**：`operator[]` 不做边界检查，非法下标是未定义行为。`at()` 做运行时边界检查；作者建议避免使用 `at()`，改用预先检查或编译期检查。
- **下标类型与转换**：`operator[]` 与 `at()` 都期望 `size_type`（`std::size_t`）。constexpr 下标经历 constexpr 转换（非窄化）；非 constexpr 的有符号下标会按窄化转换，可能产生警告。
- **`std::get()` 做编译期边界检查**：由于 `operator[]` 不检查、`at()` 只在运行时检查，而函数形参长度无法为 constexpr，`std::get()` 把下标作为非类型模板实参，其实现用 `static_assert` 断言下标小于数组长度，因此只有 constexpr 下标可用。

## 最佳实践

- 本节无 Best practice / Author's note 条目。
- **Warning**：由于一个语言缺陷，对按 (const) 引用传递的 `std::array` 函数形参调用长度函数时，会返回非 constexpr 值。该问题在 C++23 由 P2280 处理（当时编译器支持甚少），变通办法是使用带长度非类型模板参数的函数模板。
- **For Visual Studio users**：Visual Studio 会对示例 4 误报 warning C4365，已向微软反馈。
- **Related content**：类模板见 13.13；非类型模板参数见 11.9。

## 代码示例

- [17-02-example1.cpp](17-02-example1.cpp)：`arr.size()` 取长度，输出 `length: 5`。
- [17-02-example2.cpp](17-02-example2.cpp)：`std::size(arr)`（C++17），输出 `length: 5`。
- [17-02-example3.cpp](17-02-example3.cpp)：`std::ssize(arr)`（C++20，有符号），输出 `length: 5`。
- [17-02-example4.cpp](17-02-example4.cpp)：在非 constexpr 数组上用 `constexpr int length{ std::size(arr) };`。
- [17-02-example5.cpp](17-02-example5.cpp)：语言缺陷演示（GCC 15.2 已支持 P2280，故可编译，见文件头说明）。
- [17-02-example6.cpp](17-02-example6.cpp)：变通办法——`template <auto Length>` 函数模板。
- [17-02-example7.cpp](17-02-example7.cpp)：`operator[]` / `at()` / `std::get<>()` 三种下标方式，输出三行 `7`。
- [17-02-example8-error.cpp](17-02-example8-error.cpp)：`std::get<9>` 越界 → 编译失败（-error）。
- [17-02-example9.cpp](17-02-example9.cpp)：`at()` 越界抛 `std::out_of_range`。
- [17-02-quiz1.cpp](17-02-quiz1.cpp)：Quiz #1 解答——长度 + 三种下标访问，输出 `The length is 5` 与 `eee`。

> 说明：本节代码为按原文描述重建。

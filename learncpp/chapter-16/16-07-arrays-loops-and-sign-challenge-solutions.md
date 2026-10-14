# 16.7 Arrays, loops, and sign challenge solutions

> 原文：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/

## 核心概念

- **有符号 vs 无符号容器的矛盾**：前面学过数值量一般偏好有符号，但标准容器用无符号的 `std::size_t` 表示长度与索引，由此产生摩擦。
- **无符号倒序循环的 bug**：像 `index >= 0` 这样的循环条件对无符号变量永远为真，于是循环"永不终止"；而从 `0` 再减一会环绕成极大的正值，产生越界下标与未定义行为。
- **有符号索引的补救很凌乱**：改用有符号循环变量可修正环绕，但每次下标都要再转回无符号，代码可读性差。
- **不存在完美方案**：本节从最差到最好列出可行选项；在别人的代码里这些写法都会见到。
- **Author's note**：虽然以 `std::vector` 讨论，"所有标准库容器（如 `std::array`）工作方式类似，也有同样挑战。"
- **选项：关闭符号转换警告**：每个有符号下标都会触发警告，会淹没构建日志、掩盖真正有用的警告。这是"最简单的方案，但不推荐"。
- **选项：使用无符号循环变量**：由于库本就是为无符号索引设计的，这算合理立场；但要避免符号不匹配，且索引变量除索引外不要作他用。
- **用哪种无符号类型？`size_type`**：每个容器定义了用于长度与索引的嵌套 typedef；`operator[]` 也接受它，因此它在技术上最一致。
- **`size_type` 的缺点**：作为嵌套类型，必须用完全模板化的容器名写出（如 `std::vector<int>::size_type`），啰嗦。在模板里还要加 `typename`。
- **依赖名（dependent name）**："任何依赖于含模板参数的类型的名字都叫依赖名"，用作类型时必须加 `typename` 前缀。
- **别名与 `decltype` 变通**：可以给容器类型起别名，或用 `decltype(arr)::size_type` 让编译器推导；但对引用类型必须先用 `std::remove_reference_t` 去掉引用。
- **直接用 `std::size_t`**：因为 `size_type` 几乎总是 `size_t` 的 typedef，很多程序员直接用 `size_t`；除自定义分配器外，本节认为这很合理。
- **选项：使用有符号循环变量**：与本教程偏好有符号数值量一致；带来三个问题——选何类型、如何得到有符号长度、如何把索引转回无符号。
- **有符号类型的选择**：普通 `int`、`std::ptrdiff_t`（`size_t` 的有符号对应）、自定义别名如 `using Index = std::ptrdiff_t;`、由初始化器用 `auto` 推导、或 C++23 的 `Z` 字面量后缀。
- **获得有符号长度**：C++20 前用 `static_cast` 转 `size()` 的结果；这样比较的两个操作数都是有符号，负值不会环绕。把长度移出循环可提高可读性。
- **C++20 的 `std::ssize()`**："以有符号类型（很可能是 `ptrdiff_t`）返回数组类型的长度"，这是设计者偏爱有符号索引的佐证。
- **有符号转无符号**：选项包括每次使用时 `static_cast`（嘈杂）；用带 `static_assert` 的短辅助函数 `toUZ()`（限制为整数/枚举类型）；或自定义视图类。
- **自定义视图类**：`SignedArrayView` 包装任何可索引容器，其 `operator[]` 接受有符号索引，`ssize()` 返回有符号长度（在 C++20 前有用）。
- **通过 `data()` 索引底层 C 风格数组**：C 风格数组同时接受有符号与无符号下标，可绕开转换。本节称之为"最佳索引方案"。
- **干脆避免索引**：range-based for 循环与迭代器无需下标即可遍历数组，彻底消除符号转换问题。"如果你只用索引变量来遍历数组，那就优先选不用索引的方法。"

## 最佳实践

- **Author's note**：虽然以 `std::vector` 讨论，所有标准库容器（如 `std::array`）工作方式类似、有同样挑战。
- **Best practice**：尽量"避免用整数值对数组进行索引（Avoid array indexing with integral values whenever possible）。"
- **For advanced readers**：依赖含模板参数之类型的名字是依赖名，用作类型时需加 `typename`。
- **Related content**：范围 for 循环见 16.8；迭代器见 18.2。

## 代码示例

- [16-07-example1-ub.cpp](16-07-example1-ub.cpp)：无符号倒序循环——`index >= 0` 恒真且减到 0 后环绕，导致越界/未定义行为（原 Example 1）。
- [16-07-example2.cpp](16-07-example2.cpp)：有符号倒序循环，需两次 `static_cast`，可读性变差（原 Example 2）。
- [16-07-example3.cpp](16-07-example3.cpp)：用有符号索引求平均，长度与下标都要转换（原 Example 3）。
- [16-07-example4.cpp](16-07-example4.cpp)：在 `main` 里用 `std::vector<int>::size_type` 作循环变量（原 Example 4）。
- [16-07-example5.cpp](16-07-example5.cpp)：函数模板里用 `typename std::vector<T>::size_type`（原 Example 5）。
- [16-07-example6.cpp](16-07-example6.cpp)：用类型别名 `using arrayi = std::vector<int>;`（原 Example 6）。
- [16-07-example7.cpp](16-07-example7.cpp)：用 `decltype(arr)::size_type`（arr 为非引用）（原 Example 7）。
- [16-07-example8.cpp](16-07-example8.cpp)：对引用类型用 `std::remove_reference_t<decltype(arr)>::size_type`（原 Example 8）。
- [16-07-example9.cpp](16-07-example9.cpp)：直接用 `std::size_t`（原 Example 9）。
- [16-07-example10.cpp](16-07-example10.cpp)：自定义 `using Index = std::ptrdiff_t;` 并用有符号循环（原 Example 10）。
- [16-07-example11.cpp](16-07-example11.cpp)：用 `auto index{ static_cast<std::ptrdiff_t>(arr.size())-1 }` 倒序（原 Example 11）。
- [16-07-example12-cpp23.cpp](16-07-example12-cpp23.cpp)：C++23 的 `Z` 后缀字面量 `0Z`（原 Example 12，需 `-std=c++23`）。
- [16-07-example13.cpp](16-07-example13.cpp)：C++20 前用 `static_cast` 得到有符号长度（原 Example 13）。
- [16-07-example14.cpp](16-07-example14.cpp)：把长度提升到循环外（原 Example 14）。
- [16-07-example15.cpp](16-07-example15.cpp)：C++20 的 `std::ssize()`（原 Example 15）。
- [16-07-example16.cpp](16-07-example16.cpp)：`toUZ()` 转换辅助函数（含 `static_assert`）（原 Example 16）。
- [16-07-example17/SignedArrayView.h](16-07-example17/SignedArrayView.h) + [16-07-example17/main.cpp](16-07-example17/main.cpp)：自定义有符号视图类 `SignedArrayView`（原 Example 17、18，多文件示例）。
- [16-07-example19.cpp](16-07-example19.cpp)：对 `data()` 返回的 C 风格数组下标，避开符号转换（原 Example 19）。

> 说明：本节代码为按原文描述重建。

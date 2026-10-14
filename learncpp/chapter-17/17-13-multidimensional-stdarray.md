# 17.13 Multidimensional std::array

> 原文：https://www.learncpp.com/cpp-tutorial/multidimensional-stdarray/

## 核心概念

- **回顾 C 风格二维数组**：上一节讲了多维 C 风格数组，但本教程的总体建议是：除非存放全局数据，否则避开 C 风格数组。
- **没有标准的多维容器**：标准库没有提供多维数组的类；`std::array` 本身只有一维。（加框小节："There is no standard library multidimensional array class"。）
- **标准写法**：构造一个 `std::array`，其元素类型又是 `std::array`。三个小麻烦：初始化时**必须写双花括号**、语法冗长、维度顺序相对 `arr[3][4]` 是"反过来"的。
- **下标访问**：与 C 风格数组相同：`arr[1][2]` 表示第 1 行第 2 列。
- **传参**：一个对元素类型与两个维度都参数化的函数模板，可以按 const 引用接收这种嵌套数组，和一维 `std::array` 完全一样。
- **普通类型别名有局限**：`using Array2dint34 = std::array<std::array<int,4>,3>;` 可用，但每一种"元素类型 × 尺寸"组合都得单独写一个别名。
- **别名模板解决此问题**：`template <typename T, std::size_t Row, std::size_t Col> using Array2d = std::array<std::array<T, Col>, Row>;` 之后就能写 `Array2d<int, 3, 4>`。
- **维度顺序是一种选择**：本教程让元素类型排在前面（与 `std::array` 一致），并把 `Row` 放在 `Col` 前，因为 C 风格的定义习惯是行在前。
- **推广到更高维**：同一模式可扩展到三维：`using Array3d = std::array<std::array<std::array<T, Depth>, Col>, Row>;`。
- **取各维长度**：`size()` 只返回第一维。读 `arr[0].size()`（更深的数组再 `arr[0][0].size()`）可行，但当任何"非最后一维"长度为 0 时属于未定义行为。
- **更安全的维度访问**：写几个小的 `constexpr` 函数模板，直接从类型信息里返回 `Row` 与 `Col` 这两个非类型模板参数；既避免 UB，也允许零长度维度。返回 `int` 无需 `static_cast`，因为此处 `std::size_t → int` 属于非窄化转换。
- **摊平（flattening）**：把多维数组压成一维（`Row * Col` 个元素），存储不变，但失去多维访问，需要一层接口把 `(row, col)` 映射为单一下标。
- **C++23 前的下标限制**：`operator[]` 只接受一个下标，于是要么用 `operator()` 做多下标访问（`[]` 留作单下标），要么让 `operator[]` 返回一个子视图——后者更复杂、也更难扩展到更高维。C++23 允许多参数 `operator[]`。
- **`std::mdspan`（C++23）**：对连续序列的多维**视图**（可修改，非只读）。用数据指针加各维长度构造；用 `extents().extent(n)` 查各维、`size()` 查总数、`data_handle()` 取原始指针，用 `mdView[row, col]` 索引。
- **`std::mdarray`（C++26）**：拥有型多维数组，融合了 `std::array` 与 `std::mdspan` 的思想。

## 最佳实践

- 本节原文没有加框的 Best practice / Author's note / Warning。最接近的要点：
  - **Heading-style callout**："没有标准库的多维数组类。"`std::array` 只有一维，标准库没有填补这个空白的类。
  - **Related content**：示例中的 `ArrayView2d` 用到了 `std::reference_wrapper`，见 17.5 节。
  - **In-text warning（Example 6）**：为调用 `size()` 而下标访问数组元素，在"非最后一维长度为 0"时会产生未定义行为。

## 代码示例

- [17-13-example1.cpp](17-13-example1.cpp)：规范的嵌套 `std::array`（双花括号）与下标访问（原 Example 1~2）。
- [17-13-example2.cpp](17-13-example2.cpp)：把二维 `std::array` 传给函数模板（原 Example 3）。
- [17-13-example3.cpp](17-13-example3.cpp)：用别名模板 `Array2d` 简化写法（原 Example 4）。
- [17-13-example4.cpp](17-13-example4.cpp)：别名模板扩展到三维 `Array3d`（原 Example 5）。
- [17-13-example5.cpp](17-13-example5.cpp)：用 `size()` 与 `arr[0].size()` 取各维长度及其 UB 前提（原 Example 6）。
- [17-13-example6.cpp](17-13-example6.cpp)：用 `constexpr` 辅助函数安全取各维长度（原 Example 7）。
- [17-13-example7.cpp](17-13-example7.cpp)：摊平为一维 + 自定义二维视图 `ArrayView2d`（原 Example 8）。
- [17-13-example8-cpp23.cpp](17-13-example8-cpp23.cpp)：用 `std::mdspan` 提供二维视图（`-cpp23`，原 Example 9）。

> 说明：本节较长代码块按原文描述忠实重建，语义与预期输出一致。

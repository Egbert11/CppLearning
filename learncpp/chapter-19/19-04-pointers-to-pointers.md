# 19.4 Pointers to pointers and dynamic multidimensional arrays

> 原文：https://www.learncpp.com/cpp-tutorial/pointers-to-pointers/

## 核心概念

- **可选的进阶内容**：原文标注本节"optional, for advanced readers"，且后续小节不依赖它。
- **指针的指针**：持有另一个指针的**地址**。
- **声明语法**：指向 int 的指针用一个星号 `int*`；指向"指向 int 的指针"的指针用两个 `int**`。
- **解引用层级**：解引用一次得到内层指针，再解引用一次得到底层值；可连续书写（`**ptrptr`）。
- **不能直接对值取址的址**：`&&value` 这种写法非法——取地址运算符需要左值，而 `&value` 是右值。
- **空初始化**：指向指针的指针也可置为 `nullptr`。
- **指针数组**：最常见用途是动态分配一个"元素为指针"的数组；除此之外它的行为与普通动态数组一样。
- **二维动态分配更难**：定长二维数组 `int array[10][5];` 很好写，但直接 `new int[10][5]` 无法交给 `int**`。
- **方案 A：最右维度是 constexpr**：若最右侧维度是编译期常量，可用"指向数组的指针"形式分配。**括号很关键**：`int* array[5]` 是"含 5 个 `int*` 的数组"，而 `int (*array)[5]` 才是"指向含 5 个 int 的数组的指针"。
- **类型推导捷径**：用 `auto` 可让这种分配写法简单得多。
- **方案 B：最右维度不是常量**：先分配一个指针数组，再循环为每个元素分配一维动态数组——本质上是"动态一维数组的动态一维数组"。
- **元素访问**：下标照常使用；`array[9][4]` 等价于 `(array[9])[4]`。
- **锯齿 / 三角数组**：因为每列数组是独立分配的，结果不必是矩形，各行的长度可以不同。
- **释放规则**：先在循环中逐列 `delete[]`，**最后**释放外层数组。按与创建相反的顺序释放可避免触碰已释放内存（那是未定义行为）。
- **拍平（flatten）替代方案**：由于成对分配/释放容易出错，可把一个 x×y 的二维数组"拍平"成一维的 x*y 个元素。
- **下标换算**：用一个辅助函数把行列换算成单个下标：`(row * numberOfColumnsInArray) + col`。
- **按地址传指针**：用"指向指针的指针"作参数可让函数改变传入的指针，但"generally better done using a reference to a pointer instead"（参见 12.11）。
- **更深的间接**：三、四重指针都合法；三重指针可构造三维动态数组，但需要循环套循环，"extremely complicated to get correct"，更高层级"don't see much use"。
- **结论 / 建议**：除非别无他法，否则避免使用指针的指针——它们复杂且危险；双重解引用让撞上空指针或悬垂指针变得更容易。

## 最佳实践

- 本节没有标注 "Best practice" / "Warning" 框。最接近的是末节的 **Conclusion**：尽量避免指针的指针，先确认没有更安全的替代方案；解引用一个坏指针本就不易，需要两次解引用才能触达实际值时更危险。

## 代码示例

- [19-04-example1.cpp](19-04-example1.cpp)：二级指针的声明与两次解引用，输出两行 `5`（含三/四重指针声明演示）。
- [19-04-example2-error.cpp](19-04-example2-error.cpp)：`int** ptrptr { &&value };` 非法 → 编译失败（-error）。
- [19-04-example3.cpp](19-04-example3.cpp)：二级指针可为空，以及 `new int*[10]` 分配指针数组。
- [19-04-example4-error.cpp](19-04-example4-error.cpp)：`new int[10][5]` 的结果类型是 `int(*)[5]`，无法初始化 `int**` → 编译失败（-error）。
- [19-04-example5.cpp](19-04-example5.cpp)：`int (*array)[5] { new int[x][5] };`——最右维度为 constexpr 时一次分配二维数组。
- [19-04-example6.cpp](19-04-example6.cpp)：用 `auto` 简化上例。
- [19-04-example7.cpp](19-04-example7.cpp)：先分配指针数组（行），再循环分配各列（列），并按逆序释放。
- [19-04-example8.cpp](19-04-example8.cpp)：每行长 `count+1` 的三角/锯齿数组。
- [19-04-example9.cpp](19-04-example9.cpp)：把 10×5 数组拍平为一维，配合 `getSingleIndex()` 访问。

> 说明：本节代码为按原文描述重建（原文多为片段，完整代码块超出抓取引文上限）。

## 附：原文中的对照声明（未单独生成文件）

原文还给出以下对照/片段，语义已在上面各示例覆盖，故未单独生成源码：

- `int array[10][5];`（定长二维数组，见 19-04-example4-error.cpp 开头）
- `int*** ptrx3;` / `int**** ptrx4;`（三/四重指针声明，见 19-04-example1.cpp 末尾）

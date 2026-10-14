# 17.7 Introduction to C-style arrays

> 原文：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/

## 核心概念

- **在数组家族中的位置**：C 风格数组是继 `std::vector` 与 `std::array` 之后介绍的最后一类数组。
- **继承自 C / 核心语言内置**：与标准库容器类不同，它们"内置于 C++ 核心语言"，因此无需包含任何头文件。
- **旁注——实现细节**：因为它们是唯一被语言原生支持的数组类型，`std::array` 与 `std::vector` 通常都是用 C 风格数组实现的。
- **声明语法**：在标识符后写方括号 `[]`；括号内可选地给出长度，它是 `std::size_t` 类型的整型值，表示元素个数。
- **最小长度**：长度至少为 1；为 0、为负或非整型都会编译失败。
- **Advanced readers**：在堆上动态分配的 C 风格数组，长度合法地可以为 0。
- **长度必须是常量表达式**：与 `std::array` 一样，声明的长度必须是常量表达式（类型为 `std::size_t`）。
- **Tip——变长数组（VLA）**：某些编译器为兼容 C99 的 VLA 允许非 constexpr 长度，但 VLA"不是合法的 C++"，应当避免；允许它的编译器很可能仍开启了扩展。
- **下标访问**：C 风格数组用下标运算符 `operator[]` 访问，与 `std::array` 相同。
- **下标类型**：下标可以是任意整型（有符号或无符号）或无作用域枚举——不像标准库容器要求 `std::size_t`，因而避免了符号转换带来的下标问题。
- **不做边界检查**：`operator[]` 不做边界检查，越界下标产生未定义行为。
- **旁注——语法与运算符之别**：在 `int arr[5]` 这样的声明中，方括号属于声明语法，而不是调用 `operator[]`。
- **聚合初始化**：C 风格数组是聚合类型，可用花括号、逗号分隔的初始化列表初始化。
- **初始化顺序**：拷贝列表初始化与列表初始化都从元素 0 开始按序填充。
- **无初始化器 → 默认初始化**：元素通常被留下不确定值，因此不带初始化器定义的数组应当用空花括号做值初始化。
- **初始化器过多/过少**：多于长度是编译错误；少于长度则剩余元素被值初始化。
- **不做类型推导**：元素类型必须显式写出；CTAD 不适用（不是类模板），`auto` 也无法推导元素类型。
- **省略长度**：当初始化列表给每个元素都提供了值时，可省略长度，由编译器根据初始化器个数推导。
- **省略长度 + 空花括号**：`int bad[] {}` 会报错，因为编译器会推导出不被允许的零长数组。
- **最佳实践（见下）**：显式初始化每个元素时省略长度，让长度自动跟随初始化器个数，杜绝不匹配。
- **const / constexpr 数组**：C 风格数组可以是 `const` 或 `constexpr`；与其他 const 变量一样必须初始化，之后元素不可修改。
- **sizeof**：对 C 风格数组使用 `sizeof()` 返回整个数组占用的字节数，且没有额外开销——数组对象只保存元素，"别的什么都没有"。
- **取长度（C++17 / C++20）**：`std::size()`（来自 `<iterator>`）返回无符号的 `std::size_t`；`std::ssize()`（C++20）返回有符号值，"很可能是 `std::ptrdiff_t`"。
- **Tip——用哪个头文件**：`<iterator>` 是 `std::size()`/`std::ssize()` 的规范头文件，不过 `<array>` 与 `<vector>` 也常提供它们。
- **C++17 之前的取长度方式**：当时没有标准库函数；C++11/14 代码可用一个按引用接收 C 风格数组并返回非类型模板参数 `N` 的 `constexpr` 函数模板。
- **更老的惯用法**：`sizeof(array) / sizeof(array[0])`（或 `sizeof(*array)`）用总大小除以元素大小；源自"长度 = 数组大小 / 元素大小"。
- **该惯用法为何不安全**：一旦传入已退化的数组就会出错；而 `std::size()` 与 `length()` 模板会直接报编译错误，更安全。
- **不能整体赋值**：整体数组赋值非法，因为赋值需要可修改的 lvalue，而 C 风格数组不是可修改的 lvalue。替代方案：改用 `std::vector`、逐元素赋值、或用 `std::copy`。

## 最佳实践

- **Best practice**：显式给每个数组元素都提供初值时，优先省略 C 风格数组的长度。
- **Tip（常量长度）**：部分编译器为兼容 C99 VLA 而允许非 constexpr 的数组长度；变长数组"不是合法的 C++"，不应在 C++ 程序中使用。
- **Tip（下标类型）**：C 风格数组接受有符号或无符号下标（或无作用域枚举）。
- **Tip（头文件）**：`<iterator>` 是 `std::size()`/`std::ssize()` 的规范头文件，`<array>` 与 `<vector>` 也常提供。
- **As an aside（实现）**：标准库的数组容器类型通常用 C 风格数组实现。
- **Advanced readers**：堆上分配的 C 风格数组允许长度为 0。
- **As an aside（声明语法）**：`int arr[5]` 中的方括号属于声明语法，并非下标运算符调用。
- **Related content**：后续话题见 "17.8 C-style array decay"。

## 代码示例

- [17-07-example1.cpp](17-07-example1.cpp)：声明并值初始化 30 个 int 的数组，输出 `0`。
- [17-07-example2.cpp](17-07-example2.cpp)：下标访问 + 有符号/无符号下标都合法。
- [17-07-example3.cpp](17-07-example3.cpp)：聚合初始化两种形式，输出 `2 11`。
- [17-07-example4.cpp](17-07-example4.cpp)：默认初始化 vs 值初始化。
- [17-07-example5-error.cpp](17-07-example5-error.cpp)：初始化器过多 → 编译失败（-error）。
- [17-07-example6-error.cpp](17-07-example6-error.cpp)：`auto squares[5]` → 编译失败（-error）。
- [17-07-example7-error.cpp](17-07-example7-error.cpp)：`int bad[] {}` → 推导出零长数组，编译失败（-error；GCC 需加 `-pedantic-errors` 才会拒绝，默认当作扩展接受）。
- [17-07-example8.cpp](17-07-example8.cpp)：显式长度 vs 省略长度，输出 `5 5`。
- [17-07-example9.cpp](17-07-example9.cpp)：const / constexpr 数组，输出 `16 11`。
- [17-07-example10-error.cpp](17-07-example10-error.cpp)：修改 const 数组元素 → 编译失败（-error）。
- [17-07-example11.cpp](17-07-example11.cpp)：`sizeof` 返回数组总字节数，输出 `20`。
- [17-07-example12.cpp](17-07-example12.cpp)：`std::size` / `std::ssize`，各输出 `5`。
- [17-07-example13.cpp](17-07-example13.cpp)：C++11/14 的 `length()` 函数模板，输出 `The array has: 8 elements`。
- [17-07-example14.cpp](17-07-example14.cpp)：老的 `sizeof/sizeof` 求长度惯用法。
- [17-07-example15-error.cpp](17-07-example15-error.cpp)：整体数组赋值 → 编译失败（-error）。
- [17-07-example16.cpp](17-07-example16.cpp)：用 `std::copy` 拷贝数组内容，输出 `567`。
- [17-07-quiz1.cpp](17-07-quiz1.cpp)：Quiz #1 解答——`std::array<int,3>` 改写成 `int[3]`。
- [17-07-quiz2-error.cpp](17-07-quiz2-error.cpp)：Quiz #2 解答——找出三处错误（-error）。
- [17-07-quiz3.cpp](17-07-quiz3.cpp)：Quiz #3 解答——完全平方数判断程序。

> 说明：本节代码为按原文描述重建。

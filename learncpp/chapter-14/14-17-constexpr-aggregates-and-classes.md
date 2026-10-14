# 14.17 Constexpr aggregates and classes

> 原文：https://www.learncpp.com/cpp-tutorial/constexpr-aggregates-and-classes/

## 核心概念

- **constexpr 函数回顾**：constexpr 函数既可在编译期也可在运行期求值；像 `greater(5, 6)` 这样的常量表达式两种情形都行，但用于初始化 `constexpr` 变量时必须在编译期求值。
- **成员函数默认不是 constexpr**：第一个 `Pair` 聚合示例中，`greater()` 是普通成员函数，故 `p.greater()` 不是常量表达式，即使输入 5 和 6 都是常量，也无法初始化 `constexpr` 变量（编译错误）。
- **constexpr 成员函数**：给成员函数加上 `constexpr` 后它可在编译期或运行期求值。但只把 `greater()` 设为 constexpr 还不够：对象 `p` 本身也必须是 constexpr，否则 `p.greater()` 仍不是常量表达式。
- **constexpr 聚合**：聚合类型隐式支持 constexpr。一旦声明 `constexpr Pair p { 5, 6 };` 且 `greater()` 为 constexpr，`p.greater()` 就成为常量表达式，可用在任何需要常量表达式之处。
- **constexpr 类对象与 constexpr 构造函数**：把 `Pair` 改为非聚合（私有成员 + 用户构造函数）会导致 `constexpr Pair p { 5, 6 };` 失败：该类不是"字面类型（literal type）"。
- **字面类型的定义**："字面类型是那些有可能在常量表达式中创建对象的类型。"对象要成为 constexpr，其类型必须先是字面类型。
- **术语：literal 与 literal type**：literal（字面量）是写进源码的 constexpr 值；literal type（字面类型）是可用作 constexpr 值之类型的那种类型。字面量必定具有字面类型，但字面类型的对象不必是字面量。
- **哪些类型是字面类型**：标量类型（单值类型，如基础类型和指针）、引用类型、大多数聚合，以及具有 constexpr 构造函数的类。
- **非聚合为何失败**：创建对象要调用构造函数；非 constexpr 构造函数不能在编译期调用，因此该类对象不能是 constexpr。
- **修复方法**：把构造函数设为 constexpr；该类随即表现得与聚合版本一致。
- **constexpr 函数的编译期求值**：constexpr 函数在编译期求值时，只能调用具备编译期求值能力的函数；对类类型而言，意味着要用 constexpr 成员函数，且对象必须用 constexpr 构造函数创建。
- **C++11 与 C++14 中 const 与 constexpr**：C++11 中非静态 constexpr 成员函数隐式为 const（构造函数除外）；C++14 起不再是，若想要 const 语义必须显式写 `const`。
- **constexpr 非 const 成员函数**：constexpr 的非 const 成员函数可以修改数据成员，只要隐式对象不是 const，包括在编译期求值时。
- **const 与 constexpr 相互独立**：成员函数能否修改对象取决于对象的 const 性质；调用能否在编译期发生取决于上下文。二者互不相关。
- **返回 const 引用/指针的 constexpr 函数**：如 `constexpr const int& getX() const`，组合了 constexpr（可编译期求值）、`const int&`（返回类型）与尾随 `const`（可作用于 const 对象）。

> **Best practice**："如果你希望自己的类能够进行编译期求值，就把成员函数和构造函数设为 constexpr。"
> **关于默认构造函数的注记**：隐式定义的构造函数在可行时即为 constexpr；显式 default 的构造函数必须显式标记为 constexpr。
> **Tip**："constexpr 是类接口的一部分，日后移除它会破坏那些在常量上下文中使用该函数的调用方。"
> **Key insight**："当一个 constexpr 函数在编译期上下文中求值时，只能调用 constexpr 函数。"
> **作者注**："并没有要求 constexpr 变量必须用 const 值初始化。"要求的是用常量表达式初始化。"关键不在于 const，而在于编译器能在编译期确定对象的值。"constexpr 函数/运算符可以使用并返回非 const 对象。
> **Related content**：聚合见 13.8 课"struct aggregate initialization"。

## 最佳实践

- **Best practice**："如果你希望自己的类能够进行编译期求值，就把成员函数和构造函数设为 constexpr。"

## 代码示例

- [14-17-example1.cpp](14-17-example1.cpp)：constexpr 自由函数，可编译期或运行期求值（原 Example 1）。
- [14-17-example2-error.cpp](14-17-example2-error.cpp)：非 constexpr 成员函数无法初始化 constexpr 变量（原 Example 2，预期编译失败）。
- [14-17-example3-error.cpp](14-17-example3-error.cpp)：`greater()` 为 constexpr 但对象 `p` 非 constexpr（原 Example 3，预期编译失败）。
- [14-17-example4.cpp](14-17-example4.cpp)：constexpr 聚合对象，一切在编译期完成（原 Example 4）。
- [14-17-example5-error.cpp](14-17-example5-error.cpp)：非聚合、非 constexpr 构造函数——不是字面类型（原 Example 5，预期编译失败）。
- [14-17-example6.cpp](14-17-example6.cpp)：构造函数改为 constexpr 后与聚合版本一致（原 Example 6）。
- [14-17-example7.cpp](14-17-example7.cpp)：constexpr 函数在编译期创建对象，要求构造函数与成员函数均为 constexpr（原 Example 7）。
- [14-17-example8.cpp](14-17-example8.cpp)：constexpr 非 const 成员函数 `reset()` 在运行期与编译期上下文的用法（原 Example 8）。

> 说明：本节代码为按原文描述忠实重建（原文多为例程片段，已补全为可编译程序）。
> 原 Example 9（`constexpr const int* const getXPtr() const`）为一行片段，未单独生成文件；其含义已并入上面"核心概念"。

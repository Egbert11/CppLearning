# 17.x Chapter 17 summary and quiz

> 原文：https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz/
>
> 说明：本小节为 Chapter 17 的总结与测验，官方编号为 **17.x**；按本仓库约定，其文件编号取整章的下一个顺延号，即 **14**（本章共 17.1–17.13 共 13 节）。

## 本章知识速览

（按原文顺序概括整章要点；含前半部分 17.1–17.7 与本代理负责的 17.8–17.13。）

### 固定大小数组与 std::array（17.1–17.7）

- **固定大小数组（fixed-size array）**：长度必须在实例化时已知且不能改变；C 风格数组与 `std::array` 属于此类；`std::vector` 等动态数组可在运行期调整大小。
- **`std::array` 的长度**：必须是常量表达式，通常是整型字面量、`constexpr` 变量或非限定作用域枚举项。
- **`std::array` 是聚合（aggregate）**：没有构造函数，用聚合初始化。
- **优先 constexpr**：能做成 `constexpr` 的 `std::array` 就做成；做不到时，考虑改用 `std::vector`。
- **CTAD（类模板实参推导）**：编译器可从初始化器推导 `std::array` 的元素类型与长度。
- **模板形态**：大致为 `template<typename T, std::size_t N> struct array;`，其中 N 是类型为 `std::size_t` 的非类型模板参数。
- **取长度**：成员 `size()` 返回无符号的 `size_type`；C++17 的 `std::size()` 会调用它；C++20 的 `std::ssize()` 返回一种大的**有符号**类型（通常是 `std::ptrdiff_t`）。
- **constexpr 注意事项**：这些在 constexpr 语境下可用，但当 `std::array` 以引用传入时返回值不一定是 constexpr；C++23 由 P2280 修复。
- **下标访问**：`operator[]` 不做边界检查（非法下标即未定义行为）；`at()` 做运行期检查（作者建议避免）；`std::get()` 把下标作为非类型模板实参，做编译期检查。
- **传数组给函数**：用 `template <typename T, std::size_t N>`，或 C++20 的 `template <typename T, auto N>`。
- **按值返回**：会拷贝数组及其全部元素；元素小且拷贝便宜时可以，否则用输出参数更好。
- **双花括号**：初始化"由 struct/class/数组构成的 `std::array`"、且未逐个写出元素类型时，需要额外一对花括号；这是聚合初始化的产物，list-constructor 容器没有此要求。
- **花括号省略（brace elision）**：聚合在"用标量初始化"，或"用已逐个写出类型的 class/数组初始化"时允许省略花括号。
- **不能有引用的数组**：但可以有 `std::reference_wrapper` 的数组。
- **`std::reference_wrapper` 要点**：`operator=` 重新绑定（reseat）它；它可隐式转换为 `T&`；`get()` 返回 `T&` 以便更新所指对象。
- **`std::ref()` / `std::cref()`**：创建 `std::reference_wrapper` 与 `const std::reference_wrapper` 的快捷方式。
- **`static_assert`**：尽可能用它校验用 CTAD 得到的 constexpr `std::array` 的初始化器个数是否正确。
- **`std::array` 与枚举搭配（17.6）**：常用 `enum` 作下标，配合 `constexpr std::array` 做"以枚举项索引"的查表；枚举项顺序与数组元素按序对应。

### C 风格数组、指针算术、字符串与多维数组（17.8–17.13）

- **C 风格数组**：继承自 C、内建于核心语言，用方括号声明；长度可选，类型为 `std::size_t`，还必须是常量表达式。
- **C 风格数组初始化**：它们是聚合；初始化全部元素时，建议省略长度让编译器计算。
- **C 风格数组下标**：允许有符号、无符号或非限定枚举作下标，因此避开了标准库容器的符号转换下标问题；可为 const 或 constexpr。
- **C 风格数组长度**：C++17 `std::size()` 返回无符号 `std::size_t`；C++20 `std::ssize()` 返回大的有符号类型。
- **数组退化（array decay，17.8）**：在大多数表达式中，C 风格数组隐式转换为"指向其元素类型的指针"，保存元素 0 的地址。退化丢失长度信息，于是 `sizeof`/`std::size()` 结果不同、无法做边界检查，故应尽量避开 C 风格数组。
- **指针算术（pointer arithmetic，17.9）**：对指针施加整数运算（加、减、自增、自减）得到新地址；`ptr + 1` 指向"下一个**对象**"（依所指类型的大小移动）。
- **下标 vs 指针算术（17.9）**：`ptr[n]` 等价于 `*((ptr) + (n))`。从数组开头索引时用下标，使下标与元素编号对齐；做相对偏移时用指针算术。指针算术必须始终停留在数组元素内或末尾后一位，否则为未定义行为（即使不解引用）。
- **C 风格字符串（17.10）**：即 `char` 或 `const char` 的 C 风格数组，会退化；以空终止符标记结尾。`std::cout` 打印 char 指针时按字符串处理；缺少终止符即为 UB。优先用 `std::string` / `std::string_view`。
- **字符串符号常量（17.11）**：两种写法（const 数组 vs const 指针）内存行为不同；相同字面量可能被合并；打印 `char` 变量的地址会踩 UB 坑，需 `static_cast<const void*>`。优先用 `constexpr std::string_view`。
- **维度（dimension，17.12–17.13）**：选择元素所需的下标个数——一维、二维（数组的数组）、多维；摊平（flattening）可把维度降到一维。C++ 多维数组按**行主序**存储与初始化。
- **多维 std::array（17.13）**：标准库没有多维数组类；规范写法是 `std::array<std::array<T, Col>, Row>`（双花括号），并可用别名模板 `Array2d<T, Row, Col>` 简化。取长度时 `arr[0].size()` 在非最后一维为 0 时是 UB，可用 `constexpr` 辅助函数从非类型模板参数安全返回。
- **`std::mdspan`（C++23）**：对一段连续序列提供多维视图的类（可修改），用数据指针加各维长度构造，用 `extents().extent(n)` 查维度、`size()` 查总数、`data_handle()` 取原始指针、`mdView[row, col]` 索引；`std::mdarray`（C++26）是拥有型的多维数组。

## 测验

### Q1：找出并修复 bug（三小段）

**a)** 循环条件误用 `<=`，越界读取。
解答代码：[17-14-quiz1a-ub.cpp](17-14-quiz1a-ub.cpp)（`-ub`）。

```
for (std::size_t count { 0 }; count <= std::size(arr); ++count) // 应为 <
```

**b)** 把 C 风格数组传给形参 `int array[]`，在函数内用范围 for——数组已退化为指针，无法求长度，编译失败。
解答代码：[17-14-quiz1b-error.cpp](17-14-quiz1b-error.cpp)（预期编译失败）。

**c)** 用运行期读入的 `length` 作为 `std::array` 的长度——`length` 不是常量表达式，编译失败。
解答代码：[17-14-quiz1c-error.cpp](17-14-quiz1c-error.cpp)（预期编译失败）。

### Q2：Roscoe 的魔药店

用 `enum` + 若干 `constexpr std::array`（种类/名称/价格）表示商店，`Player` 类记录金子和库存，实现购买循环与库存打印。

解答代码：[17-14-quiz2/](17-14-quiz2/)（`main.cpp` + `Random.h`）。

预期输出（片段）：

```
Welcome to Roscoe's potion emporium!
Enter your name: <名字>
Hello, <名字>, you have <80~120> gold.

Here is our selection for today:
0) healing costs 20
1) mana costs 30
2) speed costs 12
3) invisibility costs 50

Enter the number of the potion you'd like to buy, or 'q' to quit:
...
```

### Q3：扑克牌与牌堆

用 `Rank`/`Suit` 枚举定义 `Card`（含 `operator<<` 输出两字母代号、`value()` 给出点数，A=11），`Deck` 用 `std::array<Card, 52>` 保存一副牌，构造时按序填牌，`shuffle()` 洗牌，`dealCard()` 发牌（越界用 `assert`）。

解答代码：[17-14-quiz3/](17-14-quiz3/)（`main.cpp` + `Random.h`）。

预期输出（首行固定，次行随机）：

```
AC 2C 3C
KD 6D 5S
```

### Q4：21 点（Blackjack）

在 Q3 的 `Card`/`Deck` 基础上，`playBlackjack()` 先给庄家一张、玩家两张；玩家可反复要牌（h/s），随后庄家按策略补到 17 点，最后比大小。

解答代码：[17-14-quiz4/](17-14-quiz4/)（`main.cpp` + `Random.h`）。交互式，输出依发牌而定，例如：

```
The dealer is showing: 10
You have score: 18
(h) to hit, or (s) to stand: s
You win!
```

### Q5：附加题（A 的处理与返回值）

把 `Player` 改成类，用 `m_ace11Count` 处理"A 当 11 还是 1"（爆牌时把 A 从 11 改算作 1），并把返回值从 `bool` 改为 `GameResult` 枚举（`playerWon`/`dealerWon`/`tie`）。

解答代码：[17-14-quiz5/](17-14-quiz5/)（`main.cpp` + `Random.h`）。交互式，例如：

```
The dealer is showing: 10
You are showing AH 7D (18)
(h) to hit, or (s) to stand: s
The dealer turned up 4S. They now have: 21
You lose!
```

> 本节 Best practice / Author's note / Warning 条目：原文无加框条目；正文中的建议已并入上文的"本章知识速览"（制作 constexpr 的 `std::array`、避免 `at()`、初始化 C 风格数组时省略长度、从元素 0 索引时用下标 / 相对偏移时用指针算术、用 `static_assert` 校验 CTAD 尺寸等）。

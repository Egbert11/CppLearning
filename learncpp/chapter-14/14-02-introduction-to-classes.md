# 14.2 Introduction to classes

> 原文：https://www.learncpp.com/cpp-tutorial/introduction-to-classes/

## 核心概念

- **struct 回顾**：struct 把多个成员变量打包成一个对象，可以整体初始化、整体传递，是打包相关数据的便利手段。（提醒：本系列中出现的所有 struct 都是聚合体 aggregate。）
- **类不变量问题**：struct 没有有效的办法来记录并**强制**它的不变量，这对大型、多人协作的程序是难题。
- **不变量（invariant）的通用定义**：此前定义为"某个组件执行期间必须始终为真的条件"。
- **类不变量（class invariant）**：一个对象在其**整个生命周期**内都必须成立、否则对象即无效的条件；违反它的对象处于**无效状态（invalid state）**，继续使用可能导致意外行为或未定义行为。
- **Pair 例子**：`first` 和 `second` 可以被独立设成任何值，因此 `Pair` 没有任何不变量。
- **Fraction 例子**：分母为 `0` 在数学上无定义，所以不变量是 `denominator` 永不为 `0`。用注释记录该不变量，并用默认成员初始化器（`1`）保证值初始化的对象合法。
- **为什么这还不够**：没有任何机制阻止聚合初始化把分母显式设成 `0`，从而构造出无效对象，随后触发除以零而终止。
- **旁注：assert**：加一句 `assert(f.denominator != 0);` 只起到记录前置条件的作用，行为上什么也没改变；真正的目标应当在源头（初始化/赋值处）发现问题，而不是在出问题的下游。
- **更复杂的不变量**：当成员之间必须彼此关联时，不变量更难维护（例如一个成员应当等于名字的首字符）。
- **Employee 例子**：`firstInitial` 应始终与 `name` 的首字符一致；若 `name` 被重新赋值，使用者必须同步更新另一个成员。即使用辅助函数，也仍然依赖使用者"选择去用"。
- **Key insight**：依赖对象的使用者去维护类不变量，很可能出问题。
- **理想目标**：把类做得"防弹"——对象要么根本无法进入无效状态，要么在进入时立刻报错，而不是把未定义行为推迟到后来才暴露。
- **类的由来**：Bjarne Stroustrup 借鉴了其它语言，特别是"第一个面向对象编程语言 Simula"，并为了致敬 Simula 把这个类型命名为 *class*。
- **类的定义**：**class** 是一种程序自定义的复合类型，可以含有许多不同类型的成员变量。用 `class` 关键字而不是 `struct` 定义，且必须先定义后使用。
- **Key insight**：从技术上说，struct 与 class 几乎是相同的——任何 struct 例子都能改写成 class，反之亦然；但在实践中两者用法不同。
- **访问说明符**：class 版 `Date` 加了 `public:`；class 的成员变量通常加 `m_` 前缀。
- **标准库**：`std::string` 与 `std::string_view` 都是类，标准库里大多数非别名的类型都是类。C++ 最初就叫 "C with classes"。

## 最佳实践

- 本节无 Best practice / Warning 条目。原文出现的是多条 **Key insight** 方框：
  - 使用类不变量已被破坏的对象，可能导致意外行为或未定义行为。
  - 依赖对象的使用者去维护类不变量，很可能出问题。
  - 技术上说 struct 与 class 几乎完全相同，因此可以互相替换，只是实践中的用法不同。
- 另有一条 **A reminder**：本系列教程中出现的每个 struct 都是聚合体（aggregate）；以及一条 **As an aside**：`assert` 只增加文档价值、不改变行为，问题最好在源头发现。

## 代码示例

- [14-02-example1.cpp](14-02-example1.cpp)：`Date` struct + `printDate()`，整体传递结构体，输出 `4/10/21`。
- [14-02-example2.cpp](14-02-example2.cpp)：`Pair` struct，成员彼此独立，故没有不变量。
- [14-02-example3.cpp](14-02-example3.cpp)：`Fraction` struct，用注释记录不变量并给默认成员初始化器。
- [14-02-example4-ub.cpp](14-02-example4-ub.cpp)：聚合初始化把分母设为 0，`printFractionValue()` 触发整数除以零（未定义行为，通常 SIGFPE 崩溃）。
- [14-02-example5.cpp](14-02-example5.cpp)：`Employee` struct，成员彼此关联（更复杂的不变量）。
- [14-02-example6.cpp](14-02-example6.cpp)：用 `class` 关键字定义类型，成员默认 private。
- [14-02-example7.cpp](14-02-example7.cpp)：把 `Date` 改写为 class，加 `public:` 与 `m_` 前缀，输出 `4/10/21`。
- [14-02-quiz1.cpp](14-02-quiz1.cpp)：测验题中的 `minMax` struct；解答为文字说明（不变量是 `min <= max`，原文未给解答代码）。

> 说明：本节代码为按原文描述**忠实重建**（抓取工具对长代码块有逐字引用上限）。

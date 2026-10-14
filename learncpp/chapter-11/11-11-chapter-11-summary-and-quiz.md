# 11.x Chapter 11 summary and quiz

> 原文：https://www.learncpp.com/cpp-tutorial/chapter-11-summary-and-quiz/
> 注：官方编号为 11.x（总结与测验小节）；本库按"下一个顺延号"命名为文件编号 11。

## 本章知识速览

- **函数重载（function overloading）**：多个函数可同名，只要各函数的形参类型集合不同（或以其他方式可区分）。返回类型不参与区分。这样的函数叫"重载函数（overloaded function / overload）"。
- **重载决议（overload resolution）**：找不到精确匹配时，编译器更偏向用数值提升匹配，而不是数值转换。它依据调用实参挑出最佳重载。
- **歧义匹配（ambiguous match）**：当两个或多个候选函数都可能匹配某次调用、而编译器无法确定唯一最佳者时发生。
- **默认实参（default argument）**：为形参给出的默认值。带默认值的形参必须位于最右侧，且在解析重载时会被忽略。
- **函数模板（function templates）**：用于生成一族相关函数的函数式模式。**类型模板参数**是稍后由类型填充的占位符；宣告模板的声明叫"模板参数声明"。
- **函数模板实例化**：由模板产出具体函数的过程。因调用而发生叫"隐式实例化"；产物叫"函数实例"（也叫"template function"）。
- **模板实参推导**：编译器从调用实参推断要实例化的类型，且不做类型转换。
- **泛型类型 / 泛型编程**：模板类型与基于模板的编程的别名。
- **缩写函数模板（C++20）**：把普通函数形参类型写成 `auto` 会让编译器生成模板，每个 `auto` 形参成为独立的类型模板参数。
- **非类型模板参数**：具有固定类型的模板参数，代替作为模板实参传入的 constexpr 值。

## 最佳实践

本节无（本章各节的最佳实践已在对应小节记录）。

## 代码示例

- [11-11-example1.cpp](11-11-example1.cpp)：`print(int)`/`print(double)`，`short` 实参提升选 `int`，输出 `int 5`。
- [11-11-example2-error.cpp](11-11-example2-error.cpp)：`print()`/`print(int x=0)`/`print(double x)`，裸 `print()` 歧义，预期编译失败。
- [11-11-example3-error.cpp](11-11-example3-error.cpp)：`print(long)`/`print(double)` 被 `print(5)` 调用，两者都需转换，歧义，预期编译失败。
- [11-11-example4.cpp](11-11-example4.cpp)：`add<T>` 模板，输出 `5`、`4.6`。
- [11-11-example5.cpp](11-11-example5.cpp)：`mult<T>`（第二参为普通 `int`，返回第一参类型），输出 `6`、`3.6`。
- [11-11-example6.cpp](11-11-example6.cpp)：`sub<T, U>` 两模板参数 + `auto` 返回，输出 `1`、`1.5`、`2.5`。
- [11-11-example7.cpp](11-11-example7.cpp)：`count(T)` 模板用函数内 `static int c`，输出 `1 2 1 2`。
- [11-11-example8.cpp](11-11-example8.cpp)：非模板 `foo(int)` 与模板 `foo(T)`，输出 `11 2 4 2 6`。

## 测验

**Question #1**
- (1a) `print(int)` / `print(double)` 程序，`short s { 5 }` 时输出是什么、为什么？→ `int 5`（提升优先于转换）。
- (1b) `print()`、`print(int x=0)`、`print(double x)` 的程序为何无法编译？→ 带默认值的形参不计入重载决议，`print()` 无法在 `print()` 与 `print(int x=0)` 间取舍。
- (1c) `print(long)` / `print(double)` 程序用 `print(5)` 调用为何无法编译？→ 字面量 `5` 是 `int`，转 `long` 与转 `double` 都是转换，没有更优匹配。

**Question #2** —— 三步练习：(1) 写同类型两值相加的 `add()` 模板；(2) 写任意类型值乘 `int`（第二参不模板化）、返回第一参类型的 `mult()` 模板；(3) 写两个不同类型值相减的 `sub()` 模板。预期输出：`5`/`4.6`；`6`/`3.6`；`1`/`1.5`/`2.5`。

**Question #3** —— `count(T)` 模板程序的输出及原因？→ `1 2 1 2`。

**Question #4** —— `foo(int)` / `foo(T)` 程序的输出？→ `11 2 4 2 6`。

解答代码：
- [11-11-quiz1a.cpp](11-11-quiz1a.cpp)（Q1a，输出 `int 5`）
- [11-11-quiz1b-error.cpp](11-11-quiz1b-error.cpp)（Q1b，预期编译失败）
- [11-11-quiz1c-error.cpp](11-11-quiz1c-error.cpp)（Q1c，预期编译失败）
- [11-11-quiz2.cpp](11-11-quiz2.cpp)（Q2，add/mult/sub，输出 `5 4.6 6 3.6 1 1.5 2.5`）
- [11-11-quiz3.cpp](11-11-quiz3.cpp)（Q3，输出 `1 2 1 2`）
- [11-11-quiz4.cpp](11-11-quiz4.cpp)（Q4，输出 `11 2 4 2 6`）

> 说明：以上代码为按原文描述重建的可编译完整程序（本抓取工具对长代码块有逐字引用上限）。

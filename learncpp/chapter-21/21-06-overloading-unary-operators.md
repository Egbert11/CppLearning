# 21.6 Overloading unary operators +, -, and !

> 原文：https://www.learncpp.com/cpp-tutorial/overloading-unary-operators/

## 核心概念

- **一元运算符**：正号 `+`、负号 `-`、逻辑非 `!` 都只作用于一个操作数，与之前讲的二元运算符不同。
- **实现为成员函数**：由于它们只作用于所应用的对象，一元重载通常写成成员函数；三者的实现方式完全相同。
- **不需要参数**：成员版一元重载不带参数，它作用于 `*this` 对象。
- **const 正确性**：因为 `operator-` 不修改对象，它应当声明为 `const`，这样才能在 `const` 对象上调用。
- **与二元 `-` 不冲突**：一元版和二元版 `-` 不会混淆，因为参数个数不同。
- **`operator!` 的语义**：逻辑非对"真"表达式返回 `false`，反之亦然；对整数而言，`0` 为假、其余为真。推广来说，`operator!` 应在对象状态为"假""零"或默认初始化状态时返回 true。
- **返回时的隐式转换**：返回类型为 `Cents` 时，函数体里 `return -m_cents` 会经 `Cents(int)` 构造函数从 `int` 隐式转换为 `Cents`。
- **测验中一元 `+` 的规则**：一元正号只是返回其操作数，**不会**把负数变正。
- **按值返回而非 const 引用**：测验解答指出结果按值返回，因为调用者很可能想修改返回的对象。

## 最佳实践

本节无正式标注的 Best practice / Author's note / Warning。原文明示的要点：

- 因为 `operator-` 不修改对象，应把它写成 `const` 成员函数，以便对 const 对象也能使用。
- 一元 `operator+` 的结果按值返回（而非 const 引用），因为调用者很可能希望返回对象是可修改的。

## 代码示例

- [21-06-example1.cpp](21-06-example1.cpp)：成员函数重载一元 `operator-`，对 const 对象取负；`return -m_cents` 经构造函数隐式转换，输出 `A nickle of debt is worth -5 cents`。
- [21-06-example2.cpp](21-06-example2.cpp)：逻辑非 `!` 的常见用法（内置 bool 版），作为铺垫，输出 `I am not happy!`。
- [21-06-example3.cpp](21-06-example3.cpp)：为 `Point` 同时重载一元 `operator-`（取负）与 `operator!`（判断是否在原点），输出 `point is set at the origin.`。
- [21-06-quiz1.cpp](21-06-quiz1.cpp)：测验解答——一元 `operator+` 返回操作数本身（`return *this;`），并演示 `+point` 原样返回、`-point` 取负。

> 示例 1、2、3 代码取自原文（逐字保留）；示例 2 原为无 `main` 的片段，已按规范包进 `main()`。测验解答为按原文描述重建。

## 测验

- 为 `Point` 实现重载的一元 `operator+`。一元正号只返回其操作数（不会把负数变正）。

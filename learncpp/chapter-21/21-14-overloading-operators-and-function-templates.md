# 21.14 Overloading operators and function templates

> 原文：https://www.learncpp.com/cpp-tutorial/overloading-operators-and-function-templates/

## 核心概念

- **模板实例化可能编译不过**：编译器用函数模板“打印”出具体函数，若函数体对实际类型做了它不支持的操作（例如给 `std::string` 加 `1`），生成的函数就编译失败。
- **本课目的**：走查“实例化失败”的情形，并演示如何通过定义缺失的运算符让它们编译通过。
- **`max()` 遇到 `Cents` 失败**：模板体求值 `x < y`，而编译器不知道怎么比较两个 `Cents`，于是编译报错。
- **规则**：想对某类型使用 `max()`，就要为它重载 `operator<`。给 `Cents` 加一个比较私有成员 `m_cents` 的 friend `operator<`，实例化的 `max()` 就能编译并正确运行。
- **`average()` 对内建类型开箱即用**：模板体把元素累加到 `T sum { 0 }`（用 `+=`），再用 `/= numValues` 求平均；对 `int`、`double` 数组都可用。
- **`average()` 遇到 `Cents` 报一堆错**：第一个错误是“把返回的 `Cents` 流式输出到 `std::cout` 失败”，因为 `Cents` 没有 `operator<<`。
- **补上 `operator<<` 后又暴露第二个错误**：实例化函数里的循环行对 `Cents` 使用 `+=`，而 `Cents` 没有 `operator+=`。
- **实例化后的函数长什么样**：当 `T = Cents` 时，“打印”出来的副本形如 `Cents sum { 0 };`，循环里 `sum += myArray[count];`，最后 `sum /= numValues;`。
- **规则**：模板体用到的**每一个**运算符都要定义。因为 `average()` 还会做除法，所以 `operator/=` 也得定义。
- **结果与要点**：当 `operator<<`、`operator+=`、`operator/=` 都齐了，程序编译通过并打印 `11 cents`。`average()` 本身一行都不用改——改的只是 `Cents` 的运算符。

## 最佳实践

- 原文没有正式的 Best practice / Warning 框；正文给出的经验：
  - 想对某类型使用 `max()`，就要为它**重载 `operator<`**。
  - **定义模板体所依赖的运算符**，实例化出的函数才能编译。

## 代码示例

- [21-14-example1-error.cpp](21-14-example1-error.cpp) — `Cents` 缺少 `operator<`，`max()` 实例化失败，**预期编译失败**。
- [21-14-example2.cpp](21-14-example2.cpp) — 补上 `operator<` 后 `max()` 正常（输出 `10 is bigger`）。
- [21-14-example3.cpp](21-14-example3.cpp) — `average()` 用于 `int`、`double` 数组（输出 `3`、`5.535`）。
- [21-14-example4-error.cpp](21-14-example4-error.cpp) — `average()` 用于 `Cents`，缺 `operator+=`，**预期编译失败**。
- [21-14-example5.cpp](21-14-example5.cpp) — 补齐 `operator<<`、`operator+=`、`operator/=`（输出 `11 cents`）。

说明：本节代码为按原文描述重建（原文长代码块受抓取工具逐字引用上限所限）。

# 27.x Chapter 27 summary and quiz

> 原文：https://www.learncpp.com/cpp-tutorial/chapter-27-summary-and-quiz/
> 说明：本小节的官方编号为 27.x；本库按顺延号命名为 27-11。

## 核心概念

1. **异常处理的目的**：把错误处理与程序的正常控制流解耦，从而更灵活地决定何时、如何处理问题，并避免返回码带来的混乱。
2. **`throw` 语句**：用于抛出异常；可以抛出任意数据类型，包括类对象。
3. **try 块**：寻找由"写在其中或被其调用"的代码所抛出的异常。
4. **catch 块**：在类型匹配时接收并处理特定类型的异常；一个被捕获的异常默认视为已处理。
5. **立即处理与栈展开**：抛出异常后，控制流跳到最近的、能被匹配的 `try`/`catch`；若找到匹配处理器，栈会展开到该 `catch` 处。若不存在 `try` 块或没有匹配的 `catch`，程序调用 `std::terminate`，以"未处理异常"错误结束。
6. **类型匹配规则**：`catch` 可针对某一数据类型，也可用省略号（`...`）做 catch-all；以基类引用捕获时也能捕获派生类异常。
7. **标准库异常**：所有标准库异常都派生自 `std::exception`（声明于 `<exception>`），因此以引用捕获 `std::exception` 能捕获它们全部；`what()` 成员函数可查知抛出的具体种类。
8. **在 catch 中抛出**：在 `catch` 块里抛出的新异常位于与之关联的 `try` 块之外，因此不会被该 `catch` 自己捕获。
9. **重抛（rethrow）**：用单独的 `throw` 关键字从 `catch` 中重抛；**不要**用被捕获的异常变量重抛，否则可能发生对象切片。
10. **函数 try 块**：可捕获函数体内或成员初始化列表中发生的任何异常，通常只用于派生类构造函数。
11. **析构函数**：绝不要从析构函数中抛出异常。
12. **`noexcept` 说明符**：把函数标记为 no-throw / no-fail。
13. **`std::move_if_noexcept`**：对象若有 `noexcept` 移动构造函数则返回可移动的右值，否则返回可拷贝的左值；配合 `noexcept`，可在强异常保证成立时使用移动语义、否则使用拷贝。
14. **异常的开销**：使用异常的代码通常略慢，且处理一个异常非常昂贵；异常应保留给"异常情形"，而非日常错误处理（如非法输入）。

## 最佳实践

（本节没有标注为 Best practice / Author's note / Warning 的提示框。）
复习中强调的规则式要点：绝不要从析构函数抛出异常；异常只应处理"异常情形"，不用于正常错误处理。

## 本章知识速览

- `throw` 抛出异常（任意类型）；`try` 块监控其内部代码抛出的异常；`catch` 按类型捕获并处理。
- 无匹配 `try`/`catch` → `std::terminate`（未处理异常）。
- `catch (...)` 为 catch-all；以基类引用捕获也捕获派生类。
- 所有标准库异常派生自 `std::exception`，用 `what()` 获取信息。
- `catch` 内抛出的新异常不会被同一 `catch` 捕获。
- 重抛用裸 `throw;`，不要用异常变量（会切片）。
- 函数 try 块主要给派生类构造函数用；析构函数绝不抛异常。
- `noexcept` 表示 no-throw / no-fail；std::move_if_noexcept 据此在移动/拷贝间抉择。

## 代码示例

- [27-11-quiz1.cpp](27-11-quiz1.cpp) — 测验第 1 题解答（Fraction 类，分母为 0 时抛 `std::runtime_error`）。

## 测验

**第 1 题**：编写一个 `Fraction` 类，其构造函数接受分子和分母。若分母为 0，则抛出 `std::runtime_error` 类型的异常（`std::runtime_error` 定义在 `<stdexcept>` 头文件中）。在 `main` 程序中要求用户输入两个整数：若分数合法则打印该分数；若不合法则捕获 `std::exception`，并告知用户输入了非法分数。

原文给出的一次运行输出：

```
Enter the numerator: 5
Enter the denominator: 0
Invalid denominator
```

解答代码见 [27-11-quiz1.cpp](27-11-quiz1.cpp)。

# 7.1 Compound statements (blocks)

> 原文：https://www.learncpp.com/cpp-tutorial/compound-statements-blocks/

## 核心概念

- **复合语句（compound statement）**：一组“零条或多条语句”，编译器将其视为**一条**语句。也叫**块（block）**或**块语句（block statement）**。块内可以什么都没有，也可以有很多语句。
- **语法**：块以 `{` 开始、以 `}` 结束，语句放在其中。凡是允许出现单条语句的地方都可以放块，**块尾不需要分号**。
- **函数体就是块**：你其实一直在使用块——每个函数体本身就是一个块。
- **嵌套块（nested block）**：函数不能嵌套在函数内，但块可以嵌套在块内。外层叫 outer block，内层叫 inner block / nested block。
- **与 `if` 配合**：默认 `if` 为真时只执行一条语句；改用块即可在该条件下执行多条语句。
- **嵌套层级（nesting level / nesting depth）**：在函数中“同时”处于其中的嵌套块的最大数量，**包含最外层块**。一个函数可以拥有的块总数多于其嵌套层级。
- **标准支持上限**：C++ 标准要求编译器至少支持 256 层嵌套；但部分编译器达不到（作者指出当年 Visual Studio 支持得更少）。
- **可读性建议**：嵌套层级控制在 3 层及以内；嵌套过深难以阅读，应像拆分过长的函数一样考虑重构。

## 最佳实践

- **Best practice**：Keep the nesting level of your functions to 3 or less.（把函数的嵌套层级控制在 3 层或更少。）
- 若确实需要更多嵌套，"consider refactoring your function into sub-functions"（考虑把函数拆分为子函数）。

## 代码示例

- [7-01-example1.cpp](7-01-example1.cpp)：函数体即块——`add()` 的块，以及 `main()` 中把多条语句放进一个块（对应原文 Example 1）。
- [7-01-example2.cpp](7-01-example2.cpp)：在 `main` 的外层块内嵌套一个内层块（对应原文 Example 2）。
- [7-01-example3.cpp](7-01-example3.cpp)：用块让 `if`/`else` 各执行多条语句（对应原文 Example 3）。
- [7-01-example4.cpp](7-01-example4.cpp)：4 个块、嵌套层级为 3 的示例（对应原文 Example 4）。

> 说明：本节示例代码为按原文清单与站点标准写法**忠实重建**，以保证可用 `g++ -std=c++20 -Wall` 编译运行；原文代码块本身未逐字获取。为在 `-Wall` 下保持无警告，示例 1、2 中的未使用变量加了 `[[maybe_unused]]`。

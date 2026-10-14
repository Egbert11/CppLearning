# 11.1 Introduction to function overloading

> 原文：https://www.learncpp.com/cpp-tutorial/introduction-to-function-overloading/

## 核心概念

- **固定参数类型带来的问题**：一个只接受 `int` 的 `add(int, int)` 无法正确处理浮点参数——把 double 传进去会被隐式转成 int，小数部分丢失。
- **用不同名字的变通做法**：可以定义 `addInteger` 与 `addDouble` 两个函数。它能工作，但要求维护一套一致的命名规范，还要记住哪个名字对应哪种类型、该调用哪个。
- **规模膨胀问题**：一旦要再加"三个整数相加"之类的变体，管理这些互不重名的名字会越来越繁琐。
- **函数重载的定义**：C++ 允许声明多个同名函数，只要每个同名函数的参数类型不同（或能以其他方式被区分）。
- **重载函数的定义**：在同一作用域内共享同一名字的每个函数都称为重载函数（overloaded function），简称重载（overload）。
- **不构成命名冲突（规则）**：两个仅参数类型不同的 `add()` 不算冲突；编译器能区分它们，把它们当作"恰好同名"的不同函数。
- **关键规则**：只有当编译器能区分这些重载时，重载才合法；若无法区分则产生编译错误。
- **相关概念——运算符重载**：运算符也能以类似方式重载（见 21.1）。
- **重载解析（overload resolution）的定义**：调用重载函数时，编译器根据实参尝试把调用匹配到正确的重载。
- **解析的实际效果**：整数实参选中整数版本，浮点实参选中 double 版本。
- **程序能编译的两个条件**：(a) 每个重载函数必须能与其他重载区分；(b) 每次调用必须能解析到某一个重载上。
- **规则——失败的后果**：若某个重载无法被区分，或某次调用无法解析到某个重载，都会产生编译错误。
- **结论/收益**：重载减少了需要记住的函数名数量，从而降低程序复杂度，应当大量使用。

## 最佳实践

- **Best practice**："Use function overloading to make your program simpler."（用函数重载让程序更简单。）
- **Key insight**："Functions can be overloaded so long as each overloaded function can be differentiated by the compiler."（只要每个重载都能被编译器区分，函数就可以被重载；否则编译错误。）

本节无 Warning / Author's note 条目。

## 代码示例

- [11-01-example1.cpp](11-01-example1.cpp)：用不同名字的 `addInteger`/`addDouble` 分别处理整数与浮点的变通做法。
- [11-01-example2.cpp](11-01-example2.cpp)：两个 `add()` 重载共存，由重载解析分别选中 int / double 版本（输出 3 与 4.6）。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。
> 原文中 Example 1（只处理整数的 `add(int, int)`）与 Example 3（新增的 `double add(double, double)`）为片段，其内容已并入上面两个完整程序。

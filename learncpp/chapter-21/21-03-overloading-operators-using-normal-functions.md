# 21.3 Overloading operators using normal functions

> 原文：https://www.learncpp.com/cpp-tutorial/overloading-operators-using-normal-functions/

## 核心概念

- **回顾友元方式**：上一节把 `operator+` 写成 Cents 的友元函数，函数体借助友元身份直接读取私有成员 `m_cents`。
- **友元的便利之处**：友元身份让你"直接访问所操作类别的内部成员"，但这种便利只在确实需要访问时才重要。
- **何时可以不用友元**：如果类已经提供了访问器（这里是 `getCents()`），运算符就能写成普通（非成员、非友元）函数。原文称此版本"既不是成员函数，也不是友元函数"。
- **普通版与友元版行为几乎相同**：两者"工作方式几乎一样"，唯一实际差别是能访问私有成员的程度不同。
- **例外：函数原型**：写在类内的友元声明同时充当原型；而普通（非友元）函数需要你自己提供原型。
- **多文件的后果**：在头文件/实现文件拆分的工程里，头文件必须显式声明该运算符重载，否则其他翻译单元不知道这个重载存在，`main.cpp` 中的 `cents1 + cents2` 会"编译失败"。
- **选择规则**：只要现有的公开接口够用，就应默认使用普通函数——因为越少的函数触碰类内部越好。但**不要为了把运算符写成普通函数而额外添加访问函数**。

## 最佳实践

- **Best practice**：只要能在不新增函数的前提下办到，优先把运算符重载为普通函数而不是友元函数。

## 代码示例

- [21-03-example1.cpp](21-03-example1.cpp)：对照——用友元函数重载 `operator+`，输出 `I have 14 cents.`。
- [21-03-example2.cpp](21-03-example2.cpp)：把 `operator+` 写成普通（非成员非友元）函数，经 `getCents()` 求和，输出 `I have 14 cents.`。
- [21-03-example3/](21-03-example3/)：多文件示例——`Cents.h`（含显式 `operator+` 原型）、`Cents.cpp`、`main.cpp`，编译：`g++ -std=c++20 -Wall 21-03-example3/*.cpp`，输出 `I have 14 cents.`。

> 本节代码取自原文（逐字保留）。

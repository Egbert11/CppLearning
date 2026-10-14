# 11.2 Function overload differentiation

> 原文：https://www.learncpp.com/cpp-tutorial/function-overload-differentiation/

## 核心概念

- **重载必须可区分**：多个函数可以同名，前提是每个都能与其他区分；否则编译器报错。
- **参数个数——可用于区分**：参数个数不同的重载总是可区分的。
- **参数类型——可用于区分，但有例外**：typedef、类型别名，以及按值参数上的 `const` 限定符会被忽略。省略号（ellipsis）算作一种独立的参数类型。
- **返回类型——不能用于区分**：返回类型不参与重载区分。
- **成员函数有额外限定符**：函数级的 `const`/`volatile` 限定符与引用限定符（ref-qualifier）会参与重载——例如一个 `const` 成员函数可以与除 `const` 外完全相同的非 `const` 成员函数区分开。
- **类型别名/typedef 不是不同的类型**：接受 `Age`（`int` 的别名）或 `Height`（`int` 的 typedef）的重载与接受 `int` 的版本等价，因此这些声明会冲突。
- **按值参数上的顶层 `const` 被忽略**：`void print(int)` 与 `void print(const int)` 不是不同的重载。
- **省略号是独特的参数类型**：`foo(int, ...)` 与 `foo(int, int)` 可区分；用两个 int 调用会绑定到精确匹配的版本。
- **返回类型永远不被考虑**：教程以想要 `int getRandomValue()` 和 `double getRandomValue()` 为例；Visual Studio 2019 报错 C2556，称该重载"仅返回类型不同"。因为裸调用 `getRandomValue();` 无法提示该选哪个，所以不被允许。
- **排除返回类型的原因**：这是有意的设计，使得"某次调用解析到哪个重载"可以独立于表达式的其余部分确定——只需看实参，不必看结果如何被使用。
- **推荐的修复方式**：改用不同的函数名（例如 `getRandomInt()` 和 `getRandomDouble()`）。
- **签名的定义**：函数的签名（signature）是其头部中用于区分的部分：函数名、参数个数、参数类型，以及函数级限定符——并明确**不**包括返回类型。
- **名字修饰（name mangling）**：编译时编译器会根据参数个数与类型等准则改写函数名，使链接器看到唯一的符号；此处"没有标准化"，不同编译器产生的修饰名不同。

## 最佳实践

本节无 Best practice / Rule / Warning 条目。
- **For advanced readers**：成员函数的函数级限定符也参与重载——`const`/`volatile` 与引用限定符均可用于区分。
- **相关阅读**：省略号将在 20.5 "Ellipsis (and why to avoid them)" 中讲解。

## 代码示例

- [11-02-example1.cpp](11-02-example1.cpp)：按参数**个数**重载：`add(int,int)` 与 `add(int,int,int)`。
- [11-02-example2.cpp](11-02-example2.cpp)：按参数**类型列表**重载的四个版本 `(int,int)`、`(double,double)`、`(int,double)`、`(double,int)`。
- [11-02-example3-error.cpp](11-02-example3-error.cpp)：类型别名/typedef 无法产生可区分的重载——**预期编译失败**。
- [11-02-example4-error.cpp](11-02-example4-error.cpp)：按值参数上的 `const` 被忽略——**预期编译失败**。
- [11-02-example5.cpp](11-02-example5.cpp)：省略号作为独立参数类型，`foo(int,int)` 与 `foo(int,...)` 可区分。
- [11-02-example6-error.cpp](11-02-example6-error.cpp)：仅靠返回类型无法重载——**预期编译失败**。
- [11-02-example8.cpp](11-02-example8.cpp)：正确做法：用不同名字 `getRandomInt()` / `getRandomDouble()`。

> 说明：本节错误示例文件按约定以 `-error` 后缀命名，文件头已写明预期错误，请勿修复。
> 原文中 Example 7（`getRandomValue();` 的裸调用）是用于说明动机的片段，未单独生成文件。

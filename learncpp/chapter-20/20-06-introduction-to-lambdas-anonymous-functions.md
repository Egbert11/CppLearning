# 20.6 Introduction to lambdas (anonymous functions)

> 原文：https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/

## 核心概念

- **命名辅助函数的问题**：`std::find_if` 需要一个函数指针，迫使一个只用一次的函数必须命名并放到全局作用域（因为 C++ 的函数不能嵌套）。
- **lambda 表达式（lambda / 闭包）**：可以在另一个函数内部定义的匿名函数；嵌套避免了命名空间污染，并让代码靠近使用处。
- **语法**：`[captureClause](parameters) -> returnType { statements; }`。捕获子句可为空；参数列表可为空或省略（除非写了返回类型）；返回类型可选（默认为 `auto`）。
- **没有名字**：因为是匿名的，不需要名字。
- **lambda 的类型**：lambda 没有可直接使用的类型；编译器为每个 lambda 生成一个唯一且不对外暴露的类型。
- **lambda 是仿函数（functor）**（进阶）：它们是重载了 `operator()` 的对象，这正是它们能绕过"函数不能嵌套"限制的原因。
- **存储方式**：函数指针（仅当捕获子句为空）、`std::function`、或 `auto`（唯一能使用 lambda 真实类型的方式，且无额外开销）。
- **把 lambda 传给函数的四种方式**：
  1. `std::function` 形参：签名显式，有少量转换开销，可拆成头文件声明 + `.cpp` 定义。
  2. 带类型模板参数的模板：高效，但签名不那么直观。
  3. C++20 缩写函数模板（`auto` 形参）：与第 2 种等价。
  4. 函数指针：只适用于无捕获的 lambda。
- **泛型 lambda**：C++14 起，lambda 形参可以用 `auto`，编译器从调用处推断所需类型。
- **auto 不总是最好**：对 C 风格字符串它推导出 `const char*`；显式写成 `std::string_view` 有时更合适。
- **constexpr lambda**：C++17 起，如果 lambda 没有捕获、或所有捕获都是 constexpr，且它调用的函数都是 constexpr，则它隐式是 constexpr。
- **泛型 lambda 与静态变量**：`auto` 每解析出一种不同类型就产生一个独立的 lambda，所以不同类型之间 static 局部变量不共享。
- **返回类型推导 / 尾置返回类型**：用推导时，所有 `return` 语句必须返回同一类型；否则显式给出返回类型（通常比给每个 return 都加转换更好）。
- **标准库函数对象**：`<functional>` 提供 `std::greater` 等可调用对象，常见操作不必手写 lambda。
- **结论**：lambda 加上算法库能实现强大而可读的操作（以及并行性）；但对非平凡、可复用的场合，仍应优先使用普通函数。

## 最佳实践

- **Best practice**：lambdas are preferred over normal functions when we need a trivial, one-off function to pass as an argument to some other function.
- **Key insight**：把 lambda 存进变量能给它一个可读的名字，并允许复用。
- **Best practice**：存储 lambda 时用 `auto` 作为变量类型。传递 lambda 时：若支持 C++20，用 `auto` 作形参类型；否则用类型模板参数、`std::function` 形参、或无捕获 lambda 用函数指针。
- **For advanced readers**：lambda 实际上就是含有重载 `operator()` 的仿函数；lambda 里的 `auto` 是模板参数的简写。

## 代码示例

- [20-06-example1.cpp](20-06-example1.cpp)：问题引入——只用一次的 `containsNut()` 辅助函数配合 `std::find_if`。
- [20-06-example2.cpp](20-06-example2.cpp)：改写为内联 lambda。
- [20-06-example3.cpp](20-06-example3.cpp)：把 lambda 存进变量并配合 `std::all_of`。
- [20-06-example4.cpp](20-06-example4.cpp)：同一个 lambda 的三种存储方式（函数指针 / `std::function` / `auto`）。
- [20-06-example5.cpp](20-06-example5.cpp)：把 lambda 传给函数的四种方式（`std::function` / 模板 / C++20 auto 形参 / 函数指针）。
- [20-06-example6.cpp](20-06-example6.cpp)：泛型 lambda 配合 `std::adjacent_find`。
- [20-06-example7.cpp](20-06-example7.cpp)：用显式 `std::string_view` 形参配合 `std::count_if`。
- [20-06-example8.cpp](20-06-example8.cpp)：泛型 lambda 中 static 变量在不同类型间不共享。
- [20-06-example9-error.cpp](20-06-example9-error.cpp)：lambda 返回类型不一致（预期编译失败）。
- [20-06-example9b.cpp](20-06-example9b.cpp)：用尾置返回类型 `-> double` 修复。
- [20-06-example10.cpp](20-06-example10.cpp)：普通函数 / lambda / `std::greater{}` 三种比较器配合 `std::sort`。
- [20-06-quiz1.cpp](20-06-quiz1.cpp)：Quiz 1 解答——`std::max_element` + lambda 找出最佳学生。
- [20-06-quiz2.cpp](20-06-quiz2.cpp)：Quiz 2 解答——`std::sort` + lambda 把四季按平均气温排序。

> 本节代码为按原文描述重建（原文中的长代码块未能逐字获取），Quiz 1/2 解答依据原文解答重建。

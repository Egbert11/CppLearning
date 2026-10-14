# 13.5 Introduction to overloading the I/O operators

> 原文：https://www.learncpp.com/cpp-tutorial/introduction-to-overloading-the-i-o-operators/

## 核心概念

- **承接上一节的动机**：上一节用辅助函数（`getColorName`）把枚举转成字符串，有两个缺点：得记住函数名，并且调用它会让输出语句变得累赘。
- **运算符重载的定义**：C++ 的一项特性，允许我们为已有运算符定义重载，使这些运算符能作用于我们的程序自定义类型。
- **运算符重载的基本规则**：函数名就是运算符本身；按从左到右的顺序为每个操作数加一个参数（其中至少一个必须是用户自定义类型，即类或枚举，否则编译器报错）；选一个合理的返回类型；返回运算结果。
- **编译器的解析行为**：对于 `x + y` 这样的表达式，编译器用重载解析找到一个匹配的 `operator+(x, y)`；若找到且无歧义就调用它，其返回值即为表达式结果。
- **延伸阅读**：第 21 章详细讲运算符重载；进阶读者可了解把运算符重载为最左操作数的成员函数（21.5 节）。
- **回顾 `operator<<` 如何输出**：在 `std::cout << 5` 中，`std::cout` 的类型是 `std::ostream`、`5` 是 `int`，编译器找到库定义的重载，输出该值，并"返回它的左操作数……以便后续 `operator<<` 调用可以链式继续"。
- **设计 `operator<<` 重载**：左参数是 `std::ostream&` 类型的输出流（非 const 引用：避免拷贝，且流必须被修改）；右参数按值接收枚举；返回类型与左操作数一致，即 `std::ostream&`。
- **参数名用 `out` 的意义**：用 `out` 而不是 `std::cout`，可以让调用者自行选择流，于是 `std::cerr << color` 也能写到 `std::cerr`。
- **改造成输入 `operator>>`**：`std::cin` 的类型是 `std::istream`，所以左参数与返回类型变成 `std::istream&`；枚举参数改为非 const 引用，以便成功提取时能修改真正的右操作数。
- **out 参数洞察**：右操作数（`pet`）是 out 参数；如果按值传递，赋值只会改到副本上。
- **失败处理规则**：若找不到匹配，就用 `in.setstate(std::ios_base::failbit)` 把流置为失败状态，与 `std::cin` 的正常行为一致；调用者可据此检测流。注意提取失败时 `operator>>` 会把基本类型零初始化（原文注释里有一行 `pet = {};` 模拟此行为）。
- **相关技术**：17.6 节展示用 `std::array` 让输入/输出运算符更少冗余，并在新增枚举量时无需改动。

## 最佳实践

本节无 Best practice / Warning 条目。仅有：

- **Key insight**：右操作数 `pet` 是一个 out 参数；按值传递只会改动副本。
- **Related content**：运算符重载详见第 21 章；`std::array` 简化 I/O 运算符见 17.6。
- **For advanced readers**：运算符也可以重载为最左操作数的成员函数（21.5 节）。

## 代码示例

- [13-05-example1.cpp](13-05-example1.cpp)：用辅助函数 `getColorName` 把枚举转成名字打印，输出 `Your shirt is blue`。
- [13-05-example2.cpp](13-05-example2.cpp)：为 `operator<<` 写重载，直接 `std::cout << shirt` 输出 `Your shirt is blue`。
- [13-05-example3.cpp](13-05-example3.cpp)：为 `operator>>` 写重载，教 `std::cin` 读取 `Pet`，并在失败时置流为失败状态。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。原文各示例的预期输出已在 cpp 文件注释中标注。

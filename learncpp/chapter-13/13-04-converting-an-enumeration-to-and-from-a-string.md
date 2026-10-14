# 13.4 Converting an enumeration to and from a string

> 原文：https://www.learncpp.com/cpp-tutorial/converting-an-enumeration-to-and-from-a-string/

## 核心概念

- **枚举默认按整数打印**：因为 `operator<<` 没有针对程序自定义枚举类型的重载，编译器会把枚举量隐式转成整数值再打印。
- **通常这不是我们想要的**：一般目标是输出枚举量的名字（如 `blue`）而不是它的数值；C++ 没有内置办法，必须自己写转换。
- **标准做法——名字查询函数**：写一个接收枚举量、返回其名字字符串的函数；关键是找到"哪个字符串对应哪个枚举量"的机制。
- **两种常用技术**：对枚举做 `switch`，或用数组做查表（数组方法留到 17.6 节 "std::array and enumerations"）。
- **`switch` 可作用于枚举量**：`switch` 可以作用于整数或枚举值，因此天然适合"枚举量→字符串"映射。
- **返回指向字符串字面量的 `string_view` 是安全的**：C 风格字符串字面量的生命周期贯穿整个程序，所以返回到调用者后 `std::string_view` 仍然有效。
- **标记为 `constexpr`**：让函数可以在常量表达式中使用枚举量的名字。
- **更好的语法在后面**：写 `std::cout << getColorName(shirt)` 不如 `std::cout << shirt` 舒服；教会 I/O 运算符处理枚举是 13.5 节的内容。
- **直接输入无作用域枚举会失败**：`Pet` 是程序自定义类型，`std::cin >> pet` 是编译错误——语言不知道如何读取一个 `Pet`。
- **整数输入绕法**：先读整数，再用 `static_cast` 转成对应的枚举类型。
- **先检查范围再转换**：只有在确认 `input` 落在枚举量范围内，才应执行 `static_cast<Pet>(input)`。
- **字符串转枚举需要另一种工具**：不能对字符串 `switch`，最简单的做法是用一串 `if` 比较输入字符串。
- **处理无效输入**：与其加一个专门的 "none/invalid" 枚举量，本节推荐用 `std::optional`；函数返回 `{}` 表示"无值"。
- **大小写敏感**：基本的字符串匹配方案只匹配小写；要不区分大小写，得先把用户输入转成小写。
- **输入重载也留到后面**：和输出一样，更希望直接写 `std::cin >> pet`，这也在 13.5 节讲。

## 最佳实践

本节无 Best practice / Warning 条目。相关 **Reminder / 提示**：

- **Reminder**：因为 C 风格字符串字面量存在于整个程序期间，返回一个"指向该字面量"的 `std::string_view` 是安全的。
- **Advanced readers**：字符串匹配方案只匹配小写字母；例 6 的 `toASCIILowerCase` 可以把输入转成小写以实现大小写不敏感匹配。
- **Related content**：`constexpr` 函数见 F.1；`std::optional` 见 12.15；lambda 见 20.6。

## 代码示例

- [13-04-example1.cpp](13-04-example1.cpp)：默认按整数打印枚举，输出 `Your shirt is 2`。
- [13-04-example2.cpp](13-04-example2.cpp)：用 `constexpr` 的 `switch` 函数把枚举量转成名字，输出 `Your shirt is blue`。
- [13-04-example3-error.cpp](13-04-example3-error.cpp)：`std::cin >> pet` 直接输入枚举是编译错误。
- [13-04-example4.cpp](13-04-example4.cpp)：读整数、范围检查后 `static_cast` 成枚举。
- [13-04-example5.cpp](13-04-example5.cpp)：用 `if` 串 + `std::optional` 把字符串转成枚举。
- [13-04-example6.cpp](13-04-example6.cpp)：进阶辅助函数 `toASCIILowerCase` 实现大小写不敏感匹配。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。原文各示例的预期输出已在 cpp 文件注释中标注。

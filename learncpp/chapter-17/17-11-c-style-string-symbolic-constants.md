# 17.11 C-style string symbolic constants

> 原文：https://www.learncpp.com/cpp-tutorial/c-style-string-symbolic-constants/

## 核心概念

- **创建 C 风格字符串**：用字符串字面量初始化 `char` 数组即可，如 `char name[]{ "Alex" };`，之后可用 `std::cout` 打印。
- **两种符号常量写法**：① 用字符串字面量初始化的 const C 风格数组；② 指向 C 风格字符串字面量的 const 指针。
- **两者的内存行为不同**：虽然结果看起来一样，C++ 处理内存分配的方式略有差异。
- **情形一（const 数组）**：字面量被放进（多半只读的）内存，然后另外分配长度为 5 的数组（4 字符 + 空终止符）并初始化，因此文本存在两份拷贝；由于该 const 值从不被修改，这次拷贝是"低效的"。
- **情形二（const 指针）**：处理方式由实现定义；通常编译器把字符串放进只读内存，并用该地址初始化指针。
- **字面量合并**：为优化起见，相同的字符串字面量可能被合并为一份共享值，于是两个指向相同文本的指针可能保存同一地址。
- **类型推导**：`auto` 与 `auto*` 推导为 `const char*`；`auto&` 推导为 `const char(&)[5]`。
- **输出流对指针的处理**：非 char 指针打印它保存的地址；但对 `char*` 或 `const char*`，流会认为你想输出字符串，于是打印所指向的字符串。
- **常见陷阱**：对 `char` 变量 `c` 打印 `&c`，其类型是 `char*`，会被当作字符串处理；由于 `c` 并非以空终止符结尾，这会造成未定义行为（一直打印垃圾字符直到遇到零字节）。
- **打印地址的变通**：先用 `static_cast<const void*>` 把 char 指针转换掉，再输出。
- **现代建议**：符号常量优先用 `constexpr std::string_view`，它通常同样快（甚至更快），行为也更一致。
- **相关内容**：`void*` 在 19.5 节（Void pointers）介绍；此处用它做转换无需了解其内部细节。

## 最佳实践

- **Best practice**："避免使用 C 风格字符串符号常量，优先用 `constexpr std::string_view`。"（小节标题："Favor `std::string_view` for C-style string symbolic constants"——现代 C++ 几乎没有理由再用 C 风格版本。）
- **Related content**：`void*` 见 19.5 节；此处使用的转换不要求理解其内部细节。
- 本节没有单独的 Warning 或 Author's note。

## 代码示例

- [17-11-example1.cpp](17-11-example1.cpp)：用字面量创建并打印 C 风格字符串（原 Example 1）。
- [17-11-example2.cpp](17-11-example2.cpp)：两种符号常量写法（const 数组 与 const 指针）（原 Example 2）。
- [17-11-example3.cpp](17-11-example3.cpp)：相同字面量可能被合并（原 Example 3）。
- [17-11-example4.cpp](17-11-example4.cpp)：从字面量推导出的三种类型（原 Example 4）。
- [17-11-example5.cpp](17-11-example5.cpp)：`std::cout` 对 `int*` 打印地址、对 `char*` 打印字符串（原 Example 5）。
- [17-11-example6-ub.cpp](17-11-example6-ub.cpp)：打印 `&c` 被当作字符串，演示未定义行为（`-ub`，原 Example 6）。
- [17-11-example7.cpp](17-11-example7.cpp)：用 `static_cast<const void*>` 正确打印 char 指针的地址（原 Example 7）。

> 说明：本节较长代码块按原文描述忠实重建，语义与预期输出一致；地址类输出依平台而定。

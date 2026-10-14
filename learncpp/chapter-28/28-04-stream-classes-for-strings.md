# 28.4 Stream classes for strings

> 原文：https://www.learncpp.com/cpp-tutorial/stream-classes-for-strings/

## 核心概念

- **字符串流类与普通 I/O 并存**：另有一族类让你把熟悉的插入（`<<`）和提取（`>>`）运算符用在与**字符串**相关的操作上。
- **它们和 istream/ostream 一样使用缓冲区**：字符串流把数据存在缓冲区里，但与 `cin`/`cout` 不同，它们"不连接到 I/O 通道"（键盘或显示器等）。
- **主要用途**：常用于先把输出缓冲起来稍后显示，或逐行处理输入。
- **共六个类**：`istringstream`（派生自 `istream`）、`ostringstream`（派生自 `ostream`）、`stringstream`（派生自 `iostream`）处理普通字符；`wistringstream`、`wostringstream`、`wstringstream` 处理宽字符。
- **需要的头文件**：使用字符串流需包含 `<sstream>`。
- **放数据的两种方式**：用插入运算符（`<<`），或用 `str(string)` 函数设置缓冲区内容。
- **取数据的两种方式**：用 `str()` 函数取得整个缓冲区，或用提取运算符（`>>`）。
- **`>>` 会逐个前进**：每次连续提取得到流中的下一个可用值。
- **`str()` 返回全部内容**：即使已经用 `>>` 提取过，`str()` 仍给出整个流的值。
- **字符串/数字转换**：因为 `<<` 和 `>>` 认识所有基本数据类型，所以可以用来把字符串转成数字、把数字转成字符串。
- **清空 stringstream**：可以用 `str("")` 或 `str(std::string{})` 清空缓冲区；之后再调用 `clear()`"通常是个好主意"，因为它重置错误标志。
- **`clear()` 做什么**：重置所有错误标志，把流恢复到 ok 状态（下一节会进一步讲解）。

## 最佳实践

本节无 Best practice / Rule / Warning / Tip 形式的方框。最接近的建议是内联说明：清空 stringstream 后再调用 `clear()`"通常是个好主意"，它会重置错误标志、让流回到 ok 状态。

## 代码示例

- [28-04-example1.cpp](28-04-example1.cpp)：用插入运算符 `<<` 把 `"en garde!\n"` 放进 stringstream（原 Example 1）。
- [28-04-example2.cpp](28-04-example2.cpp)：用 `os.str("en garde!")` 设置缓冲区内容（原 Example 2）。
- [28-04-example3.cpp](28-04-example3.cpp)：用 `str()` 取出整个缓冲区；输出 `12345 67.89`（原 Example 3）。
- [28-04-example4.cpp](28-04-example4.cpp)：用 `>>` 逐个取值并加短横连接；输出 `12345 - 67.89`（原 Example 4）。
- [28-04-example5.cpp](28-04-example5.cpp)：把 int/double 写进流再以字符串取出（数字 → 字符串）；输出 `12345 67.89`（原 Example 5）。
- [28-04-example6.cpp](28-04-example6.cpp)：把数字文本插入流再提取为 int/double（字符串 → 数字）；输出 `12345 67.89`（原 Example 6）。
- [28-04-example7.cpp](28-04-example7.cpp)：用 `str("")` 清空缓冲区后再写入；输出 `World!`（原 Example 7）。
- [28-04-example8.cpp](28-04-example8.cpp)：用 `str(std::string{})` 清空缓冲区；输出 `World!`（原 Example 8）。
- [28-04-example9.cpp](28-04-example9.cpp)：清空缓冲区并 `clear()` 重置错误标志后再写入（原 Example 9）。

> 说明：本节代码取自原文 HTML 逐字抽取（`<pre>` 块），并补上必要的 `#include <sstream>` / `<iostream>` / `<string>`，包进 `main()` 以便独立编译；原 Example 1/2/7/8/9 是片段，未显示输出语句，这里为可运行而补上 `std::cout << os.str()`（在注释中标出）。

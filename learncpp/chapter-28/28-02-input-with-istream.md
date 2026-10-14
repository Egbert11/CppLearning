# 28.2 Input with istream

> 原文：https://www.learncpp.com/cpp-tutorial/input-with-istream/

## 核心概念

- **本节范围**：iostream 库很庞大，本节只讲最常用的部分，重点是输入类 `istream`。
- **提取运算符 `>>`**：用于从输入流中取出数据。C++ 为所有内建类型定义了这些操作，也可为用户自定义类重载。
- **缓冲区溢出风险**：用 `>>` 读到固定大小的 `char` 缓冲区是危险的，因为库不会假设用户会输入多少个字符。
- **manipulator（操纵器）的定义**："manipulator 是一个对象，在与提取（`>>`）或插入（`<<`）运算符配合使用时会修改流。" 你已经用过的 `std::endl` 就是一个操纵器。
- **`std::endl`**：输出一个换行符并刷新缓冲区。
- **`setw`**：声明于 `<iomanip>`；传入一个最大数量即可限制从流中读取的字符数。
- **跳过空白**：提取运算符会跳过空格、制表符和换行符。
- **`get()`（单字符）**：从输入流取一个字符，**不丢弃空白**。
- **`get()`（字符串重载）**：接收一个缓冲区及要读取的最大字符数（含结尾的空字符位置）。
- **`get()` 与换行符**：`get()` **不会**消费换行符，这会导致后续读取出现意外行为。
- **`getline()`**：与 `get()` 类似，但会额外提取（丢弃）分隔符（换行符）。
- **`gcount()`**：返回上一次 `getline()` 提取了多少个字符，"gcount() 包含被提取并丢弃的分隔符"。
- **`std::getline()`（用于 `std::string`）**：声明于 `<string>`，是**非成员**版本，既不属于 `ostream` 也不属于 `istream`。
- **其它有用的 istream 成员**：`ignore()`、`ignore(nCount)`、`peek()`、`unget()`、`putback(char ch)`；cppreference 上还有更多。

## 最佳实践

本节无 Best practice / Rule / Warning / Tip 形式的方框。最接近的建议是内联提示："对用户会输入多少字符做任何假设都不是好主意。"

## 代码示例

- [28-02-example1-broken.cpp](28-02-example1-broken.cpp)：用 `>>` 读取到固定大小缓冲区 `char buf[10]`，用户输入过长会缓冲区溢出（原 Example 1，坏实践）。
- [28-02-example2.cpp](28-02-example2.cpp)：用 `std::setw(10)` 限制读取长度（原 Example 2）。
- [28-02-example3.cpp](28-02-example3.cpp)：`while (std::cin >> ch)` 演示提取运算符跳过空白；输入 `Hello my name is Alex`，输出 `HellomynameisAlex`（原 Example 3）。
- [28-02-example4.cpp](28-02-example4.cpp)：`while (std::cin.get(ch))` 保留空白；同样输入，输出 `Hello my name is Alex`（原 Example 4）。
- [28-02-example5.cpp](28-02-example5.cpp)：`std::cin.get(strBuf, 11)` 只读 10 个字符；输入 `Hello my name is Alex`，输出 `Hello my n`（原 Example 5）。
- [28-02-example6.cpp](28-02-example6.cpp)：连续两次 `get(strBuf, 11)`；输入 `Hello!` 时第二次立即停止（第一个未读字符是换行符）（原 Example 6）。
- [28-02-example7.cpp](28-02-example7.cpp)：改用 `std::cin.getline(strBuf, 11)`，可正确消费换行符（原 Example 7）。
- [28-02-example8.cpp](28-02-example8.cpp)：用 `std::cin.gcount()` 报告上次 `getline()` 读了多少字符（原 Example 8）。
- [28-02-example9.cpp](28-02-example9.cpp)：用非成员 `std::getline(std::cin, str)` 把整行读进 `std::string`（原 Example 9）。

> 说明：本节示例均为需要标准输入的交互式程序，代码取自原文 HTML 逐字抽取（`<pre>` 块），并补上必要的 `#include`；运行时应按注释中的示例输入进行验证。

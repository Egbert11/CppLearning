# 28.6 Basic file I/O

> 原文：https://www.learncpp.com/cpp-tutorial/basic-file-io/

## 核心概念

- **文件 I/O 与普通 I/O 很像**：工作方式与其他流 I/O 类似，只是多了"一些小的额外复杂性"。
- **三个文件 I/O 类**：`ifstream` 派生自 `istream`（输入）、`ofstream` 派生自 `ostream`（输出）、`fstream` 派生自 `iostream`（读写皆可）。原文称其为"3 个基本文件 I/O 类"。
- **需要的头文件**：必须包含 `fstream` 头。
- **文件流需要显式建立**：标准流（`cout`、`cin`、`cerr`、`clog`）开箱即用，但文件流必须由程序员创建。
- **打开文件**：实例化对应类的对象，把文件名作为构造函数参数传入——"极其简单"。
- **读写**：用插入运算符（`<<`）写、用提取运算符（`>>`）读。
- **关闭文件**：显式调用 `close()`，或让流变量离开作用域——"文件 I/O 类的析构函数会替你关闭文件"。
- **检查是否成功打开**：若打开失败，流会转换为 `false`，因此用 `if (!outf)` 就能捕获错误并向 `std::cerr` 打印。
- **写单个字符**：`put()` 函数可向文件写一个字符。
- **输入时的 EOF 行为**：`ifstream` 在文件末尾返回 0，可利用这一点控制读多少（现代 C++ 更准确的说法是流到 bool 的转换）。
- **提取遇空白即停**：用 `>>` 是按"词"读取的，所以回显文件时各行会被拆成一个个单词。
- **读整行**：要读整行，用流上的 `getline()` 函数。
- **缓冲输出的定义**：输出可能是**带缓冲**的：输出操作"可能被攒在一起统一处理"，而不是立即写盘，主要是为了性能。
- **flush（刷新）**：把缓冲区写盘叫 flush 缓冲区；关闭文件会先 flush 再关闭。
- **缓冲的风险**：如果程序崩溃或在数据还在缓冲区时调用 `exit()`，析构函数不会运行、文件不会关闭、缓冲区不会 flush，于是"缓冲区里的数据不会写入磁盘，永久丢失"。因此调用 `exit()` 前应显式关闭打开的文件。
- **手动 flush**：可用 `ostream::flush()` 函数，或向流发送 `std::flush`——在程序可能崩溃时有用。
- **`std::endl` 也会 flush**：由于它无条件 flush，在文件写入等带缓冲 I/O 中滥用 `std::endl` 会影响性能；注重性能的程序员改用 `'\n'`。
- **重新打开会覆盖**：再次运行输出示例会完全覆盖已有文件。
- **文件模式**：构造函数可带第二个"模式"参数；有效的标志属于 `ios` 类：`app`（追加）、`ate`（读写前先移到文件末尾）、`binary`（二进制而非文本模式）、`in`（读；`ifstream` 默认）、`out`（写；`ofstream` 默认）、`trunc`（清空已有文件）。
- **组合模式**：多个标志用按位或 `|` 组合。
- **默认模式**：`ifstream` = `std::ios::in`；`ofstream` = `std::ios::out`；`fstream` = `std::ios::in | std::ios::out`，默认即可读写。
- **显式打开**：正如有 `close()`，也有 `open()` 显式打开流，接收文件名与可选模式，行为与构造函数相同。

## 最佳实践

本节无形式化的 Best practice / Author's note / Warning 方框。原文以内联建议给出：

- **Tip（关于 fstream）**：由于 fstream 的设计方式，使用 `std::ios::in` 且目标文件不存在时可能失败；要创建新文件，应只用 `std::ios::out`。
- 调用 `exit()` 前应显式关闭打开的文件——崩溃或 `exit()` 会跳过析构函数，缓冲区数据"永久丢失"。
- 输出流中优先用 `'\n'` 而非 `std::endl`，以避免不必要的缓冲区刷新及其性能开销。

## 代码示例

- [28-06-example1.cpp](28-06-example1.cpp)：用 `ofstream` 写 `Sample.txt` 的两行，并检查 `if (!outf)`（原 Example A）。
- [28-06-example2.cpp](28-06-example2.cpp)：用 `ifstream` + `>>` 按词读取；每个词单独一行（原 Example B）。
- [28-06-example3.cpp](28-06-example3.cpp)：用 `std::getline(inf, strInput)` 按行读取；输出两整行（原 Example C）。
- [28-06-example4.cpp](28-06-example4.cpp)：用 `std::ios::app` 追加第 3、4 行（原 Example D）。
- [28-06-example5.cpp](28-06-example5.cpp)：显式 `close()` 再 `open(..., std::ios::app)` 的片段（原 Example E）。

> 说明：本节代码取自原文 HTML 逐字抽取（`<pre>` 块），并补上必要的头文件、`main()`（Example E 为片段，已包进 `main()`）。示例 1/4/5 需要在工作目录下生成 `Sample.txt`；示例 2/3 需要先存在 `Sample.txt`。

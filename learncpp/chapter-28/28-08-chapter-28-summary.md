# 28.x Chapter 28 summary and quiz

> 原文：https://www.learncpp.com/cpp-tutorial/chapter-28-summary-and-quiz/ （**截至抓取时该地址返回 404**）

> **重要说明**：抓取时（2026-10）learncpp.com 的目录中，Chapter 28 只到 28.7，**没有官方的 `28.x` 总结/测验小节**——该 URL 返回 404，WordPress 接口也查询不到 `chapter-28-summary-and-quiz` 这个 slug（Chapters 26、27 都有各自的 summary-and-quiz，唯独 28 尚未发布）。因此本文件是**根据本章 28.1–28.7 内容自拟的知识速览与自测题**，并非官方原文，特此注明。

## 本章知识速览

- **流（stream）**：可按顺序访问的字节序列。I/O 由标准库（`std` 命名空间）提供，不属于核心语言。输入流保存来自生产者（键盘/文件/网络）的数据，输出流保存交给消费者（显示器/文件/打印机）的数据。
- **标准流**：`cin`（stdin，键盘）、`cout`（stdout，显示器）、`cerr`（stderr，无缓冲）、`clog`（stderr，有缓冲）。
- **输入（28.2）**：提取运算符 `>>` 会跳过空白；`get()` 不丢空白、不消费换行符；`getline()` 会丢弃分隔符；`gcount()` 报告上次 `getline()` 读了多少字符（含被丢弃的分隔符）；`std::setw(n)`（`<iomanip>`）限制读取长度；非成员 `std::getline(std::cin, std::string&)` 用于整行读入（`<string>`）。把输入读进定长 `char` 缓冲区很危险，应限制长度。
- **输出格式化（28.3）**：两种手段——标志（`setf` / `unsetf`）与操纵器。常用：`boolalpha`、`showpos`、`uppercase`、`dec/hex/oct`（basefield 组，互斥）、`fixed/scientific/showpoint`、`setprecision`、`setw/width`、`fill/setfill`、`left/right/internal`。`setf` 只开不清，切互斥标志要用双参数 `setf(flag, group)` 或先 `unsetf`。`setw`/`width` 只影响下一条语句。
- **字符串流（28.4）**：`<sstream>` 提供 `istringstream`/`ostringstream`/`stringstream`（及宽字符版本）。用 `<<` 或 `str(string)` 放数据，用 `str()` 或 `>>` 取数据；可在字符串与数字之间相互转换。清空用 `str("")` 或 `str(std::string{})`，随后 `clear()` 重置错误标志。
- **流状态与输入验证（28.5）**：状态标志 `goodbit`/`badbit`/`eofbit`/`failbit`，查询用 `good()`/`bad()`/`eof()`/`fail()`，重置用 `clear()`，读取用 `rdstate()`。输入验证分字符串验证与数值验证；可用 `<cctype>` 的 `isalpha`/`isdigit`/`isspace` 等；数值验证可用提取 + `fail()`，失败后 `clear()` 再 `ignore()` 重试；用 `gcount()` 拒绝 `34abcd` 这类混合输入；也可读成字符串再用 `std::from_chars`（`<charconv>`）解析。
- **基本文件 I/O（28.6）**：`<fstream>` 的 `ifstream`/`ofstream`/`fstream`。用构造函数（或 `open()`）打开、`close()` 或析构关闭；`if (!stream)` 检查打开是否成功；模式有 `app/ate/binary/in/out/trunc`，用 `|` 组合。输出是带缓冲的：崩溃或 `exit()` 会丢失未 flush 的数据，故调用 `exit()` 前应显式关闭文件；注重性能用 `'\n'` 而非 `std::endl`。
- **随机文件 I/O（28.7）**：文件指针标记当前读写位置。`seekg()`/`seekp()` 移动指针，第二参数用 `beg`/`cur`/`end`（默认 `beg`）；`tellg()`/`tellp()` 返回绝对位置（可求文件大小）。文本文件中定位到非开头位置可能有意料之外的行为（换行编码差异），应优先用于二进制文件。用 `fstream` 混合读写时，切换读写必须经过一次改变位置的操作（可 seek 到当前位置）。不要把内存地址写入文件。`is_open()` 判断是否打开，`remove()` 删除文件。

## 测验

> 以下为**自拟**测验题（官方 28.x 尚未发布），解答代码见对应 quiz cpp。

1. 写一个程序，提示用户输入一行可能包含空格的文本，然后原样回显该行。（提示：非成员 `std::getline`。）
2. 用 `std::stringstream` 把字符串 `"12345 67.89"` 解析为一个 `int` 和一个 `double`，并把它们打印出来（两者之间一个空格）。
3. 用 `std::cout` 把整数 `27` 分别按十六进制、八进制、十进制打印，再把浮点数 `123.456` 用 `std::fixed` 加 `std::setprecision(3)` 打印出来。

解答：

- [28-08-quiz1.cpp](28-08-quiz1.cpp)：第 1 题——用 `std::getline(std::cin, str)` 读整行并回显。
- [28-08-quiz2.cpp](28-08-quiz2.cpp)：第 2 题——用 `std::stringstream` + `>>` 做字符串 → 数字转换，输出 `12345 67.89`。
- [28-08-quiz3.cpp](28-08-quiz3.cpp)：第 3 题——用 `std::hex`/`std::oct`/`std::dec` 与 `std::fixed`/`std::setprecision` 格式化输出。

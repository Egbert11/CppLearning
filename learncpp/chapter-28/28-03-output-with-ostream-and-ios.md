# 28.3 Output with ostream and ios

> 原文：https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/

## 核心概念

- **插入运算符 `<<`**：用于把信息放进输出流。C++ 为内建类型定义了它，也可为用户自定义类重载。
- **继承关系**：`istream` 与 `ostream` 都派生自 `ios`。`ios` / `ios_base` 类用于控制输出的格式化。
- **两种格式化机制**：格式化既可用 **flags（标志）**，也可用 **manipulators（操纵器）**。标志像开关；操纵器是放进流中、影响输入输出的对象。
- **打开标志**：用 `setf()` 加上目标标志。例如 `std::ios::showpos` 让正数打印出前导 `+`。
- **一次打开多个标志**：用按位或 `|` 组合，如 `std::ios::showpos | std::ios::uppercase`。
- **关闭标志**：用 `unsetf()` 加该标志关闭它。
- **format group（格式组）**：一组针对同类或互斥格式选择的标志。"basefield" 组包含 `oct`、`dec`、`hex`，默认是 `dec`。
- **`setf()` 的局限**：`setf()` 只能打开标志，可能无法清除组中已激活的互斥标志。例如在 `dec` 仍打开时尝试设置 `hex`，输出可能仍是十进制。
- **变通方法 1**：先关掉组里不要的那个标志，再打开想要的标志。
- **变通方法 2**：用双参数 `setf(flag, group)`，它会清除该组全部标志、只设置传入的那个。
- **操纵器通常更省事**：它们足够智能，能正确地打开/关闭相关标志。有些选项只能通过标志或只能通过操纵器设置，因此两者都值得了解。
- **有用的格式化类别**：布尔格式（`boolalpha`/`noboolalpha`）、符号格式（`showpos`/`noshowpos`）、大小写格式（`uppercase`/`nouppercase`）、进制格式（`dec`/`hex`/`oct`）、浮点格式（`fixed`/`scientific`/`showpoint`）、对齐（`internal`/`left`/`right`）、字段控制（`setfill`/`setw`/`precision`/`fill`/`width`）。
- **`fixed` 或 `scientific` 下的 precision**：precision 控制显示几位小数；若 precision 小于有效数字位数则四舍五入。
- **无 `fixed` / `scientific` 时的 precision**：precision 控制显示几位有效数字；低于有效数字位数时同样四舍五入。
- **`showpoint` 规则**：让浮点输出总是带小数点并补齐尾随零。
- **字段宽度与对齐**：字段宽度定义该值在输出中占据的字符数；太小的值会按对齐规则补白，太大的值会溢出而不会被截断。
- **默认对齐**：默认右对齐；`internal` 会让符号左对齐、数值右对齐。
- **持久性说明**：`setw()` / `width()` 只影响下一个输出语句；而填充字符一旦设置会跨多个语句生效。
- **原文还附有一张表**：展示正常、`showpoint`、`fixed`、`scientific` 四种模式与 precision 组合时，`12345.0`、`0.12345` 等值的显示结果。

## 最佳实践

本节无 Best practice / Rule / Warning / Tip 形式的方框。原文以内联规则给出：

- 记住 `setw()` / `width()` 只影响下一条输出语句，而填充字符会持续生效。

## 代码示例

- [28-03-example1.cpp](28-03-example1.cpp)：用 `setf(std::ios::showpos)` 打开前导加号；输出 `+27`（原 Example 1）。
- [28-03-example2.cpp](28-03-example2.cpp)：用 `|` 一次打开 `showpos | uppercase`；输出 `+1.23457E+06`（原 Example 2）。
- [28-03-example3.cpp](28-03-example3.cpp)：`unsetf()` 关闭标志；输出 `+27` 然后 `28`（原 Example 3）。
- [28-03-example4.cpp](28-03-example4.cpp)：直接用 `setf(std::ios::hex)` 想切十六进制会失败；输出仍是 `27`（原 Example 4）。
- [28-03-example5.cpp](28-03-example5.cpp)：先 `unsetf(std::ios::dec)` 再 `setf(std::ios::hex)`；输出 `1b`（原 Example 5）。
- [28-03-example6.cpp](28-03-example6.cpp)：双参数 `setf(std::ios::hex, std::ios::basefield)`；输出 `1b`（原 Example 6）。
- [28-03-example7.cpp](28-03-example7.cpp)：用操纵器 `std::hex` / `std::dec` 切换进制；输出 `1b`、`1c`、`29`（原 Example 7）。
- [28-03-example8.cpp](28-03-example8.cpp)：布尔格式 `boolalpha` / `noboolalpha`；输出 `1 0`、`true false`、`1 0`、`true false`（原 Example 8）。
- [28-03-example9.cpp](28-03-example9.cpp)：符号格式 `showpos` / `noshowpos`；输出 `5`、`+5`、`5`、`+5`（原 Example 9）。
- [28-03-example10.cpp](28-03-example10.cpp)：大小写格式 `uppercase` / `nouppercase`；原文输出 `1.23457e+007`、`1.23457E+007` 等（原 Example 10）。**注意**：GCC 输出的科学计数法指数至少两位（`1.23457e+07`），MSVC（原文所用）为三位，属编译器/平台差异，本机实测见文末。
- [28-03-example11.cpp](28-03-example11.cpp)：basefield 组的标志与操纵器写法；输出 `27 27 33 1b 27 33 1b`（原 Example 11）。
- [28-03-example12.cpp](28-03-example12.cpp)：`fixed` / `scientific` 下 `setprecision` 控制小数位；原文输出如 `123.456`…与 `1.235e+002`…（原 Example 12）。**注意**：`scientific` 的指数位数同 Example 10，GCC 为 `1.235e+02`（两位），MSVC 为 `e+002`（三位），属平台差异。
- [28-03-example13.cpp](28-03-example13.cpp)：无 `fixed` / `scientific` 时 `setprecision` 控制有效数字；输出 `123`、`123.5`、`123.46`…（原 Example 13）。
- [28-03-example14.cpp](28-03-example14.cpp)：`showpoint` 让浮点总带小数点；输出 `123.`、`123.5`…（原 Example 14）。
- [28-03-example15.cpp](28-03-example15.cpp)：字段宽度与 `left` / `right` / `internal` 对齐；原 Example 15 输出 `-12345`、`    -12345`、`-12345`、`    -12345`、`-    12345`。
- [28-03-example16.cpp](28-03-example16.cpp)：用 `fill('*')` 设置填充字符；原 Example 16 输出 `-12345`、`****-12345`、`-12345****`、`****-12345`、`-****12345`（原 Example 16）。

> 说明：本节示例代码取自原文 HTML 逐字抽取（`<pre>` 块），并补上必要的 `#include <iostream>` / `#include <iomanip>`，包进 `main()` 以便独立编译。示例 15/16 的原始输出以原文逐字块为准（填充宽度为 10，`-12345` 占 6 字符，故为 4 个填充符）。
>
> **本机（GCC 15.2，-std=c++20 -Wall）实测输出**：示例 1–9、11、13–16 与原文逐字一致；示例 10/12 的科学计数法指数按 GCC 规则为两位（如 `1.23457e+07`、`1.235e+02`），与原文 MSVC 的三位（`e+007`、`e+002`）不同，其余数值完全相同。

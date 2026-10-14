# 9.3 Common semantic errors in C++

> 原文：https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/

## 核心概念

- **语法错误（syntax error）**：代码违反 C++ 语法的错误。编译器会报告出来，因此容易发现、通常也容易改正。
- **语义错误（semantic error）**：代码没有做到作者意图的错误。编译器通常发现不了，但聪明的编译器可能给出警告。
- **语义错误的可能后果**：它可能表现得像未定义行为——输出错误、行为古怪、数据损坏、崩溃，有时甚至毫无可见影响。
- **要预期会犯错**：写语义错误几乎是不可避免的；运行程序并测试有助于发现它们（例如平台游戏里角色穿墙而过）。
- **学习常见的那几类**：了解最常见的错误类别，就能重点复查这些地方；它们大多与控制流有关。
- **条件逻辑错误**：条件语句或循环条件的逻辑写错了。
- **无限循环**：循环条件永远不为假，导致永远运行下去（例如漏写自增）。
- **无符号循环计数器陷阱**：用 `unsigned` 循环变量做倒计时，由于该类型的值不可能为负，循环永远不会终止。
- **off-by-one 错误**：循环多运行一次或少运行一次，常因选错了关系运算符。
- **运算符优先级错误**：混用运算符而不加括号会改变表达式的分组方式；例如逻辑非 `!` 比 `>` 结合得更紧。**用显式括号消除歧义**。
- **浮点精度问题**：`float` 可能没有足够精度精确表示某个值，于是被舍入。
- **浮点相等比较**：用 `==` 或 `!=` 比较浮点数不可靠，因为微小的舍入误差会累积。
- **整数除法**：两个整数操作数相除得到整数结果；用 `static_cast` 把其中一个操作数转成浮点即可得到真正的除法。
- **意外的空语句（null statement）**：条件后多写的一个分号使后面的语句脱离条件，从而无条件执行。
- **缺少复合语句（缺花括号）**：没有花括号时，只有第一条语句属于 `if`，其后的语句总会执行。"dangling else" 是相关情形。
- **条件中误用赋值代替相等**：`=` 返回其左操作数，因此放在 `if` 里的赋值通常求值为真。现代编译器常对此告警。
- **忘记函数调用运算符 `()`**：只写函数名而不加 `()` 会得到一个函数指针，它转换为 `bool` 的 `true`（打印为 `1`）。

## 最佳实践

本节无 Best practice / Rule / Warning / Tip 提示框。原文仅有一处 **For advanced readers** 说明：在函数名上不使用调用运算符一般会得到函数指针，它会隐式转换为 `bool`，其值总是 `true`（参见 20.1 节）。此外正文以 **What else?** 段落邀请读者在评论区补充其他常见陷阱。

正文中隐含的实践指导：混用逻辑运算符时使用显式括号；不要忽略编译器警告。

## 代码示例

- [9-03-example1-broken.cpp](9-03-example1-broken.cpp)：条件逻辑错误——本该用 `>` 却用了 `>=`，输入 `5` 时输出 `5 is greater than 5`。
- [9-03-example2-broken.cpp](9-03-example2-broken.cpp)：`for (int count{ 1 }; count > x; ++count)` 用了 `>` 而非 `<`，正数输入下什么都不打印。
- [9-03-example3-broken.cpp](9-03-example3-broken.cpp)：`while` 循环漏写自增，条件永不为假，反复打印 `1`（无限循环）。
- [9-03-example4-broken.cpp](9-03-example4-broken.cpp)：`for (unsigned int count{ 5 }; count >= 0; --count)` 的无符号倒计时，超过 0 后回绕成 `4294967295`（无限循环）。
- [9-03-example5-broken.cpp](9-03-example5-broken.cpp)：off-by-one——本该 `<=` 却用了 `<`，打印 `1 2 3 4` 而非 `1 2 3 4 5`。
- [9-03-example6-broken.cpp](9-03-example6-broken.cpp)：优先级错误——`!x > y` 实际按 `(!x) > y` 求值，打印 `5 is greater than 7`。
- [9-03-example7.cpp](9-03-example7.cpp)：`float f{ 0.123456789f };` 精度不足，打印 `0.123457`。
- [9-03-example8-broken.cpp](9-03-example8-broken.cpp)：`if (d == 1.0)` 浮点相等比较的舍入误差，打印 `not equal`。
- [9-03-example9-broken.cpp](9-03-example9-broken.cpp)：意外的整数除法，打印 `5 divided by 3 is: 1`。
- [9-03-example10-broken.cpp](9-03-example10-broken.cpp)：`if (c == 'y');` 之后多出的分号（空语句），使 `blowUpWorld()` 无条件执行，打印 `Kaboom!`。
- [9-03-example11-broken.cpp](9-03-example11-broken.cpp)：缺少复合语句——`if` 只守护那条 `cout`，`blowUpWorld()` 总执行，打印 `Kaboom!`。
- [9-03-example12-broken.cpp](9-03-example12-broken.cpp)：`if (c = 'y')` 用赋值代替相等，条件总为真，被守护的调用总执行。
- [9-03-example13-broken.cpp](9-03-example13-broken.cpp)：漏写调用运算符——`std::cout << getValue` 打印 `1`（部分编译器上打印的是内存地址）。

> 说明：本节代码为按原文描述**忠实重建**（抓取工具无法逐字返回完整代码块）。
> 后缀 `-broken` 表示该文件演示的是有意的坏实践/语义错误，能正常编译，但输出不符合作者意图。

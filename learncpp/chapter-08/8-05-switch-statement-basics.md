# 8.5 Switch statement basics

> 原文：https://www.learncpp.com/cpp-tutorial/switch-statement-basics/

## 核心概念

- **链式 if-else 的缺点**：把一个变量与许多值比较时，变量会被反复求值，读者还必须逐次确认测的是同一个变量。
- **switch 的用途**：C++ 提供了一种专门用于"testing a variable or expression for equality against a set of different values"的条件语句。
- **switch 的工作方式**：先求值括号里的条件（得到一个值），然后发生三件事之一。
- **规则 1 — 匹配到 case 标签**：若值等于某个 case 标签后的值，则执行该标签之后的语句。
- **规则 2 — default 标签**：若都不匹配但存在 default 标签，则执行 default 之后的语句。
- **规则 3 — 无匹配且无 default**：整个 switch 被跳过。
- **switch 的写法**：`switch` 关键字后跟括号，括号内是要求值的条件；通常是单个变量，但任何合法表达式都可以。
- **类型限制**：条件必须是整型或枚举类型，或能转换为其中之一。浮点、字符串以及大多数非整型都不允许。
- **进阶（为何限制整型）**：switch 是为优化而设计的，编译器历史上用跳转表（jump table）实现，而跳转表"only work with integral values"。编译器并非必须使用跳转表，C++ 理论上也可放宽该限制，但实际上一直没这么做。
- **switch 主体与标签**：条件之后是一个块；块内的标签定义要测试的相等值。标签有两种：case 与 default。
- **case 标签**：用 `case` 加一个常量表达式声明，该表达式必须与条件类型匹配或可转换。
- **顺序执行**：匹配后，执行"begins at the first statement after that `case` label and then continues sequentially."
- **唯一性规则**：同一个 switch 中所有 case 标签必须唯一；重复值（包括转换为同一整数的值，如 `54` 与 `'6'`）会报错。
- **无匹配则无 case 执行**：若条件与任何 case 标签都不匹配，则没有 case 语句会执行。
- **default 标签**：用 `default` 声明；可选、每个 switch 至多一个、习惯上放在最后。
- **走出 switch**：无匹配且无 default 时，执行在 switch 块之后继续。
- **break 语句**：用 `break` 声明，它表示 switch 中的语句执行到此为止；执行在 switch 块之后继续，从而可以退出 switch 而不退出整个函数。
- **标签缩进约定**：花括号建立作用域并缩进，但标签不定义嵌套作用域，因此标签之后的代码习惯上不缩进。
- **为什么不缩进标签**：把标签和语句缩进到同一层会难以看出每个 case 的起止；把语句缩进到标签下面虽然可读，却会误导性地暗示存在嵌套作用域。
- **switch 与 if-else 的取舍**：switch 适合用单个非布尔整型/枚举表达式与小集合的值做相等比较；case 太多会伤害可读性。if-else 则灵活得多。

**if / if-else 通常更合适的情形**：非相等比较（如 `x > 5`）；测试多个条件（如 `x == 5 && y == 6`）；范围检查（如 `x >= 5 && x <= 10`）；不支持的类型（如 `d == 4.0`）；以及布尔表达式。

## 最佳实践

- **Best practice**："Place the default case last in the switch block."
- **Best practice**："Each set of statements underneath a label should end in a break-statement or a return-statement. This includes the statements underneath the last label in the switch."
- **Best practice**："Prefer not to indent labels. This allows them to stand out from the surrounding code without implying that they are defining a nested scope region."
- **Best practice**："Prefer a switch-statement over if-else statements when testing a single expression (with a non-boolean integral type or an enumerated type) for equality against a small set of values."

本节无 Warning / Author's note 条目；只有一个 "For advanced readers" 跳转表说明（见"核心概念"第 9 条）。

## 代码示例

- [8-05-example1.cpp](8-05-example1.cpp)：if-else 版本的 `printDigitName(int x)`。
- [8-05-example2.cpp](8-05-example2.cpp)：改写成 switch（含原文示例 3 的注释标注 "Two"）。
- [8-05-example4.cpp](8-05-example4.cpp)：无 case 匹配、执行 default（输出 "Unknown"）。
- [8-05-example5.cpp](8-05-example5.cpp)：无匹配且无 default，switch 被跳过（输出 "Hello"）。
- [8-05-example6.cpp](8-05-example6.cpp)：用 `break` 代替 `return`，函数继续执行（输出 "Three Ah-Ah-Ah!"）。
- [8-05-example9.cpp](8-05-example9.cpp)：推荐标签排版。
- [8-05-example10-error.cpp](8-05-example10-error.cpp)：重复 case 标签（`case 54` 与 `case '6'`）—— 预期编译失败。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。原文示例 7、8 仅为排版变体（不可读版 / 可接受但不推荐版），未单独生成文件，其要点记入"核心概念"。

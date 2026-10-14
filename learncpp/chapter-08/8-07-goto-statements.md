# 8.7 Goto statements

> 原文：https://www.learncpp.com/cpp-tutorial/goto-statements/

## 核心概念

- **无条件跳转（unconditional jump）**：一种把执行移到代码中另一位置的控制流动作。它区别于 `if`/`switch`，因为它总是发生，而不取决于某个表达式的结果。
- **goto 语句**：C++ 中实现无条件跳转的机制。目标位置用**语句标签（statement label）**命名，标签的书写约定与 switch 的 case 标签相同：不缩进。
- **标签的函数作用域**：这是与局部/块作用域、文件/全局作用域并列的第三类作用域。标签在它所在函数的任何地方都可见，甚至在其书写位置之前。
- **必须同函数**：`goto` 与它指向的标签必须在同一个函数里；不允许在函数之间跳转。
- **标签必须标注一条语句**：由于标签要附着在一条语句上，若后面没有语句，就用一个 `;`（空语句）。
- **无需前置声明**：因为标签具有函数作用域，你可以跳到源码中更靠后才出现的标签，不必提前声明。
- **向前跳转的限制**：不能向前跳过某个变量的初始化，而该变量在标签所在位置仍处于作用域内——跳过初始化会让变量值未定义。
- **向后跳过初始化是允许的**：向后跳过某个初始化是合法的，执行再次到达该初始化时会重新初始化该变量。
- **风格建议**：C++ 及其他现代高层语言都不鼓励使用 `goto`。任意的跳转会产生纠缠不清的"意大利面条式代码"（spaghetti code），难以推敲。
- **值得一提的例外**：`goto` 可能最清晰的一种情况是——在不退出整个函数的前提下跳出多层嵌套循环。

## 最佳实践

- **Best practice**："Avoid goto statements (unless the alternatives are significantly worse for code readability)."
- **Author's note**：原文以朋友 xkcd 的一则关于 `goto` 的漫画作为幽默插曲（https://xkcd.com/292/ ）。
- 原文还引用了 Edsger W. Dijkstra 的论文 "Go To Statement Considered Harmful"，其中一句名言大意是：程序员的质量是其所写代码中 go to 语句密度的递减函数。绝大多数 `goto` 代码都能用 `if` 语句、循环等结构写得更清晰。

## 代码示例

- [8-07-example1.cpp](8-07-example1.cpp)：向后 goto——反复提示直到输入非负数。
- [8-07-example2.cpp](8-07-example2.cpp)：向前跳转跳过打印语句，标签 `end` 后跟空语句。
- [8-07-example3-error.cpp](8-07-example3-error.cpp)：非法的向前跳转越过变量初始化 —— 预期编译失败。
- [8-07-example4.cpp](8-07-example4.cpp)：进阶——用 goto 一次性跳出多层嵌套循环。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。

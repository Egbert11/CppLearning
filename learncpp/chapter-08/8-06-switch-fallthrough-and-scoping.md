# 8.6 Switch fallthrough and scoping

> 原文：https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/

## 核心概念

- **执行从哪里开始**：当 switch 表达式匹配到某个 case 标签（或可选的 default 标签）时，执行从匹配标签后的第一条语句开始。
- **随后顺序继续**：从那里起，执行顺序向下继续，直到遇到终止条件。
- **终止条件**：执行会在以下情况停止——到达 switch 块末尾；遇到一条离开该块或函数的控制流语句（通常是 `break` 或 `return`）；或发生其他打断正常流程的情况。
- **case 标签不是终止符**：出现另一个 case 标签并不会终止执行，所以没有 `break` 或 `return` 时控制流会落入后面的 case。
- **fallthrough（贯穿）**："When execution flows from a statement underneath a label into statements underneath a subsequent label, this is called **fallthrough**."
- **fallthrough 通常是不想要的**：多数编译器与分析工具会把它标为警告，因为它很少是有意为之。
- **注释标记有意的贯穿**：这是一种常见约定，用来告知其他开发者，但编译器和分析工具读不懂注释，警告依旧存在。
- **`[[fallthrough]]` 属性**：C++17 引入。属性给编译器提供额外信息；名字写在双方括号之间，属性不是语句，但可以出现在任何上下文合适的地方。
- **`[[fallthrough]]` 的用法**：它修饰一条空语句以表明贯穿是有意的，于是不应产生警告（注意结尾的分号）。
- **堆叠（顺序）的 case 标签**：可以把多个 case 标签排在一起，让它们共享后面的语句；效果类似用逻辑或组合多个测试，但 switch 表达式只求值一次。
- **堆叠标签不算 fallthrough**：因为 case 标签是标签而非语句，这样共享语句不构成 fallthrough，因此不需要注释或属性。
- **标签不创建作用域**：与 `if` 不同（if 后面那条单独的语句像是位于一个块内），switch 标签之后的所有语句都属于 switch 块，不会创建隐式块。
- **在 switch 中声明变量**：在 case 标签之前和之后都可以声明或定义（注意不是初始化）变量。
- **共享的 switch 作用域**：switch 内每条语句共享同一个作用域，因此某个 case 中定义的变量可以在后面的 case 里使用——即使 switch 跳过了定义它的那个 case。
- **初始化限制**：初始化要求定义语句被执行，因此除最后一个 case 外，任何 case 中都不允许初始化变量；第一个 case 标签之前也不允许，因为执行可能跳过它而留下未定义的变量（未定义行为）。
- **推荐的修正办法**：把变量的定义与初始化放进该 case 语句下方的显式块中。

## 最佳实践

- **Warning**："Once the statements underneath a case or default label have started executing, they will overflow (fallthrough) into subsequent cases. break or return statements are typically used to prevent this."
- **Best practice**："Use the `[[fallthrough]]` attribute (along with a null statement) to indicate intentional fallthrough."
- **Best practice**："If defining variables used in a case statement, do so in a block inside the case."

## 代码示例

- [8-06-example1.cpp](8-06-example1.cpp)：fallthrough 演示——无 `break`/`return`，输出 2、3、4、5。
- [8-06-example2.cpp](8-06-example2.cpp)：用 C++17 的 `[[fallthrough]]` 标记有意的贯穿。
- [8-06-example3.cpp](8-06-example3.cpp)：用 `||` 重复相等比较判断元音。
- [8-06-example4.cpp](8-06-example4.cpp)：用堆叠的 case 标签实现同一元音判断。
- [8-06-example5.cpp](8-06-example5.cpp)：`if` 后单条语句被隐式视作在块中。
- [8-06-example6.cpp](8-06-example6.cpp)：switch 标签不创建隐式块。
- [8-06-example7-error.cpp](8-06-example7-error.cpp)：switch 中变量定义与初始化的限制 —— 预期编译失败。
- [8-06-example8.cpp](8-06-example8.cpp)：最安全做法——在 case 下用显式块初始化变量。
- [8-06-example9-quiz.cpp](8-06-example9-quiz.cpp)：本节 quiz 解答——用 switch 实现简单计算器。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。

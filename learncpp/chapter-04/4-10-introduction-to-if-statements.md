# 4.10 Introduction to if statements

> 原文：https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/

## 核心概念

- **条件语句（开篇类比）**：逛市场的例子说明“只在满足某条件时才做某事”，例如“如果有草莓促销就买一些”。这类条件让程序能实现条件行为。
- **if 语句的定义**：if 语句让我们在某个条件为真时才执行一（或多）行代码，是 C++ 中最简单的条件语句。
- **基本语法**：`if (condition) true_statement;`；为了可读性通常把语句写在下一行并缩进。
- **条件 / 条件表达式**：一个求值为布尔值的表达式。
- **执行规则**：条件为 `true` 则执行 true-statement；为 `false` 则跳过该语句。
- **相等运算符（`==`）**：测试两个值是否相等，相等返回 `true`，不等返回 `false`。
- **if-else 形式**：`if (condition) true_statement; else false_statement;`——条件为真执行前者，否则执行后者。用两条独立 if（或 bool 变量加 `if`/`if (!...)`）比必要的更复杂。
- **串联 if**：可把 if 或 if-else 附加到前面的 if-else 上，依次判断多种可能，如 `if (...) ... else if (...) ... else ...`；有多少条件就可以串多长。
- **关系运算符**：`<`（小于）测试一个值是否小于另一个，`>`（大于）同理；二者都返回布尔值。
- **以布尔函数作条件**：条件也可以是一个返回类型为 `bool` 的函数调用，例如 `if (isEqual(x, y))`。
- **非布尔条件**：若条件表达式不是布尔值，其结果会被转换：非零变为 `true`，零变为 `false`。
- **提前返回（early return）**：不是函数中最后一条语句的 return 语句。它在执行时把控制权立即交还给调用者。
- **无条件提前返回**：没有用处——若 `return;` 总会被执行，它之后的语句是死代码，应当删除。
- **配合 if 的提前返回**：可以让函数的返回值变为条件性的。历史上提前返回曾被诟病，但在现代编程中更被接受，尤其是当它能简化函数或在出错时提前中止时。
- **Quiz 要点**：(1) 提前返回是出现在函数最后一行之前的 return；(2) 用一串 if-else 写质数判断；(3) 永远不需要 `if (condition) return true; else return false;`——可替换为 `return condition;`。

## 最佳实践

（原文主要标注为 Warning / Key insight / Related content / For advanced readers。）

- **Warning**：if 语句只能有条件地执行**一条**语句。要按条件执行多条语句，见 8.2 课（If statements and blocks）。
- **Key insight**：`if (x)` 的含义是“如果 x 非零/非空”。
- **相关**：提前返回的争论详见 8.11 课（Break and continue）；if 语句的进一步探讨见 8.2 课。
- **进阶读者**：啰嗦的 `isPrime()` 可用逻辑或运算符（6.8 课）或 switch 语句（8.5 课）写得更紧凑。
- **Quiz 解答注**：形如 `if (condition) return true; else return false;` 的写法永远不需要，写成 `return condition` 即可。

## 代码示例

- [4-10-example1.cpp](4-10-example1.cpp)：基本 if，判断输入是否为 0。
- [4-10-example2.cpp](4-10-example2.cpp)：用两条独立 if 分别处理 0 与非 0。
- [4-10-example3.cpp](4-10-example3.cpp)：用 bool 变量实现同样逻辑。
- [4-10-example4.cpp](4-10-example4.cpp)：改写为 if-else。
- [4-10-example5.cpp](4-10-example5.cpp)：串联 if-else，判断正/负/零。
- [4-10-example6.cpp](4-10-example6.cpp)：上一课的 isEqual（用 cout，不用 if）。
- [4-10-example7.cpp](4-10-example7.cpp)：用 if-else 改进的 isEqual。
- [4-10-example8.cpp](4-10-example8.cpp)：非布尔条件（int 转换为 bool）。
- [4-10-example9.cpp](4-10-example9.cpp)：无条件的提前返回（没有用处）。
- [4-10-example10.cpp](4-10-example10.cpp)：在 abs() 中有条件地使用提前返回。
- [4-10-example11.cpp](4-10-example11.cpp)：Quiz #2 解法：啰嗦版 isPrime（串联 if-else）。
- [4-10-example12.cpp](4-10-example12.cpp)：进阶：用逻辑或写紧凑版 isPrime。
- [4-10-example13.cpp](4-10-example13.cpp)：进阶：用 switch 写紧凑版 isPrime。
- [4-10-example14.cpp](4-10-example14.cpp)：Quiz #3：原始的游乐设施程序。
- [4-10-example15.cpp](4-10-example15.cpp)：Quiz #3 解法：直接返回条件。

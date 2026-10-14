# 8.8 Introduction to loops and while statements

> 原文：https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/

## 核心概念

- **循环（loops）**："control flow constructs that allow a piece of code to execute repeatedly until some condition is met." 它带来灵活性，能实现原本很难做到的事。
- **为什么需要循环**：硬编码打印 1–10 可以，1–1000 就不行，而"1 到用户输入的那个数"更不可能——因为那个值在编译期不可知。
- **while 语句语法**：`while (condition)` 后跟一条语句。它是 C++ 三种循环里最简单的，定义方式与 if 语句类似。
- **执行流程**：先求值条件；为真则执行语句。"unlike an if-statement"，控制流随即回到顶部并重复，因此只要条件保持为真就一直循环。
- **一开始就为假**：如果第一次求值条件就为假，"the associated statement will not execute at all."
- **无限循环**：当表达式总为真时，循环"will execute forever"。
- **有意的无限循环**：写成 `while (true)`。原文指出退出只能通过 return 语句、break 语句、exit 语句、goto 语句、抛出的异常，或用户杀掉进程。
- **意外的无限循环**："Unintentionally placing a semicolon after the condition of a while-loop is a good way to hang your program." 此时循环体变成空语句。
- **有意使用空语句**：偶尔有用，例如反复调用某个函数直到它返回 false。若它永不返回 false，就变成无限循环。
- **循环变量（loop variable）**："a variable that is used to control how many times a loop executes." 多数是 `int`，偶尔用 `char`。
- **命名**：常见简单名字 `i`、`j`、`k`，它们源自 Fortran 中最短的一批整型变量名。搜索它们会带来噪音，因此有些开发者用 `iii`、`jjj`、`kkk`，而"an even better idea"是使用实义名，如 `count` 或 `userCount`。
- **计数器（counter）**："a loop variable that counts how many times a loop has executed."
- **符号性规则**：整型循环变量几乎总应当是带符号的，因为无符号类型会带来意外问题（具体说，倒计时循环因回绕而永远不结束）。
- **迭代（iteration）**："Each time a loop executes, it is called an iteration." 借助对计数器的取余运算，很容易做到"每 N 次迭代做某事"。
- **嵌套循环（nested loops）**：循环可以嵌套在其他循环里。在循环体内调用一个自身含循环的函数，也算一种嵌套。
- **内层变量的作用域**：把内层循环变量声明在块内，则每次外层迭代都会重新创建并初始化它；原文建议把变量声明在"the smallest scope possible"。

## 最佳实践

- **Best practice（有意的无限循环）**："Favor `while(true)` for intentional infinite loops."
- **Warning（while 条件后的分号）**："Be careful about placing a semicolon after the condition of a while-statement, as it will result in an infinite loop unless the condition some way to evaluate to `false`."
- **Best practice（循环变量的符号性）**："Integral loop variables should generally be a signed integral type."
- **Author's aside**：`i`、`j`、`k` 的名字源自 Fortran 中最早出现的三个最短整型变量名，此后成为惯例。

## 代码示例

- [8-08-example1.cpp](8-08-example1.cpp)：不用循环，硬编码打印 1–10。
- [8-08-example2.cpp](8-08-example2.cpp)：基本 while 循环，从 1 数到 10。
- [8-08-example3.cpp](8-08-example3.cpp)：条件一开始就为假，循环体不执行。
- [8-08-example4-infinite.cpp](8-08-example4-infinite.cpp)：意外的无限循环（忘了递增）——请勿直接运行。
- [8-08-example6.cpp](8-08-example6.cpp)：有意的无限循环 + 用 return 退出（同时含原文示例 5 的 `while (true)` 骨架说明）。
- [8-08-example7-infinite.cpp](8-08-example7-infinite.cpp)：while 条件后误加分号导致无限循环（同时含原文示例 8 的等价写法）——请勿直接运行。
- [8-08-example9.cpp](8-08-example9.cpp)：有意的空循环体 `while (keepRunning());`。
- [8-08-example10-infinite.cpp](8-08-example10-infinite.cpp)：无符号倒计时 bug，`count >= 0` 永远为真——请勿直接运行。
- [8-08-example11.cpp](8-08-example11.cpp)：每 10 次迭代换行并补前导 0。
- [8-08-example12.cpp](8-08-example12.cpp)：通过辅助函数实现的嵌套循环。
- [8-08-example13.cpp](8-08-example13.cpp)：直接嵌套的 while 循环。
- [8-08-example14-quiz.cpp](8-08-example14-quiz.cpp)：quiz 第 2 题——打印小写字母与 ASCII 码。
- [8-08-example15-quiz.cpp](8-08-example15-quiz.cpp)：quiz 第 3 题——倒三角。
- [8-08-example16-quiz.cpp](8-08-example16-quiz.cpp)：quiz 第 4 题——右对齐的数字三角形。

## 测验

1. **quiz 第 1 题**：解释为什么 `inner` 要声明在 while 循环体内（原文解答无代码）。答案要点：这样它每次外层迭代都会重新创建并初始化为 1；若声明在前面，则每次都要手动重置，而它也只在这里用到。
2. **quiz 第 2 题**：写一个程序打印 `a` 到 `z` 以及它们的 ASCII 码。解答见 [8-08-example14-quiz.cpp](8-08-example14-quiz.cpp)。
3. **quiz 第 3 题**：用嵌套循环打印倒三角（5 4 3 2 1 / 4 3 2 1 / …）。解答见 [8-08-example15-quiz.cpp](8-08-example15-quiz.cpp)。
4. **quiz 第 4 题**：打印右对齐的数字三角形。解答见 [8-08-example16-quiz.cpp](8-08-example16-quiz.cpp)。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。原文示例 5 是 `while (true)` 的骨架片段，已并入 [8-08-example6.cpp](8-08-example6.cpp) 的注释说明；原文示例 8 是示例 7 的等价写法，已并入 [8-08-example7-infinite.cpp](8-08-example7-infinite.cpp)。

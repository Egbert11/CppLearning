# 8.1 Control flow introduction

> 原文：https://www.learncpp.com/cpp-tutorial/control-flow-introduction/

## 核心概念

- **程序执行的基本模型**：程序运行时 CPU 从 `main()` 顶部开始，默认按顺序自上而下执行若干语句，到 `main()` 末尾停止。
- **执行路径（execution path，简称 path）**：CPU 实际执行的那串语句序列。
- **直线式程序（straight-line program）**：每次运行都走同一条路线、按同样顺序执行同样语句的程序。
- **直线式程序的局限**：像"反复处理非法输入"这类问题无法实现，因为需要重复的次数在运行期才可知。
- **控制流语句（control flow statements，又称 flow control statements）**：允许程序员改变正常执行路径的语句；第 4.10 节的 if 语句就已经属于这一类。
- **分支（branching）**：当控制流语句把执行点移到一条非顺序的语句时，称为分支。
- **控制流语句的六大类别**：本章除"异常"外全部覆盖，异常在第 27 章单独讲解。

| 类别 | 含义 | C++ 中的实现 |
|---|---|---|
| 条件语句（Conditional statements） | 仅在满足条件时执行一段代码 | `if`、`else`、`switch` |
| 跳转（Jumps） | 指示 CPU 到别处继续执行 | `goto`、`break`、`continue` |
| 函数调用（Function calls） | 跳到别处执行后再返回 | 函数调用、`return` |
| 循环（Loops） | 重复执行一段代码，零次或多次，直到条件满足 | `while`、`do-while`、`for`、range-based `for` |
| 停止（Halts） | 终止程序 | `std::exit()`、`std::abort()` |
| 异常（Exceptions） | 面向错误处理的特殊控制流结构 | `try`、`throw`、`catch` |

- **本章的意义**：在学本章之前，程序行为非常受限；掌握控制流（尤其是循环）之后才能写出真正有用的程序，而不只是玩具程序。

## 最佳实践

本节无 Best practice / Warning 条目。原文仅说明异常处理留到后续章节，以及本章将覆盖其余五类控制流。

## 代码示例

- [8-01-example1.cpp](8-01-example1.cpp)：一个直线式程序，读取一个整数并把它回显出来，用来演示可预测的执行路径。

> 说明：本节代码为按原文描述**忠实重建**（抓取工具无法逐字返回完整代码块）。

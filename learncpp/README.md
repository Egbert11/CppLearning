# LearnCpp.com 中文整理笔记（全站）

整理自 <https://www.learncpp.com/>，覆盖官网**全部章节**：第 1–28 章，外加两个选学章 —— Chapter O（Bit Manipulation，位于第 6 章之后）与 Chapter F（Constexpr functions，位于第 11 章之后）。

共 **322 个小节笔记**、约 **2200 个源码文件**（cpp + 头文件，含 52 个多文件示例子文件夹）。

- 每个小节一份中文核心内容笔记（`X-YY-slug.md`），含：核心概念、最佳实践、代码示例索引、原文链接；总结小节另含「本章知识速览 + 测验」。
- 每个有意义的示例一份源码（`X-YY-exampleN.cpp`），文件头注明来源小节与说明；多文件示例放在同名子文件夹内（如 `2-11-example1/`），整文件夹一起编译。
- 绝大多数源码可用 `g++ -std=c++20 -Wall` 编译。例外（均为刻意演示错误或需特殊条件，文件头已注明，请勿"修复"）：
  - `chapter-01/1-01-example2.cpp` — 演示语法错误，**无法编译**（预期行为）。
  - 带 `-error` 后缀 — 预期编译失败；带 `-linkerror` 后缀 — 能编译但预期链接失败（如 `chapter-26/26-01-example3-linkerror/`）；带 `-broken` / `-ub` 后缀 — 演示坏实践 / 未定义行为（可编译，运行结果依实现而定）。
  - 带 `-warning` 后缀 — 编译通过但预期产生特定警告；带 `-overflow` 后缀（仅 chapter-20）— 可编译，**运行会栈溢出，请勿运行**。
  - `chapter-03/3-05-example3-plog.cpp` — 依赖第三方 plog 日志库（`-plog` 后缀），不参与独立构建。
  - `chapter-O/O-03-example13-opengl.cpp` — 需 `g++ ... -lopengl32` 链接 OpenGL。
  - `chapter-05/5-03-example9.cpp`、`chapter-21/21-09-example6-cpp23.cpp` — 需 `g++ -std=c++23`（GCC 15 编译 std::print 示例还需 `-lstdc++exp`）。
  - `chapter-17/17-13-example8-cpp23.cpp` — 演示 `std::mdspan`，需带 `<mdspan>` 实现的 C++23 工具链（本机 GCC 15.2 尚无该头文件，无法本地编译）。
  - `chapter-16/16-03-example1-error.cpp`、`chapter-17/17-07-example7-error.cpp` — GCC 15 默认把这两处 ill-formed 降级接受（列表初始化窄化只给警告；零长数组视作扩展），需加 `-pedantic-errors` 才能按预期报错。
  - 少数文件保留原文固有的教学警告（无后缀，md 中已注明）：`chapter-25/25-02-quiz1.cpp`、`chapter-25/25-03-example1.cpp`（`-Woverloaded-virtual`）、`chapter-26/26-04-example1.cpp`（`-Wmisleading-indentation`）、`chapter-27/27-05-example2/7/8.cpp`（未使用变量）。
  - `chapter-26/26-01-example4/` — 特殊编译方式：只编译 `templates.cpp`（其内 `#include "Array.cpp"`）。
- 官网状态说明：Chapter 18（迭代器与算法）、19（动态内存分配）官网尚在建设中，小节数量少且无总结小节；Chapter 28 的 `28.x` 总结页官网尚未发布（404），`chapter-28/28-08-chapter-28-summary.md` 为按统一格式**自拟**的总结与测验；Chapter 21 的 `21.y`（15-Puzzle 项目小节）未收录。
- 说明：部分小节的抓取工具限制了长代码块的逐字输出，对应示例是按原文描述与该站标准示例忠实重建的，语义与预期输出一致；第 20–28 章多数小节已用原始 HTML 逐字抽取还原（各 md 中如实注明）。GCC 与原文（MSVC）在科学计数法指数位数等输出细节上有差异，相关 md 已注明。
- 本目录为独立整理内容，未被根目录 Makefile 纳入构建（Makefile 只编译 `.` 与 `SourceFiles/`），不影响仓库原有代码。
## Chapter 1 — C++ Basics

| 小节 | 主题 | 笔记 |
|---|---|---|
| 1.1 | 语句与程序结构 | [chapter-01/1-01-statements-and-the-structure-of-a-program.md](chapter-01/1-01-statements-and-the-structure-of-a-program.md) |
| 1.2 | 注释 | [chapter-01/1-02-comments.md](chapter-01/1-02-comments.md) |
| 1.3 | 对象与变量入门 | [chapter-01/1-03-introduction-to-objects-and-variables.md](chapter-01/1-03-introduction-to-objects-and-variables.md) |
| 1.4 | 变量赋值与初始化 | [chapter-01/1-04-variable-assignment-and-initialization.md](chapter-01/1-04-variable-assignment-and-initialization.md) |
| 1.5 | iostream：cout、cin 与 endl | [chapter-01/1-05-introduction-to-iostream-cout-cin-and-endl.md](chapter-01/1-05-introduction-to-iostream-cout-cin-and-endl.md) |
| 1.6 | 未初始化变量与未定义行为 | [chapter-01/1-06-uninitialized-variables-and-undefined-behavior.md](chapter-01/1-06-uninitialized-variables-and-undefined-behavior.md) |
| 1.7 | 关键字与标识符命名 | [chapter-01/1-07-keywords-and-naming-identifiers.md](chapter-01/1-07-keywords-and-naming-identifiers.md) |
| 1.8 | 空白与基本格式 | [chapter-01/1-08-whitespace-and-basic-formatting.md](chapter-01/1-08-whitespace-and-basic-formatting.md) |
| 1.9 | 字面量与运算符入门 | [chapter-01/1-09-introduction-to-literals-and-operators.md](chapter-01/1-09-introduction-to-literals-and-operators.md) |
| 1.10 | 表达式入门 | [chapter-01/1-10-introduction-to-expressions.md](chapter-01/1-10-introduction-to-expressions.md) |
| 1.11 | 开发你的第一个程序 | [chapter-01/1-11-developing-your-first-program.md](chapter-01/1-11-developing-your-first-program.md) |
| 1.x | 第 1 章总结与测验 | [chapter-01/1-12-chapter-1-summary-and-quiz.md](chapter-01/1-12-chapter-1-summary-and-quiz.md) |

## Chapter 2 — C++ Basics: Functions and Files

| 小节 | 主题 | 笔记 |
|---|---|---|
| 2.1 | 函数入门 | [chapter-02/2-01-introduction-to-functions.md](chapter-02/2-01-introduction-to-functions.md) |
| 2.2 | 函数返回值 | [chapter-02/2-02-function-return-values-value-returning-functions.md](chapter-02/2-02-function-return-values-value-returning-functions.md) |
| 2.3 | void 函数 | [chapter-02/2-03-void-functions-non-value-returning-functions.md](chapter-02/2-03-void-functions-non-value-returning-functions.md) |
| 2.4 | 函数形参与实参 | [chapter-02/2-04-introduction-to-function-parameters-and-arguments.md](chapter-02/2-04-introduction-to-function-parameters-and-arguments.md) |
| 2.5 | 局部作用域入门 | [chapter-02/2-05-introduction-to-local-scope.md](chapter-02/2-05-introduction-to-local-scope.md) |
| 2.6 | 为什么函数有用 | [chapter-02/2-06-why-functions-are-useful-and-how-to-use-them-effectively.md](chapter-02/2-06-why-functions-are-useful-and-how-to-use-them-effectively.md) |
| 2.7 | 前向声明与定义 | [chapter-02/2-07-forward-declarations.md](chapter-02/2-07-forward-declarations.md) |
| 2.8 | 多代码文件的程序 | [chapter-02/2-08-programs-with-multiple-code-files.md](chapter-02/2-08-programs-with-multiple-code-files.md) |
| 2.9 | 命名冲突与命名空间 | [chapter-02/2-09-naming-collisions-and-an-introduction-to-namespaces.md](chapter-02/2-09-naming-collisions-and-an-introduction-to-namespaces.md) |
| 2.10 | 预处理器入门 | [chapter-02/2-10-introduction-to-the-preprocessor.md](chapter-02/2-10-introduction-to-the-preprocessor.md) |
| 2.11 | 头文件 | [chapter-02/2-11-header-files.md](chapter-02/2-11-header-files.md) |
| 2.12 | 头文件保护（header guards） | [chapter-02/2-12-header-guards.md](chapter-02/2-12-header-guards.md) |
| 2.13 | 如何设计你的第一批程序 | [chapter-02/2-13-how-to-design-your-first-programs.md](chapter-02/2-13-how-to-design-your-first-programs.md) |
| 2.x | 第 2 章总结与测验 | [chapter-02/2-14-chapter-2-summary-and-quiz.md](chapter-02/2-14-chapter-2-summary-and-quiz.md) |

## Chapter 3 — Debugging C++ Programs

| 小节 | 主题 | 笔记 |
|---|---|---|
| 3.1 | 语法错误与语义错误 | [chapter-03/3-01-syntax-and-semantic-errors.md](chapter-03/3-01-syntax-and-semantic-errors.md) |
| 3.2 | 调试流程 | [chapter-03/3-02-the-debugging-process.md](chapter-03/3-02-the-debugging-process.md) |
| 3.3 | 调试策略 | [chapter-03/3-03-a-strategy-for-debugging.md](chapter-03/3-03-a-strategy-for-debugging.md) |
| 3.4 | 基本调试手段 | [chapter-03/3-04-basic-debugging-tactics.md](chapter-03/3-04-basic-debugging-tactics.md) |
| 3.5 | 更多调试手段 | [chapter-03/3-05-more-debugging-tactics.md](chapter-03/3-05-more-debugging-tactics.md) |
| 3.6 | 集成调试器：单步执行 | [chapter-03/3-06-using-an-integrated-debugger-stepping.md](chapter-03/3-06-using-an-integrated-debugger-stepping.md) |
| 3.7 | 集成调试器：运行与断点 | [chapter-03/3-07-using-an-integrated-debugger-running-and-breakpoints.md](chapter-03/3-07-using-an-integrated-debugger-running-and-breakpoints.md) |
| 3.8 | 集成调试器：监视变量 | [chapter-03/3-08-using-an-integrated-debugger-watching-variables.md](chapter-03/3-08-using-an-integrated-debugger-watching-variables.md) |
| 3.9 | 集成调试器：调用栈 | [chapter-03/3-09-using-an-integrated-debugger-the-call-stack.md](chapter-03/3-09-using-an-integrated-debugger-the-call-stack.md) |
| 3.10 | 在问题发生前发现它 | [chapter-03/3-10-finding-issues-before-they-become-problems.md](chapter-03/3-10-finding-issues-before-they-become-problems.md) |
| 3.x | 第 3 章总结与测验 | [chapter-03/3-11-chapter-3-summary-and-quiz.md](chapter-03/3-11-chapter-3-summary-and-quiz.md) |

## Chapter 4 — Fundamental Data Types

| 小节 | 主题 | 笔记 |
|---|---|---|
| 4.1 | 基本数据类型入门 | [chapter-04/4-01-introduction-to-fundamental-data-types.md](chapter-04/4-01-introduction-to-fundamental-data-types.md) |
| 4.2 | void | [chapter-04/4-02-void.md](chapter-04/4-02-void.md) |
| 4.3 | 对象大小与 sizeof | [chapter-04/4-03-object-sizes-and-the-sizeof-operator.md](chapter-04/4-03-object-sizes-and-the-sizeof-operator.md) |
| 4.4 | 有符号整数 | [chapter-04/4-04-signed-integers.md](chapter-04/4-04-signed-integers.md) |
| 4.5 | 无符号整数（及为何避免） | [chapter-04/4-05-unsigned-integers-and-why-to-avoid-them.md](chapter-04/4-05-unsigned-integers-and-why-to-avoid-them.md) |
| 4.6 | 定宽整数与 size_t | [chapter-04/4-06-fixed-width-integers-and-size-t.md](chapter-04/4-06-fixed-width-integers-and-size-t.md) |
| 4.7 | 科学计数法入门 | [chapter-04/4-07-introduction-to-scientific-notation.md](chapter-04/4-07-introduction-to-scientific-notation.md) |
| 4.8 | 浮点数 | [chapter-04/4-08-floating-point-numbers.md](chapter-04/4-08-floating-point-numbers.md) |
| 4.9 | 布尔值 | [chapter-04/4-09-boolean-values.md](chapter-04/4-09-boolean-values.md) |
| 4.10 | if 语句入门 | [chapter-04/4-10-introduction-to-if-statements.md](chapter-04/4-10-introduction-to-if-statements.md) |
| 4.11 | 字符（char） | [chapter-04/4-11-chars.md](chapter-04/4-11-chars.md) |
| 4.12 | 类型转换与 static_cast | [chapter-04/4-12-introduction-to-type-conversion-and-static_cast.md](chapter-04/4-12-introduction-to-type-conversion-and-static_cast.md) |
| 4.x | 第 4 章总结与测验 | [chapter-04/4-13-chapter-4-summary-and-quiz.md](chapter-04/4-13-chapter-4-summary-and-quiz.md) |

## Chapter 5 — Constants and Strings

| 小节 | 主题 | 笔记 |
|---|---|---|
| 5.1 | 常量变量（命名常量） | [chapter-05/5-01-constant-variables-named-constants.md](chapter-05/5-01-constant-variables-named-constants.md) |
| 5.2 | 字面量 | [chapter-05/5-02-literals.md](chapter-05/5-02-literals.md) |
| 5.3 | 进制系统（十/二/十六/八进制） | [chapter-05/5-03-numeral-systems-decimal-binary-hexadecimal-and-octal.md](chapter-05/5-03-numeral-systems-decimal-binary-hexadecimal-and-octal.md) |
| 5.4 | as-if 规则与编译期优化 | [chapter-05/5-04-the-as-if-rule-and-compile-time-optimization.md](chapter-05/5-04-the-as-if-rule-and-compile-time-optimization.md) |
| 5.5 | 常量表达式 | [chapter-05/5-05-constant-expressions.md](chapter-05/5-05-constant-expressions.md) |
| 5.6 | constexpr 变量 | [chapter-05/5-06-constexpr-variables.md](chapter-05/5-06-constexpr-variables.md) |
| 5.7 | std::string 入门 | [chapter-05/5-07-introduction-to-stdstring.md](chapter-05/5-07-introduction-to-stdstring.md) |
| 5.8 | std::string_view 入门 | [chapter-05/5-08-introduction-to-stdstring_view.md](chapter-05/5-08-introduction-to-stdstring_view.md) |
| 5.9 | std::string_view（续） | [chapter-05/5-09-stdstring_view-part-2.md](chapter-05/5-09-stdstring_view-part-2.md) |
| 5.x | 第 5 章总结与测验 | [chapter-05/5-10-chapter-5-summary-and-quiz.md](chapter-05/5-10-chapter-5-summary-and-quiz.md) |

## Chapter 6 — Operators（运算符）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 6.1 | Operator precedence and associativity | [6-01-operator-precedence-and-associativity.md](chapter-06/6-01-operator-precedence-and-associativity.md) |
| 6.2 | Arithmetic operators | [6-02-arithmetic-operators.md](chapter-06/6-02-arithmetic-operators.md) |
| 6.3 | Remainder and Exponentiation | [6-03-remainder-and-exponentiation.md](chapter-06/6-03-remainder-and-exponentiation.md) |
| 6.4 | Increment/decrement operators, and side effects | [6-04-increment-decrement-operators-and-side-effects.md](chapter-06/6-04-increment-decrement-operators-and-side-effects.md) |
| 6.5 | The comma operator | [6-05-the-comma-operator.md](chapter-06/6-05-the-comma-operator.md) |
| 6.6 | The conditional operator | [6-06-the-conditional-operator.md](chapter-06/6-06-the-conditional-operator.md) |
| 6.7 | Relational operators and floating point comparisons | [6-07-relational-operators-and-floating-point-comparisons.md](chapter-06/6-07-relational-operators-and-floating-point-comparisons.md) |
| 6.8 | Logical operators | [6-08-logical-operators.md](chapter-06/6-08-logical-operators.md) |
| 6.x | 第 6 章总结与测验 | [6-09-chapter-6-summary-and-quiz.md](chapter-06/6-09-chapter-6-summary-and-quiz.md) |

## Chapter O — Bit Manipulation (optional chapter)（位操作（选学））

| 小节 | 主题 | 笔记 |
|---|---|---|
| O.1 | Bit flags and bit manipulation via std::bitset | [O-01-bit-flags-and-bit-manipulation-via-stdbitset.md](chapter-O/O-01-bit-flags-and-bit-manipulation-via-stdbitset.md) |
| O.2 | Bitwise operators | [O-02-bitwise-operators.md](chapter-O/O-02-bitwise-operators.md) |
| O.3 | Bit manipulation with bitwise operators and bit masks | [O-03-bit-manipulation-with-bitwise-operators-and-bit-masks.md](chapter-O/O-03-bit-manipulation-with-bitwise-operators-and-bit-masks.md) |
| O.4 | Converting integers between binary and decimal representation | [O-04-converting-integers-between-binary-and-decimal-representation.md](chapter-O/O-04-converting-integers-between-binary-and-decimal-representation.md) |

## Chapter 7 — Scope, Duration, and Linkage（作用域、生存期与链接）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 7.1 | Compound statements (blocks) | [7-01-compound-statements-blocks.md](chapter-07/7-01-compound-statements-blocks.md) |
| 7.2 | User-defined namespaces and the scope resolution operator | [7-02-user-defined-namespaces-and-the-scope-resolution-operator.md](chapter-07/7-02-user-defined-namespaces-and-the-scope-resolution-operator.md) |
| 7.3 | Local variables | [7-03-local-variables.md](chapter-07/7-03-local-variables.md) |
| 7.4 | Introduction to global variables | [7-04-introduction-to-global-variables.md](chapter-07/7-04-introduction-to-global-variables.md) |
| 7.5 | Variable shadowing (name hiding) | [7-05-variable-shadowing-name-hiding.md](chapter-07/7-05-variable-shadowing-name-hiding.md) |
| 7.6 | Internal linkage | [7-06-internal-linkage.md](chapter-07/7-06-internal-linkage.md) |
| 7.7 | External linkage and variable forward declarations | [7-07-external-linkage-and-variable-forward-declarations.md](chapter-07/7-07-external-linkage-and-variable-forward-declarations.md) |
| 7.8 | Why (non-const) global variables are evil | [7-08-why-non-const-global-variables-are-evil.md](chapter-07/7-08-why-non-const-global-variables-are-evil.md) |
| 7.9 | Inline functions and variables | [7-09-inline-functions-and-variables.md](chapter-07/7-09-inline-functions-and-variables.md) |
| 7.10 | Sharing global constants across multiple files (using inline variables) | [7-10-sharing-global-constants-across-multiple-files-using-inline-variables.md](chapter-07/7-10-sharing-global-constants-across-multiple-files-using-inline-variables.md) |
| 7.11 | Static local variables | [7-11-static-local-variables.md](chapter-07/7-11-static-local-variables.md) |
| 7.12 | Scope, duration, and linkage summary | [7-12-scope-duration-and-linkage-summary.md](chapter-07/7-12-scope-duration-and-linkage-summary.md) |
| 7.13 | Using declarations and using directives | [7-13-using-declarations-and-using-directives.md](chapter-07/7-13-using-declarations-and-using-directives.md) |
| 7.14 | Unnamed and inline namespaces | [7-14-unnamed-and-inline-namespaces.md](chapter-07/7-14-unnamed-and-inline-namespaces.md) |
| 7.x | 第 7 章总结与测验 | [7-15-chapter-7-summary-and-quiz.md](chapter-07/7-15-chapter-7-summary-and-quiz.md) |

## Chapter 8 — Control Flow（控制流）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 8.1 | Control flow introduction | [8-01-control-flow-introduction.md](chapter-08/8-01-control-flow-introduction.md) |
| 8.2 | If statements and blocks | [8-02-if-statements-and-blocks.md](chapter-08/8-02-if-statements-and-blocks.md) |
| 8.3 | Common if statement problems | [8-03-common-if-statement-problems.md](chapter-08/8-03-common-if-statement-problems.md) |
| 8.4 | Constexpr if statements | [8-04-constexpr-if-statements.md](chapter-08/8-04-constexpr-if-statements.md) |
| 8.5 | Switch statement basics | [8-05-switch-statement-basics.md](chapter-08/8-05-switch-statement-basics.md) |
| 8.6 | Switch fallthrough and scoping | [8-06-switch-fallthrough-and-scoping.md](chapter-08/8-06-switch-fallthrough-and-scoping.md) |
| 8.7 | Goto statements | [8-07-goto-statements.md](chapter-08/8-07-goto-statements.md) |
| 8.8 | Introduction to loops and while statements | [8-08-introduction-to-loops-and-while-statements.md](chapter-08/8-08-introduction-to-loops-and-while-statements.md) |
| 8.9 | Do while statements | [8-09-do-while-statements.md](chapter-08/8-09-do-while-statements.md) |
| 8.10 | For statements | [8-10-for-statements.md](chapter-08/8-10-for-statements.md) |
| 8.11 | Break and continue | [8-11-break-and-continue.md](chapter-08/8-11-break-and-continue.md) |
| 8.12 | Halts (exiting your program early) | [8-12-halts-exiting-your-program-early.md](chapter-08/8-12-halts-exiting-your-program-early.md) |
| 8.13 | Introduction to random number generation | [8-13-introduction-to-random-number-generation.md](chapter-08/8-13-introduction-to-random-number-generation.md) |
| 8.14 | Generating random numbers using Mersenne Twister | [8-14-generating-random-numbers-using-mersenne-twister.md](chapter-08/8-14-generating-random-numbers-using-mersenne-twister.md) |
| 8.15 | Global random numbers (Random.h) | [8-15-global-random-numbers-random-h.md](chapter-08/8-15-global-random-numbers-random-h.md) |
| 8.x | 第 8 章总结与测验 | [8-16-chapter-8-summary-and-quiz.md](chapter-08/8-16-chapter-8-summary-and-quiz.md) |

## Chapter 9 — Error Detection and Handling（错误检测与处理）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 9.1 | Introduction to testing your code | [9-01-introduction-to-testing-your-code.md](chapter-09/9-01-introduction-to-testing-your-code.md) |
| 9.2 | Code coverage | [9-02-code-coverage.md](chapter-09/9-02-code-coverage.md) |
| 9.3 | Common semantic errors in C++ | [9-03-common-semantic-errors-in-c.md](chapter-09/9-03-common-semantic-errors-in-c.md) |
| 9.4 | Detecting and handling errors | [9-04-detecting-and-handling-errors.md](chapter-09/9-04-detecting-and-handling-errors.md) |
| 9.5 | std::cin and handling invalid input | [9-05-stdcin-and-handling-invalid-input.md](chapter-09/9-05-stdcin-and-handling-invalid-input.md) |
| 9.6 | Assert and static_assert | [9-06-assert-and-static_assert.md](chapter-09/9-06-assert-and-static_assert.md) |
| 9.x | 第 9 章总结与测验 | [9-07-chapter-9-summary-and-quiz.md](chapter-09/9-07-chapter-9-summary-and-quiz.md) |

## Chapter 10 — Type Conversion, Type Aliases, and Type Deduction（类型转换、类型别名与类型推导）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 10.1 | Implicit type conversion | [10-01-implicit-type-conversion.md](chapter-10/10-01-implicit-type-conversion.md) |
| 10.2 | Floating-point and integral promotion | [10-02-floating-point-and-integral-promotion.md](chapter-10/10-02-floating-point-and-integral-promotion.md) |
| 10.3 | Numeric conversions | [10-03-numeric-conversions.md](chapter-10/10-03-numeric-conversions.md) |
| 10.4 | Narrowing conversions, list initialization, and constexpr initializers | [10-04-narrowing-conversions-list-initialization-and-constexpr-initializers.md](chapter-10/10-04-narrowing-conversions-list-initialization-and-constexpr-initializers.md) |
| 10.5 | Arithmetic conversions | [10-05-arithmetic-conversions.md](chapter-10/10-05-arithmetic-conversions.md) |
| 10.6 | Explicit type conversion (casting) and static_cast | [10-06-explicit-type-conversion-casting-and-static-cast.md](chapter-10/10-06-explicit-type-conversion-casting-and-static-cast.md) |
| 10.7 | Typedefs and type aliases | [10-07-typedefs-and-type-aliases.md](chapter-10/10-07-typedefs-and-type-aliases.md) |
| 10.8 | Type deduction for objects using the auto keyword | [10-08-type-deduction-for-objects-using-the-auto-keyword.md](chapter-10/10-08-type-deduction-for-objects-using-the-auto-keyword.md) |
| 10.9 | Type deduction for functions | [10-09-type-deduction-for-functions.md](chapter-10/10-09-type-deduction-for-functions.md) |
| 10.x | 第 10 章总结与测验 | [10-10-chapter-10-summary-and-quiz.md](chapter-10/10-10-chapter-10-summary-and-quiz.md) |

## Chapter 11 — Function Overloading and Function Templates（函数重载与函数模板）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 11.1 | Introduction to function overloading | [11-01-introduction-to-function-overloading.md](chapter-11/11-01-introduction-to-function-overloading.md) |
| 11.2 | Function overload differentiation | [11-02-function-overload-differentiation.md](chapter-11/11-02-function-overload-differentiation.md) |
| 11.3 | Function overload resolution and ambiguous matches | [11-03-function-overload-resolution-and-ambiguous-matches.md](chapter-11/11-03-function-overload-resolution-and-ambiguous-matches.md) |
| 11.4 | Deleting functions | [11-04-deleting-functions.md](chapter-11/11-04-deleting-functions.md) |
| 11.5 | Default arguments | [11-05-default-arguments.md](chapter-11/11-05-default-arguments.md) |
| 11.6 | Function templates | [11-06-function-templates.md](chapter-11/11-06-function-templates.md) |
| 11.7 | Function template instantiation | [11-07-function-template-instantiation.md](chapter-11/11-07-function-template-instantiation.md) |
| 11.8 | Function templates with multiple template types | [11-08-function-templates-with-multiple-template-types.md](chapter-11/11-08-function-templates-with-multiple-template-types.md) |
| 11.9 | Non-type template parameters | [11-09-non-type-template-parameters.md](chapter-11/11-09-non-type-template-parameters.md) |
| 11.10 | Using function templates in multiple files | [11-10-using-function-templates-in-multiple-files.md](chapter-11/11-10-using-function-templates-in-multiple-files.md) |
| 11.x | 第 11 章总结与测验 | [11-11-chapter-11-summary-and-quiz.md](chapter-11/11-11-chapter-11-summary-and-quiz.md) |

## Chapter F — Constexpr functions (optional chapter)（constexpr 函数（选学））

| 小节 | 主题 | 笔记 |
|---|---|---|
| F.1 | Constexpr functions | [F-01-constexpr-functions.md](chapter-F/F-01-constexpr-functions.md) |
| F.2 | Constexpr functions (part 2) | [F-02-constexpr-functions-part-2.md](chapter-F/F-02-constexpr-functions-part-2.md) |
| F.3 | Constexpr functions (part 3) and consteval | [F-03-constexpr-functions-part-3-and-consteval.md](chapter-F/F-03-constexpr-functions-part-3-and-consteval.md) |
| F.4 | Constexpr functions (part 4) | [F-04-constexpr-functions-part-4.md](chapter-F/F-04-constexpr-functions-part-4.md) |
| F.x | 第 F 章总结与测验 | [F-05-chapter-f-summary-and-quiz.md](chapter-F/F-05-chapter-f-summary-and-quiz.md) |

## Chapter 12 — Compound Types: References and Pointers（复合类型：引用与指针）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 12.1 | Introduction to compound data types | [12-01-introduction-to-compound-data-types.md](chapter-12/12-01-introduction-to-compound-data-types.md) |
| 12.2 | Value categories (lvalues and rvalues) | [12-02-value-categories-lvalues-and-rvalues.md](chapter-12/12-02-value-categories-lvalues-and-rvalues.md) |
| 12.3 | Lvalue references | [12-03-lvalue-references.md](chapter-12/12-03-lvalue-references.md) |
| 12.4 | Lvalue references to const | [12-04-lvalue-references-to-const.md](chapter-12/12-04-lvalue-references-to-const.md) |
| 12.5 | Pass by lvalue reference | [12-05-pass-by-lvalue-reference.md](chapter-12/12-05-pass-by-lvalue-reference.md) |
| 12.6 | Pass by const lvalue reference | [12-06-pass-by-const-lvalue-reference.md](chapter-12/12-06-pass-by-const-lvalue-reference.md) |
| 12.7 | Introduction to pointers | [12-07-introduction-to-pointers.md](chapter-12/12-07-introduction-to-pointers.md) |
| 12.8 | Null pointers | [12-08-null-pointers.md](chapter-12/12-08-null-pointers.md) |
| 12.9 | Pointers and const | [12-09-pointers-and-const.md](chapter-12/12-09-pointers-and-const.md) |
| 12.10 | Pass by address | [12-10-pass-by-address.md](chapter-12/12-10-pass-by-address.md) |
| 12.11 | Pass by address (part 2) | [12-11-pass-by-address-part-2.md](chapter-12/12-11-pass-by-address-part-2.md) |
| 12.12 | Return by reference and return by address | [12-12-return-by-reference-and-return-by-address.md](chapter-12/12-12-return-by-reference-and-return-by-address.md) |
| 12.13 | In and out parameters | [12-13-in-and-out-parameters.md](chapter-12/12-13-in-and-out-parameters.md) |
| 12.14 | Type deduction with pointers, references, and const | [12-14-type-deduction-with-pointers-references-and-const.md](chapter-12/12-14-type-deduction-with-pointers-references-and-const.md) |
| 12.15 | std::optional | [12-15-stdoptional.md](chapter-12/12-15-stdoptional.md) |
| 12.x | 第 12 章总结与测验 | [12-16-chapter-12-summary-and-quiz.md](chapter-12/12-16-chapter-12-summary-and-quiz.md) |

## Chapter 13 — Compound Types: Enums and Structs（复合类型：枚举与结构体）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 13.1 | Introduction to program-defined (user-defined) types | [13-01-introduction-to-program-defined-user-defined-types.md](chapter-13/13-01-introduction-to-program-defined-user-defined-types.md) |
| 13.2 | Unscoped enumerations | [13-02-unscoped-enumerations.md](chapter-13/13-02-unscoped-enumerations.md) |
| 13.3 | Unscoped enumerator integral conversions | [13-03-unscoped-enumerator-integral-conversions.md](chapter-13/13-03-unscoped-enumerator-integral-conversions.md) |
| 13.4 | Converting an enumeration to and from a string | [13-04-converting-an-enumeration-to-and-from-a-string.md](chapter-13/13-04-converting-an-enumeration-to-and-from-a-string.md) |
| 13.5 | Introduction to overloading the I/O operators | [13-05-introduction-to-overloading-the-i-o-operators.md](chapter-13/13-05-introduction-to-overloading-the-i-o-operators.md) |
| 13.6 | Scoped enumerations (enum classes) | [13-06-scoped-enumerations-enum-classes.md](chapter-13/13-06-scoped-enumerations-enum-classes.md) |
| 13.7 | Introduction to structs, members, and member selection | [13-07-introduction-to-structs-members-and-member-selection.md](chapter-13/13-07-introduction-to-structs-members-and-member-selection.md) |
| 13.8 | Struct aggregate initialization | [13-08-struct-aggregate-initialization.md](chapter-13/13-08-struct-aggregate-initialization.md) |
| 13.9 | Default member initialization | [13-09-default-member-initialization.md](chapter-13/13-09-default-member-initialization.md) |
| 13.10 | Passing and returning structs | [13-10-passing-and-returning-structs.md](chapter-13/13-10-passing-and-returning-structs.md) |
| 13.11 | Struct miscellany | [13-11-struct-miscellany.md](chapter-13/13-11-struct-miscellany.md) |
| 13.12 | Member selection with pointers and references | [13-12-member-selection-with-pointers-and-references.md](chapter-13/13-12-member-selection-with-pointers-and-references.md) |
| 13.13 | Class templates | [13-13-class-templates.md](chapter-13/13-13-class-templates.md) |
| 13.14 | Class template argument deduction (CTAD) and deduction guides | [13-14-class-template-argument-deduction-ctad-and-deduction-guides.md](chapter-13/13-14-class-template-argument-deduction-ctad-and-deduction-guides.md) |
| 13.15 | Alias templates | [13-15-alias-templates.md](chapter-13/13-15-alias-templates.md) |
| 13.x | 第 13 章总结与测验 | [13-16-chapter-13-summary-and-quiz.md](chapter-13/13-16-chapter-13-summary-and-quiz.md) |
| 13.y | Using a language reference | [13-17-using-a-language-reference.md](chapter-13/13-17-using-a-language-reference.md) |

## Chapter 14 — Introduction to Classes（类入门）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 14.1 | Introduction to object-oriented programming | [14-01-introduction-to-object-oriented-programming.md](chapter-14/14-01-introduction-to-object-oriented-programming.md) |
| 14.2 | Introduction to classes | [14-02-introduction-to-classes.md](chapter-14/14-02-introduction-to-classes.md) |
| 14.3 | Member functions | [14-03-member-functions.md](chapter-14/14-03-member-functions.md) |
| 14.4 | Const class objects and const member functions | [14-04-const-class-objects-and-const-member-functions.md](chapter-14/14-04-const-class-objects-and-const-member-functions.md) |
| 14.5 | Public and private members and access specifiers | [14-05-public-and-private-members-and-access-specifiers.md](chapter-14/14-05-public-and-private-members-and-access-specifiers.md) |
| 14.6 | Access functions | [14-06-access-functions.md](chapter-14/14-06-access-functions.md) |
| 14.7 | Member functions returning references to data members | [14-07-member-functions-returning-references-to-data-members.md](chapter-14/14-07-member-functions-returning-references-to-data-members.md) |
| 14.8 | The benefits of data hiding (encapsulation) | [14-08-the-benefits-of-data-hiding-encapsulation.md](chapter-14/14-08-the-benefits-of-data-hiding-encapsulation.md) |
| 14.9 | Introduction to constructors | [14-09-introduction-to-constructors.md](chapter-14/14-09-introduction-to-constructors.md) |
| 14.10 | Constructor member initializer lists | [14-10-constructor-member-initializer-lists.md](chapter-14/14-10-constructor-member-initializer-lists.md) |
| 14.11 | Default constructors and default arguments | [14-11-default-constructors-and-default-arguments.md](chapter-14/14-11-default-constructors-and-default-arguments.md) |
| 14.12 | Delegating constructors | [14-12-delegating-constructors.md](chapter-14/14-12-delegating-constructors.md) |
| 14.13 | Temporary class objects | [14-13-temporary-class-objects.md](chapter-14/14-13-temporary-class-objects.md) |
| 14.14 | Introduction to the copy constructor | [14-14-introduction-to-the-copy-constructor.md](chapter-14/14-14-introduction-to-the-copy-constructor.md) |
| 14.15 | Class initialization and copy elision | [14-15-class-initialization-and-copy-elision.md](chapter-14/14-15-class-initialization-and-copy-elision.md) |
| 14.16 | Converting constructors and the explicit keyword | [14-16-converting-constructors-and-the-explicit-keyword.md](chapter-14/14-16-converting-constructors-and-the-explicit-keyword.md) |
| 14.17 | Constexpr aggregates and classes | [14-17-constexpr-aggregates-and-classes.md](chapter-14/14-17-constexpr-aggregates-and-classes.md) |
| 14.x | 第 14 章总结与测验 | [14-18-chapter-14-summary-and-quiz.md](chapter-14/14-18-chapter-14-summary-and-quiz.md) |

## Chapter 15 — More on Classes（类进阶）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 15.1 | The hidden "this" pointer and member function chaining | [15-01-the-hidden-this-pointer-and-member-function-chaining.md](chapter-15/15-01-the-hidden-this-pointer-and-member-function-chaining.md) |
| 15.2 | Classes and header files | [15-02-classes-and-header-files.md](chapter-15/15-02-classes-and-header-files.md) |
| 15.3 | Nested types (member types) | [15-03-nested-types-member-types.md](chapter-15/15-03-nested-types-member-types.md) |
| 15.4 | Introduction to destructors | [15-04-introduction-to-destructors.md](chapter-15/15-04-introduction-to-destructors.md) |
| 15.5 | Class templates with member functions | [15-05-class-templates-with-member-functions.md](chapter-15/15-05-class-templates-with-member-functions.md) |
| 15.6 | Static member variables | [15-06-static-member-variables.md](chapter-15/15-06-static-member-variables.md) |
| 15.7 | Static member functions | [15-07-static-member-functions.md](chapter-15/15-07-static-member-functions.md) |
| 15.8 | Friend non-member functions | [15-08-friend-non-member-functions.md](chapter-15/15-08-friend-non-member-functions.md) |
| 15.9 | Friend classes and friend member functions | [15-09-friend-classes-and-friend-member-functions.md](chapter-15/15-09-friend-classes-and-friend-member-functions.md) |
| 15.10 | Ref qualifiers | [15-10-ref-qualifiers.md](chapter-15/15-10-ref-qualifiers.md) |
| 15.x | 第 15 章总结与测验 | [15-11-chapter-15-summary-and-quiz.md](chapter-15/15-11-chapter-15-summary-and-quiz.md) |

## Chapter 16 — Dynamic arrays: std::vector（动态数组 std::vector）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 16.1 | Introduction to containers and arrays | [16-01-introduction-to-containers-and-arrays.md](chapter-16/16-01-introduction-to-containers-and-arrays.md) |
| 16.2 | Introduction to std::vector and list constructors | [16-02-introduction-to-stdvector-and-list-constructors.md](chapter-16/16-02-introduction-to-stdvector-and-list-constructors.md) |
| 16.3 | std::vector and the unsigned length and subscript problem | [16-03-stdvector-and-the-unsigned-length-and-subscript-problem.md](chapter-16/16-03-stdvector-and-the-unsigned-length-and-subscript-problem.md) |
| 16.4 | Passing std::vector | [16-04-passing-stdvector.md](chapter-16/16-04-passing-stdvector.md) |
| 16.5 | Returning std::vector, and an introduction to move semantics | [16-05-returning-stdvector-and-an-introduction-to-move-semantics.md](chapter-16/16-05-returning-stdvector-and-an-introduction-to-move-semantics.md) |
| 16.6 | Arrays and loops | [16-06-arrays-and-loops.md](chapter-16/16-06-arrays-and-loops.md) |
| 16.7 | Arrays, loops, and sign challenge solutions | [16-07-arrays-loops-and-sign-challenge-solutions.md](chapter-16/16-07-arrays-loops-and-sign-challenge-solutions.md) |
| 16.8 | Range-based for loops (for-each) | [16-08-range-based-for-loops-for-each.md](chapter-16/16-08-range-based-for-loops-for-each.md) |
| 16.9 | Array indexing and length using enumerators | [16-09-array-indexing-and-length-using-enumerators.md](chapter-16/16-09-array-indexing-and-length-using-enumerators.md) |
| 16.10 | std::vector resizing and capacity | [16-10-stdvector-resizing-and-capacity.md](chapter-16/16-10-stdvector-resizing-and-capacity.md) |
| 16.11 | std::vector and stack behavior | [16-11-stdvector-and-stack-behavior.md](chapter-16/16-11-stdvector-and-stack-behavior.md) |
| 16.12 | std::vector<bool> | [16-12-stdvector-bool.md](chapter-16/16-12-stdvector-bool.md) |
| 16.x | 第 16 章总结与测验 | [16-13-chapter-16-summary-and-quiz.md](chapter-16/16-13-chapter-16-summary-and-quiz.md) |

## Chapter 17 — Fixed-size arrays: std::array and C-style arrays（定长数组：std::array 与 C 风格数组）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 17.1 | Introduction to std::array | [17-01-introduction-to-stdarray.md](chapter-17/17-01-introduction-to-stdarray.md) |
| 17.2 | std::array length and indexing | [17-02-stdarray-length-and-indexing.md](chapter-17/17-02-stdarray-length-and-indexing.md) |
| 17.3 | Passing and returning std::array | [17-03-passing-and-returning-stdarray.md](chapter-17/17-03-passing-and-returning-stdarray.md) |
| 17.4 | std::array of class types, and brace elision | [17-04-stdarray-of-class-types-and-brace-elision.md](chapter-17/17-04-stdarray-of-class-types-and-brace-elision.md) |
| 17.5 | Arrays of references via std::reference_wrapper | [17-05-arrays-of-references-via-stdreference_wrapper.md](chapter-17/17-05-arrays-of-references-via-stdreference_wrapper.md) |
| 17.6 | std::array and enumerations | [17-06-stdarray-and-enumerations.md](chapter-17/17-06-stdarray-and-enumerations.md) |
| 17.7 | Introduction to C-style arrays | [17-07-introduction-to-c-style-arrays.md](chapter-17/17-07-introduction-to-c-style-arrays.md) |
| 17.8 | C-style array decay | [17-08-c-style-array-decay.md](chapter-17/17-08-c-style-array-decay.md) |
| 17.9 | Pointer arithmetic and subscripting | [17-09-pointer-arithmetic-and-subscripting.md](chapter-17/17-09-pointer-arithmetic-and-subscripting.md) |
| 17.10 | C-style strings | [17-10-c-style-strings.md](chapter-17/17-10-c-style-strings.md) |
| 17.11 | C-style string symbolic constants | [17-11-c-style-string-symbolic-constants.md](chapter-17/17-11-c-style-string-symbolic-constants.md) |
| 17.12 | Multidimensional C-style Arrays | [17-12-multidimensional-c-style-arrays.md](chapter-17/17-12-multidimensional-c-style-arrays.md) |
| 17.13 | Multidimensional std::array | [17-13-multidimensional-stdarray.md](chapter-17/17-13-multidimensional-stdarray.md) |
| 17.x | 第 17 章总结与测验 | [17-14-chapter-17-summary-and-quiz.md](chapter-17/17-14-chapter-17-summary-and-quiz.md) |

## Chapter 18 — Iterators and Algorithms (under construction)（迭代器与算法（官网在建））

| 小节 | 主题 | 笔记 |
|---|---|---|
| 18.1 | Sorting an array using selection sort | [18-01-sorting-an-array-using-selection-sort.md](chapter-18/18-01-sorting-an-array-using-selection-sort.md) |
| 18.2 | Introduction to iterators | [18-02-introduction-to-iterators.md](chapter-18/18-02-introduction-to-iterators.md) |
| 18.3 | Introduction to standard library algorithms | [18-03-introduction-to-standard-library-algorithms.md](chapter-18/18-03-introduction-to-standard-library-algorithms.md) |
| 18.4 | Timing your code | [18-04-timing-your-code.md](chapter-18/18-04-timing-your-code.md) |

## Chapter 19 — Dynamic Allocation (under construction)（动态内存分配（官网在建））

| 小节 | 主题 | 笔记 |
|---|---|---|
| 19.1 | Dynamic memory allocation with new and delete | [19-01-dynamic-memory-allocation-with-new-and-delete.md](chapter-19/19-01-dynamic-memory-allocation-with-new-and-delete.md) |
| 19.2 | Dynamically allocating arrays | [19-02-dynamically-allocating-arrays.md](chapter-19/19-02-dynamically-allocating-arrays.md) |
| 19.3 | Destructors | [19-03-destructors.md](chapter-19/19-03-destructors.md) |
| 19.4 | Pointers to pointers and dynamic multidimensional arrays | [19-04-pointers-to-pointers.md](chapter-19/19-04-pointers-to-pointers.md) |
| 19.5 | Void pointers | [19-05-void-pointers.md](chapter-19/19-05-void-pointers.md) |

## Chapter 20 — Functions（函数（指针、递归与 lambda））

| 小节 | 主题 | 笔记 |
|---|---|---|
| 20.1 | Function Pointers | [20-01-function-pointers.md](chapter-20/20-01-function-pointers.md) |
| 20.2 | The stack and the heap | [20-02-the-stack-and-the-heap.md](chapter-20/20-02-the-stack-and-the-heap.md) |
| 20.3 | Recursion | [20-03-recursion.md](chapter-20/20-03-recursion.md) |
| 20.4 | Command line arguments | [20-04-command-line-arguments.md](chapter-20/20-04-command-line-arguments.md) |
| 20.5 | Ellipsis (and why to avoid them) | [20-05-ellipsis-and-why-to-avoid-them.md](chapter-20/20-05-ellipsis-and-why-to-avoid-them.md) |
| 20.6 | Introduction to lambdas (anonymous functions) | [20-06-introduction-to-lambdas-anonymous-functions.md](chapter-20/20-06-introduction-to-lambdas-anonymous-functions.md) |
| 20.7 | Lambda captures | [20-07-lambda-captures.md](chapter-20/20-07-lambda-captures.md) |
| 20.x | 第 20 章总结与测验 | [20-08-chapter-20-summary-and-quiz.md](chapter-20/20-08-chapter-20-summary-and-quiz.md) |

## Chapter 21 — Operator Overloading（运算符重载）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 21.1 | Introduction to operator overloading | [21-01-introduction-to-operator-overloading.md](chapter-21/21-01-introduction-to-operator-overloading.md) |
| 21.2 | Overloading the arithmetic operators using friend functions | [21-02-overloading-the-arithmetic-operators-using-friend-functions.md](chapter-21/21-02-overloading-the-arithmetic-operators-using-friend-functions.md) |
| 21.3 | Overloading operators using normal functions | [21-03-overloading-operators-using-normal-functions.md](chapter-21/21-03-overloading-operators-using-normal-functions.md) |
| 21.4 | Overloading the I/O operators | [21-04-overloading-the-io-operators.md](chapter-21/21-04-overloading-the-io-operators.md) |
| 21.5 | Overloading operators using member functions | [21-05-overloading-operators-using-member-functions.md](chapter-21/21-05-overloading-operators-using-member-functions.md) |
| 21.6 | Overloading unary operators +, -, and ! | [21-06-overloading-unary-operators.md](chapter-21/21-06-overloading-unary-operators.md) |
| 21.7 | Overloading the comparison operators | [21-07-overloading-the-comparison-operators.md](chapter-21/21-07-overloading-the-comparison-operators.md) |
| 21.8 | Overloading the increment and decrement operators | [21-08-overloading-the-increment-and-decrement-operators.md](chapter-21/21-08-overloading-the-increment-and-decrement-operators.md) |
| 21.9 | Overloading the subscript operator | [21-09-overloading-the-subscript-operator.md](chapter-21/21-09-overloading-the-subscript-operator.md) |
| 21.10 | Overloading the parenthesis operator | [21-10-overloading-the-parenthesis-operator.md](chapter-21/21-10-overloading-the-parenthesis-operator.md) |
| 21.11 | Overloading typecasts | [21-11-overloading-typecasts.md](chapter-21/21-11-overloading-typecasts.md) |
| 21.12 | Overloading the assignment operator | [21-12-overloading-the-assignment-operator.md](chapter-21/21-12-overloading-the-assignment-operator.md) |
| 21.13 | Shallow vs. deep copying | [21-13-shallow-vs-deep-copying.md](chapter-21/21-13-shallow-vs-deep-copying.md) |
| 21.14 | Overloading operators and function templates | [21-14-overloading-operators-and-function-templates.md](chapter-21/21-14-overloading-operators-and-function-templates.md) |
| 21.x | 第 21 章总结与测验 | [21-15-chapter-21-summary-and-quiz.md](chapter-21/21-15-chapter-21-summary-and-quiz.md) |

## Chapter 22 — Move Semantics and Smart Pointers（移动语义与智能指针）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 22.1 | Introduction to smart pointers and move semantics | [22-01-introduction-to-smart-pointers-move-semantics.md](chapter-22/22-01-introduction-to-smart-pointers-move-semantics.md) |
| 22.2 | R-value references | [22-02-rvalue-references.md](chapter-22/22-02-rvalue-references.md) |
| 22.3 | Move constructors and move assignment | [22-03-move-constructors-and-move-assignment.md](chapter-22/22-03-move-constructors-and-move-assignment.md) |
| 22.4 | std::move | [22-04-stdmove.md](chapter-22/22-04-stdmove.md) |
| 22.5 | std::unique_ptr | [22-05-stdunique_ptr.md](chapter-22/22-05-stdunique_ptr.md) |
| 22.6 | std::shared_ptr | [22-06-stdshared_ptr.md](chapter-22/22-06-stdshared_ptr.md) |
| 22.7 | Circular dependency issues with std::shared_ptr, and std::weak_ptr | [22-07-circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr.md](chapter-22/22-07-circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr.md) |
| 22.x | 第 22 章总结与测验 | [22-08-chapter-22-summary-and-quiz.md](chapter-22/22-08-chapter-22-summary-and-quiz.md) |

## Chapter 23 — Object Relationships（对象间关系）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 23.1 | Object relationships | [23-01-object-relationships.md](chapter-23/23-01-object-relationships.md) |
| 23.2 | Composition | [23-02-composition.md](chapter-23/23-02-composition.md) |
| 23.3 | Aggregation | [23-03-aggregation.md](chapter-23/23-03-aggregation.md) |
| 23.4 | Association | [23-04-association.md](chapter-23/23-04-association.md) |
| 23.5 | Dependencies | [23-05-dependencies.md](chapter-23/23-05-dependencies.md) |
| 23.6 | Container classes | [23-06-container-classes.md](chapter-23/23-06-container-classes.md) |
| 23.7 | std::initializer_list | [23-07-stdinitializer_list.md](chapter-23/23-07-stdinitializer_list.md) |
| 23.x | 第 23 章总结与测验 | [23-08-chapter-23-summary-and-quiz.md](chapter-23/23-08-chapter-23-summary-and-quiz.md) |

## Chapter 24 — Inheritance（继承）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 24.1 | Introduction to inheritance | [24-01-introduction-to-inheritance.md](chapter-24/24-01-introduction-to-inheritance.md) |
| 24.2 | Basic inheritance in C++ | [24-02-basic-inheritance-in-c.md](chapter-24/24-02-basic-inheritance-in-c.md) |
| 24.3 | Order of construction of derived classes | [24-03-order-of-construction-of-derived-classes.md](chapter-24/24-03-order-of-construction-of-derived-classes.md) |
| 24.4 | Constructors and initialization of derived classes | [24-04-constructors-and-initialization-of-derived-classes.md](chapter-24/24-04-constructors-and-initialization-of-derived-classes.md) |
| 24.5 | Inheritance and access specifiers | [24-05-inheritance-and-access-specifiers.md](chapter-24/24-05-inheritance-and-access-specifiers.md) |
| 24.6 | Adding new functionality to a derived class | [24-06-adding-new-functionality-to-a-derived-class.md](chapter-24/24-06-adding-new-functionality-to-a-derived-class.md) |
| 24.7 | Calling inherited functions and overriding behavior | [24-07-calling-inherited-functions-and-overriding-behavior.md](chapter-24/24-07-calling-inherited-functions-and-overriding-behavior.md) |
| 24.8 | Hiding inherited functionality | [24-08-hiding-inherited-functionality.md](chapter-24/24-08-hiding-inherited-functionality.md) |
| 24.9 | Multiple inheritance | [24-09-multiple-inheritance.md](chapter-24/24-09-multiple-inheritance.md) |
| 24.x | 第 24 章总结与测验 | [24-10-chapter-24-summary-and-quiz.md](chapter-24/24-10-chapter-24-summary-and-quiz.md) |

## Chapter 25 — Virtual Functions（虚函数）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 25.1 | Pointers and references to the base class of derived objects | [25-01-pointers-and-references-to-the-base-class-of-derived-objects.md](chapter-25/25-01-pointers-and-references-to-the-base-class-of-derived-objects.md) |
| 25.2 | Virtual functions and polymorphism | [25-02-virtual-functions.md](chapter-25/25-02-virtual-functions.md) |
| 25.3 | The override and final specifiers, and covariant return types | [25-03-the-override-and-final-specifiers-and-covariant-return-types.md](chapter-25/25-03-the-override-and-final-specifiers-and-covariant-return-types.md) |
| 25.4 | Virtual destructors, virtual assignment, and overriding virtualization | [25-04-virtual-destructors-virtual-assignment-and-overriding-virtualization.md](chapter-25/25-04-virtual-destructors-virtual-assignment-and-overriding-virtualization.md) |
| 25.5 | Early binding and late binding | [25-05-early-binding-and-late-binding.md](chapter-25/25-05-early-binding-and-late-binding.md) |
| 25.6 | The virtual table | [25-06-the-virtual-table.md](chapter-25/25-06-the-virtual-table.md) |
| 25.7 | Pure virtual functions, abstract base classes, and interface classes | [25-07-pure-virtual-functions-abstract-base-classes-and-interface-classes.md](chapter-25/25-07-pure-virtual-functions-abstract-base-classes-and-interface-classes.md) |
| 25.8 | Virtual base classes | [25-08-virtual-base-classes.md](chapter-25/25-08-virtual-base-classes.md) |
| 25.9 | Object slicing | [25-09-object-slicing.md](chapter-25/25-09-object-slicing.md) |
| 25.10 | Dynamic casting | [25-10-dynamic-casting.md](chapter-25/25-10-dynamic-casting.md) |
| 25.11 | Printing inherited classes using operator<< | [25-11-printing-inherited-classes-using-operator.md](chapter-25/25-11-printing-inherited-classes-using-operator.md) |
| 25.x | 第 25 章总结与测验 | [25-12-chapter-25-summary-and-quiz.md](chapter-25/25-12-chapter-25-summary-and-quiz.md) |

## Chapter 26 — Templates and Classes（模板与类）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 26.1 | Template classes | [26-01-template-classes.md](chapter-26/26-01-template-classes.md) |
| 26.2 | Template non-type parameters | [26-02-template-non-type-parameters.md](chapter-26/26-02-template-non-type-parameters.md) |
| 26.3 | Function template specialization | [26-03-function-template-specialization.md](chapter-26/26-03-function-template-specialization.md) |
| 26.4 | Class template specialization | [26-04-class-template-specialization.md](chapter-26/26-04-class-template-specialization.md) |
| 26.5 | Partial template specialization | [26-05-partial-template-specialization.md](chapter-26/26-05-partial-template-specialization.md) |
| 26.6 | Partial template specialization for pointers | [26-06-partial-template-specialization-for-pointers.md](chapter-26/26-06-partial-template-specialization-for-pointers.md) |
| 26.x | 第 26 章总结与测验 | [26-07-chapter-26-summary-and-quiz.md](chapter-26/26-07-chapter-26-summary-and-quiz.md) |

## Chapter 27 — Exceptions（异常）

| 小节 | 主题 | 笔记 |
|---|---|---|
| 27.1 | The need for exceptions | [27-01-the-need-for-exceptions.md](chapter-27/27-01-the-need-for-exceptions.md) |
| 27.2 | Basic exception handling | [27-02-basic-exception-handling.md](chapter-27/27-02-basic-exception-handling.md) |
| 27.3 | Exceptions, functions, and stack unwinding | [27-03-exceptions-functions-and-stack-unwinding.md](chapter-27/27-03-exceptions-functions-and-stack-unwinding.md) |
| 27.4 | Uncaught exceptions and catch-all handlers | [27-04-uncaught-exceptions-catch-all-handlers.md](chapter-27/27-04-uncaught-exceptions-catch-all-handlers.md) |
| 27.5 | Exceptions, classes, and inheritance | [27-05-exceptions-classes-and-inheritance.md](chapter-27/27-05-exceptions-classes-and-inheritance.md) |
| 27.6 | Rethrowing exceptions | [27-06-rethrowing-exceptions.md](chapter-27/27-06-rethrowing-exceptions.md) |
| 27.7 | Function try blocks | [27-07-function-try-blocks.md](chapter-27/27-07-function-try-blocks.md) |
| 27.8 | Exception dangers and downsides | [27-08-exception-dangers-and-downsides.md](chapter-27/27-08-exception-dangers-and-downsides.md) |
| 27.9 | Exception specifications and noexcept | [27-09-exception-specifications-and-noexcept.md](chapter-27/27-09-exception-specifications-and-noexcept.md) |
| 27.10 | std::move_if_noexcept | [27-10-stdmove_if_noexcept.md](chapter-27/27-10-stdmove_if_noexcept.md) |
| 27.x | 第 27 章总结与测验 | [27-11-chapter-27-summary-and-quiz.md](chapter-27/27-11-chapter-27-summary-and-quiz.md) |

## Chapter 28 — Input and Output (I/O)（输入输出（I/O））

| 小节 | 主题 | 笔记 |
|---|---|---|
| 28.1 | Input and output (I/O) streams | [28-01-input-and-output-io-streams.md](chapter-28/28-01-input-and-output-io-streams.md) |
| 28.2 | Input with istream | [28-02-input-with-istream.md](chapter-28/28-02-input-with-istream.md) |
| 28.3 | Output with ostream and ios | [28-03-output-with-ostream-and-ios.md](chapter-28/28-03-output-with-ostream-and-ios.md) |
| 28.4 | Stream classes for strings | [28-04-stream-classes-for-strings.md](chapter-28/28-04-stream-classes-for-strings.md) |
| 28.5 | Stream states and input validation | [28-05-stream-states-and-input-validation.md](chapter-28/28-05-stream-states-and-input-validation.md) |
| 28.6 | Basic file I/O | [28-06-basic-file-io.md](chapter-28/28-06-basic-file-io.md) |
| 28.7 | Random file I/O | [28-07-random-file-io.md](chapter-28/28-07-random-file-io.md) |
| 28.x | 第 28 章总结与测验 | [28-08-chapter-28-summary.md](chapter-28/28-08-chapter-28-summary.md) |

## 编译示例

```bash
# 单文件示例
g++ -std=c++20 -Wall chapter-01/1-05-example1.cpp -o demo && ./demo

# 多文件示例（整文件夹一起编译）
g++ -std=c++20 -Wall chapter-02/2-11-example1/*.cpp -o demo && ./demo

# 特殊示例
g++ -std=c++23 chapter-05/5-03-example9.cpp -lstdc++exp -o demo   # C++23 / std::print
g++ -std=c++20 -Wall -pedantic-errors chapter-17/17-07-example7-error.cpp  # 零长数组按预期报错
```

> 提示：批量编译时请排除上文列出的刻意报错文件（`1-01-example2.cpp`、`*-error.cpp`、`*-linkerror*`、`*-broken.cpp`、`*-ub.cpp`、`*-plog.cpp`、`*-opengl.cpp`、`*-cpp23.cpp`、`*-overflow.cpp` 等）。

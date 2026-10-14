# 9.6 Assert and static_assert

> 原文：https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/

## 核心概念

1. **坏参数的问题**：调用者可能传入能编译却毫无意义的参数（例如除数为零）。这是一种语义错误，会让程序崩溃。
2. **为什么静默失败不好**：出错时直接跳过语句等于静默失败，会"掩盖真正的问题"；错误信息也可能淹没在输出中，且难以判断它来自哪里。
3. **为什么 `std::exit` 不理想**：用 `std::exit` 终止会丢失调用栈与调试信息。更推荐 `std::abort`，因为开发者通常能在中止点获得调试的机会。
4. **前置条件（precondition）**：某段代码（通常是函数体）执行前必须成立的条件。作者的 `y != 0` 检查就是一例。
5. **规则：把前置条件放在最前面，用提前返回**：推荐的结构是先检查前置条件，不满足就返回给调用者。
6. **"bouncer pattern"（门卫模式）**：一个可选的术语，指一旦检测到错误就立即从函数"弹回"。好处：所有测试用例与其处理代码都集中在最前面，且嵌套更少。
7. **不变式（invariant）**：在某段代码执行期间必须始终保持为真的条件；常与循环搭配使用。
8. **类不变式（class invariant）**：在 "For advanced readers" 中提及，后续第 14.2 节讲解。
9. **后置条件（postcondition）**：某段代码执行之后必须为真的东西。示例函数没有后置条件。
10. **断言（assertion）**：一个除非程序有 bug、否则应为真的表达式。为真时什么都不发生；为假时显示一条信息并经 `std::abort` 终止程序。信息通常包含失败的表达式文本、文件名和行号。
11. **规则：用断言尽早捕捉问题**：断言失败会停下程序，让你用调试工具检查状态并回溯根因。
12. **运行期断言：`assert` 宏**：由 `assert` 预处理宏实现，位于 `<cassert>` 头文件。
13. **规则：断言可以验证的不只是参数**：只要你想确认某事为真，任何地方都可以用。
14. **规则：断言是可接受的宏**：尽管前面建议避免预处理宏，断言是少数可接受的宏之一；作者鼓励大量使用。
15. **关键洞察——断言胜过注释**：断言既记录又强制某个条件；过期（stale）的断言是正确性问题，因此不像注释那样容易被放着腐烂。
16. **让断言更具描述性**：字符串字面量总是求值为真，因此用逻辑与把一段字符串字面量"与"进条件不会改变求值结果，却能为失败信息补充上下文（例如是哪个查找失败）。
17. **用断言标记未实现的功能**：用来标注故意未处理的情形，让碰到该情形的开发者看到有用的信息。
18. **NDEBUG**：定义 `NDEBUG` 预处理宏会禁用 `assert` 宏。多数 IDE 在 release 配置中会定义它；Visual Studio 的项目级定义为 `WIN32;NDEBUG;_CONSOLE`，要去掉 `NDEBUG` 才能在 release 构建中保留断言，否则需手动添加。
19. **Tip——按翻译单元启用/禁用**：把 `#define NDEBUG`（禁用）或 `#undef NDEBUG`（启用）单独放在**任何 `#include` 之前**的一行，且行尾不要加分号。
20. **`static_assert`**：在编译期求值的断言；失败即为编译错误。它是关键字，因此不需要任何头文件（不同于 `assert`）。
21. **`static_assert` 的语法**：形如 `static_assert(condition, diagnostic_message)`；若条件为假，则打印该信息。
22. **`static_assert` 的规则**：条件必须是常量表达式；可出现在文件任何位置（包括全局命名空间）；在 release 构建中不会被停用；没有运行期开销。
23. **C++17 的变化**：C++17 之前必须提供第二个参数作为诊断信息；C++17 起它变为可选。
24. **断言 vs. 错误处理**：断言用于在开发期检测编程错误，不提供恢复途径；它通常会被编译出 release 构建，因此开销很小。错误处理处理的是 release 构建中可能发生的、无论可否恢复的情形，既耗费运行期性能也耗费开发时间。
25. **规则：有时两者都用**：对于"不应该发生但有可能发生"的事，同时使用断言和优雅的错误处理。
26. **断言的局限**：断言可能被写错（误报或漏掉真正的 bug）。断言表达式不能有副作用，因为定义 `NDEBUG` 时它们不被求值，否则 debug 与 release 行为会不一致。`abort()` 立即终止、不做清理（文件、数据库），因此断言只应用在不太可能造成损坏的地方。

## 最佳实践

- **Rule**：把前置条件放在（函数体）最前面，用提前返回处理（bouncer pattern）。
- **Rule**：用断言尽早捕捉问题。
- **Rule**：断言可以验证的不只是参数。
- **Rule**：断言是可接受的宏。
- **Rule**：有时两者都用（对"不该发生但可能发生"的情况同时用断言 + 优雅的错误处理）。
- **Best practice**：Favor `static_assert` over `assert()` whenever possible.（尽可能优先使用 `static_assert` 而非 `assert()`。）
- **Key insight**：Asserts are used to detect errors while developing and debugging.（断言用于在开发与调试期间检测错误。）
- **Key insight**：Asserts are better than comments because they have both document and enforce a condition.（断言胜过注释，因为它们既记录又强制某个条件。）
- **Tip**：通过在任何 `#include` 之前单独一行写 `#define NDEBUG`（禁用）或 `#undef NDEBUG`（启用）来按翻译单元开关断言，行尾不加分号。
- **Tip**：对编程错误、错误假设或正确代码中不应出现的条件用断言；对正常运行中预期会出现的问题用错误处理；对"不该发生但应优雅失败"的情况两者都用。
- **Warning**：断言可能被写得不正确（误报或漏掉真实 bug）；断言表达式不能有副作用，否则 debug 与 release 行为会分叉；`abort()` 立即结束程序、无清理机会，因此断言只应用在意外终止不太可能造成损坏之处。

## 代码示例

- [9-06-example1.cpp](9-06-example1.cpp)：显式零检查 + 错误信息版 `printDivision()`。
- [9-06-example2.cpp](9-06-example2.cpp)：把前置条件放在最前面、提前返回的 `printDivision()`（bouncer pattern）。
- [9-06-example3.cpp](9-06-example3.cpp)：非 bouncer 版本，因分离与嵌套被作者称为"strictly worse"。
- [9-06-example4.cpp](9-06-example4.cpp)：运行期断言验证函数参数——`calculateTimeUntilObjectHitsGround()`，用 `-9.8` 调用时触发断言并 `std::abort`。
- [9-06-example5.cpp](9-06-example5.cpp)：不具描述性的断言 `assert(found);` 及其产生的信息。
- [9-06-example6.cpp](9-06-example6.cpp)：用逻辑与给断言补上字符串字面量，使信息更具体：`assert(found && "Car could not be found in database");`。
- [9-06-example7.cpp](9-06-example7.cpp)：用断言记录未实现情形——`assert(moved && "Need to handle case where student was just moved to another classroom");`。
- [9-06-example8.cpp](9-06-example8.cpp)：用 `#define NDEBUG` 禁用某翻译单元的断言（须放在任何 `#include` 之前）。
- [9-06-example9-error.cpp](9-06-example9-error.cpp)：编译期 `static_assert` 检查类型大小；在 Windows（`long` 为 4 字节）上预期编译失败。
- [9-06-example10.cpp](9-06-example10.cpp)：`getInverse(double x)`——`x` 为 `0.0` 时行为异常，引出断言/错误处理的讨论。
- [9-06-example11.cpp](9-06-example11.cpp)：把断言与错误处理结合起来。

> 说明：本节代码为按原文描述**忠实重建**（抓取工具无法逐字返回完整代码块）。

## 测验

本节原文没有测验小节（本章测验在 9.x）。

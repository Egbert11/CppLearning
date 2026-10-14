# 9.5 std::cin and handling invalid input

> 原文：https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/

## 核心概念

1. **用户输入是自由形式的**：只要程序有任何用户界面，就必须处理输入；因为用户"可以输入任何内容"，很容易产生意料之外的输入。
2. **健壮性（robustness）**：写得好的程序会预料到误用，并优雅地处理它或阻止它。**能很好地处理错误情形的程序称为鲁棒（robust）**。
3. **`operator>>` 的工作原理（简化）**：先丢弃输入缓冲区中的前导空白（包括之前输入残留的换行）；若缓冲区随即为空就等待更多数据；最后提取连续的有效字符，直到遇到换行或对目标类型无效的字符。
4. **提取的结果**：若提取到了任意字符，则提取成功并把转换后的值赋给变量；若一个字符都提取不到，则提取失败——目标变量被赋为 `0`（C++11 起），此后直到清除 `std::cin` 之前，后续提取都会失败。
5. **输入验证（input validation）的定义**：检查用户输入是否符合程序预期的过程。
6. **三种验证方式**：
   - 内联（边输入边验证）：在按键输入时就拦截非法键。
   - 先读成字符串再验证：读入字符串、验证、再转换。
   - 先提取再验证：让 `std::cin`/`operator>>` 尝试提取并处理失败。
7. **逐字符验证**：某些 GUI/高级文本界面会用验证函数对每次按键做接受或丢弃，而 `std::cin` 不支持这种风格。
8. **字符串总能提取成功**（没有字符限制），但提取仍会在遇到第一个非前导空白处停止。把字符串解析成其他类型比较困难，很少这么做。
9. **最常见的做法**：让 `std::cin` 和 `operator>>` 来做提取，然后处理出错的地方——最简单，也是本节的重点。
10. **示例计算器**：一个没有任何错误处理的程序，包含 `getDouble()`、`getOperator()`、`printResult()`、`main()`；正常运行时输出 `5 * 7 is 35`。
11. **可能出问题的地方**：数字可能提取不出来；运算符可能被提取到但不是预期的那一个；缓冲区里多余的输入（例如 `*q hello`）可能引发后续问题。
12. **四种非法文本输入**：能成功提取但无意义的输入；成功提取但同时带有多余输入；提取失败；成功提取但数值溢出。健壮的程序应在每个输入点都考虑这四种情形。
13. **错误情形 1——无意义输入**：修改办法是分三步验证：检查输入是否符合预期；符合就返回它；否则报告问题并重试。用一个 `while (true)` 循环加 `switch`，只接受 `+ - * /`。
14. **错误情形 2——多余输入**：输入 `5*7` 会把 `*7\n` 留在缓冲区，后续提示会吞掉残留，输出也会挤在一起。`std::cin.ignore(100, '\n')` 清除最多 100 个字符或直到换行；传入 `std::numeric_limits<std::streamsize>::max()` 会禁用计数检查，把直到并包含下一个换行符的内容全部移除。
15. **`ignoreLine()` 辅助函数**：把 ignore 调用包进函数即可复用。
16. **另一种做法：把多余输入视为失败**：`hasUnextractedInput()` 在当前行还有未提取输入时返回 true，用到 `std::cin.eof()`（上一次操作命中流末尾时为真）和 `std::cin.peek()`（查看下一个字符而不提取）。用一个循环清除多余输入并重试。还可用德摩根定律改写被取反的布尔表达式，使其更清晰。
17. **错误情形 3——提取失败**：给 `double` 输入 `a`，该字符留在缓冲区，且 `std::cin` 进入"失败模式"，此后提取会静默失败——造成提示反复出现的死循环。恢复需要三件事：检测失败、恢复正常模式、移除出错的输入。
18. **恢复代码**：检查 `std::cin.fail()`（更惯用的写法是 `!std::cin`，因为 `std::cin` 可转换为表示上一次操作结果的布尔值），然后依次调用 `std::cin.clear()` 和 `ignoreLine()`。
19. **关键洞察（原文引用）**："Once an extraction has failed, future requests for input extraction (including calls to `ignore()`) will silently fail until the `clear()` function is called." 因此检测到失败后，**`clear()` 应最先调用**。
20. **提取失败时的值**：对于基础类型，因非法输入导致的失败会把变量赋为 `0`（或该类型对应的零值）。在没有失败时调用 `clear()` 无害，因此可以用一个记下来的 `bool success { std::cin };` 把成功与失败两条路径合并。
21. **检查 EOF**：文件末尾是一个特殊错误状态，表示没有更多数据可用。对文件来说这很正常；`std::cin` 通常只是等待而不会发出 EOF 信号，除非用户按下操作系统特定的 EOF 键（Unix 上是 Ctrl-D，Windows 上是 Ctrl-Z + 回车）。第二个**关键洞察**："In C++, EOF is an error state, not a character."
22. **EOF 行为依操作系统而定**：若 EOF 不是第一个字符，先前输入会被刷新、EOF 字符被忽略（Windows 上后续字符除换行外都被忽略）。若 EOF 是第一个字符，则设置错误状态且流可能断开。`clear()` 能清除 EOF 错误，但断开的流会在下次请求时再次产生 EOF——这可能让 `while(true)` 里出现死循环。建议的做法是用 `std::cin.eof()` 检测 EOF 并终止程序。
23. **错误情形 4——数值溢出**：给 16 位有符号值输入 `40000` 会让 `std::cin` 进入失败模式，并把最接近的在范围内的值（此处 `32767`）赋给它；后续输入被跳过，`y` 保持初始化的 `0`。这与提取失败的处理方式相同。
24. **合到一起**：最终计算器加入 `clearFailedExtraction()`、`ignoreLine()`、经过验证的 `getDouble()`/`getOperator()`、对意外运算符返回 `"???"` 的 `printResult()`，以及一个在除零时重新提示的 `main()` 循环。
25. **结论**：对每个输入点都问：提取可能失败吗？用户可能多输入吗？用户可能输入无意义的内容吗？数值可能溢出吗？用 `if` 语句、布尔逻辑和循环来重新提示。

## 最佳实践

本节没有 "Best practice" / "Warning" 提示框。仅有的提示框：

- **Tip**（示例 6 之后）：在某些情况下，把多余输入当作失败情形处理可能更好，即提示用户重新输入，而不是直接忽略它。
- **Key insight**（`!std::cin` 片段之后）：一旦提取失败，后续的提取请求（包括对 `ignore()` 的调用）都会静默失败，直到调用 `clear()`；因此检测到失败后，`clear()` 通常应最先调用。
- **Key insight**（EOF 一节）：在 C++ 中 EOF 是一个错误状态，而不是一个字符；操作系统提供特定的按键组合，被当作"用户请求的 EOF"。
- **Author's note**（结尾）：输入验证很重要，但它会让示例更复杂、更难读，因此后续小节一般不包含输入验证，除非与主题相关。

## 代码示例

- [9-05-example1.cpp](9-05-example1.cpp)：没有任何错误处理的简易计算器（`getDouble()` / `getOperator()` / `printResult()` / `main()`）；正常运行输出 `5 * 7 is 35`。
- [9-05-example2.cpp](9-05-example2.cpp)：带验证的 `getOperator()`——用 `while (true)` + `switch`，只接受 `+ - * /`，否则打印 `"Oops, that input is invalid.  Please try again.\n"` 后重试。
- [9-05-example3.cpp](9-05-example3.cpp)：清除多余输入——`std::cin.ignore(100, '\n')`、`std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')`，以及把后者封装成 `ignoreLine()` 辅助函数。
- [9-05-example4.cpp](9-05-example4.cpp)：把多余输入视为失败——`hasUnextractedInput()`（用 `std::cin.eof()` 与 `std::cin.peek()`），并在 `getDouble()` 中据此重新提示。
- [9-05-example5.cpp](9-05-example5.cpp)：处理提取失败——`if (std::cin.fail())`（或惯用的 `!std::cin`）后依次 `clear()` + `ignoreLine()`；并用 `bool success { std::cin };` 合并成功/失败路径。
- [9-05-example6.cpp](9-05-example6.cpp)：数值溢出演示——把 `40000` 读进 `std::int16_t`，`std::cin` 进入失败模式并赋值为 `32767`，输出 `The sum is: 32767`。
- [9-05-example7.cpp](9-05-example7.cpp)：完整健壮计算器——含 `ignoreLine()`、`clearFailedExtraction()`（遇 EOF 时 `std::exit(0)`）、验证过的 `getDouble()`/`getOperator()`、处理除零与意外运算符的 `printResult()`。

> 说明：本节代码为按原文描述**忠实重建**（抓取工具无法逐字返回完整代码块）。原文示例 3/4/5/6 的零散片段已合并入 `9-05-example3.cpp`，示例 7/13 合并入 `9-05-example4.cpp`，示例 8/9/10 合并入 `9-05-example5.cpp`，其余一一对应。

## 测验

本节原文没有测验小节。

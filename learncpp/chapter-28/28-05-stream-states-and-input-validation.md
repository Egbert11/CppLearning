# 28.5 Stream states and input validation

> 原文：https://www.learncpp.com/cpp-tutorial/stream-states-and-input-validation/

## 核心概念

- **流状态标志位于 `ios_base`**：它们表示流使用过程中可能出现的状况。
- **`goodbit`**：表示"一切正常"。
- **`badbit`**：表示"发生了某种致命错误"；原文举例是读到文件末尾之后继续读。
- **`eofbit`**：表示"流已到达文件末尾"。
- **`failbit`**：表示"发生了非致命错误"；原文举例是期望整数却输入了字母。
- **标志通常通过 `ios` 访问**：它们定义在 `ios_base`，但 `ios` 派生自 `ios_base` 且更短好写，所以常用 `std::ios::failbit` 这种写法。
- **`good()`**："若 goodbit 已设置（流 OK）返回 true"。
- **`bad()`**：`badbit` 设置时返回 true，即发生了致命错误。
- **`eof()`**：`eofbit` 设置时返回 true，即到达文件末尾。
- **`fail()`**：`failbit` 设置时返回 true，即发生了非致命错误。
- **`clear()`**："清除所有标志，把流恢复到 goodbit 状态"。
- **`clear(state)`**：清除所有标志后，再设置传入的状态标志。
- **`rdstate()`**："返回当前已设置的标志"。
- **`setstate(state)`**："设置传入的状态标志"。
- **`failbit` 是最常处理的位**：当输入无法按预期提取（如给整数输入了非数字文本）时被设置。
- **流一旦离开 `goodbit`，后续操作都会被忽略**；要恢复流必须调用 `clear()`。
- **input validation（输入验证）**是"检查用户输入是否满足某组标准的过程"。
- **验证分为字符串验证与数值验证**：字符串验证把输入当文本、检查其格式；数值验证检查数值，通常还包括范围。
- **字符串验证在其他语言里常用正则表达式**：C++ 有 regex 库，但原文说 regex 比手写验证慢，只在性能不敏感或手写太繁琐时才用。
- **数值验证还必须处理"根本不是数字"的输入**：这一点与字符串验证不同。
- **提供 `cctype` 字符检查**：包括 `isalnum`、`isalpha`、`iscntrl`、`isdigit`、`isgraph`、`isprint`、`ispunct`、`isspace`、`isxdigit`，属于某个类别的返回非零。
- **姓名验证示例**：只接受字母或空格。对不定长字符串，逐个字符检查，可用 `std::all_of` / `std::ranges::all_of`。
- **该姓名验证并不完善**：用户可以输入乱码或全是空格；原文建议细化条件为"至少一个字符、至多一个空格"。
- **电话号码验证用模板**：`#` 匹配任意数字、`@` 匹配任意字母、`_` 匹配任意空白、`?` 匹配任意字符，其它模板字符必须精确匹配。
- **模板的局限**：若 `#`、`@`、`_`、`?` 本身是合法输入字符，函数就会失效；而且没有表示"不定长度"的模板符号，因此难以验证被空格分隔的两个变长单词。
- **数值验证可用提取 + `failbit`**：把值提取到数值类型，再检查 `std::cin.fail()` 判断输入是否非法。
- **基本数值循环**：失败时先 `clear()`、再 `ignore()` 掉坏输入，然后重试。
- **混合输入问题**：对 `34abcd56` 这类输入，会提取出 `34`，其余留在流中，且 `failbit` **不会**被设置；结果可能让垃圾留在流里，或无法拒绝不需要的输入。
- **修复"残留垃圾"**：在成功提取后无条件调用 `ignore()` 丢弃本行剩余内容。
- **修复"拒绝混合输入"**：在 `ignore()` 之后用 `gcount()`，若返回值大于 1，说明还有额外字符，应把该输入视为非法。
- **把数值验证当作字符串做**：先把输入读成字符串，再用 `std::from_chars` 转换；可封装成返回 `std::optional<int>` 的可复用函数。
- **结论**：C++ 里输入验证相当费工夫，但许多验证任务都能做成可复用函数。

## 最佳实践

本节无 Best practice / Warning 形式的方框。原文只有一条 Author's note：

- **Author's note**：读者 "Waldo" 提供了一个 C++20 解法（使用 `std::ranges`）来弥补这些缺陷，原文给出了该评论的链接。

## 代码示例

- [28-05-example1.cpp](28-05-example1.cpp)：把整数读入 `age`；若输入 `"Alex"` 之类的非数字会置位 `failbit`（原 Example 1，片段补全为可运行程序）。
- [28-05-example2.cpp](28-05-example2.cpp)：用 `std::ranges::all_of` 实现的 `isValidName`（只允许字母或空格），并循环用 `std::getline` 直到姓名合法（原 Example 2，含 C++20 前的注释写法）。
- [28-05-example3.cpp](28-05-example3.cpp)：电话号码模板匹配——`std::map` 把 `#`/`_`/`@`/`?` 映射到验证函数，再用 `std::ranges::equal` 与模板 `"(###) ###-####"` 比较（原 Example 3，含 C++20 前的注释写法）。
- [28-05-example4.cpp](28-05-example4.cpp)：基础数值验证循环——`std::cin.fail()` 时 `clear()` + `ignore()` 后重试，并拒绝非正数（原 Example 4）。
- [28-05-example5.cpp](28-05-example5.cpp)：在 Example 4 基础上，成功提取后额外 `ignore()` 掉本行剩余输入（原 Example 5）。
- [28-05-example6.cpp](28-05-example6.cpp)：在 Example 5 基础上，用 `std::cin.gcount() > 1` 判断是否还有额外字符，若是则视为非法输入并重试（原 Example 6）。
- [28-05-example7.cpp](28-05-example7.cpp)：把数值验证当作字符串——读入一行后用 `std::from_chars` 在 `extractAge` 里解析，返回 `std::optional<int>`（原 Example 7）。

> 说明：本节代码取自原文 HTML 逐字抽取（`<pre>` 块），并补上必要的头文件与 `main()` 以便独立编译。除 Example 1 外，其余示例都是需要标准输入的交互式程序。

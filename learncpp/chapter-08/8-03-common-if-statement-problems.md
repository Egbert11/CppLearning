# 8.3 Common if statement problems

> 原文：https://www.learncpp.com/cpp-tutorial/common-if-statement-problems/

## 核心概念

- **嵌套 if 语句**：if 语句可以放在另一条 if 语句里面。原文指出不加块地嵌套是糟糕的风格。
- **悬垂 else 问题（dangling else problem）**：当 else 出现在嵌套 if 之后时，它到底与哪个 if 配对并不清楚；原文称之为"a source of potential ambiguity"。
- **配对规则**：else 绑定到"同一块中最后一个尚未配对的 if 语句"。因此在有歧义的例子里 else 会附着到内层 if。
- **规则的后果**：这种附着会让程序打印错误结果（例如 21 被报告成负数）。
- **消除歧义**：把内层 if 用花括号包起来，就能把 else 明确地挂到内层或外层 if 上而不产生混淆——块内的 else 绑内层 if，块外的 else 绑外层 if。
- **展平嵌套 if**：嵌套通常可以通过重构逻辑或使用逻辑运算符（参见 6.8 节）来消除。原文的理由："Code that is less nested is less error prone."
- **空语句（null statement）**：定义为"an expression statement that consists of just a semicolon"，不执行任何动作。当语法需要一个语句但实际不需要做任何事时使用，通常单独占一行以增强可读性。
- **空语句与 if**：与 if 一起使用时极少是出于本意，但粗心使用会导致 bug，例如条件后面多出一个分号。
- **分号陷阱**：if 条件后的分号可以编译通过，却会让本想条件执行的语句变成无条件执行。
- **Python 类比（Tip）**：Python 的 `pass` 关键字充当空语句，同时还能占位；因为它是单词而非符号，更不容易被误用也更容易搜索。
- **在 C++ 中模拟 `pass`**：由于 `PASS` 会被预处理器替换掉，行尾的分号就成了一条空语句；该宏定义为空替换文本。
- **operator== 与 operator=**：相等测试要用 `operator==`；误用 `operator=` 会在条件里执行赋值。由于 `x = 0` 把 0 赋给 x 并以 0（布尔假）作为结果，else 分支总会执行。

## 最佳实践

- **Warning**："Do not end an if-statement with a semicolon"，否则你想让它条件执行的语句"will execute unconditionally instead (even if they are inside a block)"。
- **Tip**：Python 的 `pass` 关键字充当空语句，适合当占位符；因为它是单词，"less prone to inadvertent misuse and more searchable"。C++ 中可用 `PASS` 这样的预处理宏模仿它。

本节无 Best practice 条目。

## 代码示例

- [8-03-example1.cpp](8-03-example1.cpp)：嵌套 if（原文注明是不好的风格）。
- [8-03-example2-warning.cpp](8-03-example2-warning.cpp)：悬垂 else 歧义（原文示例 2/3，附注释说明编译器实际分组，输入 21 输出 "21 is negative"；编译时会产生 `-Wdangling-else` 警告）。
- [8-03-example4.cpp](8-03-example4.cpp)：用显式块消除歧义。
- [8-03-example5.cpp](8-03-example5.cpp)：用 else if 链把嵌套展平。
- [8-03-example6.cpp](8-03-example6.cpp)：用 `&&` / `||` 组合条件。
- [8-03-example7.cpp](8-03-example7.cpp)：合法的空语句用法。
- [8-03-example8-broken.cpp](8-03-example8-broken.cpp)：坏实践——if 条件后误加分号，语句无条件执行（原文示例 8/9）。
- [8-03-example11.cpp](8-03-example11.cpp)：用宏 `PASS` 模拟 Python 的 `pass`。
- [8-03-example12-warning.cpp](8-03-example12-warning.cpp)：误把 `==` 写成 `=`，产生 `-Wparentheses` 警告且逻辑错误。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。原文示例 10 是一段 Python `pass` 代码，非 C++，未生成文件，其要点记入上文"核心概念"。

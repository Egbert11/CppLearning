# 8.2 If statements and blocks

> 原文：https://www.learncpp.com/cpp-tutorial/if-statements-and-blocks/

## 核心概念

- **条件语句（conditional statement）**：指定某些关联语句是否应当执行的一类语句。原文定义为"a statement that specifies whether some associated statement(s) should be executed or not"。
- **C++ 的两种条件语句**：`if` 语句（此前已介绍，本节扩展）与 `switch` 语句（稍后讲解）。
- **基本 `if` 形式**：`if (condition)` 后跟一条 `true_statement`；条件为真时执行该语句。
- **可选的 `else`**：条件为假且存在 `else` 时，执行 `false_statement`。
- **单语句限制**：原文强调"the `true_statement` and `false_statement` can only be a single statement"——因此误导性的缩进不会改变程序行为。
- **块（block）解决单语句限制**：复合语句（块）把多条语句组合成一条。"Remember that blocks are treated as a single statement,"所以只要加花括号就能让多行成为分支体。
- **隐式块**：不写块时，编译器会隐式地补一个块；因此裸写形式与给每个分支加花括号等价。
- **作用域后果**：在分支中声明的变量具有块作用域，在块结束时被销毁，之后不再可见。
- **争论：单语句是否该加块**——支持加块的理由：容易在无意中加入非条件语句、注释掉某分支时难以调试、且与 `if constexpr` 的写法保持一致。
- **反对加块的理由**：额外的纵向空白会让同一屏能看到的代码变少，可能影响可读性。
- **单行的折中方案**：把分支语句写在 `if`/`else` 同一行，可同时缓解两个问题，代价是可读性略降；调试时条件与语句会一起单步执行，无法单独给该语句下断点（临时加个换行即可）。
- **if-else 与 if-if 的选用规则**："Use if-else when you only want to execute the code after the first `true` condition." / "Use if-if when you want to execute the code after all `true` conditions."
- **return 语句使 `else` 变得多余**：如果每个分支都 return，省略 `else` 行为完全相同，因为函数在第一个为真的条件处就已退出。

## 最佳实践

- **Best practice**："Consider putting single statements associated with an `if` or `else` in blocks"。原文补充说更有经验的开发者有时为节省纵向空间而省略花括号。
- **Key insight**："When all associated statements return a value, you can always just use if-if since `else` provides no value."

本节无 Author's note / Warning 条目。

## 代码示例

- [8-02-example1.cpp](8-02-example1.cpp)：基本 if-else，判断输入是否大于 10。
- [8-02-example2-broken.cpp](8-02-example2-broken.cpp)：坏实践——误导性缩进，`else` 只关联一条语句，"Too bad!" 总是执行。
- [8-02-example4.cpp](8-02-example4.cpp)：用花括号（复合语句）修正示例 2。
- [8-02-example5-error.cpp](8-02-example5-error.cpp)：变量定义在分支的（隐式）块内，出块即销毁 —— 预期编译失败（同时表达原文示例 5、6）。
- [8-02-example7-broken.cpp](8-02-example7-broken.cpp)：坏实践——只加缩进导致 `gamble()` 总是执行；注释掉一行导致 `checkout()` 变成条件语句（原文示例 7、8）。
- [8-02-example9.cpp](8-02-example9.cpp)：单行折中风格。
- [8-02-example10.cpp](8-02-example10.cpp)：`ifelse` 与 `ifif` 的差异。
- [8-02-example11.cpp](8-02-example11.cpp)：`if` / `else if` 链 + return。
- [8-02-example12.cpp](8-02-example12.cpp)：每个分支都 return 时省略 `else` 的等价 if-if 写法。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。原文示例 3 只是用注释标出示例 2 实际的分组方式，未单独生成文件；示例 5、6 讲的是同一件事（隐式块的作用域），合并为一份 error 文件并在注释中给出显式块等价写法。

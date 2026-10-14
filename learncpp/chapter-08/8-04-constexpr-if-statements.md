# 8.4 Constexpr if statements

> 原文：https://www.learncpp.com/cpp-tutorial/constexpr-if-statements/

## 核心概念

- **普通 `if` 的默认行为**：普通的 if 语句其条件通常在程序运行时求值。
- **条件是常量表达式的情形**：如果条件是常量表达式（例如把 `constexpr` 变量与字面量比较），其值在运行前就已确定，因此只可能有一个分支被走到。
- **为什么运行期求值是浪费的**：一个结果永远不会改变的条件仍然要付出运行期开销，而永远不会执行的分支也不必出现在编译产物里。
- **C++17 的 constexpr if**：这种形式要求条件是常量表达式，并会在编译期求值。
- **分支选择规则**：编译期条件为 `true` 时，整个 if-else 被替换为真分支；为 `false` 时被替换为假分支（若存在），否则什么都不剩。
- **语法规则**：把 `constexpr` 关键字紧跟在 `if` 之后。
- **编译结果**：编译器丢弃永远不可能执行的分支，只留下存活的那条语句。
- **现代编译器（C++17 起）**：对于条件为常量的普通 if，编译器通常会像处理 constexpr if 那样优化掉死分支，但并没有义务这么做。
- **警告**：编译器可能提示你改用 `if constexpr`，即使关闭优化也能保证编译期求值。

## 最佳实践

- **Best practice**："Favor constexpr if statements over non-constexpr if statements when the conditional is a constant expression."

本节无 Warning / Author's note 条目。

## 代码示例

- [8-04-example1.cpp](8-04-example1.cpp)：条件为常量表达式的普通 `if`，else 分支永不执行。
- [8-04-example2.cpp](8-04-example2.cpp)：同样逻辑改用 `if constexpr`。
- [8-04-example3-warning.cpp](8-04-example3-warning.cpp)：示例 2 经编译器只保留真分支后"实际等价"的程序（会产生未使用变量的警告）。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。

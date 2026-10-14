# 8.10 For statements

> 原文：https://www.learncpp.com/cpp-tutorial/for-statements/

## 核心概念

- **for 语句是 C++ 中最常用的循环**。它适用于循环变量显而易见的场合，因为它允许在一行里"定义、初始化、检验、修改循环变量的值"。
- **C++11 起有两种 for**：经典 for 语句（本节）和基于范围的 for 语句（因前置知识未讲，留到 16.8 节）。
- **抽象语法**：`for (init-statement; condition; end-expression) statement;`
- **与 while 的等价改写**：把 init-statement 包进外层块，后接一个 `while (condition)`，其循环体内先执行原循环体、再执行 end-expression，行为完全一致；外层块使循环变量获得"循环作用域"。
- **三部分执行顺序**：
  1. init-statement 在循环开始时**只执行一次**（通常是循环变量的定义/初始化，具有循环作用域）。
  2. condition 每次迭代前检验；为真执行循环体，为假结束循环。
  3. end-expression 在循环体之后执行（通常递增/递减循环变量），然后控制权返回 condition。
- **关键洞见（执行顺序）**：Init-statement → Condition（若为假，循环在此终止）→ Loop body → End-expression（随后跳回 Condition）。
- **可读性权衡**：新手觉得 for 循环难读，但有经验的程序员欣赏它的紧凑——循环变量、条件、修改器信息都集中在顶部，"有助于减少错误"。
- **递减循环**：虽然大多数循环递增 1，循环变量也可以递减。
- **步长大于 1**：循环变量每次可以变化多于 1（例如 `i += 2`）。
- **`operator!=` 的隐患**：`<` 比 `!=` 更安全，因为即使计数器跳过了边界值，`<` 仍会终止；而 `!=` 可能永远不为假，从而无限循环。
- **Off-by-one 错误**：循环次数"比产生期望结果多一次或少一次"。通常是关系运算符写错造成；前置/后置递增递减混淆也可能导致。
- **省略表达式**：for 语句的任何部分都可以省略。省略 init 和 end-expression 意味着要在别处手动完成这些工作。
- **省略 condition 即为 true**：没有条件的 for 循环是无限循环，等价于 `while (true)`。标准有意地把缺失条件表达式当作 true；作者建议避免这种写法，改用 `while (true)`。
- **多个计数器**：可以在 init-statement 中定义多个变量，并在 end-expression 中用逗号运算符同时更新它们。
- **嵌套 for**：for 可以嵌套；外层每迭代一次，内层循环"完整地运行一遍"。
- **循环内定义循环专用变量**：创建变量本身免费，初始化才有开销，而初始化与赋值的开销通常相同。把变量声明在循环外（而循环外并不需要它）会降低可读性，还可能妨碍编译器优化。
- **结论**：for 是 C++ 最常用的循环，因为它把所有需要的信息放在顶部。有计数器变量时它最擅长；没有计数器时，用 while 语句通常更好。

## 最佳实践

- Avoid `operator!=` when doing numeric comparisons in the for-loop condition. Prefer `operator<` or `operator<=` where possible.
- Defining multiple variables (in the init-statement) and using the comma operator (in the end-expression) is acceptable inside a for-statement.
- Variables used only inside a loop should be defined inside the scope of the loop.
- Prefer for-loops over while-loops when there is an obvious loop variable. Prefer while-loops over for-loops when there is no obvious loop variable.
- **Warning**：Qu 3 提示"除非必要，最好避免在 unsigned 变量上循环"，因为 unsigned 变量不可能变成负数。
- **Author's note**：省略条件的 for 循环，作者建议避免并改用 `while (true)`。

## 代码示例

主体示例：

- [`8-10-example1.cpp`](8-10-example1.cpp)：基本 for 循环，打印 1..10。
- [`8-10-example2.cpp`](8-10-example2.cpp)：把同一循环改写为等价的 while 循环（用外层块给出循环作用域）。
- [`8-10-example3.cpp`](8-10-example3.cpp)：`pow(base, exponent)` 用 for 循环实现（注意溢出）。
- [`8-10-example4.cpp`](8-10-example4.cpp)：递减循环，打印 9..0。
- [`8-10-example5.cpp`](8-10-example5.cpp)：循环变量每次加 2，打印 0 2 4 6 8 10。
- [`8-10-example6.cpp`](8-10-example6.cpp)：同一行为分别用 `<` 和 `!=` 写出的两个循环。
- [`8-10-example7.cpp`](8-10-example7.cpp)：用 `<` 的循环，即使循环体跳过 10 仍会终止。
- [`8-10-example7-broken.cpp`](8-10-example7-broken.cpp)：用 `!=` 的同类循环，跳过 10 后**永不终止**（无限循环演示）。
- [`8-10-example8.cpp`](8-10-example8.cpp)：off-by-one——误用 `<` 代替 `<=`，只打印到 4。
- [`8-10-example9.cpp`](8-10-example9.cpp)：省略 init-statement 与 end-expression 的 for 循环。
- [`8-10-example10.cpp`](8-10-example10.cpp)：`for (;;)` 无限循环，等价于 `while (true)`（**有意为之，运行不会自行结束**）。
- [`8-10-example11.cpp`](8-10-example11.cpp)：两个计数器，用逗号运算符同时递增/递减。
- [`8-10-example12.cpp`](8-10-example12.cpp)：嵌套循环（外层字母 a..e，内层数字 0..2）。
- [`8-10-example13.cpp`](8-10-example13.cpp)：在循环外定义 `i`、循环内赋值的反面写法。

本节 Quiz 解答：

- [`8-10-quiz1.cpp`](8-10-quiz1.cpp)：用 for 循环打印 0 到 20 的所有偶数。
- [`8-10-quiz2.cpp`](8-10-quiz2.cpp)：`sumTo(value)` 累加 1 到 value。
- [`8-10-quiz3-broken.cpp`](8-10-quiz3-broken.cpp)：`unsigned int` 倒数循环的 bug——循环永不结束（**不要运行到结束**）。
- [`8-10-quiz4.cpp`](8-10-quiz4.cpp)：`fizzbuzz(count)` 用 for + if/else-if 链实现。
- [`8-10-quiz5.cpp`](8-10-quiz5.cpp)：扩展版 FizzBuzz，为 7 的倍数加上 "pop"，用一个 bool 标志，仅用 4 个 if。

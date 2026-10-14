# 22.2 R-value references

> 原文：https://www.learncpp.com/cpp-tutorial/rvalue-references/

## 核心概念

- **回顾值类别（value categories）**：更早的小节把值类别介绍为"表达式的属性"，用来判断一个表达式最终解析为一个值、一个函数还是一个对象；当时为了讨论左值引用而引入了左值/右值。
- **左值引用（l-value reference）**：C++11 之前只有一种引用类型，就叫做"引用"；C++11 起它被改称为**左值引用**——它"只能用可修改的左值来初始化"。绑定表：可修改左值 能/能改；不可修改左值 否/否；右值 否/否。
- **左值引用到 const（const l-value reference）**：可接受可修改左值、不可修改左值和右值，但什么都不能修改。它很有用，因为它让任意类型的实参都能传入函数而不产生拷贝。
- **右值引用（r-value reference，C++11）**：一种专门用来被右值初始化的引用。语法上：左值引用一个 `&`，右值引用两个 `&&`，"右值引用不能用左值初始化"。绑定表：可修改左值 否/否；不可修改左值 否/否；右值 能/能改。
- **右值引用到 const（const r-value reference）**：只能被右值初始化，且不能修改该右值。
- **两个有用的性质**：其一，它们会把所绑定对象的生命周期延长到与引用本身一样长（const 左值引用也能做到这点）；其二，非 const 右值引用允许你修改那个右值。
- **作为函数参数（最常见的用法）**：用于重载决议，让左值实参与右值实参走向不同的代码分支。右值实参会优先选择右值引用重载——它"被认为比 const 左值引用是更好的匹配"。
- **右值引用变量本身是左值**：一个具名的 `int&&` 类型变量，在被当作表达式使用时其实是**左值**。所以 `fun(ref)` 会调用 `fun(const int&)`，而且根本无法匹配 `fun(int&&)`，因为右值引用不能绑定左值。"对象的类型与其值类别是相互独立的。"
- **返回右值引用**：几乎永远不该这么做，理由与返回左值引用相同——被引用的对象通常在函数结束时消亡，留下悬垂引用。
- **绑定关系小结（测验回顾）**：非 const 左值引用只绑定非 const 左值；const 左值引用绑定非 const 左值、const 左值以及右值；右值引用只绑定右值。

## 最佳实践

本节没有独立的 Best practice / Author's note / Warning 框，但给出若干建议性表述：

- **建议**：You should almost never return an r-value reference, for the same reason you should almost never return an l-value reference.（几乎永远不要返回右值引用，理由与不要返回左值引用相同。）
- **说明**：R-value references are not very often used（右值引用在"延长临时对象生命周期""修改字面量临时对象"这类用法中并不常用），它最主要的用途是函数参数的重载决议。
- **提示**：在重载决议中，右值引用匹配"is considered a better match than an l-value reference to const"（比 const 左值引用更好）。

## 代码示例

- [22-02-example1.cpp](22-02-example1.cpp)：左值引用用左值初始化、右值引用用右值初始化（原 Example 1）。
- [22-02-example2.cpp](22-02-example2.cpp)：用 `auto&&` 绑定临时 `Fraction`，右值引用延长其生命周期，输出 `3/5`（原 Example 2）。
- [22-02-example3.cpp](22-02-example3.cpp)：用字面量初始化右值引用（先创建临时对象），再修改它，输出 `10`（原 Example 3）。
- [22-02-example4.cpp](22-02-example4.cpp)：按 const 左值引用 / 右值引用重载 `fun()`，展示重载决议（原 Example 4）。
- [22-02-example5.cpp](22-02-example5.cpp)：具名右值引用变量是左值——`fun(ref)` 调用的是 `fun(const int&)`（原 Example 5）。
- [22-02-quiz1-error.cpp](22-02-quiz1-error.cpp)：原文本节测验——A~H 八条定义中 B、E、G 编译失败（预期编译失败，勿修复）。

> 说明：本节代码为按原文描述重建。

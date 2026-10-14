# 7.2 User-defined namespaces and the scope resolution operator

> 原文：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/

## 核心概念

- **命名冲突回顾**：当两个同名标识符以编译器或链接器无法区分的方式进入同一程序时就会报错；编译器/链接器无法判断该用哪一个。
- **Key insight（规模问题）**：随着标识符数量增加，"a linear increase in identifiers will result in an exponential increase in potential collisions"（标识符的线性增长会导致潜在冲突的指数级增长）。这是把名字定义在尽可能小的作用域里的主要理由。
- **冲突示例**：两个源文件各自定义同名同参但行为不同的函数，同时链接会产生链接器报出的 multiple-definition 错误；该错误在重定义处出现，与被调用与否无关。
- **改名是一种修法，命名空间更好**：改名会迫使修改所有调用点；更好的做法是把函数放进你自己的命名空间里（标准库移入 `std` 正是这个原因）。
- **定义自己的命名空间**：使用 `namespace` 关键字。用户创建的常被称作 *user-defined namespaces*（更准确叫 *program-defined namespaces*）。
- **语法**：`namespace` 关键字 + 命名空间标识符 + 花括号，命名空间内容放在其中。
- **命名约定**：命名空间名历史上用小写，很多风格指南仍这么建议；本课建议首字母大写，并说明两种都可接受。
- **放置规则**："A namespace must be defined either in the global scope, or inside another namespace."（命名空间必须定义在全局作用域，或另一个命名空间内部。）内容习惯缩进一级，右花括号后可跟可选的分号。
- **限定访问**：放进命名空间后，非限定调用会失败——链接器报 unresolved external symbol，因为两个版本现在各自位于自己的命名空间，而非全局命名空间。
- **作用域解析运算符（scope resolution operator）`::`**："The scope resolution operator tells the compiler that the identifier specified by the right-hand operand should be looked for in the scope of the left-hand operand."（它告诉编译器：右操作数指定的标识符应在左操作数的作用域中查找。）它消除了歧义。
- **`::` 左侧留空**：如 `::doSomething`，表示在全局命名空间中查找。
- **命名空间内部的标识符解析**：非限定查找先查当前命名空间，再依次查各外层命名空间，最后查全局命名空间。
- **命名空间内的前向声明**：为命名空间内容写前向声明时，前向声明也必须放在同一命名空间内；否则它声明的是全局名字，限定调用会报错。
- **多个命名空间块**：命名空间块可以在多个文件或同一文件内被多次声明；所有声明合并为同一个命名空间（标准库正是如此）。
- **Warning**：向 `std` 添加自己的功能 "causes undefined behavior most of the time"（大多数情况下会导致未定义行为）。参见 "Do not add custom functionality to the std namespace."
- **嵌套命名空间**：命名空间可嵌套，用 `Foo::Goo::add` 访问。自 C++17 起，`namespace Foo::Goo` 可直接声明嵌套，效果等价。
- **只向外层命名空间添加**：单独的 `namespace Foo` 块只向 `Foo` 添加声明；分开写还是嵌套写属风格问题。
- **命名空间别名（namespace alias）**：别名临时缩短长限定路径，在其作用域结束（右花括号）处失效。好处：代码迁移时只需改别名，无需改每一处。
- **如何使用命名空间**：命名空间不是信息层级结构，而是防止命名冲突的机制——整个标准库都放在 `std` 就是证据。较新的特性用嵌套命名空间（如 `std::ranges`）来避免 `std` 内部冲突。
- **实践建议**：小型个人程序通常无需命名空间；有第三方库的大型项目受益明显。分发的代码/库应始终使用命名空间，常用单一顶层命名空间（如 `Foologger`），这也便于编辑器自动补全。多团队组织常用两三层：项目/库::模块、公司::项目、或公司::项目::模块。超过 3 层的深层嵌套一般应避免。

## 最佳实践

本节没有独立的 Best practice 条目。相关提示：

- **Key insight**：标识符线性增长 → 潜在冲突然指数级增长。
- **For advanced readers**：建议命名空间名首字母大写的理由——与程序自定义类型保持一致（便于区分 `Foo::x`）、避免与小写的系统/库名冲突、且 C++20 标准文档与 C++ Core Guidelines 均如此。
- **Warning**：Do not add custom functionality to the `std` namespace.（不要向 `std` 命名空间添加自定义功能。）
- **Author's note**：教学示例除非主题就是命名空间，否则通常不加命名空间，以求简洁。
- **延伸阅读**：未命名与内联命名空间见本章 7.14。

## 代码示例

- [7-02-example3.cpp](7-02-example3.cpp)：`Foo`/`Goo` 两个同名 `doSomething`，用 `Foo::doSomething(4, 3)` 调用，输出 7（对应原文 Example 3）。
- [7-02-example4.cpp](7-02-example4.cpp)：同上，改用 `Goo::doSomething(4, 3)`，输出 1（对应原文 Example 4）。
- [7-02-example5.cpp](7-02-example5.cpp)：依次调用两个版本，输出 7、1（对应原文 Example 5）。
- [7-02-example6.cpp](7-02-example6.cpp)：`Foo::print()` 与 `::print()`（全局）对比，输出 Hello there（对应原文 Example 6）。
- [7-02-example7.cpp](7-02-example7.cpp)：命名空间内非限定查找先解析到 `Foo::print()`；输出 Hello there（对应原文 Example 7）。
- [7-02-example8/](7-02-example8/)：`add.h` / `add.cpp` / `main.cpp` —— `namespace BasicMath` 内的前向声明与跨文件调用，输出 7（对应原文 Example 8）。
- [7-02-example9/](7-02-example9/)：`circle.h` / `growth.h` / `main.cpp` —— 多个命名空间块合并进同一 `BasicMath`，输出 3.14、2.7（对应原文 Example 9）。
- [7-02-example10.cpp](7-02-example10.cpp)：嵌套命名空间 `Foo::Goo::add`，输出 3（对应原文 Example 10）。
- [7-02-example11.cpp](7-02-example11.cpp)：C++17 的 `namespace Foo::Goo` 写法，输出 3（对应原文 Example 11）。
- [7-02-example12.cpp](7-02-example12.cpp)：C++17 嵌套写法 + 单独的 `namespace Foo` 块，输出 3、1（对应原文 Example 12）。
- [7-02-example13.cpp](7-02-example13.cpp)：命名空间别名 `namespace Active = Foo::Goo;`，输出 3（对应原文 Example 13）。
- [7-02-example14.cpp](7-02-example14.cpp)：把别名重定向到 `V2`，调用点不变，输出 3（对应原文 Example 14）。

### 原文中"无法编译/无法链接"的示例（仅说明，不生成文件）

- **Example 1（命名冲突）**：`foo.cpp` 与 `goo.cpp` 各自在全局命名空间定义 `doSomething`，`main.cpp` 前向声明后调用。两个同名全局函数同时链接 → 链接器 **multiple-definition（重定义）错误**。此例需要两个互相冲突的文件，无法表达为单个可构建文件，故不生成。
- **Example 2（未解析的外部符号）**：把 `doSomething` 分别放进 `Foo` 与 `Goo` 后，`main.cpp` 仍用非限定调用 → 链接器 **unresolved external symbol** 错误。同样需要跨文件，故不生成；正确做法见 example3–5 的限定调用。

> 说明：本节示例代码为按原文清单与站点标准写法**忠实重建**，以保证可用 `g++ -std=c++20 -Wall` 编译运行；原文代码块本身未逐字获取。

# 7.5 Variable shadowing (name hiding)

> 原文：https://www.learncpp.com/cpp-tutorial/variable-shadowing-name-hiding/

## 核心概念

- **块创建作用域**：每个块定义自己的作用域区域，因此名字可以在嵌套块里各自独立声明。
- **名字隐藏 / 遮蔽（name hiding / shadowing）**：内层块声明了与外层同名的变量时，内层名字在"两者都可见的区域里"隐藏了外层名字。
- **内层块内顺序很重要**：内层声明之前，该名字仍解析为外层变量；声明之后，解析为内层变量。
- **外层变量不受影响**：对内层变量赋值只改内层变量；内层块结束后内层变量销毁，外层保持原值。
- **未声明内层名字即指外层**：若内层没有同名变量，该名字指外层变量，赋值修改的是外层。
- **被遮蔽时无法直接访问**：从嵌套块内部，"no way to directly access the shadowed variable from the outer block"（没有直接访问外层被遮蔽变量的办法）。
- **全局变量也能被遮蔽**：与外层全局同名的局部变量会"在该局部变量可见的任何地方"隐藏该全局变量。
- **全局变量的特殊出口**：全局变量位于全局命名空间，故无前缀的作用域运算符 `::` 可显式指名全局版本。
- **建议避免遮蔽**：它 "can lead to inadvertent errors where the wrong variable is used or modified"（可能导致误用/误改错误的变量），有些编译器会发出警告。
- **命名约定**：若所有全局名字都加 `g_` 前缀，就很容易避免遮蔽全局变量。
- **编译器支持**：GCC 与 Clang 提供 `-Wshadow`，还有 `-Wshadow=global`、`-Wshadow=local`、`-Wshadow=compatible-local` 变体；Visual Studio 默认开启此类警告。

## 最佳实践

- **Best practice**：Avoid variable shadowing.（避免变量遮蔽。）
- **For GCC users**：`-Wshadow` 会在变量被遮蔽时给出警告；其子变体含义见 GCC 文档。（注：`-Wall` 不含 `-Wshadow`，需显式开启。）

## 代码示例

- [7-05-example1.cpp](7-05-example1.cpp)：嵌套块中的局部遮蔽，输出 5、10、5（对应原文 Example 1）。
- [7-05-example2.cpp](7-05-example2.cpp)：内层未声明同名变量，赋值作用于外层，输出 5、10、10（对应原文 Example 2）。
- [7-05-example3.cpp](7-05-example3.cpp)：局部变量遮蔽全局变量，输出 `local variable value: 8`、`global variable value: 5`（对应原文 Example 3）。
- [7-05-example4.cpp](7-05-example4.cpp)：用 `::value` 访问被遮蔽的全局变量，输出 `local variable value: 8`、`global variable value: 4`（对应原文 Example 4）。

> 说明：本节示例代码为按原文清单与站点标准写法**忠实重建**，以保证可用 `g++ -std=c++20 -Wall` 编译运行；原文代码块本身未逐字获取。这些示例在 `-Wall` 下不告警（`-Wshadow` 未包含在 `-Wall` 中）；如需观察遮蔽警告，请额外加 `-Wshadow`。

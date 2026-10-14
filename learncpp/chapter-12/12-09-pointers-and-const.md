# 12.9 Pointers and const

> 原文：https://www.learncpp.com/cpp-tutorial/pointers-and-const/

## 核心概念

- **普通指针的两项能力**：既能改变它保存的地址（重新指向），也能通过解引用改变该地址处的值。
- **普通指针不能指向 const 变量**：把一个普通指针初始化/赋值为 const 变量的地址会编译失败；否则就能通过解引用修改一个被声明为常量的值，破坏其 const 性。
- **指向 const 值的指针（pointer to const value）**：指针本身**不是** const，但指向的值是 const。声明方式是把 `const` 写在被指类型前面（`const int* ptr`）。
- **指向 const 的行为**：因为被指类型是 const，不能通过该指针修改值；因为指针本身不是 const，可以把它重新指向另一个地址。
- **指向 const 的指针可以指向非 const 对象**：此时经由该指针把目标当作 const 处理（不能写），但原来的非 const 标识符仍可修改它。这一点与“指向 const 的左值引用”一致。
- **const 指针（const pointer）**：**一个初始化后地址就不能再改变的指针**。声明方式是把 `const` 写在星号**后面**（`int* const ptr`）。
- **const 指针的要求**：像任何 const 变量一样必须在定义时初始化，之后不能再被重新赋值；若被指的值是非 const，仍可通过它修改该值。
- **指向 const 值的 const 指针**：星号前后各一个 `const`（`const int* const ptr`）。既不能改地址，也不能改被指的值，只能解引用读取。
- **重设地址规则回顾**：非 const 指针可以改指向的地址；const 指针永远保持同一地址。
- **取值/改值规则回顾**：指向非 const 值的指针可以修改所指对象，但不能指向 const 值；指向 const 值的指针把目标当作 const，不能修改它，但可以指向 const 或非 const 的左值，不能指向没有地址的右值。
- **语法助记**：`const` 在星号**左边** → 属于**被指的值**（不能通过指针改值）；`const` 在星号**右边** → 属于**指针本身**（不能改地址）。

## 最佳实践

- 本节无“Best practice / Author's note / Warning”形式的独立提示框。原文强调的助记要点为：
  - `const` 在 `*` 左侧 → 约束**被指向的值**；`const` 在 `*` 右侧 → 约束**指针本身**。
  - 指向非 const 值的指针不能指向 const 值；指向 const 值的指针可以指向 const 或非 const 的左值，但不能指向右值（右值没有地址）。

## 代码示例

- [12-09-example1.cpp](12-09-example1.cpp)：普通指针可重新指向并可改值（原 Example 1）。
- [12-09-example2-error.cpp](12-09-example2-error.cpp)：普通指针指向 const 变量 —— 预期编译失败（原 Example 2）。
- [12-09-example3-error.cpp](12-09-example3-error.cpp)：指向 const 的指针执行 `*ptr = 6` —— 预期编译失败（原 Example 3）。
- [12-09-example4.cpp](12-09-example4.cpp)：指向 const 的指针可重新指向另一个 const 对象（原 Example 4）。
- [12-09-example5-error.cpp](12-09-example5-error.cpp)：指向 const 的指针指向非 const 变量，`*ptr = 6` 仍报错 —— 预期编译失败（原 Example 5）。
- [12-09-example6.cpp](12-09-example6.cpp)：声明 const 指针（原 Example 6）。
- [12-09-example7-error.cpp](12-09-example7-error.cpp)：给 const 指针重新赋值 —— 预期编译失败（原 Example 7）。
- [12-09-example8.cpp](12-09-example8.cpp)：通过 const 指针修改（非 const 的）被指值（原 Example 8）。
- [12-09-example9.cpp](12-09-example9.cpp)：指向 const 值的 const 指针（原 Example 9）。
- [12-09-example10.cpp](12-09-example10.cpp)：四种指针与 const 组合对照（原 Example 10）。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块（原文示例本身不含程序输出）。

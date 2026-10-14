# 15.1 The hidden "this" pointer and member function chaining

> 原文：https://www.learncpp.com/cpp-tutorial/the-hidden-this-pointer-and-member-function-chaining/

## 核心概念

- **导入问题**：C++ 如何知道某个成员函数是在哪个对象上被调用的？答案藏在一个隐式指针里。
- **隐藏的 `this` 指针**：在任意成员函数内部，`this` 是一个 const 指针，保存"当前隐式对象（implicit object）"的地址。
- **隐式与显式等价**：写 `m_id` 与写 `this->m_id` 效果相同；编译器会自动在成员前补上 `this->`，以减少重复。
- **成员选择提醒**：箭头运算符从"指向对象的指针"中选择成员，因此 `this->m_id` 等价于 `(*this).m_id`。
- **`this` 如何传入**：表面只有一个实参的调用，实际携带两个。编译器把 `simple.setID(2)` 改写成普通函数调用 `Simple::setID(&simple, 2)`。
- **定义如何改写**：成员函数被改写为接受最左参数 `this`（一个 const 指针——自身不可重新指向，但所指内容可修改），函数体内成员变成 `this->m_id`。这是实现相关的细节。
- **三步总结**：调用变成 `Simple::setID(&simple, 2)`；隐藏的 `this` 参数收到 `&simple`；函数内成员经 `this` 解析，于是 `this->m_id` 即 `simple.m_id`。
- **无需死记**：这一过程自动完成；要点只是——每个非静态成员函数都有一个 `this` 指针，指向调用它的那个对象。
- **`this` 跟踪当前对象**：每个成员函数只有一个 `this` 参数，它随调用在不同对象间切换。
- **无体积开销**：`this` 是函数参数而非数据成员，因此不会让类实例变大。
- **用途一——消歧义**：当参数与数据成员同名时，用 `this->` 区分成员与遮蔽的局部参数。
- **用途二——返回 `*this` 实现链式调用**：让成员函数按引用返回隐式对象，就能在一条表达式里对同一对象连续调用多个成员函数，即"函数链式调用 / 方法链式调用（method chaining）"。
- **流类比**：`operator<<` 返回流本身，所以 `std::cout << a << b` 能工作；若它返回 `void`，则部分求值的表达式就无法继续。
- **链式如何求值**：返回 `Calc&` 时，`calc.add(5).sub(3).mult(4)` 依次加、减、乘，每一步返回 `calc` 供下一步使用，结果 `((0 + 5) - 3) * 4 == 8`。
- **无需判空**：`this` 总是指向隐式对象，使用前不必检查它是否为 nullptr。
- **重置对象**：构造函数只用于初始化新对象，不应被直接调用。要把对象恢复默认状态，可写 `reset()` 成员函数——值初始化一个临时对象再赋给 `*this`。
- **`this` 与 const**：对非 const 成员函数，`this` 是"指向非 const 值的 const 指针"；对 const 成员函数，`this` 是"指向 const 值的 const 指针"。在 const 对象上调用非 const 成员函数需要丢弃 const 而编译器不允许隐式这么做，于是产生晦涩的报错。
- **为何是指针而非引用**：`this` 被加入 C++ 时引用还不存在，故用指针；现代类 C++ 语言（如 Java、C#）里它则是引用。

## 最佳实践

- **Key insight**：所有非静态成员函数都有一个 `this` const 指针，保存隐式对象的地址。
- **风格建议**：不要到处写 `this->`，那样可读性差且收益小；用 `m_` 前缀区分私有成员与局部变量更简洁。
- **警告**：不要通过直接调用构造函数来重置对象，否则会产生意外行为；应改用 `reset()` 一类的成员函数。
- **For advanced readers**：改写后的签名里 `static` 表示该函数不与类对象绑定，行为类似类作用域中的普通函数（详见 15.7）。

## 代码示例

- [15-01-example1.cpp](15-01-example1.cpp)：`Simple` 类隐式使用 `this`（`m_id`），输出 `2`（原 Example 1）。
- [15-01-example2.cpp](15-01-example2.cpp)：同一 `Simple`，`print()` 显式写 `this->m_id`，输出 `2`（原 Example 2）。
- [15-01-example3.cpp](15-01-example3.cpp)：`this` 在不同调用间指向 a、b 两个对象（原 Example 6）。
- [15-01-example4.cpp](15-01-example4.cpp)：用 `this->data` 消歧义参数与成员（原 Example 7）。
- [15-01-example5.cpp](15-01-example5.cpp)：`Calc` 成员返回 `void`，只能分开调用，输出 `8`（原 Example 9、10）。
- [15-01-example6.cpp](15-01-example6.cpp)：`Calc` 成员返回 `Calc&`，可链式调用 `calc.add(5).sub(3).mult(4)`，输出 `8`（原 Example 11、12）。
- [15-01-example7.cpp](15-01-example7.cpp)：`reset()` 用 `*this = {}` 恢复默认状态，先输出 `8` 再输出 `0`（原 Example 13、14）。
- [15-01-example8-error.cpp](15-01-example8-error.cpp)：在 const 对象上调用非 const 成员函数——预期编译失败（原 Example 15 的报错）。

> 说明：原文给出了完整代码；example3 及 example8 为按原文描述重建（原文相应处为片段或报错文本）。

## 编译说明

单文件示例使用：

```
g++ -std=c++20 -Wall 15-01-example1.cpp -o example1
```

`15-01-example8-error.cpp` 为预期编译失败示例，请勿修复。

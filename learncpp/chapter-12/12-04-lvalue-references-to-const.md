# 12.4 Lvalue references to const

> 原文：https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/

## 核心概念

- **普通左值引用只能绑定可修改左值**。把非 const 引用绑定到 const 对象是被禁止的，否则就能通过引用改掉 const 变量。
- **对 const 的左值引用（lvalue reference to const）**：在声明引用时加上 `const`，让引用把被引用对象视为 const，也称 "const reference"、"reference to const"。
- **const 左值引用可绑定不可修改（const）左值**：允许读取被引用值，但不允许写入。
- **const 左值引用也可绑定可修改左值**：此时透过引用看到的是 const，但底层对象并非 const——仍可通过它原本的标识符修改它。
- **const 左值引用可绑定右值**：会创建一个以该右值初始化的临时对象，引用绑定到这个临时对象（临时对象见 2.5）。
- **const 左值引用可绑定类型不同但能隐式转换的值**：编译器创建一个引用类型的临时对象，用它初始化，再让引用绑定该临时对象。
- **类型转换的注意点**：因为引用的临时对象类型与原件不同（如 `int` 而非 `char`），打印时得到的是整数形式的转换值。
- **临时量的危险**："引用与被引用对象是同一个"这一通常假设，在引用绑定到拷贝临时量或转换临时量时失效——原对象后续变化对引用不可见，反之亦然。
- **生存期延长规则**：临时对象通常在创建它的表达式结束时销毁；但当 const 左值引用**直接**绑定到临时对象时，该临时对象的生存期被延长到与引用一致，从而避免悬垂引用。
- **小结**：普通左值引用只绑定可修改左值；const 左值引用可绑定可修改左值、不可修改左值、右值，是灵活得多的引用类型。
- **高级说明**：生存期延长只对"直接绑定"有效——函数返回的临时对象（即使按 const 引用返回）不享受延长；对类类型右值，把引用绑定到其某个成员会延长整个对象的生存期。
- **constexpr 左值引用（可选）**：给引用加 `constexpr` 可让它出现在常量表达式中，但它只能绑定具有静态存储期（全局或静态局部）的对象，因为其内存地址在编译期已知；不能绑定非静态局部变量。指向 const 变量时需同时写 `constexpr` 与 `const`。鉴于这些限制，这类引用实际用途不大。

## 最佳实践

- **Best practice**：**除非确实需要修改被引用对象，否则优先使用"对 const 的左值引用"而不是"对非 const 的左值引用"。**
- **Warning**："引用与被引用对象是同一个"的假设，在引用绑定到对象的拷贝临时量或转换临时量时会被打破——对原件的修改不会被引用观察到，反之亦然。
- **Key insight（转换）**：若把 const 左值引用绑定到类型不同的值，编译器会创建一个与引用同类型的临时对象，用该值初始化它，再让引用绑定该临时对象。
- **Key insight（绑定灵活性）**：左值引用只能绑定可修改左值；而对 const 的左值引用可绑定可修改左值、不可修改左值和右值，是灵活得多的引用类型。
- **For advanced readers**：生存期延长只在 const 引用**直接**绑定临时量时生效；函数返回的结果（即使按 const 引用返回）不享受延长。对类类型右值，把引用绑定到其成员会延长整个对象的生存期。为何 const 引用可绑定右值留到下一节解释。
- **Related content**：临时对象见 2.5 "Introduction to local scope"。
- **Constexpr lvalue references — Optional**：本节标记为可选；要点是 constexpr 引用要求被引用对象有静态存储期，实际用处不大。

## 代码示例

- [12-04-example1-error.cpp](12-04-example1-error.cpp)：非 const 引用绑定 const 左值 —— 预期编译失败（原 Example 1）。
- [12-04-example2.cpp](12-04-example2.cpp)：const 左值引用绑定 const 左值（原 Example 2）。
- [12-04-example3-error.cpp](12-04-example3-error.cpp)：通过 const 引用读取可行、写入不行 —— 预期编译失败（原 Example 3）。
- [12-04-example4-error.cpp](12-04-example4-error.cpp)：const 引用绑定可修改左值；只能通过原名修改 —— 预期编译失败（原 Example 4）。
- [12-04-example5.cpp](12-04-example5.cpp)：const 引用由右值初始化（输出 5）（原 Example 5）。
- [12-04-example6.cpp](12-04-example6.cpp)：const 引用绑定不同类型（输出 5、97）（原 Example 6）。
- [12-04-example7.cpp](12-04-example7.cpp)：`bombs` 示例——引用绑定的是转换出的临时量（输出 Bombs away!）（原 Example 7）。
- [12-04-example8.cpp](12-04-example8.cpp)：临时对象生存期被延长的演示（原 Example 8）。
- [12-04-example9-error.cpp](12-04-example9-error.cpp)：constexpr 引用只能绑定全局/静态局部 —— 预期编译失败（原 Example 9）。
- [12-04-example10.cpp](12-04-example10.cpp)：constexpr 引用指向 const 变量需同时写 constexpr 和 const（原 Example 10）。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。

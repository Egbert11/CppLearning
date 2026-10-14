# 5.8 Introduction to std::string_view

> 原文：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view/

## 核心概念

- **基本类型的拷贝很廉价**：`int x { 5 }` 初始化时把值 5 拷进为 `x` 分配的内存；对基本类型而言这很快。
- **拷贝 `std::string` 很昂贵**：`std::string s{ "Hello, world!" }` 会把 C 风格字面量拷进字符串自己分配的内存；与基本类型不同，这很慢。
- **无谓的拷贝很浪费**：在简单的打印程序里，只为了打印而创建、随后销毁一份文本副本，纯属浪费。
- **按值传参又多一次拷贝**：函数以按值方式接收 `std::string`，再加上 `main()` 里的局部 `std::string`，同一个字面量会产生两份拷贝。
- **C++17 引入 `std::string_view`**（头文件 `<string_view>`）：用来避免字符串初始化/拷贝的开销。它对**已存在**的字符串（C 风格字符串、`std::string` 或另一个 `std::string_view`）提供**只读**访问，且不拷贝。"只读"意味着可以访问并使用被查看的值，但不能修改它。
- **使用 string_view 的效果**：把打印示例的局部变量和形参都改成 `std::string_view` 后，输出不变，但文本不再被拷贝。
- **Best practice**：只读字符串（尤其是函数形参）优先使用 `std::string_view` 而不是 `std::string`。
- **初始化很灵活**：`std::string_view` 可用 C 风格字符串字面量、`std::string` 或另一个 `std::string_view` 初始化。
- **形参接受度很高**：C 风格字符串和 `std::string` 都能隐式转换为 `std::string_view`，因此一个 `std::string_view` 形参可以接受这三种实参。
- **不能隐式转换为 `std::string`**：因为 `std::string` 初始化要付出昂贵拷贝，C++ 禁止 `std::string_view` → `std::string` 的隐式转换，以防在不需要时意外产生昂贵拷贝。
- **需要转换时的两种显式做法**：(a) 用 `std::string_view` 作初始化器构造 `std::string`（允许，因为极少是无意为之）；(b) 用 `static_cast` 转换。
- **赋值是重新绑定，而非修改**：给 `std::string_view` 赋新的字符串，只是让它改为查看那个新字符串；先前查看的字符串毫发无损。
- **字面量后缀**：双引号字面量默认是 C 风格；加小写 `sv` 后缀即成为 `std::string_view` 字面量。
- **字面量建议**：用 C 风格字面量初始化 `std::string_view` 完全可以，并不需要 `std::string_view` 字面量；即便用了也无妨（"这类字面量其实就是伪装的 C 风格字符串字面量"）。
- **constexpr 支持**：与 `std::string` 不同，`std::string_view` 拥有完整的 `constexpr` 支持，因此 `constexpr std::string_view` 是字符串符号常量的首选（值可在编译期替换）。

## 最佳实践

- **Best practice**：需要只读字符串时优先使用 `std::string_view` 而不是 `std::string`，尤其是函数形参。
- **相关（字面量）**：用 C 风格字面量初始化 `std::string_view` 没问题；`sv` 后缀必须小写。
- 本节没有单独的 Warning 或 Author's note。原文还提示：`using namespace` 的建议同 5.7 一节。

## 代码示例

> 说明：本节的抓取工具限制了长代码块的逐字输出，以下 cpp 为按原文描述与该站标准示例忠实重建，语义与预期输出一致。

- [5-08-example1.cpp](5-08-example1.cpp) — 拷贝代价对比：`int` 初始化、`std::string` 初始化，以及按值传参（对应原文 Example 1–3）。
- [5-08-example2.cpp](5-08-example2.cpp) — 改用 `std::string_view` 后输出相同但不再拷贝（对应 Example 4）。
- [5-08-example3.cpp](5-08-example3.cpp) — 用 C 风格字面量、`std::string`、`std::string_view` 三种来源初始化视图（对应 Example 5）。
- [5-08-example4.cpp](5-08-example4.cpp) — `std::string_view` 形参接受三种实参（对应 Example 6）。
- [5-08-example5.cpp](5-08-example5.cpp) — 显式转换为 `std::string`：构造与 `static_cast` 两种做法（含禁用的隐式转换注释，对应 Example 7）。
- [5-08-example6.cpp](5-08-example6.cpp) — 赋值只重新绑定视图，原字符串不变（对应 Example 8）。
- [5-08-example7.cpp](5-08-example7.cpp) — 字面量三种形态：无后缀、`s` 后缀、`sv` 后缀（对应 Example 9）。
- [5-08-example8.cpp](5-08-example8.cpp) — `constexpr std::string_view` 支持编译期求值（对应 Example 10）。

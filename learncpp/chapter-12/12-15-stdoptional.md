# 12.15 std::optional

> 原文：https://www.learncpp.com/cpp-tutorial/stdoptional/

## 核心概念

- **函数自身无法处理的错误**：负责计算值的函数应当无副作用，因此通常的做法是检测到错误后把它交回调用方。
- **两种传统的“返回错误”方式**：void 函数可以改为返回 `bool` 表示成功/失败；或让返回值函数返回一个正常不会出现的哨兵值。
- **哨兵值的缺点**：调用方必须知道某函数用哪个哨兵；不同版本的函数可能用不同的哨兵；当所有可能的返回值都合法时，这个技术就失效了。
- **除法问题**：`doIntDivision()` 不能用 `0` 作哨兵，因为 `0` 是合法结果——没有任何 int 值天然不可能出现。
- **哨兵值变通**：用 `std::numeric_limits<T>::lowest()`（`max()` 的对应物）返回最负的 `T`，作为失败标记。
- **该变通的问题**：每个调用点都要和 `lowest()` 比较，**冗长难看**；而且当参数本来就产生该值时，会产生**半谓词问题（semipredicate problem）**——结果有歧义。
- **异常作为替代**：异常自带复杂性与性能开销，可能小题大做。
- **三者中最好的**：返回两样东西——一个 `bool` 成功标志加实际值（失败时值为不确定）。
- **C++17 的 `std::optional`**：一个实现“可选值”的类模板；`std::optional<T>` 要么含有一个 `T`，要么什么都不含，它干净地实现了“两值”方案。
- **构造**：带值构造、用空花括号构造、或用 `std::nullopt` 构造。
- **检查是否含值**：调用 `has_value()`，或依赖到 `bool` 的隐式转换。
- **取值**：用 `*` 解引用（若为空是未定义行为）、调用 `value()`（若为空抛 `std::bad_optional_access`）、或调用 `value_or(default)`。
- **类指针的语法**：其接口与指针相似——都有“没有值”“含有值”“检查”“取值”这些操作。
- **但语义不同**：指针是**引用语义**（赋值复制指针而非对象，返回局部变量地址会悬垂）；`std::optional` 是**值语义**（赋值复制值，按值返回是安全的）。
- **`doIntDivision` 内部**：返回 `{}` 得到空 optional；返回一个值则会隐式包装它。
- **返回 `std::optional` 的优点**：它表明函数可能返回也可能不返回值；省去了记哨兵的负担；语法直观。
- **缺点**：解引用前必须确认含值（否则 UB）；且无法传达失败**原因**。
- **可选参数**：按地址传递可以表达可选实参，但非空实参必须是左值；`std::optional` 是同样可接受右值的替代（因为它复制）。
- **该做法的代价**：对复制代价高的类型（如 `std::string`）复制是个问题；普通参数用 const 左值引用可解决，但截至 C++23 `std::optional` 不支持引用。
- **对参数的建议**：只有当 `T` 本来就会按值传递时才用 `std::optional<T>`；否则优先 `const T*`。
- **进阶变通**：可用 `std::reference_wrapper` 在 optional 内部模拟引用。
- **指针版 vs. reference_wrapper 版**：两个程序几乎一样，作者认为前者并不更难读或更难维护。
- **重载**：很多情况下，函数重载是可选参数的更优解。
- **相关内容**：`std::expected`（C++23）处理“返回期望值或非期望的错误码”。

## 最佳实践

- **Best practice（返回）**：对于可能失败、但**不需要**说明失败原因的函数，优先返回 `std::optional` 而不是哨兵值；需要说明原因时是例外。
- **Best practice（参数）**：优先用 `std::optional` 作可选返回类型。
- **Best practice（参数）**：可选函数参数优先用函数重载（在可行时）；否则当 `T` 本来按值传递时用 `std::optional<T>`，当 `T` 复制昂贵时优先 `const T*`。
- **Related content**：`std::expected` 于 C++23 引入，用于“值或错误码”的情形。

## 代码示例

- [12-15-example1.cpp](12-15-example1.cpp)：普通的按值返回函数，引出错误处理问题（原 Example 1）。
- [12-15-example2.cpp](12-15-example2.cpp)：用 `0.0` 哨兵报告错误（原 Example 2）。
- [12-15-example3.cpp](12-15-example3.cpp)：用 `numeric_limits<int>::lowest()` 作哨兵（原 Example 3）。
- [12-15-example4.cpp](12-15-example4.cpp)：返回 `std::optional<int>`（输出 `Result 1: 4`、`Result 2: failed`）（原 Example 4）。
- [12-15-example5.cpp](12-15-example5.cpp)：构造 optional 的三种方式（原 Example 5）。
- [12-15-example6.cpp](12-15-example6.cpp)：检查 optional 是否含值（原 Example 6）。
- [12-15-example7.cpp](12-15-example7.cpp)：取出 optional 中的值（原 Example 7）。
- [12-15-example9.cpp](12-15-example9.cpp)：用指针 + `nullptr` 实现可选参数（原 Example 9）。
- [12-15-example10.cpp](12-15-example10.cpp)：用 `std::optional` 实现可选参数、可接受右值（原 Example 10）。
- [12-15-example11.cpp](12-15-example11.cpp)：（进阶）用 `std::reference_wrapper` 在 optional 内模拟引用（原 Example 11）。
- [12-15-example12.cpp](12-15-example12.cpp)：上例的指针版本（原 Example 12）。
- [12-15-example13.cpp](12-15-example13.cpp)：用重载替代可选参数（原 Example 13）。

> 说明：原文 Example 8 是“指针 vs optional 行为对照表”，非代码，未生成文件。本节代码为按原文描述与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。

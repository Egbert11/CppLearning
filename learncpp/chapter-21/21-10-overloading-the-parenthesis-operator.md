# 21.10 Overloading the parenthesis operator

> 原文：https://www.learncpp.com/cpp-tutorial/overloading-the-parenthesis-operator/

## 核心概念

- **参数最灵活**：多数重载运算符的参数个数是固定的（`operator==` 两个、`operator!` 一个），而 `operator()` 的参数**类型和个数都可以随意变化**。
- **两条规则**：其一，`operator()` **必须作为成员函数**实现；其二，在类里它就是一个名为 `operator()` 的普通重载运算符，用“函数调用”语法触发。
- **动机（二维索引）**：`Matrix` 内部是 4x4 数组，需要两个下标才能访问元素。C++23 之前 `operator[]` 只接受一个参数，无法直接索引二维数组，于是用 `operator()`。
- **解法**：因为 `operator()` 可接受任意个参数，给它写一个“两个 int 下标”的版本即可访问二维数据；同时提供 const 重载，让 const 对象也能读取。
- **零参数重载**：还可以写一个无参的 `operator()`，例如把矩阵所有元素重置为 0.0。
- **慎用**：`()` 太灵活，容易诱使你拿它做各种事，但这被**强烈不建议**，因为符号本身看不出操作含义。例如“清除”操作写成具名函数 `clear()` / `erase()` 会更清晰。
- **C++23 提醒**：C++23 起 `operator[]` 也可接收多个下标，行为与上面的 `operator()` 示例相同。
- **仿函数（functors / function objects）**：常用 `operator()` 造出“用起来像函数”的类；相比普通函数，它的优势是能带数据成员。
- **仿函数的复用与扩展**：可以创建任意多个仿函数对象同时使用，也可提供别的便利成员函数（如 `reset()`）。
- **推荐用途**：`operator()` 常用于“多参数索引多维数组”或“返回一维数组的子集”；除此之外的操作大概率写成具名成员函数更好。简单仿函数较易理解，但仿函数整体偏进阶。
- **测验**：写 `MyString` 包装 `std::string`，重载 `operator<<` 打印自身，重载 `operator()` 返回从第一个参数起、长度为第二个参数的子串（可用 `std::string::substr`）。额外加分：为效率改为返回 `std::string_view`。

## 最佳实践

- 原文没有正式的 Best practice / Warning 框；要点为：**不要滥用 `operator()` 做各种奇怪操作，除“多维索引 / 取子集”外应改用有描述性名字的成员函数**。
- 注意（C++23）：`operator[]` 现在可以接收多个下标。
- 警告（额外加分 Step 3）：改用 `std::string_view` 时务必**不要返回指向临时 `std::string` 的视图**（会悬垂）；只创建指向 `m_string` 的 `std::string_view` 才是安全的。

## 代码示例

- [21-10-example1.cpp](21-10-example1.cpp) — `Matrix` 的双下标 `operator()` + const 重载（输出 `4.5`）。
- [21-10-example2.cpp](21-10-example2.cpp) — 追加零参数 `operator()` 清空矩阵（输出 `0`）。
- [21-10-example3.cpp](21-10-example3.cpp) — `Accumulator` 仿函数（输出 `1 4 10 30`）。
- [21-10-quiz1.cpp](21-10-quiz1.cpp) — 测验 1：`MyString` 的 `operator()` 返回子串（输出 `world`）。
- [21-10-quiz2.cpp](21-10-quiz2.cpp) — 测验 2 额外加分：返回 `std::string_view` 的版本（输出 `world`）。

说明：本节代码为按原文描述重建（原文长代码块受抓取工具逐字引用上限所限）。

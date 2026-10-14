# 5.7 Introduction to std::string

> 原文：https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/

## 核心概念

- **C 风格字符串变量问题多**：它们"行为古怪、难以使用……而且危险"；无法直接赋新值；把更长的字符串拷进原本为更短字符串准备的存储区会引发未定义行为。
- **现代替代品**：C++ 加入了 `std::string` 与 `std::string_view`（C++17）。与基本类型不同，它们是**类类型**，但基本用法很简单。
- **头文件与创建**：`std::string` 位于 `<string>`，创建方式与其他对象一样，例如 `std::string name {};` 创建空字符串。
- **初始化与赋值**：可以像普通变量那样初始化，也能正常重新赋值。
- **"数字样"的字符串仍是文本**：`"45"` 不是整数 45，不能当数字运算（不能相乘），且 C++ **不会**在字符串与数值类型间自动转换。
- **输出**：`std::string` 可正常用 `std::cout` 打印；空字符串什么都不打印。
- **长度可变**：同一个对象可以先后存放不同长度的字符串（更长或更短），这是它的一大优势。
- **动态内存分配**：存储不足时，`std::string` 会在运行期申请更多内存。灵活但"相对较慢"，将在后续章节讲解。
- **`std::cin` 的输入陷阱**：`operator>>` 只提取到第一个空白字符为止，其余留在流中，因此读"全名"会失败。
- **`std::getline()`**：要读整行，用 `std::getline()`，第一个参数为 `std::cin`，第二个为字符串变量。
- **`std::ws` 操纵符**：告诉 `std::cin` 在提取前跳过前导空白（空格、制表、换行）。
- **遗留换行问题**：`operator>>` 会把用户按下的换行符留在流里；其后紧跟的 `std::getline()` 会立即读到空字符串而不是等待输入。
- **字符串长度**：用成员函数 `name.length()` 获取长度。注意 `std::string` 自 C++11 起以空字符结尾，但返回的长度**不含**结尾的空字符。
- **成员函数语法**：普通函数写成 `function(object)`，成员函数写成 `object.function()`。
- **`length()` 的返回类型**：返回无符号整型（很可能是 `size_t`）；存进 `int` 时应使用 `static_cast<int>` 以避免有符号/无符号告警。
- **C++20 的 `std::ssize()`**：以较大的**有符号**类型（通常是 `std::ptrdiff_t`）返回长度；存进 `int` 时同样用 `static_cast`。
- **拷贝代价高**：初始化一个 `std::string` 会复制源字符串，因此应尽量避免拷贝。
- **不要按值传递**：按值传递 `std::string` 会实例化并复制形参，代价昂贵。
- **返回 `std::string`**：当返回的表达式是以下之一时按值返回可接受：局部的 `std::string`；另一个调用/运算符按值返回的 `std::string`；在 return 语句中创建的临时对象（移动语义）。否则尽量避免。
- **返回字面量 / 引用**：返回 C 风格字符串字面量时，返回类型优先用 `std::string_view`；某些情形下也可返回（const）引用。
- **`s` 后缀字面量**：给双引号字面量加小写 `s` 会使其成为 `std::string` 字面量；该后缀位于 `std::literals::string_literals`。
- **推荐的 using 指令**：优先用 `using namespace std::string_literals;`，而不是导入全部标准字面量；避免在头文件中、函数外使用此类指令。
- **字面量解析**：`"Hello"s` 会解析为由 C 风格字面量初始化得到的临时 `std::string`。
- **constexpr 字符串**：C++17 及更早不支持定义 `constexpr std::string`；C++20/23 中也只在极有限情况下可用；应改用 `std::string_view`。
- **结论**：`std::string` 内部很复杂，但这些复杂度在简单的输入输出任务中并不需要关心。

## 最佳实践

- **Best practice（getline 与空白）**：用 `std::getline()` 读字符串时，应配合 `std::cin >> std::ws` 操纵符跳过前导空白。每次调用 `std::getline()` 都要重复写 `std::ws`，因为它不会在调用之间保留。
- **Best practice（传递字符串）**：不要按值传递 `std::string`，因为会产生昂贵的拷贝。
- **关键要点（提取行为）**：`operator>>` 忽略前导空白、遇到非前导空白即停止；`std::getline()` 不忽略前导空白（可传 `std::cin >> std::ws` 使其忽略），遇到换行停止。
- **关键要点（动态内存）**：`std::string` 内存不足时会通过动态内存分配在运行期申请更多内存；这种灵活性也使它相对较慢。动态分配将在后续章节讲解。
- **关键要点（函数调用语法）**：普通函数以 `function(object)` 调用，成员函数以 `object.function()` 调用。
- **Tip（参数）**：多数情况下应使用 `std::string_view` 形参而不是 `std::string`（见 5.8）。
- **Tip（返回字面量）**：返回 C 风格字符串字面量时，返回类型应改用 `std::string_view`（见 5.9）。
- **Tip（字面量后缀）**：`s` 后缀属于 `std::literals::string_literals`；推荐用 `using namespace std::string_literals;`，它只导入 `std::string` 字面量。

## 代码示例

> 说明：本节的抓取工具限制了长代码块的逐字输出，以下 cpp 为按原文描述与该站标准示例忠实重建，语义与预期输出一致。

- [5-07-example1.cpp](5-07-example1.cpp) — `std::string` 基础：创建、初始化、重新赋值、输出、空字符串、长度可变、"数字样"字符串（对应原文 Example 1–7）。
- [5-07-example2.cpp](5-07-example2.cpp) — `std::cin >>` 遇空白即停的 bug：读全名失败（对应 Example 8，需交互输入）。
- [5-07-example3.cpp](5-07-example3.cpp) — 用 `std::getline(std::cin >> std::ws, name)` 修正，读取整行（对应 Example 9，需交互输入）。
- [5-07-example4.cpp](5-07-example4.cpp) — 遗留换行 bug：先读 `int` 再 `getline`（不加 `std::ws`）会读到空字符串（对应 Example 10，需交互输入）。
- [5-07-example5.cpp](5-07-example5.cpp) — 在 `getline` 前加上 `std::ws` 的修正版（对应 Example 11，需交互输入）。
- [5-07-example6.cpp](5-07-example6.cpp) — 取长度：`name.length()` 与 C++20 的 `std::ssize(name)`（对应 Example 12–13）。
- [5-07-example7.cpp](5-07-example7.cpp) — `s` 后缀的 `std::string` 字面量（对应 Example 14）。
- [5-07-example8-error.cpp](5-07-example8-error.cpp) — `constexpr std::string` 编译错误（对应 Example 15，错误行以注释保留）。
- [5-07-example9.cpp](5-07-example9.cpp) — 本节测验解答：读取全名与年龄，把无符号长度转成有符号 `int` 后相加输出（对应 Example 16，需交互输入）。

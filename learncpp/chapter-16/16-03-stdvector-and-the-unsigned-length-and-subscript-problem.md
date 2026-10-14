# 16.3 std::vector and the unsigned length and subscript problem

> 原文：https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem/

## 核心概念

- **下标类型应与长度类型一致**：用来给数组下标的类型，应当与存储其长度的类型相同，这样才能索引到"可能的最大数组"的每个元素，且不多不少。
- **1997 年的设计选择是无符号**：标准库容器类大约在 1997 年设计时，设计者选择了无符号类型来存放长度和下标。
- **当时的理由**：标准库数组类型的下标"不可能为负"；无符号能多出一位取值范围（在 16 位时代有意义）；范围检查只需一次比较而不是两次。
- **如今被认为是个错误**：无符号并不能真正强制非负，因为"一个负的有符号整数会隐式转换成一个很大的无符号整数，产生垃圾结果"。
- **多一位与范围检查的理由也站不住脚**：现代 32/64 位系统并不需要那一位；而常用的 `operator[]` 根本不进行范围检查。
- **对程序员的影响**：由于容器使用无符号长度/下标，用它们时无法回避无符号值——"我们只能接受这个选择以及它带来的不必要复杂度"。
- **符号转换是收窄转换**：有符号与无符号类型都无法表示对方的全部取值，因此在运行期转换属于收窄（narrowing）。
- **收窄何时被禁止/允许**：列表初始化拒绝收窄转换（编译错误）；拷贝初始化允许它，可能警告也可能不警告（GCC 和 Clang 在 `-Wsign-conversion` 下会警告）。
- **constexpr 例外**：若被转换的值是 `constexpr` 且能放进目标类型，则不算收窄，因为编译器能保证安全，否则就中止编译。
- **`size_type` 的定义**：每个标准库容器都定义了一个嵌套 typedef 成员 `size_type`——即该容器用于表示长度（以及长度支持时的下标）的类型别名。
- **`size_type` 默认为 `std::size_t`**：因为它几乎从不改变，可以放心把 `size_type` 当作 `std::size_t` 的别名——一种无符号大整数类型（通常是 `unsigned long` 或 `unsigned long long`）。
- **作用域规则**：要写明这个成员必须用完全模板化的容器名限定，如 `std::vector<int>::size_type`。
- **用 `size()` 取长度**：成员函数 `size()` 以无符号 `size_type` 返回长度。与 `std::string`/`std::string_view` 不同，`std::vector` 只有 `size()`，没有 `length()`。
- **用 `std::size()` 取长度（C++17）**：非成员 `std::size()` 对容器类只是调用成员 `size()`；它也能作用于未退化的 C 风格数组，因此在函数模板中有用。
- **把长度存进有符号变量**：把两者之一存进有符号类型很可能产生转换警告或错误，"这里最简单的做法是用 static_cast 把结果转成目标类型"。
- **`std::ssize()`（C++20）**：这个非成员函数以有符号大整数类型（通常是 `std::ptrdiff_t`）返回长度；三者中只有它返回有符号类型。赋给 `int` 时应 `static_cast<int>`，或用 `auto` 让编译器推导正确的有符号类型。
- **`operator[]` 不做边界检查**：越界下标是未定义行为。下标可以是非 const 的。
- **`at()` 做运行期边界检查**：它验证下标，有效则返回引用；下标无效时终止程序。内部抛 `std::out_of_range`，未捕获的异常会终止程序。`at()` 比 `operator[]` 慢但更安全；通常更偏好 `operator[]`，因为最好在索引之前先做边界检查。
- **用 constexpr 有符号 int 索引没问题**：像字面量 `3` 或 `constexpr int` 下标会隐式转成 `std::size_t`，且不算收窄转换。
- **用非 constexpr 的 `std::size_t` 索引没问题**：`operator[]` 本就期望 `std::size_t`，无需转换。
- **用非 constexpr 有符号 int 索引会警告**：它必须转成 `std::size_t`；虽然对非负下标并不危险，但在运行期算作收窄，应当产生警告，可能刷屏日志或在"警告即错误"下中断编译。
- **最简单的修法**：把下标变量本身设为 `std::size_t`，并只用它来索引，从而完全避免非 constexpr 转换。

## 最佳实践

- **Key insight**：`size_type` 是标准库容器类中定义的嵌套 typedef，用作该容器长度（以及长度支持时的下标）的类型；它默认为 `std::size_t`，因此实践中可假定 `size_type` 就是 `std::size_t` 的别名。
- **For advanced readers（分配器）**：除 `std::array` 外，每个标准库容器都用 `std::allocator` 分配内存；容器的 `size_type` 来自其分配器的 `size_type`，而 `std::allocator<T>::size_type` 就是 `std::size_t`，故容器 `size_type` 默认为 `std::size_t`。只有自定义分配器才会改变它，这很罕见。
- **For advanced readers（`std::size()`）**：由于 `std::size()` 也能作用于未退化的 C 风格数组，它有时比成员函数更受青睐，尤其是在能同时接受容器或 C 风格数组的模板中。
- **For advanced readers（`at()` 异常）**：越界下标会让 `at()` 抛出 `std::out_of_range` 异常；未处理会终止程序。异常见第 27 章。
- **Tip**：与其直接对 `std::vector` 下标，不如对 `data()` 返回的指针下标。`std::vector` 把元素存在一个 C 风格数组中，而 C 风格数组同时接受有符号和无符号索引，因此不会产生符号转换警告。
- **Author's note**：这些索引挑战的其他方案见 16.7。

本节无 Best practice / Warning 条目。

## 代码示例

- [16-03-example1-error.cpp](16-03-example1-error.cpp)：列表初始化拒绝符号收窄（编译失败），拷贝初始化仅可能警告（原 Example 1）。
  - 注意：GCC 15 默认把列表初始化的收窄转换降级为 `-Wnarrowing` 警告，需加 `-pedantic-errors`（或用 Clang/MSVC）才能复现标准要求的硬错误。
- [16-03-example2.cpp](16-03-example2.cpp)：当源值是 `constexpr` 时，同样的转换不算收窄、可以编译（原 Example 2）。
- [16-03-example3.cpp](16-03-example3.cpp)：用成员 `size()` 取长度，输出 `length: 5`（原 Example 3）。
- [16-03-example4.cpp](16-03-example4.cpp)：用 C++17 的 `std::size()` 取长度（原 Example 4）。
- [16-03-example5.cpp](16-03-example5.cpp)：用 `static_cast<int>` 把长度存进有符号 `int`（原 Example 5）。
- [16-03-example6.cpp](16-03-example6.cpp)：用 C++20 的 `std::ssize()` 得到有符号长度（原 Example 6）。
- [16-03-example7.cpp](16-03-example7.cpp)：把 `std::ssize()` 的结果 `static_cast` 为 `int`（原 Example 7）。
- [16-03-example8.cpp](16-03-example8.cpp)：用 `auto` 推导 `std::ssize()` 的有符号类型（原 Example 8）。
- [16-03-example9-ub.cpp](16-03-example9-ub.cpp)：`operator[]` 不做边界检查，越界下标导致未定义行为（原 Example 9）。
- [16-03-example10.cpp](16-03-example10.cpp)：`at()` 做运行期边界检查，越界时抛异常并终止程序（原 Example 10）。
- [16-03-example11.cpp](16-03-example11.cpp)：用字面量与 constexpr 下标索引（原 Example 11）。
- [16-03-example12.cpp](16-03-example12.cpp)：用非 constexpr 的 `std::size_t` 下标，无需转换（原 Example 12）。
- [16-03-example13-warning.cpp](16-03-example13-warning.cpp)：用非 constexpr 的有符号 int 下标，预期产生收窄警告（原 Example 13）。
- [16-03-example14.cpp](16-03-example14.cpp)：改为对 `data()` 返回的指针下标，避免符号转换警告（原 Example 14）。
- [16-03-quiz1.cpp](16-03-quiz1.cpp)：Quiz #1 解答——输出数组长度并用两种方式打印下标 1 的元素（原 Example 15）。

> 说明：本节代码为按原文描述重建。

# 17.3 Passing and returning std::array

> 原文：https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray/

## 核心概念

- **按值传递 `std::array` 代价高**：数组对象像普通对象一样，按值传参会拷贝，通常按 (const) 引用传递。
- **元素类型与长度都是类型的一部分**：接收 `std::array` 的函数形参必须写全两者，例如 `const std::array<int, 5>&`。
- **CTAD 对函数形参无效**：形参里不能只写 `std::array` 让编译器推导模板实参。
- **函数模板处理不同元素类型/长度**：把 `T` 与 `N` 都参数化，一个模板就能为任意元素类型与长度生成函数。
- **`std::array` 的声明**：它是带一个类型参数和一个 `std::size_t` 非类型参数 `N` 的模板，因此可以照搬其参数声明写自己的函数模板。
- **Warning——必须用 `std::size_t`**：因为 `std::array` 的非类型参数是 `std::size_t`，写成 `int` 会导致编译器无法匹配实参，因为模板不做转换。
- **只模板化一个参数也可行**：可以只模板化长度、把元素类型固定为 `int`，但用其他元素类型调用就找不到匹配。
- **C++20 的 `auto` 非类型模板参数**：写 `auto N` 让编译器从实参推导非类型参数的类型，无需记住确切类型。
- **`static_assert(N != 0)`**：可在模板体内拒绝零长数组。
- **`operator[]` 越界是未定义行为**：总读下标 3 的模板对 2 元素数组照样编译通过，导致 UB。
- **`std::get<index>()` 做编译期边界检查**：用它替换 `operator[]`，非法访问就变成编译错误。
- **`static_assert` 可强制长度前置条件**：如 `static_assert(N > 3)`，长度太小时实例化失败。
- **返回 `std::array` 比 `std::vector` 更棘手**：`std::array` 不具备移动能力，按值返回会拷贝整个数组；元素可移动则移动，否则拷贝。
- **按值返回可接受的场合**：数组不大、元素类型拷贝/移动便宜、且代码不追求性能。
- **按值返回的优缺点**：优点是写法常规、明确返回值、可在一条语句里定义并初始化数组；缺点是会拷贝数组及其元素，且调用者必须显式给出模板实参（没有形参可供推导）。
- **输出参数返回**：调用者传入非 const 引用（或地址）让函数填充。优点是从不发生拷贝；缺点是不常规、只能赋值不能初始化、也无法产生临时对象。
- **考虑改用量 `std::vector`**：`std::vector` 可移动，按值返回可避免昂贵拷贝；若返回的 `std::array` 不是 constexpr，改用 vector 可能更好。

## 最佳实践

- 本节无正式 Best practice 条目。
- **Warning**：`std::array` 的非类型模板参数必须是 `std::size_t`，不能用 `int`。`std::array` 是用 `std::size_t N` 声明的，写 `int` 会让编译器无法把 `std::array<T, std::size_t>` 与 `std::array<T, int>` 匹配——模板不做转换。
- **Key insight**：应写 `static_assert (N > 3);` 而不是 `static_assert (std::size(arr) > 3)`；后者在 C++23 之前因 17.2 的语言缺陷无法编译。
- **Related content**：函数模板见 11.6；前置条件 / `static_assert` 见 9.6。

## 代码示例

- [17-03-example1.cpp](17-03-example1.cpp)：按 `const std::array<int, 5>&` 传参，输出 `9`。
- [17-03-example2.cpp](17-03-example2.cpp)：`<typename T, std::size_t N>` 函数模板 + `static_assert(N != 0)`。
- [17-03-example3-error.cpp](17-03-example3-error.cpp)：只模板化长度、元素固定为 int，用 double 数组调用 → 编译失败（-error）。
- [17-03-example4.cpp](17-03-example4.cpp)：C++20 `template <typename T, auto N>`。
- [17-03-example5.cpp](17-03-example5.cpp)：`printElement3` 读 `arr[3]`，5 元素数组正常，输出 `3`。
- [17-03-example6-ub.cpp](17-03-example6-ub.cpp)：同一函数用 2 元素数组调用 → 越界未定义行为（-ub）。
- [17-03-example7-error.cpp](17-03-example7-error.cpp)：改用 `std::get<3>` → 编译期报错（-error）。
- [17-03-example8-error.cpp](17-03-example8-error.cpp)：`static_assert(N > 3)` → 短数组编译报错（-error）。
- [17-03-example9.cpp](17-03-example9.cpp)：按值返回 `inputArray<T, N>()`。
- [17-03-example10.cpp](17-03-example10.cpp)：输出参数版本 `inputArray(std::array<T, N>&)`。
- [17-03-quiz1.cpp](17-03-quiz1.cpp)：Quiz 解答——`printArray` 模板，输出两行数组信息。

> 说明：本节代码为按原文描述重建。

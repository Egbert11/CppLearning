# 16.4 Passing std::vector

> 原文：https://www.learncpp.com/cpp-tutorial/passing-stdvector/

## 核心概念

- **vector 与普通对象一样可传参**：`std::vector` 能像任何对象一样传给函数，但按值传递会触发昂贵的拷贝。
- **优先（const）引用**：由于拷贝代价大，通常做法是按 const 引用传递 vector。
- **元素类型属于类型本身**：元素类型存在于对象的类型信息中，因此使用 `std::vector` 的函数参数必须显式写出元素类型。
- **不同元素类型间不能隐式转换**：期望 `std::vector<int>` 的函数不能接受 `std::vector<double>`；这是编译错误，因为这两种类型不能互相转换。
- **CTAD 不能用于函数参数**：虽然类模板实参推导可在定义变量时推导元素类型，但它"（目前）不能用于函数参数"。
- **函数模板可解决**：把元素类型参数化，编译器就能为每种实际类型实例化出对应函数。
- **实例化如何发生**：用 `primes`（`std::vector<int>`）调用会实例化 `int` 版本；用 `dbl`（`std::vector<double>`）调用会实例化 `double` 版本。
- **泛型模板接受更多类型**：以 `T` 为模板参数、接受 `const T&` 的模板可作用于任何支持 `operator[]` 的类型——vector、`std::array`、`std::string` 等。
- **C++20 缩写模板**：`auto` 参数以更少语法实现同样效果。
- **过于泛型的缺点**：如果某类型能编译却不具语义，就容易埋下隐患。
- **长度假设招致未定义行为**：像 `printElement3` 这样固定索引元素 3 的函数，无论 vector 多短都会去索引；过短的 vector 导致 UB。
- **运行期断言选项**：可以对 `arr.size()` 断言，debug 构建能抓到错误，但由于 `size()` 不是 constexpr，只能在运行期生效。
- **运行期替代方案**：`std::ssize`（C++20）在有符号下标与长度比较时免去强制转换。
- **Quiz 要点**：要能检测负下标，下标参数应为 `int` 而非 `std::size_t`。

## 最佳实践

- **Tip（关于对数组长度断言）**：比断言更好的做法是——需要断言长度时别用 `std::vector`，改用支持 constexpr 数组的类型如 `std::array`，这样能对长度做 `static_assert`（见 17.3）。最好的做法是避免写出依赖调用者传入"至少某长度"的 vector 的函数。
- **Related content**：函数模板背景见 11.6。

本节无 Best practice / Author's note / Warning 条目。

## 代码示例

- [16-04-example1.cpp](16-04-example1.cpp)：按 const 引用传递 vector，且须显式写出 `<int>`（原 Example 1）。
- [16-04-example2-error.cpp](16-04-example2-error.cpp)：`std::vector<double>` 不能绑定到 `std::vector<int>` 参数，预期编译失败（原 Example 2）。
- [16-04-example3-error.cpp](16-04-example3-error.cpp)：在函数参数里用 CTAD 是错误（原 Example 3）。
- [16-04-example4.cpp](16-04-example4.cpp)：用函数模板参数化元素类型，同时支持 int 与 double 的 vector（原 Example 4）。
- [16-04-example5.cpp](16-04-example5.cpp)：接受任何带 `operator[]` 的泛型模板（原 Example 5）。
- [16-04-example6.cpp](16-04-example6.cpp)：C++20 缩写函数模板 `const auto&`（原 Example 6）。
- [16-04-example7.cpp](16-04-example7.cpp)：`printElement3` 在长度足够的 vector 上正常输出（原 Example 7）。
- [16-04-example8-ub.cpp](16-04-example8-ub.cpp)：同样函数作用在 2 元素 vector 上，越界索引导致未定义行为（原 Example 8）。
- [16-04-quiz1.cpp](16-04-quiz1.cpp)：Quiz 解答——带边界检查的 `printElement`，下标用 `int` 以便检测负数（原 Example 10）。

> 说明：原 Example 9 是测验起始骨架（`printElement` 留空，无法独立编译），故不生成 cpp。本节代码为按原文描述重建。

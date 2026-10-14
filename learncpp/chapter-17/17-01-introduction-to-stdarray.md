# 17.1 Introduction to std::array

> 原文：https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/

## 核心概念

- **三种常用数组类型**：`std::vector`、`std::array`、C 风格数组。容器（container）存储一组没有名字的对象，这些对象称为元素（element）。
- **数组的特点**：元素在内存中连续存放、没有间隙，因此能用下标快速随机访问任意元素。
- **定长数组 vs 动态数组**：定长数组（fixed-size / fixed-length array）的长度在实例化时就已知且不可改变——C 风格数组与 `std::array` 属于此类；动态数组（dynamic array）可在运行时调整长度——`std::vector` 属于此类。
- **`std::vector` 的取舍**：它比定长数组略微低效，且只在"非常有限的场合"支持 `constexpr`。
- **为什么看重 constexpr**：现代 C++ 重视 constexpr 数组带来的健壮性与更好的编译器优化。
- **声明形式**：`std::array` 接受两个模板实参——元素类型，以及给出长度的整型非类型实参。
- **长度必须是常量表达式**：常见写法是整型字面量、`constexpr` 变量或无作用域枚举项；用宏也可以但不推荐（优先用 constexpr 变量）。
- **被拒绝的长度**：非 const 变量与运行期常量都不能作为长度，否则是编译错误。
- **零长数组**：`std::array` 的长度可以为 0，此时它是一个"无数据"的特殊类；对它调用任何访问数据的成员（包括 `operator[]`）都是未定义行为，用 `empty()` 判断是否为空。
- **聚合类型**：`std::array` 没有构造函数，是聚合类型，用聚合初始化。
- **聚合初始化**：用花括号列表从元素 0 开始按顺序初始化。
- **无初始化列表时**：定义时不带初始化列表会默认初始化元素（通常留下不确定值）；应改用空花括号做值初始化。
- **初始化列表个数**：多于长度是编译错误；少于长度则剩余元素被值初始化。
- **const 数组**：`const std::array` 的元素即使没有显式标注，也被当作 const 对待，不能修改。
- **constexpr 支持**：`std::array` 完整支持 constexpr，这是使用它的关键理由。
- **CTAD（C++17）**：类模板实参推导可从初始化列表同时推导元素类型与长度。
- **CTAD 不能部分省略**：截至 C++23，CTAD 不能只省略长度或只省略类型。
- **`std::to_array`（C++20）**：借助函数模板实参推导，可省略长度（也可只给类型）；它比直接创建更昂贵，因为会先构造一个临时对象。
- **元素访问**：常用 `operator[]`，它不做边界检查，越界下标是未定义行为。

## 最佳实践

- **Best practice**：constexpr 数组用 `std::array`，非 constexpr 数组用 `std::vector`。
- **Best practice**：尽可能把数组定义为 `constexpr`；如果某个数组不是 constexpr，考虑改用它处使用 `std::vector`。
- **Best practice**：使用 CTAD，让编译器从初始化列表推导 `std::array` 的类型与长度。
- **Warning**：`std::array` 的长度可以定义为 0，此时它没有数据；调用任何触及数据的成员（包括 `operator[]`）都会产生未定义行为。
- **Related content**：非类型模板参数见 11.9；struct 聚合初始化见 13.8。

## 代码示例

- [17-01-example1.cpp](17-01-example1.cpp)：声明 `std::array<int, 5>` 与 `std::vector<int>(5)` 的对比。
- [17-01-example2.cpp](17-01-example2.cpp)：合法的长度写法——字面量、constexpr 变量、枚举项、宏。
- [17-01-example3-error.cpp](17-01-example3-error.cpp)：运行期常量/输入值作长度 → 编译失败（-error）。
- [17-01-example4.cpp](17-01-example4.cpp)：零长 `std::array` 与 `empty()`，输出 `1`。
- [17-01-example5.cpp](17-01-example5.cpp)：聚合初始化（拷贝列表 vs 列表初始化），输出 `2 11`。
- [17-01-example6.cpp](17-01-example6.cpp)：默认初始化 vs 值初始化。
- [17-01-example7-error.cpp](17-01-example7-error.cpp)：初始化列表过多 → 编译失败（-error）。
- [17-01-example8.cpp](17-01-example8.cpp)：const 与 constexpr `std::array`，输出 `11 25`。
- [17-01-example9-error.cpp](17-01-example9-error.cpp)：修改 const 数组元素 → 编译失败（-error）。
- [17-01-example10.cpp](17-01-example10.cpp)：CTAD 推导类型与长度，输出 `1 7.31`。
- [17-01-example11-error.cpp](17-01-example11-error.cpp)：CTAD 只给一个模板实参 → 编译失败（-error）。
- [17-01-example12.cpp](17-01-example12.cpp)：`std::to_array` 三种写法与 `short` 用例。
- [17-01-example13-ub.cpp](17-01-example13-ub.cpp)：`operator[]` 越界 → 未定义行为（-ub）。
- [17-01-quiz2.cpp](17-01-quiz2.cpp)：Quiz #2 解答——`std::array<double, 365>` 保存每日最高气温。
- [17-01-quiz3.cpp](17-01-quiz3.cpp)：Quiz #3 解答——`'h','e','l','l','o'` 数组打印下标 1，输出 `e`。

> 说明：本节代码为按原文描述重建。

# 16.9 Array indexing and length using enumerators

> 原文：https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators/

## 核心概念

- **纯整数下标的文档性问题**：光看整数下标看不出每个位置代表什么，读者无法判断 `testScores[2]` 对应哪位学生。
- **用无作用域枚举量当下标**：因为 `std::vector<T>::operator[]` 接受 `size_type`（通常是 `std::size_t`），而无作用域枚举量可隐式转换为 `std::size_t`，所以可以用枚举量作下标，让下标自带含义（自文档化）。
- **为什么不会触发窄化/符号问题**：枚举量隐含为 `constexpr`，把一个枚举量转换到无符号整型不被视为窄化转换。
- **用非 constexpr 的无作用域枚举变量作下标**：无作用域枚举的底层类型是实现定义的，因此当底层类型默认是有符号时，这种非 constexpr 变量可能触发符号转换警告。
- **消除该警告的两种办法**：把变量声明为 `constexpr`（仅当初始化器是常量表达式时可行），或显式把枚举的底层类型声明为 `unsigned int`。
- **计数枚举量（count enumerator）**：放在最后的一个额外枚举量；当之前各枚举量都取默认值时，它自动等于前面枚举量的个数，可在任何需要"个数"的地方复用。
- **自动调整大小的好处**：在计数枚举量之前插入一个新枚举量，会让它的值自动加一，于是用它确定尺寸的容器会自动变大，无需改动别处。
- **断言数组长度**：当容器由初始化列表构造、并用枚举量索引时，断言容器大小等于计数枚举量，可及早发现枚举列表与初始化列表不匹配（或漏写初始化项）的问题。
- **数组与 enum class**：enum class 不会隐式转换为整型，因此用它的枚举量作下标、作 vector 尺寸、或配合 `operator<<` 输出都会产生编译错误。
- **enum class 的变通办法**：`static_cast` 可用但啰嗦、代码杂乱；更好的办法是重载一元 `operator+`，返回 `std::underlying_type_t`。
- **何时更适合普通枚举**：如果需要大量"枚举量→整型"的转换，那么把普通 enum 放进 namespace 或 class 里通常更简单。

## 最佳实践

- **Tip**：对 constexpr 数组用 `static_assert`，而不是 `assert`；`std::vector` 不支持 constexpr，但 `std::array` 和 C 风格数组支持（详见 17.3）。
- **Best practice**：用 `static_assert` 校验 constexpr 数组长度与计数枚举量一致；用 `assert` 对非 constexpr 数组做同样的事。

## 代码示例

- [16-09-example1.cpp](16-09-example1.cpp)：纯整数下标不说明含义（原 Example 1，补全为可编译程序）。
- [16-09-example2.cpp](16-09-example2.cpp)：用无作用域枚举量作自文档化下标（原 Example 2）。
- [16-09-example3.cpp](16-09-example3.cpp)：非 constexpr 枚举变量可能触发符号转换警告（原 Example 3）。
- [16-09-example4.cpp](16-09-example4.cpp)：显式声明底层类型为 `unsigned int` 以消除警告（原 Example 4）。
- [16-09-example5.cpp](16-09-example5.cpp)：用计数枚举量确定容器大小并报告个数（原 Example 5）。
- [16-09-example6.cpp](16-09-example6.cpp)：新增枚举量后容器自动变大（原 Example 6）。
- [16-09-example7.cpp](16-09-example7.cpp)：用 `assert` 校验容器大小与计数枚举量一致（原 Example 7）。
- [16-09-example8-error.cpp](16-09-example8-error.cpp)：enum class 枚举量导致多处编译错误（原 Example 8，**预期编译失败，勿修复**）。
- [16-09-example9.cpp](16-09-example9.cpp)：用 `static_cast` 逐个转换 enum class 枚举量（原 Example 9）。
- [16-09-example10.cpp](16-09-example10.cpp)：重载一元 `operator+` 简化 enum class 到整型的转换（原 Example 10）。
- [16-09-quiz1.cpp](16-09-quiz1.cpp)：测验解答——用枚举量索引动物腿数数组（原 Example 11）。

> 说明：本节代码为按原文描述重建。Example 3 的反面情形（不指定底层类型时的警告）在不同编译器/不同底层类型下表现不一致，GCC 默认底层类型为无符号时可能并不告警，详见该文件注释。

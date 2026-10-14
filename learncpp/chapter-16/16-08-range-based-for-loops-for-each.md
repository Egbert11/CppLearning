# 16.8 Range-based for loops (for-each)

> 原文：https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each/

## 核心概念

- **基于下标的 for 循环**：本节先用下标变量遍历一个装斐波那契数的 `std::vector`，指出这种循环虽然灵活，但"容易写错、容易差一（off-by-one）"，还会遇到下标符号问题。
- **范围 for 循环（range-based / for-each）**：一种不带显式下标、按前向顺序遍历容器的循环形式，更简单、更安全，适用于 `std::vector`、`std::array` 和 C 风格数组。
- **语法**：`for (element_declaration : array_object) statement;`
- **迭代行为**：每轮把当前元素的值赋给声明的变量，然后执行循环体；元素遍历完就结束。
- **类型匹配**：声明的变量最好与元素类型一致，否则会发生（隐式）类型转换。
- **Key insight**：声明的变量"并不是数组下标"，它拿到的是元素的一个副本，因此对胖类型来说复制可能很昂贵。
- **空容器**：如果容器里没有任何元素，循环体一次都不会执行（"Hi mom!" 示例什么都不打印）。
- **`auto` 类型推导**：用 `auto` 让编译器推导元素类型，既省去重复书写和写错的风险，将来元素类型变化时循环也会自动同步。
- **用引用避免复制**：把声明写成引用（通常是 `const auto&`）可绑定到真实元素、避免昂贵复制；用非 const 引用还能修改元素。
- **`auto` / `auto&` / `const auto&` 的取舍**：常规建议是——类型复制便宜用 `auto`，要修改原元素用 `auto&`，类型昂贵用 `const auto&`；很多开发者则一律用 `const auto&` 以求"面向未来"，因为引用的代价很小。
- **类型变更陷阱**：一个对 `std::vector<std::string_view>` 使用 `auto` 的循环，如果容器后来改成 `std::string`，会悄悄变成昂贵的复制。
- **两种补救方式**：要么放弃类型推导、显式写出元素类型；要么用 `const auto&` 保证不发生复制。
- **其他标准容器**：范围 for 也适用于未退化的 C 风格数组、`std::array`、`std::vector`、链表、树和 map。
- **进阶限制**：已退化（decayed）的 C 风格数组不能用（长度信息丢失）；枚举也不能直接用（解决办法见 17.6）。
- **获取当前下标**：范围 for 没有直接拿到当前下标的方法（像 `std::list` 这类结构根本没有下标）；可以自己维护一个计数器，但更该考虑改用普通 for 循环。
- **逆序遍历（C++20）**：范围 for 只能前向遍历；从 C++20 起可用 Ranges 库的 `std::views::reverse` 构造一个可反向遍历的视图。

## 最佳实践

- **Best practice**：遍历容器时，优先使用范围 for 循环而不是普通 for 循环。
- **Best practice**：在范围 for 循环中使用类型推导（`auto`），让编译器推导数组元素类型。
- **Best practice（元素类型）**：只想查看元素时，优先用 `const auto&`；需要修改副本用 `auto`；需要修改原元素用 `auto&`。
- **For advanced readers**：已退化的 C 风格数组和枚举不支持范围 for 循环。

## 代码示例

- [16-08-example1.cpp](16-08-example1.cpp)：基于下标的 for 循环遍历斐波那契 `std::vector`（原 Example 1）。
- [16-08-example2.cpp](16-08-example2.cpp)：范围 for 循环遍历同一容器，并演示 `auto` 推导（原 Example 2 与 Example 4）。
- [16-08-example3.cpp](16-08-example3.cpp)：对空 `std::vector` 做范围 for，循环体一次都不执行（原 Example 3）。
- [16-08-example4.cpp](16-08-example4.cpp)：`std::vector<std::string>` 下用 `auto`（复制）与 `const auto&`（引用）的对比（原 Example 5 与 Example 6）。
- [16-08-example5.cpp](16-08-example5.cpp)：`std::vector<std::string_view>` 用 `auto` 合适，但容器改为 `std::string` 后 `auto` 会悄悄复制（原 Example 7 与 Example 8）。
- [16-08-example6.cpp](16-08-example6.cpp)：范围 for 遍历 `std::array`（原 Example 9）。
- [16-08-example7.cpp](16-08-example7.cpp)：C++20 `std::views::reverse` 逆序遍历（原 Example 10）。
- [16-08-quiz1.cpp](16-08-quiz1.cpp)：测验 1 解答——在名字列表中查找用户输入的名字。
- [16-08-quiz2.cpp](16-08-quiz2.cpp)：测验 2 解答——`isValueInArray()` 函数模板实现同样的查找。

> 说明：本节代码为按原文描述重建。

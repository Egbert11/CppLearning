# 13.12 Member selection with pointers and references

> 原文：https://www.learncpp.com/cpp-tutorial/member-selection-with-pointers-and-references/

## 核心概念

- **对象与引用上的成员选择**：成员选择运算符（`.`）从 struct 对象中选取成员；对引用作用相同，因为"引用一个对象时其行为就像对象本身"。
- **点运算符不能用于指针**：直接把 `.` 用于指向 struct 的指针是编译错误，因为指针保存的是地址而不是对象。
- **显式解引用的替代写法**：先解引用再选择 `(*ptr).id`。括号是必须的，好让解引用先于成员选择绑定。
- **箭头运算符**：C++ 提供了"从指针选择成员运算符"（`->`），也叫箭头运算符，给出更干净的指针成员访问语法。
- **隐式解引用规则**：`->` 的行为像 `.`，但先隐式解引用，因此"`ptr->id` 等价于 `(*ptr).id`"，且完全避开优先级问题。
- **链式 `operator->`**：若 `->` 得到的成员本身又是指向类类型的指针，可在同一表达式中再次使用 `->`，例如 `ptr->c->y`。
- **链式箭头的可读性**：运算符反复出现时，在它两边加空格（如 `ptr -> c -> y`）更便于区分成员与运算符。
- **混用指针与非指针**：成员选择作用于"当前选中的东西"，因此 `.` 与 `->` 可以连用：指针用 `->`，非指针成员用 `.`。
- **那时括号可省**：在 `(ptr->paw).claws` 中括号并非必需，因为 `->` 与 `.` 都从左向右求值；括号只是提升可读性。

## 最佳实践

- **Best practice**：通过指针访问成员时，**使用"从指针选择成员运算符"（`->`）而不是"成员选择运算符"（`.`）**。
- **Author's note（可读性）**：`ptr -> c -> y` 这类链式箭头不易读，把成员与运算符隔开加空格有助于区分。
- **Author's note（括号）**：`(ptr->paw).claws` 中的括号不必要，因为两个运算符都从左向右求值，但能让可读性略好。

无单独 Warning 条目。

## 代码示例

- [13-12-example1.cpp](13-12-example1.cpp)：用 `.` 修改结构体对象的成员（原 Example 1）。
- [13-12-example2.cpp](13-12-example2.cpp)：对结构体的 const 引用用 `.` 访问成员（原 Example 2）。
- [13-12-example3-error.cpp](13-12-example3-error.cpp)：对指针直接使用 `.` —— 预期编译失败（原 Example 3）。
- [13-12-example4.cpp](13-12-example4.cpp)：先解引用再选择 `(*ptr).id`（原 Example 4）。
- [13-12-example5.cpp](13-12-example5.cpp)：用箭头 `ptr->id`（原 Example 5）。
- [13-12-example6.cpp](13-12-example6.cpp)：链式 `operator->`，`ptr->c->y` 与 ugly 的解引用写法对比（原 Example 6）。
- [13-12-example7.cpp](13-12-example7.cpp)：混用 `->` 与 `.`，`(ptr->paw).claws`（原 Example 7）。

> 说明：本节代码为按原文清单与站点标准写法重建。

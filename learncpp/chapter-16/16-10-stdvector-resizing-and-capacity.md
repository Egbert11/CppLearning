# 16.10 std::vector resizing and capacity

> 原文：https://www.learncpp.com/cpp-tutorial/stdvector-resizing-and-capacity/

## 核心概念

- **固定长度数组**：数组长度必须在创建时确定，之后永不改变；`std::array` 与 C 风格数组都属于这一类。
- **动态（可调整大小）数组**：创建之后长度还能改变的数组，`std::vector` 就是其一，这正是它的特别之处。
- **用 `resize(n)` 调整大小**：调用成员函数传入新长度即可在运行时改变 vector。已有元素的值会被保留，新增元素被**值初始化**（类类型做默认初始化，其他类型做零初始化）。
- **缩小尺寸**：用更小的值调用 `resize()` 会从尾部丢弃元素，保留下来的值不变。
- **长度与容量的类比**：一排 12 个房间（length = 12）；一个 12 格的蛋盒里只装了 5 个蛋（length = 5，capacity = 12），还可以再放 7 个而不溢出。
- **定义**：容量（capacity）是"已分配存储能容纳的元素个数"；长度（length / size）是"当前实际使用的元素个数"。
- **`capacity()`**：返回当前容量的成员函数。实际编程中很少需要，但可用它观察存储行为。
- **重新分配（reallocation）**：当 vector 需要改变它管理的存储量时发生。步骤是：为新数量获取新内存并值初始化；把旧元素复制（能移动则移动）过来并归还旧内存；然后设置新的容量与长度。外表看像是 resize，内部其实是内存与元素被整体替换。
- **规则：重新分配很昂贵**：通常每个元素都要被复制，因此应避免不必要的重新分配。
- **为什么要分开记录长度与容量**：如果只记录长度，那么每次 `resize()` 都会被迫昂贵地重新分配；保留容量后，vector 就能自行判断何时才真的需要重新分配。例如先缩到 3 再长回 5，因为容量仍是 5，就免去了两次重新分配。
- **规则：下标以长度为准**：`operator[]` 和 `at()` 的合法下标是 0 到 length − 1。位于 [length, capacity) 区间的元素在内存里存在，但索引它们是越界的。
- **缩小策略**：扩容可能同时提高长度与容量；缩容只会降低长度，绝不降低容量。只有在不再需要大量元素时，回收存储才值得。
- **`shrink_to_fit()`**：请求把容量缩减到与长度相同。该请求是**非强制的**：实现可以完全照做、部分照做，或干脆忽略。

## 最佳实践

- **Key insight（长度 vs 容量）**：长度是"正在使用"的元素数；容量是"已分配存储"的元素数。
- **Key insight（重新分配的代价）**：Reallocation is typically expensive. Avoid unnecessary reallocations.（重新分配通常很昂贵，应避免不必要的重新分配。）
- **Key insight（为何分开记录）**：把容量与长度分开记录，能让 vector 在改变长度时少做一些重新分配。
- **Warning（下标越界）**：A subscript is only valid if it is between 0 and the vector's length (not its capacity)!（下标只有在 0 到 vector 的**长度**之间时才合法，与容量无关！）

## 代码示例

- [16-10-example1.cpp](16-10-example1.cpp)：把 vector 调大，已有元素保留、新元素零初始化（原 Example 1）。
- [16-10-example2.cpp](16-10-example2.cpp)：把 vector 调小，尾部元素被丢弃（原 Example 2）。
- [16-10-example3.cpp](16-10-example3.cpp)：观察扩容时 capacity 与 length 的变化（原 Example 3）。
- [16-10-example4.cpp](16-10-example4.cpp)：缩容再扩回时容量保持为 5，避免重新分配（原 Example 4）。
- [16-10-example5.cpp](16-10-example5.cpp)：`resize(0)` 不释放存储，`shrink_to_fit()` 才回收（原 Example 5）。

> 说明：本节代码为按原文描述重建。capacity 的具体数值依实现而定（原文注明是"在作者的机器上"的结果），不同编译器可能与注释中的示例输出不同。

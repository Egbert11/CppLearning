# 22.6 std::shared_ptr

> 原文：https://www.learncpp.com/cpp-tutorial/stdshared_ptr/

## 核心概念

- **用途**：与只能单一拥有的 `std::unique_ptr` 不同，`std::shared_ptr` 用于"需要多个智能指针共同拥有同一个资源"的场景。
- **允许多个指针**：可以有多个 `std::shared_ptr` 合法地指向同一资源；内部会记录有多少个共享者。
- **释放规则**：只要还有至少一个 `std::shared_ptr` 引用该资源，它就继续存活；当最后一个这样的指针离开作用域或被重新赋值时，资源才被释放。
- **头文件**：与 `std::unique_ptr` 一样，声明在 `<memory>` 中。
- **增加拥有者的正确方式是拷贝**：从已有指针拷贝构造出第二个指针，才是正确地共享资源（见 Example 1）。
- **独立创建的危害**：用同一个裸指针分别构造两个 `shared_ptr`，会让两者都以为自己是唯一拥有者，导致二次删除并崩溃（见 Example 2）。
- **可为空**：`std::shared_ptr` 可以是空的，和 `std::unique_ptr` 一样，使用前应当检查。
- **`std::make_shared`**：C++11 起可用（与 C++14 的 `std::make_unique()` 类似），应优先用它创建 shared pointer。它更简单、更安全（没有机会意外造出两个互不知情的指针），也更快。
- **内部结构**：shared pointer 内部持有两个指针——一个指向所管理的资源，另一个指向动态分配的**控制块（control block）**，控制块里记录使用计数等信息。用构造函数创建时，对象与控制块**分别**分配；`std::make_shared` 可以把它们合并成一次分配，从而提升性能。
- **为什么独立创建会出问题**：每个独立创建的指针都会分配自己的控制块，各自报告"我是唯一拥有者"，于是各自在析构时都去释放资源。
- **拷贝会更新控制块**：通过拷贝赋值克隆一个 shared pointer，会正确地更新控制块以反映多了一个共享者。
- **从 unique_ptr 转换**：`std::shared_ptr` 有一个接收 `std::unique_ptr` 右值的特殊构造函数，可把内容移动过来。反向转换不安全，因此返回智能指针的函数一般应返回 `std::unique_ptr`，让调用方在需要时再赋给 `std::shared_ptr`。
- **风险点**：每一个 `std::shared_ptr` 都必须被妥善处置；只要有任何一个管理该资源的指针泄漏了，资源就永远不会被释放——这不同于 `std::unique_ptr`，那里只需在意唯一那个指针。
- **数组**：C++17 及更早，`std::shared_ptr` 对数组支持不完善，不应让它管理 C 风格数组；C++20 增加了该支持。
- **结论**：需要多个智能指针共同管理同一资源时使用 `std::shared_ptr`，资源会在最后一个指针被销毁后释放。

## 最佳实践

- **Best practice**："Always make a copy of an existing std::shared_ptr if you need more than one std::shared_ptr pointing to the same resource."（若需要多个 `std::shared_ptr` 指向同一资源，一定要**拷贝**已有的 shared pointer，而不是各自用裸指针构造。）

（本节没有 Author's note / Warning 框。）

## 代码示例

- [22-06-example1.cpp](22-06-example1.cpp)：从 `ptr1` **拷贝**得到 `ptr2`，两者共同拥有同一 `Resource`，最后一个销毁时才释放（原 Example 1）。
- [22-06-example2-ub.cpp](22-06-example2-ub.cpp)：直接用同一裸指针分别构造两个 `shared_ptr`，各自独立释放 → 二次释放、崩溃（原 Example 2，UB）。
- [22-06-example3.cpp](22-06-example3.cpp)：用 `std::make_shared` 创建 `ptr1` 再拷贝出 `ptr2`，输出与 Example 1 相同（原 Example 3）。

> 说明：本节代码为按原文描述重建。

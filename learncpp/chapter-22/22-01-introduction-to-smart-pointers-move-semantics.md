# 22.1 Introduction to smart pointers and move semantics

> 原文：https://www.learncpp.com/cpp-tutorial/introduction-to-smart-pointers-move-semantics/

## 核心概念

- **手动 `new`/`delete` 很脆弱**：用 `new` 分配资源的函数，必须在每一条退出路径上记得 `delete`，否则就会泄漏。
- **提前 `return` 会泄漏**：`if (x == 0) return;` 会跳过函数末尾的 `delete`，每次都泄漏一次已分配的对象。
- **异常也会泄漏**：在 `delete` 之前 `throw`，异常直接终止函数，指针指向的对象没被删除。
- **根本原因**：指针变量本身"没有任何自我清理的机制"——它只是个地址，不拥有对象。
- **类的析构函数可以救场**：对象离开作用域时会自动调用析构函数；因此可以把"在构造函数里获取的内存"在析构函数里释放。这就是 RAII 的核心思想（见 19.3）。
- **RAII 的初稿：一个拥有者类**：`Auto_ptr1` 保存一个 `T*`，在析构函数里 `delete`，并重载 `operator*` / `operator->` 让它用起来像指针。
- **智能指针（smart pointer）定义**："一种组合类（composition class），专门用于管理动态分配的内存，并保证当智能指针对象离开作用域时该内存会被释放。"与之相对，内建指针被戏称为"哑指针（dumb pointer）"。
- **局部作用域保证**：把智能指针声明为局部变量，无论函数以何种方式结束，资源都会在块结束时被销毁。
- **致命缺陷**：编译器会自动生成拷贝构造函数与拷贝赋值运算符，它们只做**浅拷贝**（复制裸指针），于是两个拥有者指向同一个对象。
- **后果**：第一个析构函数删除资源，第二个析构函数再删除"已被删除的指针" → 未定义行为，通常导致崩溃。
- **按值传参会重演该问题**：把智能指针拷贝进形参，形参销毁后调用方的指针就悬垂了。
- **禁止拷贝是有代价的**：删掉拷贝操作能消除这个 bug，但这样一来函数就无法按值返回该智能指针；返回引用或裸指针也都行不通。
- **深拷贝是另一种思路，但不可取**：深拷贝开销大、有时无法实现，而且与裸指针的行为不一致。
- **移动语义（move semantics）定义**："类将转移对象的所有权，而不是制造一个拷贝。"在 `Auto_ptr2` 中的实现方式是：拷贝函数接收非 const 引用，并在转移后把源指针置空。
- **所有权转移是有效的**：执行 `res2 = res1` 之后源报告为空，只发生一次 `delete`，因此既没有重复对象也没有二次释放。
- **`std::auto_ptr`**（C++98，C++17 移除）是第一个标准化的智能指针，采用的就是 `Auto_ptr2` 那种"用拷贝实现移动"的写法。
- **`std::auto_ptr` 的问题 1**：按值传给它时它会静默地移动并销毁资源，导致调用方之后解引用空指针。
- **问题 2**：它始终使用非数组形式的 `delete`，因此动态数组被错误管理或泄漏，而且它不阻止你把数组传进去。
- **问题 3**：它无法与标准容器/算法互操作——这些组件假定"拷贝就应该是真的拷贝"。
- **状态**：C++11 起被弃用，C++17 移除。
- **为何失败**：C++11 之前无法区分拷贝语义与移动语义，把"拷贝"重载为"移动"会产生 `res1 = res2` 这类令人意外的行为。
- **C++11 之后**：移动语义被正式定义，`auto_ptr` 被"感知移动"的智能指针取代：`std::unique_ptr`、`std::weak_ptr`、`std::shared_ptr`。

## 最佳实践

本节没有独立的 Best practice / Author's note / Warning 框，但有一处提示：

- **A reminder（提示）**："Deleting a nullptr is okay, as it does nothing."（对 `nullptr` 执行 `delete` 是安全的，它什么也不做。）——正因如此，智能指针析构函数里可以放心地无条件 `delete m_ptr`。

## 代码示例

- [22-01-example1.cpp](22-01-example1.cpp)：用 `new` 分配 `Resource` 再手动 `delete`，输出 `Resource acquired` / `Resource destroyed`（原 Example 1）。
- [22-01-example2-broken.cpp](22-01-example2-broken.cpp)：提前 `return` 跳过 `delete`，导致内存泄漏（原 Example 2）。
- [22-01-example3-broken.cpp](22-01-example3-broken.cpp)：在 `delete` 之前 `throw`，同样导致泄漏（原 Example 3）。
- [22-01-example4.cpp](22-01-example4.cpp)：`Auto_ptr1` 模板（析构函数自动 `delete`），离开作用域自动释放资源（原 Example 4）。
- [22-01-example5.cpp](22-01-example5.cpp)：在函数中使用 `Auto_ptr1<Resource>`，无论正常返回还是提前返回都会自动清理（原 Example 5）。
- [22-01-example6-ub.cpp](22-01-example6-ub.cpp)：`Auto_ptr1` 被隐式浅拷贝（`res2(res1)`），析构时二次释放同一对象 → 未定义行为（原 Example 6）。
- [22-01-example7-ub.cpp](22-01-example7-ub.cpp)：按值把 `Auto_ptr1` 传入函数，形参析构后调用方指针悬垂（原 Example 7）。
- [22-01-example8.cpp](22-01-example8.cpp)：`Auto_ptr2` 用非 const 引用的拷贝构造函数/赋值运算符实现移动语义，正确转移所有权（原 Example 8）。
- [22-01-example9-broken.cpp](22-01-example9-broken.cpp)：草图——`generateResource()` 按值返回局部 `Auto_ptr1`，说明"需要返回时仍会触发拷贝"，从而引出移动语义的需求（原 Example 9）。

> 说明：本节代码为按原文描述重建（抓取工具无法逐字返回完整代码清单）。

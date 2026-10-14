# 22.7 Circular dependency issues with std::shared_ptr, and std::weak_ptr

> 原文：https://www.learncpp.com/cpp-tutorial/circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr/

## 核心概念

- **共享所有权也会反噬**：当两个对象各自持有指向对方的 `std::shared_ptr` 时，它们会互相维持对方的存活，谁也不会被释放。
- **泄漏为何发生**：`partnerUp()` 之后，"Ricky" 和 "Lucy" 各自被两个 shared pointer 指向。`ricky`、`lucy` 离开作用域时，每个对象都发现"还有另一个共享者"，于是谁也不去释放。用书里的话说，每个对象"最终都让下一个对象活着"。
- **循环引用（circular reference）**：指一系列引用中每个元素指向下一个、而最后一个指回第一个，构成一个"引用环"。这里的"引用"不必是真正的 C++ 引用，也可以是指针或 ID。
- **实际后果**：在 shared pointer 构成的环里，环中没有任何对象能被释放，"因为它们都以为还有别的对象需要自己！"
- **最简化的情形**：哪怕只是一个 `std::shared_ptr` 指向"包含它自己的那个对象"，也仍是一个环，一样会泄漏；而且你无法 reset 它，因为拥有它的那个指针已经不在作用域里了。
- **`std::weak_ptr` 的用途**：它就是为解决循环所有权而设计的。它是一个"观察者"，可以访问与某个 `std::shared_ptr` 相同的对象，但**不是拥有者**——**不计入**引用计数。
- **转换规则**：`weak_ptr` 没有 `operator->`，不能直接使用；要用 `.lock()` 把它转换成 `std::shared_ptr` 再使用。
- **悬垂风险**：和裸指针一样，`weak_ptr` 可能比它所指向的对象活得更久，但它会跟踪引用计数：计数非零表示仍有效，计数为零表示对象已销毁。
- **`expired()`**：如果 `weak_ptr` 指向的对象已失效（被释放）则返回 `true`，否则返回 `false`。
- **不要 lock 已过期的 `weak_ptr`**：对象已经没了，lock 一个已过期的 `weak_ptr` 会返回一个指向 `nullptr` 的 `std::shared_ptr`。
- **结论**：需要多个智能指针共同拥有资源时用 `shared_ptr`（最后一个离开作用域时释放）；只想观察/使用共享资源而不参与其所有权时用 `weak_ptr`。

## 最佳实践

本节没有 Best practice / Author's note / Warning 框。

（可总结为实践要点：用 shared_ptr 表示"拥有"，用 weak_ptr 表示"观察但不拥有"，从而打断循环引用。）

## 代码示例

- [22-07-example1-broken.cpp](22-07-example1-broken.cpp)：`Person` 用 `std::shared_ptr<Person> m_partner` 互相指向，构成循环引用，两个对象都不被销毁（原 Example 1，泄漏演示）。
- [22-07-example2-broken.cpp](22-07-example2-broken.cpp)：`Resource::m_ptr` 指向"包含它自己的对象"，最简化的自循环泄漏（原 Example 2）。
- [22-07-example3.cpp](22-07-example3.cpp)：把 `m_partner` 改成 `std::weak_ptr<Person>`，打断循环，两个对象正常销毁（原 Example 3）。
- [22-07-example4.cpp](22-07-example4.cpp)：在 Example 3 基础上增加 `getPartner()`（用 `lock()`）与 `getName()`，输出 `Ricky's partner is: Lucy`（原 Example 4）。
- [22-07-example5.cpp](22-07-example5.cpp)：对比 `weak_ptr` 与裸指针——裸指针无法察觉对象已死（`non-null`），而 `weak_ptr.expired()` 能正确报告 `expired`（原 Example 5）。
- [22-07-quiz1.cpp](22-07-quiz1.cpp)：本节测验解答——把 Example 2 的 `m_ptr` 改为 `std::weak_ptr`，资源得以正常销毁。

> 说明：本节代码为按原文描述重建。

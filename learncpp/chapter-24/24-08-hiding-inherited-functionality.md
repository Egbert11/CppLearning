# 24.8 Hiding inherited functionality

> 原文：https://www.learncpp.com/cpp-tutorial/hiding-inherited-functionality/

## 核心概念

- **改变继承成员的访问级别**：派生类可以在新的访问说明符下，用一个 **using 声明**为继承来的成员命名，从而改变其访问说明符。该声明标识的是带作用域的基类成员。
- **基类设置示例**：`Base::printValue()` 是 protected，因此只有 `Base` 及其派生类可以调用它。
- **把它变 public**：在 `Derived` 中，把 `using Base::printValue;`（不带括号）写进 public 区，就把它提升为公有，外部代码便可调用 `derived.printValue()`。
- **改访问级别的限制**：你只能对那些派生类本来就能访问的基类成员改变访问级别。基类中 private 的成员永远不能改成 protected 或 public，因为派生类本来就无法访问私有基类成员。
- **隐藏功能**：C++ 无法在不改源码的情况下移除或限制基类功能；派生类只能把它**隐藏**，使它在派生类中不可访问。办法就是改变访问说明符。
- **把 public 成员变 private**：把 `using Base::m_value;` 放进 private 区，就使 `m_value` 在 `Derived` 中是私有的，从而对一个设计不佳的基类的数据实现封装。私有继承也能直接达到同样效果。
- **封装可被绕过**：虽然 `m_value` 在 `Derived` 中是私有的，它在 `Base` 中仍是公有的，所以把它转换为 `Base&` 就能直接访问。作者称这是封装"仍可被绕过"的一种方式。
- **进阶读者——虚函数与访问级别**：如果一个 `Base` 的 public 虚函数在 `Derived` 中被改为 private，外部仍可把 `Derived` 对象转换为 `Base&` 来调用它。编译器允许，因为该函数在 `Base` 中是 public，而虚分派实际运行的是派生类那个私有版本。"**访问控制在运行期不强制执行。**"
- **重载函数**：你不能只改某一个重载的访问说明符。一个 using 声明会改变该名字的**所有**函数的访问级别。
- **在派生类中删除函数**：可以把某个成员函数在派生类中标记为 `= delete`，使它完全无法通过派生对象调用。基类版本仍可通过 `derived.Base::getValue()` 或转换到 `Base&` 来访问。
- **转换注意**：通过转换调用基类版本时，应转换为 `Base&` 而不是 `Base`，"以免对派生对象的 Base 部分做一份拷贝"。

## 最佳实践

本节无 Best practice / Warning / Author's note 框。有一处 **"For advanced readers"** 框，覆盖虚函数访问级别的示例（Example 5），要点为："Access controls are not enforced at runtime."（访问控制在运行期不强制执行。）

## 代码示例

- [24-08-example1.cpp](24-08-example1.cpp)：用 `using Base::printValue;` 把基类 protected 的 `printValue()` 提升为 public（原 Example 2/3）。预期输出：`7`。
- [24-08-example2.cpp](24-08-example2.cpp)：用 `using Base::m_value;` 把公有成员变私有，再演示转换为 `Base&` 绕过封装（原 Example 4）。预期输出：`7`。
- [24-08-example3-error.cpp](24-08-example3-error.cpp)：一个 using 声明把 **所有** `getValue` 重载都变私有，两次调用都报错（原 Example 6，预期**编译失败**）。
- [24-08-example4.cpp](24-08-example4.cpp)：在派生类中 `= delete` 掉 `getValue()`，再用 `Base::getValue()` 与转换到 `Base&` 两种方式仍调用基类版本（原 Example 7/8）。预期输出两行 `7`。
- [24-08-example5-error.cpp](24-08-example5-error.cpp)：虚函数改私有后，直接调用报错，而经 `static_cast<A&>` 转换可以调用（原 Example 5，含一处预期**编译失败**）。

> 说明：本节代码为按原文描述重建。

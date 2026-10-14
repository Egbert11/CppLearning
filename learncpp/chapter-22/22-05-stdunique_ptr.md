# 22.5 std::unique_ptr

> 原文：https://www.learncpp.com/cpp-tutorial/stdunique_ptr/

## 核心概念

- **裸指针的隐患**：函数提前返回或抛出异常时可能跳过 `delete`，导致动态分配的对象泄漏。
- **智能指针"智能"在哪里**：它的核心特征在于——拥有用户提供的动态分配资源，并在合适的时刻（通常是离开作用域时）释放它。
- **绝不要把智能指针本身动态分配**：如果这个智能指针泄漏了，它拥有的资源也会一起泄漏。请把智能指针放在栈上（局部变量或类成员），以保证它一定被销毁、从而一定完成清理。
- **四种标准智能指针**：C++11 提供了 `std::auto_ptr`（C++17 移除）、`std::unique_ptr`、`std::shared_ptr`、`std::weak_ptr`；其中最常用的是 `std::unique_ptr`。
- **`std::unique_ptr` 的用途**：它取代 `std::auto_ptr`，用于管理"不与其它拥有者共享"的动态分配对象；定义在 `<memory>` 中。
- **正确的移动语义**：与 `std::auto_ptr` 不同，`std::unique_ptr` 正确支持移动，因此拷贝构造与拷贝赋值被禁用；转移所有权必须使用 `std::move`。
- **访问所管理的对象**：`operator*` 返回资源本身的引用；`operator->` 返回指向资源的指针。
- **解引用前先检查**：`unique_ptr` 可以是空的（默认构造、以 `nullptr` 构造，或被移动走之后），因此应先测试它到 `bool` 的隐式转换。
- **数组会被正确处理**：`unique_ptr` 会自动选用标量 `delete` 还是数组 `delete[]`；不过固定数组、动态数组、C 风格字符串几乎总是更适合用 `std::array`、`std::vector` 或 `std::string`。
- **`std::make_unique`（C++14）**：一个模板函数，负责构造对象并把它包起来，构造函数实参原样透传；更简单、少打字，也更安全。
- **异常安全的理由**：C++17 之前函数实参的求值顺序未指定，若实参列表里先 `new T`、而后面某个实参抛异常，`new` 出来的对象就可能在交给 `unique_ptr` 之前泄漏；`make_unique` 把两步合并在内部完成，从而避免该问题。
- **按值返回是安全的**：`unique_ptr` 可以按值返回——C++14 及更早用移动语义转移所有权，C++17 起返回值会被省略（elided）。按指针返回永远不合适，按引用返回只有在有充分理由时才可以。
- **传参语义**：要用 `std::move` 按值传参以**转移所有权**；否则应当直接传资源本身（指针或引用），让函数不需要知道调用方用的是哪种所有权方案。
- **取出裸指针**：使用成员函数 `get()`。
- **作为类成员使用**：把 `unique_ptr` 作为组合成员，可以省去在析构函数里手写清理；但如果外层对象本身没有被正确销毁，该成员及其资源同样会泄漏。
- **两个经典误用**：让两个 `unique_ptr` 拥有同一个资源；或者手动删除了 `unique_ptr` 背后管理的资源。两者都会导致二次释放和未定义行为。`make_unique` 能在无意中避免这两种错误。

## 最佳实践

- **Best practice**："Favor std::array, std::vector, or std::string over a smart pointer managing a fixed array, dynamic array, or C-style string."（固定数组、动态数组或 C 风格字符串，优先用 `std::array`、`std::vector`、`std::string`，而不是用智能指针来管理。）
- **Best practice**："Use std::make_unique() instead of creating std::unique_ptr and using new yourself."（优先用 `std::make_unique()`，而不是自己 `new` 再构造 `std::unique_ptr`。）

（本节没有 Author's note / Warning 框。）

## 代码示例

- [22-05-example1-broken.cpp](22-05-example1-broken.cpp)：用裸指针 `new Resource`，中途 `throw` 导致泄漏（原 Example 1）。
- [22-05-example2.cpp](22-05-example2.cpp)：栈上的 `std::unique_ptr<Resource>` 拥有并自动释放资源（原 Example 2）。
- [22-05-example3.cpp](22-05-example3.cpp)：用 `std::move` 把所有权从 `res1` 转移给 `res2`，并演示 `bool` 检查（原 Example 3）。
- [22-05-example4.cpp](22-05-example4.cpp)：先做 `bool` 检查再 `*res` 解引用打印资源（原 Example 4）。
- [22-05-example5.cpp](22-05-example5.cpp)：`std::make_unique` 创建单个 `Fraction` 与 `Fraction` 数组，输出 `3/5` 与 `0/1`（原 Example 5）。
- [22-05-example6-broken.cpp](22-05-example6-broken.cpp)：实参求值顺序导致 `new T` 可能泄漏的表达式（原 Example 6，危险写法示意）。
- [22-05-example7.cpp](22-05-example7.cpp)：`createResource()` 按值返回 `unique_ptr`（原 Example 7）。
- [22-05-example8.cpp](22-05-example8.cpp)：用 `std::move` 按值传参以转移所有权，资源在函数内被销毁（原 Example 8）。
- [22-05-example9.cpp](22-05-example9.cpp)：用 `get()` 取出裸指针传给只需要使用资源的函数（原 Example 9）。
- [22-05-example10-ub.cpp](22-05-example10-ub.cpp)：两个 `unique_ptr` 拥有同一资源 → 二次释放，UB（原 Example 10）。
- [22-05-example11-ub.cpp](22-05-example11-ub.cpp)：手动 `delete` 了 `unique_ptr` 管理的资源 → 二次释放，UB（原 Example 11）。
- [22-05-example12.cpp](22-05-example12.cpp)：本节测验的原始版本——用裸指针与 `delete` 打印 `Fraction`。
- [22-05-quiz1.cpp](22-05-quiz1.cpp)：测验解答——改用 `std::make_unique` / `get()`，无需手动 `delete`。

> 说明：本节代码为按原文描述重建。

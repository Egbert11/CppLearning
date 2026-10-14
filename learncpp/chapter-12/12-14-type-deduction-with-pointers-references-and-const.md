# 12.14 Type deduction with pointers, references, and const

> 原文：https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/

## 核心概念

- **`auto` 推导基础**：编译器从初始化器推断变量类型；用 `int` 初始化器时 `auto` 即 `int`。
- **默认丢弃 const**：普通类型推导会剥离 `const`（以及 `constexpr` 隐含的 const）。
- **可重新施加 const/constexpr**：在被推导的定义上加 `const` 或 `constexpr` 即可恢复该限定。
- **引用也会被丢弃**：初始化器是引用时，推导得到的是被引用对象的类型，而非引用类型。
- **可重新施加引用**：写 `auto&` 可让推导出的类型重新成为引用。
- **顶层 const**：作用在对象自身的 const（如变量上、或指针变量上的 const）。
- **底层 const**：作用在“通过引用或指针访问到的对象”上的 const。
- **引用与 const**：指向 const 的引用永远是底层 const；指针可以带顶层 const、底层 const，或两者兼有。
- **丢弃哪一种 const**：推导只丢弃顶层 const；底层 const 会保留。
- **推导中的 const 引用**：先移除引用，再把（此时已是顶层的）const 丢弃。
- **移除引用会改变 const 层级**：`const std::string&` 是底层 const，但引用被剥离后，它就变成顶层 const——这是关键洞察。
- **重新施加引用/const**：可以恢复引用、`const`，或两者兼施加；在已是 const 引用上再加 `const` 虽冗余但能表达意图。
- **`constexpr` 与类型**：`constexpr` 不属于表达式类型，`auto` 永远不会推导出它，必须显式施加。
- **constexpr 引用提醒**：对 const 引用而言，`const` 限定的是被引用对象；指向 const 对象的 `constexpr` 引用需要同时写 `constexpr` 和 `const`。
- **指针不会被丢弃**：与引用不同，指针类型原样通过推导。
- **`auto*` 语法**：用 `auto*` 明确表示正在推导一个指针。
- **引用与指针为何不同**：求值一个引用就是求值其指代对象，而求值一个指针就是求值指针本身。
- **`auto` 与 `auto*` 的语义**：用 `auto` 时指针属于被推导的类型；用 `auto*` 时推导的是被指类型，指针在之后重新施加。
- **`auto*` 要求指针**：若初始化器不是指针，`auto*` 会编译失败。
- **指针推导中的 const**：只丢弃顶层 const；`const auto`/`auto const` 使推导出的指针为 const，`const auto*` 得到指向 const 的指针，`auto* const` 得到 const 指针。
- **`auto*` 时顺序重要**：左侧的 `const` 作用于被指对象；右侧的 `const` 作用于指针本身。
- **双重 const 非法**：把 `const` 施加两次（`const auto const`）不允许，会触发编译错误。
- **两种 const 可并存**：`const auto* const` 得到“指向 const 的 const 指针”。
- **总结规则**：先丢弃引用（除非重新声明）、再丢弃顶层 const（除非用 `const`/`constexpr` 重新施加）；`constexpr` 永远不会被推导；指针永远不会被丢弃。显式写出限定符（即便冗余）是推荐做法。

## 最佳实践

- **Best practice**：想要 const 引用时，即便不是必需也重新写上 `const`，因为能表达意图并帮助避免错误。
- **Best practice**：对 const 指针、指向 const 的指针、或指向 const 的 const 指针，即便不必要也重新写上相应的 `const` 限定符，以表达意图、减少失误。
- **Tip**：推导指针类型时优先用 `auto*`，因为它表明意图是指针、让编译器强制“确实推导出指针”，并对 const 有更细的控制。
- **Key insight**：丢弃引用可能把底层 const 变成顶层 const（`const std::string&` 是底层，去掉引用后 const 变顶层）。
- **Key insight**：推导时引用被丢弃、指针不被丢弃，因为语义不同：求值引用是求值其指代对象，求值指针是求值指针自身。
- **A reminder**：`const int&` 里的 `const` 作用于被引用对象，而非引用本身；`constexpr` 引用指向 const 变量时需要同时写 `constexpr` 与 `const`（参见 12.4 节）。

## 代码示例

- [12-14-example1.cpp](12-14-example1.cpp)：最基本的 `auto` 推导（原 Example 1）。
- [12-14-example2.cpp](12-14-example2.cpp)：推导丢弃 const/constexpr 隐含 const（原 Example 2）。
- [12-14-example3.cpp](12-14-example3.cpp)：重新施加 const 或 constexpr（原 Example 3）。
- [12-14-example4.cpp](12-14-example4.cpp)：初始化器是引用时丢弃引用（原 Example 4）。
- [12-14-example5.cpp](12-14-example5.cpp)：用 `auto&` 重新施加引用（原 Example 5）。
- [12-14-example6.cpp](12-14-example6.cpp)：顶层 const 示例（原 Example 6）。
- [12-14-example7.cpp](12-14-example7.cpp)：底层 const 示例（原 Example 7）。
- [12-14-example8.cpp](12-14-example8.cpp)：同时带两种 const 的指针（原 Example 8）。
- [12-14-example9.cpp](12-14-example9.cpp)：const 引用初始化器先丢引用再丢顶层 const（原 Example 9）。
- [12-14-example10.cpp](12-14-example10.cpp)：重新施加引用与 const 的各种组合（原 Example 10）。
- [12-14-example11.cpp](12-14-example11.cpp)：constexpr 引用指向 const 对象（`std::string_view`）（原 Example 11）。
- [12-14-example12.cpp](12-14-example12.cpp)：指针在推导中不被丢弃（原 Example 12）。
- [12-14-example13.cpp](12-14-example13.cpp)：`auto` 与 `auto*` 对比（原 Example 13）。
- [12-14-example14-error.cpp](12-14-example14-error.cpp)：`auto*` 遇到非指针初始化器 —— 预期编译失败（原 Example 14）。
- [12-14-example15.cpp](12-14-example15.cpp)：`auto`/`auto*` 与 const 的位置组合（原 Example 15）。
- [12-14-example16-error.cpp](12-14-example16-error.cpp)：`const auto const` 双重 const —— 预期编译失败（原 Example 16）。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。原文的 `getRef()`/`getConstRef()`/`getPtr()` 只有原型，为可构建已补上定义；Example 6、7、8 原文为无初始化的片段（单独不能编译），已补上初始化，语义不变。

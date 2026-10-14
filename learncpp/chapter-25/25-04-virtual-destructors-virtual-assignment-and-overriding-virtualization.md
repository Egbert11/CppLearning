# 25.4 Virtual destructors, virtual assignment, and overriding virtualization

> 原文：https://www.learncpp.com/cpp-tutorial/virtual-destructors-virtual-assignment-and-overriding-virtualization/

## 核心概念

- **默认析构 vs 自定义析构**：若不写析构函数，C++ 会提供一个默认析构；但你可能需要自己的（例如释放内存）。在继承场景中，析构函数应当设为虚函数。
- **非虚析构为何泄漏**：删除一个指向 Derived 对象的 `Base*` 时，会检查 Base 的析构函数是否为虚。若不是，则只运行 `Base` 的析构，仅属于派生类的资源（如 `m_array`）永远不会被释放。
- **Rule 告示**："只要涉及继承，任何显式析构函数都应设为虚函数。"
- **虚性会传播**：与普通虚函数一样，基类析构一旦是虚的，每个派生覆写都会自动是虚的，无论是否显式书写；不必为了"标记为虚"而额外写一个空的派生析构。
- **空的虚析构**：若基类的虚析构函数本来就为空，可以写成 `virtual ~Base() = default;`（生成一个虚的默认析构函数）。
- **虚赋值**：把 `operator=` 设为虚函数是可行的，但会"打开一罐子虫子"并深入高级主题，因此本节建议暂时让赋值运算符保持非虚。
- **忽略虚函数机制**：少数情况下你可能希望 `Base*`/`Base&` 指向 Derived 对象时调用 `Base::getName()` 而非覆写版本。使用作用域解析运算符（`base.Base::getName()`）即可强制调用基类版本。
- **是否该把所有析构都设为虚？** 增加虚函数会给每个实例带来一个虚指针，是性能开销。建议策略：若某类并非设计为基类，就不要给它任何虚成员、也不要有虚析构（组合仍然可用）；若它被设计为基类、且有虚函数，就应始终有虚析构。
- **Herb Sutter 的传统经验**："基类的析构函数应当是 public 且 virtual，或者 protected 且非 virtual。"protected 析构会阻止通过基类指针删除，但同时使基类无法公开使用：既不能常规地删除动态分配的基类对象，甚至也无法静态分配（离开作用域时析构不可访问）。
- **借助 `final` 的现代建议**：若有意让某类可被继承，就保持析构为 public 且 virtual；若无意图被继承，就把该类标为 `final`，这样无需施加其它使用限制就能阻止继承。

## 最佳实践

本节无独立的 Best practice / Warning 标题框，但含以下明确规范：
- **Rule**：Whenever you are dealing with inheritance, you should make any explicit destructors virtual.（涉及继承时，任何显式析构函数都应设为虚函数。）
- **编译器警告说明（Example 1）**：编译器可能对非虚析构给出警告；这是刻意的，可能需要关闭"警告视为错误"开关才能运行。
- **空虚析构说明**：可用 `virtual ~Base() = default;` 写成空的虚析构。
- **顾问性建议**：暂时让赋值运算符保持非虚；不打算当基类的类不要有虚成员/虚析构；基类或含虚函数的类应有虚析构；不想被继承的类标为 `final`。

## 代码示例

- [25-04-example1-broken.cpp](25-04-example1-broken.cpp)：非虚析构——通过 `Base*` 删除只调用 `~Base()`，`m_array` 泄漏（坏实践演示，原 Example 1，输出 `Calling ~Base()`）。
- [25-04-example2.cpp](25-04-example2.cpp)：虚析构——先 `~Derived()` 再 `~Base()`（原 Example 2，输出 `Calling ~Derived()` / `Calling ~Base()`）。
- [25-04-example3.cpp](25-04-example3.cpp)：用 `base.Base::getName()` 强制调用基类版本，忽略虚函数（原 Example 4+5，输出 `Base`）。

> 说明：本节代码为按原文描述重建（原文长代码块超出抓取引文上限）。原文 Example 3 的一行片段 `virtual ~Base() = default;` 已并入各示例说明，未单独成文件。

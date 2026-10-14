# 25.11 Printing inherited classes using operator<<

> 原文：https://www.learncpp.com/cpp-tutorial/printing-inherited-classes-using-operator/

## 核心概念

- **通过引用可虚派发**：当 `Base&` 绑定到 `Derived` 对象、且 `print()` 虚函数在 `Derived` 中被重写时，`b.print()` 会运行派生版本。
- **成员函数打印与 `std::cout` 不搭**：使用 `print()` 这类函数会迫使你把一条输出语句拆开（先 `std::cout << "b is a ";`，再 `b.print();`，再 `std::cout << '\n';`）。
- **目标**：让 `std::cout << "b is a " << b << '\n';` 直接可用——原文称之为「much better」。
- **常规地重载 `operator<<` 不够**：为 `Base` 和 `Derived` 各写一个友元 `operator<<`，直接对象可用，但 `std::cout << bref`（`Base&` 绑定 Derived）只打印 `Base`。
- **原因**：`Base` 版本的 `operator<<` **不是虚函数**，因此被选中而不是 `Derived` 版本——这是本节要解决的核心难题。
- **规则：`operator<<` 不能是虚函数**：只有成员函数才能是虚并可被重写；友元不是成员，因此只能被重载，不能被重写。
- **规则：签名本就不同**：`Base` 版接受 `Base` 形参，`Derived` 版接受 `Derived` 形参，后者不构成重写，也不会参与虚解析。
- **解决模式**：让 `operator<<` 作为基类的友元，但它转去调用一个**能被虚化**的普通成员函数，由这个虚函数决定打印什么。
- **方案一——返回字符串**：虚成员 `identify()` 返回 `std::string`，`Base::operator<<` 把它插入流中。
- **三种情形如何解析**：对 `Base`，`b.identify()` → `Base::identify()`；对 `Derived`，编译器找不到 `Derived` 重载，于是隐式向上转换为 `Base&` 并虚派发到 `Derived::identify()`；对绑定到 `Derived` 的 `Base&`，匹配 `Base` 版重载，再经虚派发得到 `Derived::identify()`。
- **无需为每个派生类都定义**：不必为每个派生类写 `operator<<`，`Base` 版即可服务所有派生类。
- **字符串版的两点不足**：（1）假设输出能装进单个 `std::string`；（2）`identify()` 拿不到流对象。
- **为什么需要拿到流**：你可能需要用这个流去打印某个自身也重载了 `operator<<` 的成员。
- **更灵活的方案——委托给虚 `print()`**：让虚成员 `print()` 接受流并完成打印、返回流引用，而不是让 `identify()` 返回文本。
- **委托细节**：`Base::operator<<` 自己不做打印，只是 `return b.print(out);`，实际输出由 `print()` 完成。
- **带成员类型的派生情形**：`Derived` 持有一个自身有 `operator<<` 的 `Employee` 成员；`Derived::print()` 用传入的流输出 `out << "Derived: ";` 再 `out << m_e;`——原文指出这在「返回字符串」的方案里会更难实现。

## 最佳实践

本节无（原文没有正式标注的 "Best practice" / "Author's note" / "Warning" 栏目）。唯一相近的是正文中的一句提示：「注意我们不需要为每个派生类定义 `operator<<`！」

## 代码示例

- [25-11-example1.cpp](25-11-example1.cpp)：通过基类引用调用虚函数 `print()`，派发到 `Derived::print()`。
- [25-11-example2.cpp](25-11-example2.cpp)：`print()` 与 `std::cout` 混用时的别扭写法。
- [25-11-example3.cpp](25-11-example3.cpp)：为 `Base`/`Derived` 各写一个友元 `operator<<`，直接对象可用。
- [25-11-example4.cpp](25-11-example4.cpp)：同样两个重载，但通过 `Base&` 输出时只得到 `Base`（`operator<<` 不是虚函数）。
- [25-11-example5.cpp](25-11-example5.cpp)：方案一——友元 `operator<<` 调用虚函数 `identify()`。
- [25-11-example6.cpp](25-11-example6.cpp)：方案二——委托给接受流对象的虚函数 `print()`（可打印 `Employee` 成员）。

代码说明：各示例代码取自 learncpp 原文逐字提取（对只给 `main()` 的片段补入了同小节前例的类定义，并补上 `#include <string>`）。示例 5、6 的 `operator<<` 定义仅在 `Base` 中给出，`Derived` 无需自己的 `operator<<`。

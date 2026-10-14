# 25.1 Pointers and references to the base class of derived objects

> 原文：https://www.learncpp.com/cpp-tutorial/pointers-and-references-to-the-base-class-of-derived-objects/

## 核心概念

- **派生对象由多部分组成**：一个 Derived 对象包含"每个继承基类的一部分"再加上自己的成员。基类部分先构造，派生部分后构造。
- **继承表示 is-a 关系**：Derived is-a Base，因此 Derived 中"含有 Base 的一份"是合理的。
- **派生指针/引用绑定派生对象很直接**：`Derived&` / `Derived*` 绑定 Derived 对象时，一切按预期调用派生类成员。
- **规则：基类的指针/引用可以合法地绑定到派生对象**：`Base&` 与 `Base*` 都可以引用一个 Derived 对象。
- **规则：基类指针/引用只能"看到"基类的成员**：即使派生类同名函数隐藏了基类版本，基类指针/引用也看不到派生版本，于是调用的是基类版本。
- **推论**：无法通过基类指针/引用调用派生类独有的成员——它们"看不见 Derived 里的任何东西"。
- **Animal/Cat/Dog 演示**：`pAnimal->speak()` 返回 Animal 版本 `???`，而不是 Cat/Dog 的版本，因为指针只看到 Animal 部分。
- **用途一：用一个函数取代多个重载**：若不用基类指针/引用，需要为每个派生类型写一个重载 `report()`；改用 `const Animal&` 后，一个函数即可接受任何现有或将来的派生类。**代价**：该函数调用的仍是基类版本的 `speak()`，多态问题依然存在。
- **旁注——模板替代方案**：函数模板 `report(const T&)` 也能减少重载，但有缺点：`T` 本意是 Animal 这一点无法在接口中体现；模板会接受任何具有 `getName()`/`speak()` 的类型，无论其是否真的合适。
- **用途二：一个异构数组**：数组只能存一种类型，不用基类指针就得为每种动物各建一个数组；用 `const Animal*` 元素即可把所有派生类型放进同一个容器。**问题依旧**：`animal->speak()` 仍解析到 `Animal::speak()`，每个动物都输出 `???`。
- **测验一的思路**：给 Animal 增加 `m_speak` 成员，由派生类构造函数填入正确声音，这样基类就能返回正确结果。解答里还删除了基类拷贝构造与拷贝赋值，"为防止切片（后续小节讲解）"。
- **测验二——为何该方案并不理想**：三个原因：(a) 每多一个差异特征就要给基类加一个成员，基类会膨胀；(b) 只在"能在初始化时确定取值"时才行得通——若 `speak()` 的结果是随机的就不行；(c) `speak()` 位于 Animal，除非把更多逻辑塞进基类，否则对所有派生类型行为都相同。

## 最佳实践

本节无独立的 Best practice / Rule / Warning 框。相关内容：
- 有一个 "As an aside…" 旁注，介绍基于模板的 `report()` 及其两个问题（见上）。
- 测验二中有两个 "Hint:" 提示（关于未来差异化需求、以及只应在初始化时设定的成员）。
- 内联注释本身带有告诫意味：Animal 构造函数设为 protected，避免直接创建 Animal 对象；删除拷贝构造与拷贝赋值以防切片。

## 代码示例

- [25-01-example1.cpp](25-01-example1.cpp)：`Derived&` / `Derived*` 绑定 Derived 对象，成员按预期解析（原 Example 1）。
- [25-01-example2.cpp](25-01-example2.cpp)：`Base&` / `Base*` 合法绑定 Derived 对象，但只看到 Base 部分（原 Example 2）。
- [25-01-example3.cpp](25-01-example3.cpp)：Animal/Cat/Dog 层级，`const Animal*` 指向派生对象时 `speak()` 仍输出 `???`（原 Example 3）。
- [25-01-example4.cpp](25-01-example4.cpp)：单个 `report(const Animal&)` 取代多个重载，但因 speak() 非虚仍输出 `???`（原 Example 5）。
- [25-01-example5.cpp](25-01-example5.cpp)：一个 `const Animal*` 数组容纳不同派生类型，全部输出 `???`（原 Example 8）。
- [25-01-quiz1.cpp](25-01-quiz1.cpp)：测验一解答——把声音存进 Animal 的 `m_speak`，通过基类指针也能取到正确声音。

> 说明：本节代码为按原文描述重建（原文长代码块超出抓取引文上限）。模板旁注（原 Example 6）与 STL 数组版本（原 Example 7）未单独生成可编译文件，要点已在核心概念中说明。

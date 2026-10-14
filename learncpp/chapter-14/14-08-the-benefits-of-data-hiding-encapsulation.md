# 14.8 The benefits of data hiding (encapsulation)

> 原文：https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation/

## 核心概念

- **为何成员通常私有**：初学者常觉得这多此一举，即便已有公有访问函数也看不出意义；但原因"极为根本"。
- **设备类比**：遥控器、油门、灯开关只暴露简单的用户接口，隐藏设备内部如何运作。用户只需知道如何交互，不必知道原理。
- **类的接口（interface）**：公有成员构成类的接口，定义用户如何与对象交互。接口被描述为"类作者与类用户之间的一份隐式契约"，因此应设计良好且保持稳定。
- **类的实现（implementation）**：让类正常工作的代码，包括存储数据的成员变量与含逻辑的成员函数体。
- **数据隐藏（data hiding，又称信息隐藏 information hiding 或数据抽象 data abstraction）**：通过让实现不可访问来强制分离接口与实现的技术。
- **如何实现**：把数据成员设为 private，成员函数设为 public；成员函数体本来就对用户不可访问。
- **class 与 struct 之别**：C++ 的 class 应使用数据隐藏（标准库的类都如此）；struct 则不应，因为存在非公有成员会使其不能再作为聚合体（aggregate）。
- **封装（encapsulation）**：通常指把条目装进容器，或"把数据与操作这些数据的函数打包在一起"。既有数据又有公有接口的类即封装；该词常也包含数据隐藏。本系列假定封装的类都实现了数据隐藏。
- **降低复杂度**：用户只需理解接口而非实现，"极大地降低程序的复杂度，进而减少错误"——教程称这是封装的关键优势。
- **不变式（invariants）**：类不变式是对象在其整个生命周期内必须始终成立、对象才保持有效的条件。若用户能直接访问成员，则维持不变式的责任落到用户身上，用户可能失误而破坏功能。
- **错误检测**：把对数据的所有修改都经由接口函数，便能在函数里做校验（忽略请求、断言、抛异常等），避免产生"名字为空"之类会导致未定义行为的坏状态。
- **实现变更不破坏使用方**：只要公有接口不变，内部实现改变时使用该类的程序不需要任何修改。
- **更易调试**：若某个成员只能经由一个函数改变，那么在该函数下断点即可查出是哪个调用者写入了坏值。
- **偏好非成员函数**：好处是接口更小、强制封装、实现变更时无需回改依赖方、更易调试，并把应用特定逻辑与可复用的类代码分离。Java/C# 不同，因为其模型以类为中心。
- **成员 vs 非成员指南**：当 C++ 要求时必须用成员（构造函数、析构函数、虚函数、某些运算符），或在需要访问 private/protected 数据时用成员；其余情况偏好非成员。
- **访问函数的权衡**：添加 getter/setter 会扩大接口，除非确实会被复用否则未必值得；也不应为本不该直接访问、或会让用户破坏不变式的数据添加访问。
- **声明顺序**：两派做法——private 在前（遵循先声明后使用的传统）或 public 在前（先向用户展示所需要的内容）。现代 C++ 更常推荐 public 在前。

## 最佳实践

- **Best practice**：尽可能把函数实现为非成员——尤其是持有应用特定数据或逻辑的函数。
- **Tip**：当 C++ 要求时使用成员函数；需要访问私有/受保护成员时偏好成员函数；否则偏好非成员函数，尤其对于"不修改对象状态的函数"。
- **Best practice**：先声明 public 成员，其次 protected 成员，最后 private 成员。这样突出接口，弱化实现。
- **Author's note**：本站大多数示例采用与上述建议相反的声明顺序，部分出于历史原因，也认为这样对学习语言机制更直观。
- **For advanced readers**：Google C++ 风格指南的建议顺序为：类型/别名、静态常量、工厂函数、构造与赋值运算符、析构函数、其余所有函数、最后是数据成员。
- **Related content**：Scott Meyers 的文章 "How Non-Member Functions Improve Encapsulation" 进一步探讨偏好非成员函数的理由。

## 代码示例

- [14-08-example1.cpp](14-08-example1.cpp)：`std::string_view` 的 `length()`——实现细节对用户隐藏（原 Example 1）。
- [14-08-example2.cpp](14-08-example2.cpp)：struct 的公有成员破坏不变式，改名后首字母仍是旧的 J（原 Example 2）。
- [14-08-example3.cpp](14-08-example3.cpp)：改为 class + 私有成员 + `setName()`，首字母随名字同步更新为 M（原 Example 3）。
- [14-08-example4.cpp](14-08-example4.cpp)：不再存储首字母，而由 `firstInitial()` 就地计算，消除了成对数据的不变式（原 Example 4）。
- [14-08-example5.cpp](14-08-example5.cpp)：struct `Something` 直接公开三个成员并赋值（原 Example 5）。
- [14-08-example6-error.cpp](14-08-example6-error.cpp)：把成员换成数组后，`something.value1` 不再存在——预期编译失败（原 Example 6）。
- [14-08-example7.cpp](14-08-example7.cpp)：封装版 `Something`，用 `setValue1()`/`getValue1()` 访问（原 Example 7）。
- [14-08-example8.cpp](14-08-example8.cpp)：把内部改为数组重新实现，接口不变——使用方无需修改（原 Example 8）。
- [14-08-example9.cpp](14-08-example9.cpp)：Yogurt "最差"版——成员 `print()` 即使已有 getter 仍直接读私有成员（原 Example 9）。
- [14-08-example10.cpp](14-08-example10.cpp)：Yogurt "较好"版——`print(std::string_view prefix)` 通过 getter 取数据（原 Example 10）。
- [14-08-example11.cpp](14-08-example11.cpp)：Yogurt "最佳"版——把打印写成非成员自由函数 `print(const Yogurt&)`（原 Example 11）。

> 说明：本节代码为按原文描述忠实重建（原文示例多为短片段，已补全为可编译程序）。

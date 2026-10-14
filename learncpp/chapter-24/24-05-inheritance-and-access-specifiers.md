# 24.5 Inheritance and access specifiers

> 原文：https://www.learncpp.com/cpp-tutorial/inheritance-and-access-specifiers/

## 核心概念

- **背景**：本章此前的例子都只用公有继承。本节比较 public、protected、private 三种继承，以及它们与访问说明符如何相互作用。
- **private / public 回顾**：public 成员任何人可用；private 成员仅限该类的成员函数与友元。因此派生类不能直接访问基类的私有成员。
- **protected 访问说明符**：C++ 的第三种说明符主要为继承而生。它允许拥有它的类、其友元以及**派生类**访问该成员，但外部代码不行。
- **何时使用 protected**：它让派生类能直接触碰基类成员，因此日后对该成员的任何修改（类型、含义等）多半要同时改基类和**每一个**派生类。它适合你或你的团队掌控派生过程、且派生类数量可控的场景。
- **私有成员的代价**：把成员设为 private 能阻止外界与派生类的直接改动，有利于保护实现细节与不变式。代价是类可能需要更大的 public/protected 接口，构建、测试与维护这些接口都要花力气。
- **经验法则**：能私有时优先私有；只有在"计划要派生"且"构造私有接口代价过高"时才用 protected。
- **三种继承类型**：类可以 public、protected、private 地继承，由基类名前的关键字决定。若不写，C++ 默认是**私有继承**，正如成员默认是私有的。
- **九种组合**：3 种成员访问说明符（public / private / protected）× 3 种继承类型（public / private / protected）。
- **继承改变了什么**：成员被继承时，其访问说明符**仅在派生类中**可能改变，取决于所用的继承类型。基类中原本 public 或 protected 的成员，到了派生类里可能变成别的说明符。
- **三条指导规则**：类始终能访问自己非继承的成员；public 按它所访问的那个类的访问说明符来访问成员；派生类按从父类继承来的说明符来访问继承的成员。
- **公有继承**：最常见、最简单：继承来的 public 成员保持 public，protected 保持 protected，private 保持不可访问。除非有特定理由，否则应默认采用。
- **受保护继承**：最罕见，几乎从不使用。public 与 protected 成员在派生类中变成 protected，private 成员保持不可访问。
- **私有继承**：所有基类成员都以 private 继承：public 与 protected 变成 private，private 保持不可访问。注意，这**不改变派生类自身**对继承成员的访问方式——它只影响试图通过派生类访问这些成员的外部代码。
- **私有继承的用途**：当派生类与基类没有明显关系、只是内部使用基类来做实现，因而不应通过派生对象暴露基类的公有接口时，它有用。实践中很少用。
- **适用范围**：虽然示例用的是成员变量，但同样的访问规则适用于所有成员，包括成员函数与嵌套类型。

## 最佳实践

- **Best practice**："Favor private members over protected members."（优先选择 private 成员而非 protected 成员。）
- **Best practice**："Use public inheritance unless you have a specific reason to do otherwise."（除非有特定理由，否则使用公有继承。）

## 代码示例

- [24-05-example1.cpp](24-05-example1.cpp)：public / protected / private 三种成员，派生类可访问前两者、不能访问第三者；外部代码只能访问 public（原 Example 2/4，非法行以注释保留）。
- [24-05-example2-error.cpp](24-05-example2-error.cpp)：演示非法访问——派生类访问基类 private 成员、以及外部访问 protected/private 成员（预期**编译失败**）。
- [24-05-example3.cpp](24-05-example3.cpp)：私有继承演示——基类 public/protected 成员在派生类中变为 private（原 Example 5）。
- [24-05-example4.cpp](24-05-example4.cpp)：链式继承 `D2 : private Base`、`D3 : public D2`，展示逐级继承后访问说明符的叠加效果（原 Example 6）。

> 说明：本节代码为按原文描述重建。原文示例中的"不允许"行本身是注释形式，本仓库将其保留为注释；非法访问另用 `-error` 文件演示。

## 访问说明符对照表

| 基类中的访问说明符 | 公有继承 | 私有继承 | 受保护继承 |
|---|---|---|---|
| Public | Public | Private | Protected |
| Protected | Protected | Private | Protected |
| Private | 不可访问 | 不可访问 | 不可访问 |

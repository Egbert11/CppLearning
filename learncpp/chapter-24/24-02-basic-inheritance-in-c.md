# 24.2 Basic inheritance in C++

> 原文：https://www.learncpp.com/cpp-tutorial/basic-inheritance-in-c/

## 核心概念

- **继承发生在类之间**：被继承的类称为**父类（parent class）/ 基类（base class）/ 超类（superclass）**，继承者称为**子类（child class）/ 派生类（derived class）/ 子类（subclass）**。
- **is-a 关系**：继承建模的是 is-a 关系；示意图中 Fruit 是父类，Apple 与 Banana 是子类。
- **一个类可以同时是子类和父类**：例如 Triangle 是 Shape 的子类，同时又是 Right Triangle 的父类。
- **继承到的东西**：子类会继承父类的行为（成员函数）和属性（成员变量），"受某些访问限制约束"，这些成员成为派生类自己的成员。
- **子类仍是完整的类**：派生类可以添加自己特有的成员。
- **Person 类的用意**：通用的 Person 只持有所有人共有的成员（姓名与年龄）。示例中成员被设为 public，"纯粹是为了让示例保持简单"，正常情况应为 private。
- **BaseballPlayer 的需求**：在姓名、年龄之上，还需要棒球特有的数据（打击率、本垒打数）。
- **复用姓名/年龄的三种方案**：
  - 直接把成员加进 BaseballPlayer —— 被形容为"大概是最差的选择"，因为代码重复，且日后要同步修改多处。
  - 用组合 —— 被否决，因为 BaseballPlayer 并不"有一个"Person。
  - 从 Person 继承 —— 被采纳，因为 BaseballPlayer **是一个** Person。
- **公有继承语法**：在类名之后写冒号、单词 `public`、再写基类名。这称为**公有继承（public inheritance）**；其确切含义留到后面的小节讲解。
- **得到的成员集合**：一个 BaseballPlayer 对象最终有四个成员变量：来自自身的 `m_battingAverage`、`m_homeRuns`，以及来自 Person 的 `m_name`、`m_age`。
- **继承的成员可直接使用**：示例能工作，是因为 BaseballPlayer 拥有继承来的 `m_name` 变量与 `getName()` 函数。
- **第二个派生类**：Employee 也从 Person 继承，并添加 `m_hourlySalary`、`m_employeeID` 以及 `printNameAndSalary()`，后者同时用到自己的变量和父类的变量。
- **兄弟类互不相关**：Employee 与 BaseballPlayer 之间没有直接关系，尽管都派生自 Person。
- **继承链**：可以从一个本身派生自另一个类的类继续继承；作者说"这么做没什么值得特别指出的"。
- **Supervisor 示例**：Supervisor 是一个 Employee，而 Employee 是一个 Person；Supervisor 派生自 Employee，并添加一个最多管理五名雇员的数组，因此它同时继承自 Employee 和 Person。
- **设计收益**：这种继承链让你能构造"一组可复用的类，顶端非常通用"，越往下越具体。
- **维护收益**：不必重复定义基类信息；对基类的修改（新函数、修 bug）会自动惠及所有派生类。例如给 Person 加一个新函数，Employee、Supervisor、BaseballPlayer 都会得到；给 Employee 加一个新变量，Supervisor 也会得到。
- **结论**：继承让类彼此继承成员，从而支持类的复用。

## 最佳实践

本节无独立的 Best practice / Warning / Author's note 框。最接近建议性的表述是：示例把成员设为 public "纯粹是为了让示例保持简单"；并把"在派生类里重复定义成员"评价为"大概是最差的选择"。

## 代码示例

- [24-02-example1.cpp](24-02-example1.cpp)：`Person` 类——姓名与年龄，以及 `getName()` / `getAge()` 访问器（原 Example 1）。
- [24-02-example2.cpp](24-02-example2.cpp)：`BaseballPlayer` 公有继承 `Person` 的完整程序，`main` 中设置姓名并打印继承来的 `getName()`（原 Example 3/4，输出 `Joe`）。
- [24-02-example3.cpp](24-02-example3.cpp)：`Employee` 派生自 `Person`，`printNameAndSalary()` 同时使用自身与父类成员（原 Example 5/6，输出 `Frank: 20.25`）。
- [24-02-example4.cpp](24-02-example4.cpp)：`Supervisor` 继承 `Employee`（再上溯 `Person`），演示继承链（原 Example 7）。

> 说明：本节代码为按原文描述重建（原文长代码块超出抓取引文上限）。示例中成员设为 public 仅为教学简便。

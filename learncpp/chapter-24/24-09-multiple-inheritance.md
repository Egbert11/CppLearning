# 24.9 Multiple inheritance

> 原文：https://www.learncpp.com/cpp-tutorial/multiple-inheritance/

## 核心概念

- **多继承**：C++ 的一项特性，允许一个派生类从**不止一个**父类获取成员，不同于此前示例中的单继承。用法是用逗号分隔列出每个基类。
- **建模示例**：教师既是一个人又是雇员，因此 `Teacher` 类可以同时继承 `Person` 与 `Employee` 来组合这两类属性。
- **mixin（混入类）**：一个小类，通过继承它来给别的类添加属性。这个术语表示该类意在"被混入其他类，而不单独实例化"。
- **混入时为何显式加作用域前缀**——给出三个理由：
  - `Label::setText()` 与 `Tooltip::setText()` 原型相同，不加限定会形成"歧义函数调用编译错误"，前缀可消除歧义。
  - 即使不产生歧义，前缀也能表明该调用属于哪个混入，便于阅读。
  - 现在不歧义的调用，日后加入更多混入后可能变得歧义。
- **进阶读者：混入与虚函数**：混入是用来添加功能而非提供接口，因此通常不使用虚函数；若需要定制，一般用模板，所以混入类常被模板化。
- **奇异的递归模板模式（CRTP）**：派生类可以把**它自己**作为模板类型参数，去继承某个混入基类；这种继承模式称为 CRTP。它允许混入通过把 `this` 做静态转换来触达派生类的成员。
- **问题一：歧义**：若多个基类声明了同名函数，不加限定的调用会有歧义并导致编译错误，因为派生对象里有两份这样的函数。编译器先查派生类，再查父类。
- **歧义的变通**：显式用基类名限定调用来选定目标版本。随着继承的类增多，这会越来越难，因为命名冲突"呈指数级增长"，每一处都要显式解决。
- **问题二：菱形问题**：即"doom 之菱形（diamond of doom）"，当一个类多继承自两个各自又继承自同一共享基类的类时，就形成菱形。由此产生"共享基类有几份拷贝""歧义引用如何解析"等问题。多数问题可用显式作用域处理，但维护成本很高；解决方案见 25.8 节"虚基类"。
- **多继承值得吗？**：它能解决的多数问题用单继承也能解决。Smalltalk 和 PHP 没有多继承；Java 和 C# 把类限制为单继承，但允许接口的多继承，因为多继承被认为会让语言过于复杂。有些程序员主张完全避免；作者不同意，认为它有时才是最佳方案，但应"**极其审慎地使用**"。
- **附注**：`std::cin` 与 `std::cout` 这些 iostream 对象就是用多继承实现的。

## 最佳实践

- **Best practice**："Avoid multiple inheritance unless alternatives lead to more complexity."（除非替代方案会导致更大的复杂度，否则避免多继承。）
- **For advanced readers**：混入用来添加功能而非提供接口，通常不用虚函数；需要定制时常用模板，因此混入类常被模板化。

## 代码示例

- [24-09-example1.cpp](24-09-example1.cpp)：`Teacher` 同时公有继承 `Person` 与 `Employee`，组合两者的属性（原 Example 1）。
- [24-09-example2.cpp](24-09-example2.cpp)：混入示例 `Box` + `Label` + `Tooltip` 组合成 `Button`；同名 `setText` 需显式加作用域前缀（原 Example 2）。
- [24-09-example3.cpp](24-09-example3.cpp)：CRTP——`Derived` 继承 `Mixin<Derived>`，混入通过 `static_cast<T*>(this)` 触达派生类成员（原 Example 3，已补全为可编译最小示例）。
- [24-09-example4-error.cpp](24-09-example4-error.cpp)：`WirelessAdapter` 同时继承两个都有 `getID()` 的基类，不加限定的调用产生歧义（原 Example 4，预期**编译失败**）。
- [24-09-example5.cpp](24-09-example5.cpp)：用 `c54G.USBDevice::getID()` 显式作用域消除歧义（原 Example 5）。
- [24-09-example6.cpp](24-09-example6.cpp)：菱形问题——`Copier` 同时继承 `Scanner` 与 `Printer`，两者又都继承 `PoweredDevice`（原 Example 6）。

> 说明：本节代码为按原文描述重建。

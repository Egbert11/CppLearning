# 21.12 Overloading the assignment operator

> 原文：https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/

## 核心概念

- **拷贝赋值运算符**：`operator=` 把值从**一个已存在的对象**拷贝到**另一个已存在的对象**（区别于拷贝构造函数——后者负责“创建新对象”）。
- **移动赋值（相关）**：C++11 起还支持移动赋值，见 22.3。
- **用途重叠**：拷贝构造函数和拷贝赋值运算符做的事几乎一样——都是“把一个对象拷到另一个对象”。
- **关键区别**：拷贝构造函数创建**新对象**；赋值运算符替换**已存在对象**的内容。
- **用哪个**：若必须先创建新对象（包括按值传参 / 返回），用拷贝构造函数；若无需新对象，用赋值运算符。
- **必须是成员函数**：拷贝赋值运算符“必须作为成员函数”重载。
- **返回 `*this`**：好的 `operator=` 返回 `*this`，从而支持链式赋值 `f1 = f2 = f3`。
- **自赋值合法**：C++ 允许对象赋给自己，`f1 = f1` 会调用 `f1.operator=(f1)`。
- **自赋值为何危险**：只做成员逐个复制时它仅浪费；但当运算符需要动态分配内存时，对象可能先删掉自己将要复制的资源。
- **失败机制**：若参数与隐式对象是同一对象，则 `m_data == str.m_data`；删掉 `m_data` 后两个指针都悬垂，随后的复制读到未初始化（垃圾）内存。
- **如何检测**：比较地址 `if (this == &str) return *this;`——快速的指针比较，不需要 `operator==`。
- **何时不必检查**：拷贝构造函数里通常可省（被构造的对象是新的；唯一风险是用“未初始化的自身”初始化自身，编译器会报警告）。
- **天然安全的类**：每个操作本身都能容忍自赋值的类（如简单的 `Fraction`）可省去检查。
- **作者立场**：虽然有知名专家主张“自赋值极罕见、可省检查以优化”，但本课建议**防御式编码**，优化留到以后按需进行。
- **copy-and-swap**：处理自赋值的更优技术，原文给了 Stack Overflow 链接。
- **隐式拷贝赋值运算符**：不写时编译器会生成一个 public 的、做**逐成员赋值**的版本（类似默认拷贝构造的逐成员初始化）。
- **禁用赋值**：可把拷贝赋值运算符设为 private，或用 `= delete`。
- **const 成员**：若类有 const 成员，编译器把隐式 `operator=` 定义为 **deleted**（const 成员不能赋值）；要让这样的类可赋值，必须显式重载 `operator=` 并手工给每个非 const 成员赋值。

## 最佳实践

- 原文没有正式的 Best practice / Warning 框；核心建议为：
  - 除非类天然安全或用 copy-and-swap，否则**始终写自赋值检查**（防御式编码）。
  - 需要“创建新对象”用拷贝构造，其余用赋值运算符。
  - 注意：带 const 成员的类，隐式 `operator=` 会被定义为 deleted。

## 代码示例

- [21-12-example1.cpp](21-12-example1.cpp) — `Fraction` 的朴素 `operator=`，`f = fiveThirds`（输出 `5/3`）。
- [21-12-example2.cpp](21-12-example2.cpp) — 链式赋值 `f1 = f2 = f3` 与自赋值 `f1 = f1`（输出 `9/5`）。
- [21-12-example3-broken.cpp](21-12-example3-broken.cpp) — `MyString` 的“朴素/勿用”`operator=`（坏实践，输出 `Alex`）。
- [21-12-example4-ub.cpp](21-12-example4-ub.cpp) — 自赋值 `alex = alex` 读到已释放内存（**未定义行为**）。
- [21-12-example5.cpp](21-12-example5.cpp) — 带自赋值检查的 `MyString::operator=`（输出 `Alex`）。
- [21-12-example6.cpp](21-12-example6.cpp) — 带自赋值保护的 `Fraction::operator=`（输出 `5/3`）。
- [21-12-example7-error.cpp](21-12-example7-error.cpp) — `= delete` 禁止拷贝与赋值，**预期编译失败**。

说明：本节代码为按原文描述重建（原文长代码块受抓取工具逐字引用上限所限）。

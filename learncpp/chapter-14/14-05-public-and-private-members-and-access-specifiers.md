# 14.5 Public and private members and access specifiers

> 原文：https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/

## 核心概念

- **开篇类比**：公园是任何人可进入的公共空间（public），而陌生人的住宅是私有的（private），只有其成员（或被明确许可者）才能进入。
- **访问级别（access level）**：类类型的每个成员都有一个"访问级别"属性，决定谁可以访问它。
- **三种访问级别**：C++ 提供 public、private、protected；本节讲常用的前两种，protected 留到继承章节。
- **编译期检查**：每次访问成员时，编译器都会检查访问级别是否允许；否则产生编译错误。这套机制俗称"访问控制（access controls）"。
- **struct 成员默认 public**：public 成员没有任何访问限制，只要在作用域内任何人都能访问。
- **"the public" 的含义**：指某个类类型的成员之外的代码，例如非成员函数、其它类类型的成员；public 成员既能被同类成员访问，也能被 public 访问。
- **class 成员默认 private**：private 成员只能被同一个类的其它成员访问，public 无法访问。
- **非聚合体的后果**：含私有成员的 class 不满足聚合体"没有 private/protected 非静态数据成员"的要求，因此不再能使用聚合初始化。
- **命名约定**：私有数据成员常见做法是加 `m_` 前缀，把数据成员与形参、局部变量区分开，避免命名冲突。类似约定还有静态局部量的 `s_` 和全局量的 `g_`。
- **访问说明符（access specifiers）**：`public:`、`private:`、`protected:` 用来设置**其后所有成员**的访问级别。
- **显式与冗余说明符**：由于 class 默认 private，开头的 `private:` 可以省略，不过许多开发者仍写出来以求清晰。
- **可以出现多个说明符**：一个类类型可以按任意顺序、任意次数地重复使用访问说明符。
- **struct / class 的最佳实践**：struct 应完全避免访问说明符，保持所有成员 public 且仍是聚合体；class 一般应把数据成员设为 private（或 protected）、把成员函数设为 public。
- **按类而非按对象**：访问控制是按**类**定义的，因此成员函数可以直接访问**同类任意对象**的私有成员（只要该对象在作用域内）。
- **struct 与 class 的技术区别**：class 的成员默认 private，struct 的成员默认 public——这是唯一有意义的区别。
- **实践指导**：当满足"数据只是一个简单集合、不需要限制访问、聚合初始化足够、没有类不变量和构造/清理需求"时用 struct；否则用 class。

## 访问级别速查表

| 访问级别 | 访问说明符 | 同类成员可访问 | 派生类可访问 | public 可访问 |
|---|---|---|---|---|
| Public | `public:` | 是 | 是 | 是 |
| Protected | `protected:` | 是 | 是 | 否 |
| Private | `private:` | 是 | 否 | 否 |

## 最佳实践

- **Best practice（命名）**：考虑给私有数据成员加 `m_` 前缀，以便与局部变量、函数形参和成员函数区分开。
- **Best practice（struct 与 class 的取舍）**：class 一般应把成员变量设为 private（或 protected）、成员函数设为 public；struct 一般应避免访问说明符，让所有成员保持 public。
- **Key insight（struct）**：struct 的成员默认是 public，可被同类其它成员与 public 访问。
- **Key insight（class）**：class 的成员默认是 private，只能被同类其它成员访问；这样的 class 含私有成员，不再是聚合体，无法使用聚合初始化。
- **Author's note**：还有一个吹毛求疵的差别——struct 默认 public 继承，class 默认 private 继承；但这实际上无关紧要，因为依赖继承默认值是被劝阻的做法。
- **测验要点回顾**：public 成员=任何人都能访问（含同类成员与 public）；private 成员=只有同类其它成员能访问；访问说明符=控制其后成员可被谁访问；共有三种：public、private、protected。

## 代码示例

- [14-05-example1.cpp](14-05-example1.cpp)：struct 成员默认 public，可被成员函数与 `main()` 访问，输出 `2020/10/16`。
- [14-05-example2-error.cpp](14-05-example2-error.cpp)：改为 class 后三处编译失败（聚合初始化、访问私有成员、调用私有函数）。
- [14-05-example3.cpp](14-05-example3.cpp)：`setName()` setter 片段，演示 `m_` 前缀命名约定（已补最小类与 `main()`）。
- [14-05-example4.cpp](14-05-example4.cpp)：显式使用 `public:` / `private:` 划分成员可访问性，输出 `2020/14/10`（原文成员初值如此）。
- [14-05-example5.cpp](14-05-example5.cpp)：省略冗余的开头 `private:`。
- [14-05-example6.cpp](14-05-example6.cpp)：显式写出冗余的 `private:` 以求清晰。
- [14-05-example7.cpp](14-05-example7.cpp)：访问控制按类生效，`kisses()` 读取另一个对象的私有成员，输出 `Joe kisses Kate`。
- [14-05-quiz1.cpp](14-05-quiz1.cpp)：测验 2a 解答，`Point3d` 的 `setValues()` / `print()`，输出 `<1, 2, 3>`。
- [14-05-quiz2.cpp](14-05-quiz2.cpp)：测验 2b 解答，为 `Point3d` 增加 `isEqual()`，输出两行比较结果。

> 说明：本节代码为按原文描述**忠实重建**（抓取工具对长代码块有逐字引用上限）。原文中两段仅调用接口的 driver 程序（测验 2a/2b）已并入对应解答文件的 `main()`。

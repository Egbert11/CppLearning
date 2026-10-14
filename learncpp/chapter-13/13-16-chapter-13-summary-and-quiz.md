# 13.x Chapter 13 summary and quiz

> 原文：https://www.learncpp.com/cpp-tutorial/chapter-13-summary-and-quiz/
>
> 说明：本小节为 Chapter 13 的总结与测验，官方编号为 **13.x**；按本仓库约定，其文件编号取整章的下一个顺延号，即 **16**。

## 本章知识速览

（按原文顺序概括整章要点，含前半部分 13.1–13.8 与本代理负责的 13.9–13.15。）

- **程序定义类型（program-defined type，又称 user-defined type）**：为自用程序创建的自定义类型。通过枚举类型和类类型（struct、class、union）实现；程序定义类型必须先定义后使用，其定义称为**类型定义（type definition）**，**豁免于单一定义规则（ODR）**。
- **枚举（enumeration / enum，枚举类型）**："一种复合数据类型，其中每个可能的值都定义为一个符号常量（称为**枚举项 enumerator**）。"枚举是**不同的类型**，编译器能把它们与其它类型区分开——不像类型别名。
- **非限定作用域枚举（unscoped enumeration）**：得名于其枚举项名字落在与枚举定义相同的**作用域**里，而不是像命名空间那样获得一个新作用域区域。它仍为枚举项提供命名的作用域区域，并且"会隐式转换为整数值"。
- **限定作用域枚举（scoped enumeration）**：与非限定枚举类似，但"不会隐式转换为整数"，且枚举项**只**存在于枚举自身的作用域区域内，而非枚举定义所在处。
- **结构体（struct，全称 structure）**：一种把多个变量捆绑进一个类型的程序定义数据类型。其变量称为**数据成员（data member / member variable）**；访问用**成员选择运算符**（`operator.`，用于 struct 对象与引用）或**从指针选择成员运算符**（`operator->`，用于指针）。
- **聚合数据类型（aggregate data type / aggregate）**：一般指持有多个数据成员的类型。在 C++ 中，数组以及只含数据成员的 struct 都属于聚合。
- **聚合初始化（aggregate initialization）**：通过**初始化列表**（逗号分隔的值）直接初始化成员；它执行**逐成员初始化（memberwise initialization）**，各成员按声明顺序初始化。
- **指定初始化器（designated initializers，C++20）**：可指明哪个值对应哪个成员。成员"必须按 struct 中的声明顺序初始化，否则会报错"。
- **非静态成员初始化（non-static member initialization）**：在类型定义中为每个成员给出默认值，该值即**默认成员初始化器（default member initializer）**。
- **填充（padding）**：编译器有时为性能而向结构体中插入空隙，因此结构体的大小"可能大于其成员大小之和"。
- **类模板（class template）**：用于实例化类类型（struct、class、union）的模板定义。**类模板实参推导（CTAD）**是 C++17 特性，允许编译器"从初始化器"推导模板类型实参。

其它贯穿本章的要点：

- **按 const 引用传递结构体**以避免拷贝；函数只返回一个值，struct 可打包多个；返回函数内的 struct 要**按值返回**，以免悬垂引用。
- **拥有者 vs 观察者**：struct/class 通常应是**拥有者**——给每个成员一个拥有型类型；观察者成员可能悬垂。
- **成员选择**：对象/引用用 `.`，指针用 `->`（等价于 `(*ptr).member`）；可链式 `ptr->c->y`，也可混用 `(ptr->paw).claws`。
- **模板**：类模板把类型参数化；推导指引（C++17）帮助 CTAD；别名模板只能定义在全局作用域。

## 测验

### Q1：Monster 结构体

编写一个 `Monster` 结构体，包含：一个枚举类型成员（怪物种类：ogre、dragon、orc、giant_spider、slime）、一个 `std::string` 名字、一个 `int` 生命值。再写一个函数把种类枚举转成字符串、一个 `printMonster()` 函数打印描述，并在 `main` 中创建两只怪物并打印。

解答代码：[13-16-quiz1.cpp](13-16-quiz1.cpp)

预期输出：

```
This Ogre is named Torg and has 145 health.
This Slime is named Blurp and has 23 health.
```

### Q2：传递约定

对以下每个类型/情形，判断一般应按值、按引用、按 const 引用还是按地址传递：

- `char` → 按值
- `std::string` → 按 const 引用
- `unsigned long` → 按值
- `bool` → 按值
- `int`（当 nullptr 是合法实参时）→ 按地址
- `Position`（含 `double x, y, z` 的 struct）→ 按 const 引用
- `Player`（含 `int health` 的 struct，仍在开发中）→ 按 const 引用
- `std::string_view` → 按值（拷贝便宜，且不会拷贝所观察的字符串）

**Q2f 的结构体定义**（`Position`）：

```cpp
struct Position
{
    double x{};
    double y{};
    double z{};
};
```

**Q2g 的结构体定义**（`Player`）：

```cpp
struct Player
{
    int health{};
};
```

> 本题为概念题，无独立可运行程序；结构体定义随题给出。

### Q3：Triad 类模板

编写一个 `Triad` 类模板，含三个同类型成员 `first`、`second`、`third`；允许 `Triad t{ 1, 2, 3 }` 使用 CTAD（必要时补一个推导指引）；再写 `print` 函数模板打印形如 `[1, 2, 3]` 的内容。

解答代码：[13-16-quiz3.cpp](13-16-quiz3.cpp)

预期输出：

```
[1, 2, 3][1.2, 3.4, 5.6]
```

> 本节 Best practice / Author's note / Warning 条目：无。

# 15.x Chapter 15 summary and quiz

> 原文：https://www.learncpp.com/cpp-tutorial/chapter-15-summary-and-quiz/

（官方编号 15.x；本库文件编号顺延为 15-11。）

## 本章知识速览

- **`this` 指针**：凡是**非静态**成员函数，`this` 都是一个 const 指针，保存着"当前隐式对象"的地址。
- **方法链式调用**：让函数按引用返回 `*this`，就能在一个表达式里对同一对象连续调用多个成员函数。
- **类的声明放在哪**：把类定义放进"与类同名"的头文件。
- **平凡的成员函数**：访问函数、空函数体的构造函数等，可直接定义在类定义内。
- **非平凡的成员函数**：定义在"与类同名"的源文件里。
- **嵌套类型（成员类型）**：声明在类类型内部的类型；类型别名也可以嵌套在类里。
- **模板与成员函数**：定义在类模板内的成员函数可以使用该模板的参数；定义在类模板外的成员函数必须重列模板参数声明，并且要与类模板放在同一文件、紧邻其下方。
- **静态成员变量**：具有静态存储期、被该类所有对象共享的成员；即使一个对象都没实例化，它也存在。
- **访问静态成员**：首选"类名 + 作用域解析运算符 `::` + 成员名"的形式。
- **`inline` 静态成员**：把静态成员标为 `inline`，就能在类定义内初始化它。
- **静态成员函数**：无需任何对象即可调用；它没有 `*this` 指针，因此不能访问非静态数据成员。
- **`friend` 声明**：类体内的 `friend` 关键字告知编译器：另一个类或函数现在是友元。
- **友元（friend）**：被授予"对另一个类的私有和保护成员完全访问权"的类或函数（成员或非成员）。
- **友元函数**：可以像属于某个类一样去读取其私有和保护成员的函数——无论它是成员函数还是非成员函数。
- **友元类**：被允许访问另一个类的私有和保护成员的类。

## 最佳实践

- **Best practice**：把类定义放进与类同名的头文件。
- **Best practice**：把非平凡的成员函数定义在与类同名的源文件里。
- **Best practice**：用类名和作用域解析运算符（`::`）访问静态成员。

## 代码示例

- [15-11-quiz1.cpp](15-11-quiz1.cpp)：本章综合测验"随机怪物生成器"的完整解答（覆盖下述 a–h 全部要求）。

> 说明：本节代码为按原文描述重建。原文使用 8.15 的 `Random.h`，本文件为自包含起见将随机数工具内联在顶部；输出为随机结果。

## 测验

**题目：让我们来做一个"随机怪物生成器"（Let's create a random monster generator）。** 要求按 a–h 逐步完成：

- **(a)** 声明一个限定枚举（scoped enum）`MonsterType`，包含 8 个怪物类型：`dragon`、`goblin`、`ogre`、`orc`、`skeleton`、`troll`、`vampire`、`zombie`，末尾再加一个 `maxMonsterTypes` 用于计数。
- **(b)** 编写 `Monster` 类，含 4 个私有成员：`MonsterType m_type`、`std::string m_name`、`std::string m_roar`、`int m_hitPoints`。
- **(c)** 把 `MonsterType` 移入 `Monster` 内，改为嵌套的**非限定**枚举 `Type`（同样 8 个类型 + `maxMonsterTypes`）；这样写成 `Monster::Type` 而非 `Monster::MonsterType`。
- **(d)** 给 `Monster` 添加一个四参数构造函数 `(Type type, std::string_view name, std::string_view roar, int hitPoints)`，用成员初始化列表初始化全部成员。要求示例 `Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };` 能编译。
- **(e)** 添加 `constexpr std::string_view getTypeString() const`，用 `switch` 返回类型名（`default` 返回 `"???"`）；再添加 `void print() const`：打印名字与类型，当血量 ≤ 0 时打印 `" is dead.\n"`，否则打印"血量 + 叫声"的句子。
- **(f)** 添加一个**无状态**的 `MonsterGenerator` 命名空间，内含 `Monster generate()`，先返回一只固定的骷髅怪物。
- **(g)** 在 `MonsterGenerator` 中加入 `getName(int)` 与 `getRoar(int)`（均为覆盖 0–5 的 `switch`，`default` 返回 `"???"`），并让 `generate()` 调用它们。
- **(h)** 引入随机化：用 8.15 的 `Random.h` 为类型、名字、吼声、血量（1–100）分别取随机值。

**解答**：见 [15-11-quiz1.cpp](15-11-quiz1.cpp)（完整实现 a–h）。

原文给出的期望输出形态（随机，仅供参考）：

```
Bones the skeleton has 4 hit points and says *rattle*.
Nibblez the vampire is dead.
Blarg the skeleton has 4 hit points and says *ROAR*
Mort the zombie has 61 hit points and says *growl*
```

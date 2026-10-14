# 11.3 Function overload resolution and ambiguous matches

> 原文：https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/

## 核心概念

- **重载解析（overload resolution）**：编译器确定某次调用最匹配哪个重载函数的过程。一次函数调用只能解析到唯一一个重载。
- **每步的可能结果**：在每个步骤中编译器应用转换并检查匹配，结果只有三种——找不到匹配（进入下一步）、恰好一个匹配（最佳匹配，结束）、出现多个匹配（ambiguous，报错）。
- **步骤 1——精确匹配**：分两个阶段。第一阶段是实参类型与形参类型完全一致；第二阶段是应用"平凡转换"（trivial conversions）。
- **平凡转换**：只改变类型而不改变值的转换——左值到右值、限定转换（如 non-const 到 const）、非引用到引用。通过这些转换得到的匹配仍算作精确匹配。
- **步骤 2——数值提升（numeric promotion）**：把较窄的整型/浮点型提升为更宽的类型（如 `int`、`double`）；由此得到的匹配即确定该次调用。
- **步骤 3——数值转换（numeric conversion）**：若提升失败，则尝试数值转换（如 `char` 到 `double`）。
- **Key insight**："Matches made by applying numeric promotions take precedence over any matches made by applying numeric conversions."（由数值提升得到的匹配优先于由数值转换得到的匹配。）
- **步骤 4——用户定义转换（user-defined conversion）**：类类型可定义隐式转换；在此转换之后还可继续应用提升/转换。
- **步骤 5——省略号**：编译器接下来寻找使用省略号形参的函数。
- **步骤 6——失败**：到此仍无匹配则产生编译错误。
- **歧义匹配（ambiguous match）**：当编译器在**同一步骤内**找到两个或更多匹配时，它停止并报告 ambiguous function call。
- **Key insight**："no match from a given step is considered to be better than any other match from the same step."（同一步骤内的多个匹配之间没有优劣之分。）
- **消除歧义的三种办法**：(a) 定义接受精确类型的重载；(b) 显式转换实参；(c) 对字面量使用类型后缀。
- **多参数情形**：胜出的函数必须对**每个**实参的匹配都不差于其他候选，且至少对其中一个实参更优；否则该调用要么有歧义，要么根本无匹配。

## 最佳实践

本节无 Best practice / Rule / Warning 条目。
- **Key insight ×2**：数值提升优先于数值转换；同一步骤内的多个匹配无优劣之分，构成歧义。
- **For advanced readers ×2**：类的构造函数也充当一种用户定义转换；默认实参（见 11.5）可能导致歧义匹配。

## 代码示例

- [11-03-example1.cpp](11-03-example1.cpp)：精确匹配——`int` 实参选 `print(int)`，`double` 实参选 `print(double)`（对应原文 Example 1/3）。
- [11-03-example2.cpp](11-03-example2.cpp)：`char` 实参没有精确匹配，经数值提升解析到 `print(int)`（对应原文 Example 2）。
- [11-03-example3.cpp](11-03-example3.cpp)：平凡转换——`int→const int`、`double→const double&` 仍算精确匹配（对应原文 Example 4）。
- [11-03-example4-error.cpp](11-03-example4-error.cpp)：`foo(int)` 与 `foo(const int&)` 均以平凡转换匹配，构成歧义——**预期编译失败**（对应原文 Example 5）。
- [11-03-example5.cpp](11-03-example5.cpp)：数值提升解析调用——`'a'`、`true` 提升到 `int`，`4.5f` 提升到 `double`（对应原文 Example 6）。
- [11-03-example6.cpp](11-03-example6.cpp)：无精确/提升匹配时用数值转换——`'a'` 转换以匹配 `foo(double)`（对应原文 Example 7）。
- [11-03-example7.cpp](11-03-example7.cpp)：用户定义转换——类 `X` 经 `operator int()` 匹配 `foo(int)`（对应原文 Example 8）。
- [11-03-example8.cpp](11-03-example8.cpp)：非重载函数：`foo()` 找到匹配即通过（对应原文 Example 9）。
- [11-03-example9-error.cpp](11-03-example9-error.cpp)：`foo(5L)` 中 `long` 到 `int` 与到 `double` 均为数值转换，构成歧义——**预期编译失败**（对应原文 Example 10）。
- [11-03-example10-error.cpp](11-03-example10-error.cpp)：`foo(0)` 与 `foo(3.14159)` 相对 `foo(unsigned int)`/`foo(float)` 均歧义——**预期编译失败**（对应原文 Example 11）。
- [11-03-example11.cpp](11-03-example11.cpp)：用 `static_cast` 或字面量后缀 `u` 消除歧义（对应原文 Example 12/13）。
- [11-03-example12.cpp](11-03-example12.cpp)：多参数时提升优先于转换——`print('x','a')` 解析到 `print(char,int)`（对应原文 Example 14）。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。
> 错误示例文件按约定以 `-error` 后缀命名，文件头已写明预期错误，请勿修复。

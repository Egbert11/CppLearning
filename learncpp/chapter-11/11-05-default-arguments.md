# 11.5 Default arguments

> 原文：https://www.learncpp.com/cpp-tutorial/default-arguments/

## 核心概念

- **默认实参（default argument）**：为函数形参提供的默认值，即调用时可以省略其值的形参。
- **调用者行为**：调用时既可传入该形参的值（用你给的值），也可省略（用默认值）。
- **语法要求**：必须用 `=`；用括号或花括号初始化默认值是编译错误。
- **编译器处理方式（Key insight）**：默认实参在**调用点**处理——编译器把 `print(3)` 这样的调用改写成 `print(3, 4)`，使实参个数与形参个数一致。
- **何时使用**：当一个函数需要一个有合理默认值、但调用者可能想覆盖的值时适用。
- **Author's note（术语）**：带默认值的形参有时被称为"optional parameter"，但该词也被用于其他概念（按地址传递的形参、`std::optional`），因此建议避免使用它。
- **给已有函数增加形参**：增加一个**没有**默认值的形参会破坏所有既有调用；增加一个**带**默认值的形参则让老调用继续可用，同时允许新调用传显式值。
- **多个默认实参**：一个函数可有多个带默认值的形参。
- **不能跳过位置**：C++（直至 C++23）没有 `print(,,3)` 这样的语法，由此产生三点后果：
  - (a) 显式给出的实参必须是最左边的若干个；不能跳过默认值。
  - (b) **规则**：若某个形参给了默认实参，则其右侧的每个形参也必须给默认实参。
  - (c) 若有多个形参带默认值，最左侧的那个应是用户最可能显式设置的值。
- **不能重复声明**：默认实参不能在同一翻译单元中被重复声明，因此若同时有前向声明和定义，它只能出现在声明或定义**之一**中（不能都写）。
- **使用前须先声明**：默认实参必须在任何依赖它的调用之前出现于该翻译单元中。
- **Best practice**：若存在前向声明（尤其是放在头文件里），把默认实参放在前向声明中；否则放在函数定义中。
- **重载**：带默认实参的函数可以被重载；默认值不属于函数签名的一部分，因此仅默认值不同的声明是不同的重载。
- **歧义**：默认实参可能使调用产生歧义（例如空调用同时匹配两个重载），不过可通过显式指定第二个实参来消除歧义。
- **函数指针（进阶）**：通过函数指针调用时不考虑默认实参；这也提供了绕开默认实参所致歧义的办法。

## 最佳实践

- **Best practice**："If the function has a forward declaration (especially one in a header file), put the default argument there. Otherwise, put the default argument in the function definition."（若有前向声明——尤其是头文件里的——把默认实参放在那里；否则放在函数定义中。）
- **Rule**："If a parameter is given a default argument, all subsequent parameters (to the right) must also be given default arguments."（若某形参给了默认实参，其右侧所有形参也必须给默认实参。）
- **Key insight**："Default arguments are inserted by the compiler at site of the function call."（默认实参由编译器在调用点插入。）
- **Author's note**：带默认值的形参有时被称作 "optional parameter"，但该词也指按地址传递的形参和 `std::optional` 形参，建议避免使用。
- **For advanced readers**：通过函数指针调用时不会应用默认实参（见 20.1），这也提供了绕开默认实参所致歧义的办法。

## 代码示例

- [11-05-example1.cpp](11-05-example1.cpp)：带默认实参 `y=4` 的 `print`，对比显式传参与省略传参（对应原文 Example 2）。
- [11-05-example2-error.cpp](11-05-example2-error.cpp)：默认值只能用 `=` 给出，括号/花括号写法均报错——**预期编译失败**（对应原文 Example 3）。
- [11-05-example3.cpp](11-05-example3.cpp)：三个默认实参 `x=10,y=20,z=30` 的各种省略组合及其输出（对应原文 Example 5）。
- [11-05-example4-error.cpp](11-05-example4-error.cpp)：带默认值的形参无法被跳过——`print(20.0)` 无匹配——**预期编译失败**（对应原文 Example 6）。
- [11-05-example5-error.cpp](11-05-example5-error.cpp)：默认形参右侧不允许出现无默认值的形参——**预期编译失败**（对应原文 Example 7）。
- [11-05-example6-error.cpp](11-05-example6-error.cpp)：同一翻译单元内重复声明默认实参——**预期编译失败**（对应原文 Example 8）。
- [11-05-example7-error.cpp](11-05-example7-error.cpp)：默认实参必须在调用之前声明，否则实参过少——**预期编译失败**（对应原文 Example 9）。
- [11-05-example8/](11-05-example8/)：把默认实参放在头文件的前向声明里（`foo.h` + `main.cpp`）（对应原文 Example 10）。
- [11-05-example9.cpp](11-05-example9.cpp)：重载函数中使用默认实参，`print()` 解析到 `print(char)`（对应原文 Example 11）。
- [11-05-example10.cpp](11-05-example10.cpp)：默认值不属于签名——三个签名不同的重载声明（对应原文 Example 12）。
- [11-05-example11-error.cpp](11-05-example11-error.cpp)：两个带默认值的重载使空调用歧义——**预期编译失败**（对应原文 Example 13）。
- [11-05-example12-error.cpp](11-05-example12-error.cpp)：三个重载下 `print(1)` 因默认值而歧义——**预期编译失败**（对应原文 Example 14）。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。
> 原文 Example 1、4（`void print(int x, int y=10)` 与 `int rollDie(int sides=6)` 等声明片段）已并入上面示例的说明。
> 错误示例文件按约定以 `-error` 后缀命名，文件头已写明预期错误，请勿修复。

## 附加说明：多文件示例 11-05-example8/

`foo.h` 中的前向声明写有默认实参 `y=4`，`main.cpp` 中的定义**不**再重复默认值（重复会报错）。编译：

```
g++ -std=c++20 -Wall 11-05-example8/*.cpp -o a
```

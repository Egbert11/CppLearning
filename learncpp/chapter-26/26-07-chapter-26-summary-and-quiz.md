# 26.x Chapter 26 summary and quiz

> 原文：https://www.learncpp.com/cpp-tutorial/chapter-26-summary-and-quiz/
> 注：本文件按官方编号记为 26.x，文件名顺延为 `26-07-...`。

## 本章知识速览

- **模板 = 占位类型**：模板让我们用占位类型编写函数或类，从而针对不同类型"拓印"出相同的版本；已被实例化的函数或类称为函数实例（function instance）或类实例（class instance）。
- **模板参数声明**：所有模板函数或类都必须以模板参数声明开头，告诉编译器"下面这是个模板"；声明中列出模板类型参数或表达式参数。类型参数就是占位类型，通常命名为 `T`、`T1`、`T2` 或其它单字母名（例如 `S`）。表达式参数通常是整型，但也可以是指向函数、类对象或成员函数的指针或引用。
- **模板的拆分方式与普通类不同**：不能像普通类那样把类定义放头文件、成员函数定义放 `.cpp`。通常最好把它们都放在头文件里，成员函数定义写在类下方。
- **特化**：当我们想针对某个具体类型覆盖模板函数或类默认行为时，使用模板特化。若所有类型都被覆盖，称为全特化（full specialization）。类还支持偏特化（partial specialization），即只特化部分模板参数。**函数不能被偏特化**。
- **标准库与容器**：C++ 标准库中许多类都用了模板，包括 `std::array` 与 `std::vector`。模板常用于实现容器类，让容器写一次就能配合任意合适的类型使用。

## 测验

1. 有时我们需要"成对出现"的数据。写一个模板类 `Pair1`，只允许用户定义一个模板类型，该类型同时用于一对中的两个值。给定程序应当能运行：
   ```cpp
   int main()
   {
       Pair1<int> p1 { 5, 8 };
       std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

       const Pair1<double> p2 { 2.3, 4.5 };
       std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

       return 0;
   }
   ```
   并打印 `Pair: 5 8` 与 `Pair: 2.3 4.5`。解答见 [26-07-quiz1.cpp](26-07-quiz1.cpp)。

2. 写一个 `Pair` 类，允许分别为一对中的两个值指定不同类型。注意：之所以给它另起名字，是因为 C++ 目前不允许"重载"仅模板参数个数或类型不同的类。给定程序应当能运行：
   ```cpp
   int main()
   {
       Pair<int, double> p1 { 5, 6.7 };
       std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

       const Pair<double, int> p2 { 2.3, 4 };
       std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

       return 0;
   }
   ```
   并打印 `Pair: 5 6.7` 与 `Pair: 2.3 4`。
   提示：要定义使用两种不同类型的模板，在模板参数声明中用逗号把两个类型分开。参见 11.8 —— Function templates with multiple template types。解答见 [26-07-quiz2.cpp](26-07-quiz2.cpp)。

3. string-value pair 是一种特殊的 pair：第一个值恒为字符串类型，第二个值可以是任意类型。写一个模板类 `StringValuePair`，它继承自一个部分特化的 `Pair` 类（以 `std::string` 作为第一个类型，并允许用户指定第二个类型）。给定程序应当能运行：
   ```cpp
   int main()
   {
       StringValuePair<int> svp { "Hello", 5 };
       std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

       return 0;
   }
   ```
   并打印 `Pair: Hello 5`。
   提示：当你从 `StringValuePair` 的构造函数里调用 `Pair` 的构造函数时，别忘了把模板参数作为 `Pair` 类名的一部分写出来。解答见 [26-07-quiz3.cpp](26-07-quiz3.cpp)。

> 说明：本节代码取自原文 HTML 逐字抽取（`<pre>` 块），与原文一致。

# 21.2 Overloading the arithmetic operators using friend functions

> 原文：https://www.learncpp.com/cpp-tutorial/overloading-the-arithmetic-operators-using-friend-functions/

## 核心概念

- **算术运算符**：`+`、`-`、`*`、`/`。它们都是**二元运算符**，各取两个操作数（左右各一个），四者的重载方式完全一样。
- **三种重载方式**：成员函数、友元函数、普通函数。本节讲友元方式（对大多数二元运算符更直观）；下一节讲普通函数方式；本章稍后讲成员函数方式，并会总结各自适用场景。
- **如何用友元重载 `+`**：声明一个名为 `operator+` 的函数，参数类型与要相加的两个操作数一致，选择合适的返回类型，然后实现。因为函数是友元，可直接访问私有成员（如 `m_cents`）；函数内部对整数的相加用的是内置 `+`。
- **`-`、`*`、`/`**：减法同理，乘、除法只要分别定义 `operator*`、`operator/`，同样简单。
- **友元函数可以定义在类内**：虽然友元不是成员（原文注释：即便定义写在类内部，它也不算类的成员），但对实现简单的运算符，这样写是可以接受的。
- **操作数类型不同**：在 `x + y` 中，`x` 是第一个参数、`y` 是第二个参数。两操作数类型相同时，`x + y` 与 `y + x` 调用同一个函数；类型不同时，两者解析到不同重载，因此要写两个函数（如 `operator+(Cents, int)` 与 `operator+(int, Cents)`）。两个重载的实现通常完全相同，只是参数顺序不同。
- **MinMax 例子的动机**：该类记录已见的最小值和最大值；`+` 被重载了三次，使两个 MinMax 能合并，也能把整数加到 MinMax 上。
- **求值顺序**：`operator+` 从左到右求值，因此 `m1 + m2 + 5 + 8 + m3 + 16` 会嵌套成 `(((((m1 + m2) + 5) + 8) + m3) + 16)`，每一步结果成为下一步的左操作数。
- **用别的运算符实现运算符**：`operator+(int, MinMax)` 可以直接调用 `operator+(MinMax, int)`，把实现缩到一行、也更易维护。原文建议："常常可以用其它重载运算符来定义重载运算符；只要这样能让代码更简单就应该这样做。"
- **测验 (c) 的规则——隐式转换**：若构造函数 `Fraction(int, int)` 非 `explicit`，并去掉整数重载，`2 * f2` 仍能工作——构造函数把 `2` 转成临时 `Fraction`，再走 `Fraction * Fraction` 重载。这比专用整数重载略慢。
- **测验 (d) 的规则——对临时量的引用**：把 `operator*` 的参数改成非 const 引用后，对临时 `Fraction` 对象做乘法会失败，因为"非 const 引用不能绑定到临时量"。
- **测验 (e) 的规则——约分**：把分数化到最简的方法是求分子分母的最大公约数（GCD）并同时相除；`std::gcd()` 于 C++17 加入 `<numeric>`。把 `reduce()` 放进构造函数，可保证每个构造出的分数（含中间结果）都自动约分；同时要防止除以 0。

## 最佳实践

本节无正式标注的 Best practice / Author's note / Warning。

要点提示（原文明示）：
- "常常可以用其它重载运算符来定义重载运算符；只要这样能让代码更简单就应该这样做。"
- 乘法重载用 `const Fraction&` 传参：既避免拷贝（按值慢），又能接受右值（非 const 引用则不行）。

## 代码示例

- [21-02-example1.cpp](21-02-example1.cpp)：友元重载 `operator+`，两个 Cents 相加，输出 `I have 14 cents.`。
- [21-02-example2.cpp](21-02-example2.cpp)：友元重载 `operator+` 与 `operator-`（构造函数 `explicit`），输出 `I have 4 cents.`。
- [21-02-example3.cpp](21-02-example3.cpp)：把友元 `operator+` 定义在类内部，输出 `I have 14 cents.`。
- [21-02-example4.cpp](21-02-example4.cpp)：`Cents + int` 与 `int + Cents` 两个重载，输出两行 `I have 10 cents.`。
- [21-02-example5.cpp](21-02-example5.cpp)：MinMax 的三个 `operator+` 与链式相加，输出 `Result: (3, 16)`。
- [21-02-quiz1a.cpp](21-02-quiz1a.cpp)：测验 1a——`Fraction` 类与 `print()`，输出 `1/4`、`1/2`。
- [21-02-quiz1b.cpp](21-02-quiz1b.cpp)：测验 1b——友元乘法（Fraction×Fraction、Fraction×int、int×Fraction），输出 `2/5 3/8 6/40 4/5 6/8 6/24`（未约分）。
- [21-02-quiz1e.cpp](21-02-quiz1e.cpp)：测验 1e（加分题）——构造函数中用 `std::gcd` 自动约分，输出 `2/5 3/8 3/20 4/5 3/4 1/4 0/1`。

> 测验 1c（去掉 `explicit` 后 `2 * f2` 仍可用）与 1d（非 const 引用无法绑定临时量）在原文中是**说明性片段**，不是可独立构建的程序；其结论见上文"核心概念"，未单独生成文件。本节代码取自原文。

## 测验

- **1a**：写一个 `Fraction` 类，含整数分子、分母成员和打印分数的 `print()` 函数。
- **1b**：用友元函数法，添加分数与整数相乘、以及分数与分数相乘的重载乘法运算符。
- **1c**：如果去掉构造函数里的 `explicit` 并删掉整数重载，`2 * f2` 还能编译吗？为什么？
- **1d**：若把 `operator*(Fraction, Fraction)` 的引用参数改成非 const，`Fraction{1,2} * Fraction{2,3} * Fraction{3,4}` 为何无法工作？
- **1e（加分）**：加一个 `reduce()` 成员，把分数约到最简（先求 GCD 再相除；C++17 用 `std::gcd`）。

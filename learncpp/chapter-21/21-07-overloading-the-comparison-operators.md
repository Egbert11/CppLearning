# 21.7 Overloading the comparison operators

> 原文：https://www.learncpp.com/cpp-tutorial/overloading-the-comparison-operators/

## 核心概念

- **六个比较运算符**：在 6.7 关系运算符与浮点比较中已介绍过。重载它们相对简单，因为沿用前面见过的重载模式。
- **实现为友元函数**：它们都是**不修改左操作数**的二元运算符，因此本节把重载写成类的友元。
- **例一：Car 的 `==` 与 `!=`**：`Car` 存有品牌和型号；相等要求两个成员都相同，不等则只要有任一成员不同。`main()` 比较 Corolla 与 Camry。
- **并非每个运算符都有意义**：讨论一辆车"大于"另一辆车并不直观，所以原文建议对这类类型**不要**定义 `operator<` 和 `operator>`。
- **排序例外**：若需要排序对象，则可能希望按最可能用于排序的成员来比较（如按 make 与 model 字母序）。若干标准库容器要求重载的 `operator<` 才能保持元素有序。
- **例二：Cents 的全部六个运算符**：每个运算符都独立地比较 `m_cents`。
- **冗余度高**：比较逻辑越复杂，六个实现看起来越重复。
- **四个运算符可由两个推导**：
  - `operator!=` 实现为 `operator==` 取反；
  - `operator>` 实现为把 `operator<` 的两个参数对调；
  - `operator>=` 实现为 `!(operator<)`；
  - `operator<=` 实现为 `!(operator>)`。
- **只实现 `==` 与 `<`**：其余四个都能由这两个定义出来。
- **维护收益**：逻辑要改时，只需改那两个核心运算符，而不是六个。
- **C++20 三路比较（spaceship）运算符**：`operator<=>` 把需要写的比较函数减少到"至多 2 个，有时只需 1 个"。
- **测验 1：Fraction**：给 `Fraction`（含基于 `std::gcd` 的约分）添加六个比较运算符，使给出的 `main()` 能编译；原文也给出 C++17 前的 `gcd` 替代写法。
- **测验 2：Car 排序**：给 `Car` 添加 `operator<<` 和 `operator<`，使 `std::sort` 与范围 for 输出可用。

## 最佳实践

- **Best practice**：只为你觉得直观合理、对类有意义的运算符定义重载。
- **Author's note**（关于三路比较运算符）：原文计划很快新增一节专门讲这个话题；在此之前，请把当前提及当作"勾起你的兴趣"，更多细节需到站外查找。

## 代码示例

- [21-07-example1.cpp](21-07-example1.cpp)：`Car` 只重载 `==` 与 `!=`（有意不定义 `<`/`>`），输出 `a Corolla and Camry are not the same.`。
- [21-07-example2.cpp](21-07-example2.cpp)：`Cents` 独立定义全部六个运算符，输出三行比较结果。
- [21-07-example3.cpp](21-07-example3.cpp)：`Cents` 只实现 `==` 与 `<`，其余四个推导得到；输出与上例相同。
- [21-07-quiz1.cpp](21-07-quiz1.cpp)：测验 1 解答——`Fraction` 的六个比较运算符（`<` 用交叉相乘），输出六行比较结果。
- [21-07-quiz2.cpp](21-07-quiz2.cpp)：测验 2 解答——`Car` 的 `operator<<` 与 `operator<`，供 `std::sort` 与范围 for 使用，输出排序后的 `(Honda, Accord) (Honda, Civic) (Toyota, Camry) (Toyota, Corolla)`。

> 本节代码取自原文（逐字保留）。

## 测验

- **Question #1**：给 `Fraction` 类添加六个比较运算符，使给出的程序能编译（可用 `std::gcd` 约分；C++17 前可用原文给的 `gcd` 替代函数）。
- **Question #2**：给开头的 `Car` 类添加重载的 `operator<<` 和 `operator<`，使给出的 `std::sort` 排序程序能编译并按序输出。

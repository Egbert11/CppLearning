# 6.7 Relational operators and floating point comparisons

> 原文：https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/

## 核心概念

- **关系运算符（relational operators）**：六个比较两值的运算符——`>`（大于）、`<`（小于）、`>=`（大于等于）、`<=`（小于等于）、`==`（相等）、`!=`（不等）。每个都“求值为布尔值 true (1) 或 false (0)”。
- **整数比较很直接**：样例程序读取两个整数并打印成立的每条关系；对 4 和 5 会打印不等、4 更小、4 小于等于。比较整数用这些运算符被描述为直观、无问题。
- **布尔条件值**：`if` 语句或条件运算符中的条件本身已按布尔求值，所以写 `if (b1 == true)` 毫无增益，直接写 `if (b1)`；false 检查 `if (b1 == false)` 同理应写 `if (!b1)`。
- **比较计算得到的浮点值有风险**：一个程序把 `d1` 算作 `100.0 − 99.99`、`d2` 算作 `10.0 − 9.99`，数学上都应等于 0.01，却意外打印 `d1 > d2`。在调试器中两值显示为 0.010000000000005116 与 0.0099999999999997868——都在 0.01 附近，却一个偏大、一个偏小。
- **风险来源**：浮点数不精确，操作数中微小的舍入误差可能把值推得略高或略低于预期，从而打乱比较（详见 4.8）。
- **浮点的 `<` 与 `>`**：`<`、`>`、`<=`、`>=` 在多数情况下给出可信结果，前提是两操作数不几乎相同；当两操作数几乎相等时这些运算符不可靠——上面的 `d1 > d2` 若误差方向相反也可能得到 `false`。
- **该不可靠是否要紧取决于应用**：若两操作数几乎相等时得到错误答案可接受，用这些运算符也无妨。例如游戏判断导弹与外星人是否重叠：相距远时答案正确；极近时结果任意，判错看起来也像擦身而过，不易察觉。
- **相等与不等更麻烦**：`operator==` 只在两操作数完全相等时才返回真，故“哪怕最小的舍入误差”都可能让它在本应为真时返回假；`operator!=` 有同样缺陷。打印 `(0.3 == 0.2 + 0.1)` 得到 `false`。因此对浮点操作数一般应避免使用这两个运算符。
- **一个显著例外**：浮点字面量与“用同类字面量初始化的同类型变量”之间直接比较是安全的，只要每个字面量的有效数字不超过该类型的最小精度（float：6 位有效数字；double：15 位）。故可将函数返回的字面量与同类字面量比较，也可用从字面量初始化的 `const`/`constexpr` 变量与字面量比较。
- **混用不同字面量类型一般不安全**：把 float 字面量与 double 字面量比较（如 `9.8f` 与 `9.8`）会返回 false。
- **进阶：epsilon 思路**：常见做法是判断两数是否“足够接近”以至于可算相等；该阈值称为 **epsilon**，通常是像 1e-8 这样的小正数。
- **朴素的绝对 epsilon 函数**：`approximatelyEqualAbs(a, b, absEpsilon)` 返回 `std::abs(a - b) <= absEpsilon`，用 `<cmath>` 的 `std::abs()`。它能用但被评价为“不够好”：固定 epsilon 0.00001 在 1.0 附近合适，在 0.0000001 附近过大，在 10000 附近过小。
- **固定 epsilon 为何失败**：阈值 0.00001 时，1 与 1.00001 算相等而 1 与 1.0001 不算（合理）；0.0000001 与 0.00001 算相等，尽管相差两个数量级（糟糕）；10000 与 10000.0001 算不同，尽管几乎无法区分（糟糕）。epsilon 需要随输入量级缩放，不如让函数自己去做。
- **Knuth 的相对 epsilon 算法**：Donald Knuth 在《The Art of Computer Programming, Volume II: Seminumerical Algorithms》（Addison-Wesley, 1969）中提出。这里 epsilon 相对于 `a` 或 `b` 的量级：`<=` 左侧度量两操作数间的距离，右侧取较大者乘以 `relEpsilon`，后者相当于百分比（0.01 表示 1% 以内；0.002 表示 0.2% 以内）。
- **用同一函数判断不等**：调用该函数并用逻辑非取反，如 `if (!approximatelyEqualRel(a, b, 0.001))`。
- **相对 epsilon 在零附近失效**：把“几乎 1.0”与 1.0 比较、再把“几乎 0.0”与 0.0 比较，会打印 `true` 然后 `false`——第二种在接近零时算术退化而失败。
- **结合绝对与相对 epsilon**：`approximatelyEqualAbsRel()` 先检查两数在绝对意义上是否极近（处理近零情形），否则回退到 Knuth 算法。`absEpsilon` 应设得极小，如 1e-12。两种算法对样例数据的结果是 `true`、`false`、`true`、`true`，故组合函数能正确处理小输入。
- **没有万能解**：浮点比较很难，没有一刀切算法；不过 `absEpsilon` 取 1e-12、`relEpsilon` 取 1e-8 应付多数情况已足够。
- **把函数设为 `constexpr`（进阶）**：C++23 下 `approximatelyEqual` 函数可标为 `constexpr`，因为 `std::abs` 从 C++23 起是 `constexpr`。C++23 之前不能在常量表达式中调用它们，因为用于常量表达式的 `constexpr` 函数不能调用非 `constexpr` 函数。
- **C++14/17/20 的变通**：用自制的 `constexpr` 绝对值实现（`constAbs()` 函数模板）替代 `std::abs`，它可处理多种数值类型（函数模板见 11.6）。

## 最佳实践

- 不要给条件添加不必要的 `==` 或 `!=`，这会降低可读性而没有额外价值。
- Warning：避免用 `operator==` 和 `operator!=` 比较浮点值——只要这些值有可能是计算出来的。
- Tip：把浮点字面量与“用字面量初始化的同类型变量”比较是安全的，只要每个字面量的有效数字不超过该类型的最小精度（float 6 位，double 15 位）。一般来说，比较不同类型的浮点字面量是不安全的。
- 相关阅读：舍入误差见 4.8；`constexpr` 函数见 F.1；函数模板见 11.6。

## 代码示例

- [6-07-example1.cpp](6-07-example1.cpp)：读取两个整数并打印成立的每条关系。
- [6-07-example2.cpp](6-07-example2.cpp)：布尔条件——`if (b1)` 与 `if (!b1)` 优于 `== true` / `== false`。
- [6-07-example3.cpp](6-07-example3.cpp)：浮点减法意外——数学上都等于 0.01 的两个表达式并不相等。
- [6-07-example4.cpp](6-07-example4.cpp)：相等判断失败——`(0.3 == 0.2 + 0.1)` 打印 `false`。
- [6-07-example5.cpp](6-07-example5.cpp)：`approximatelyEqualAbs()`——朴素绝对 epsilon 版本。
- [6-07-example6.cpp](6-07-example6.cpp)：`approximatelyEqualRel()`（Knuth）及其测试程序（输出 `true`/`false`）。
- [6-07-example7.cpp](6-07-example7.cpp)：`approximatelyEqualAbsRel()` 与同时运行两种算法的测试（输出 `true`/`false`/`true`/`true`）。
- [6-07-example8-cpp23.cpp](6-07-example8-cpp23.cpp)：C++23 的 `constexpr` 版本（需 `-std=c++23`）。
- [6-07-example9.cpp](6-07-example9.cpp)：C++14/17/20 变通——用 `constAbs()` 函数模板替代 `std::abs`。

> 说明：本节代码为按原文描述与站点标准写法**忠实重建**，以保证可用 `g++ -std=c++20 -Wall` 编译运行；原文代码块本身未逐字获取。

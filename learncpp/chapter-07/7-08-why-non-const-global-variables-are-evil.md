# 7.8 Why (non-const) global variables are evil

> 原文：https://www.learncpp.com/cpp-tutorial/why-non-const-global-variables-are-evil/

## 核心概念

- **老手建议：避免全局变量**：若问资深程序员一条良好的实践，多半会说"避免全局变量"；它被列为语言里最常被滥用的概念之一。
- **新手为何喜欢**：它"easy to work with"，尤其在函数调用很多、通过形参传数据很繁琐时——但这种习惯总体是坏主意。
- **澄清——const 与否很关键**：开发者说"全局变量是邪恶的"时，通常指 **非 const** 全局变量，而非所有全局变量。
- **核心危险：状态不可预测**：非 const 全局变量的值可被任何被调用的函数改动，而程序员无从轻易得知；于是每次函数调用都变得潜在危险。
- **局部变量更安全**：其它函数无法直接影响局部变量。
- **调试负担**：若全局变量取到意外值，必须逐一找出所有可能给它赋值的地方并追踪方式——可能涉及看似无关的代码。
- **检查范围**：把变量声明在靠近使用处，可把需要阅读的代码限制在局部；而全局变量可能迫使你通读整个程序。
- **使用点之多**：一个全局变量可能被引用数百次，除非有良好文档，否则每一处都要检查。
- **丧失模块化**：只依赖形参、无副作用的函数是"perfectly modular"；全局变量削弱模块化，损害可理解性与复用性。
- **决策点变量**：避免把全局变量用于条件判断；信息型全局变量（如用户名）比控制"如何运行"的全局变量更不容易搞坏程序。
- **初始化顺序——两个阶段**：静态变量（含全局变量）在程序启动、`main` 之前初始化。**静态初始化**涵盖 constexpr 初始化式（**常量初始化 constant initialization**）与未初始化的全局变量（**零初始化**）；**动态初始化**涵盖非 constexpr 初始化式。
- **文件内**：各阶段一般按定义顺序初始化，动态阶段有少数例外——因此不要依赖在其后才定义的变量。
- **跨翻译单元**：初始化顺序不确定；某文件里的变量可能尚未就绪，另一个文件里使用它的静态存储期对象就用到了它。
- **静态初始化顺序惨案（static initialization order fiasco）**：这种跨翻译单元的初始化顺序不确定性就叫这个名字。
- **少数合理用途**：某些情况下能降低复杂度，例如日志文件、随机数生成器。`std::cout` 与 `std::cin` 就是实现在 `std` 命名空间里的全局变量。
- **经验法则**：使用全局变量应同时满足两条——"There should only ever be one of the thing the variable represents in your program"（程序中该变量代表的事物只应有一个）与"its use should be ubiquitous throughout your program"（它的使用应遍及整个程序）。
- **常见新手错误**：仅因为"现在只需要一个实例"就选全局变量，例如单机游戏后来要加多机。
- **命名安全**：给非命名空间化的全局变量加 `g` 或 `g_` 前缀，或（更好）放进命名空间。
- **封装**：把访问限制在声明它的文件内（`static` 或 `const`），并对外暴露会校验输入的访问函数；这样改动实现只需改这些函数。
- **链接提示**：全局 `const` 变量默认内部链接，所以 `gravity` 不需要 `static`。
- **作为参数传递**：与其在函数内直接用全局变量，不如把它传进去——这保持了模块化，也能改变取值。

## 最佳实践

- **Best practice**：Use local variables instead of global variables whenever possible.（尽可能用局部变量代替全局变量。）
- **Warning**：Avoid initializing objects with static duration using other objects with static duration from a different translation unit.（避免用来自另一翻译单元的静态存储期对象来初始化本对象的静态存储期。）全局变量的动态初始化同样易受顺序问题影响，应"尽可能"避免。
- **A reminder**：全局 `const` 变量默认内部链接，`gravity` 不需要写 `static`。

## 代码示例

- [7-08-example1.cpp](7-08-example1.cpp)：`g_mode` 被另一函数悄悄改为 2，输出 `Launching nuclear missiles...`（对应原文 Example 1）。
- [7-08-example2.cpp](7-08-example2.cpp)：追踪全局变量的意外取值，输出 `g_mode is 3, not 4 -- debugging required`（对应原文 Example 2）。
- [7-08-example3.cpp](7-08-example3.cpp)：非常量初始化式导致动态初始化，输出 5（对应原文 Example 3）。
- [7-08-example4.cpp](7-08-example4.cpp)：同文件内初始化顺序问题——`initX()` 返回尚未初始化的 `g_y`，输出 `0 5`（对应原文 Example 4）。
- [7-08-example5-broken.cpp](7-08-example5-broken.cpp)：**坏实践**——全局命名空间里裸放 `gravity`，存在冲突风险（对应原文 Example 5）。
- [7-08-example6.cpp](7-08-example6.cpp)：把 `gravity` 放进 `constants` 命名空间，输出 9.8（对应原文 Example 6）。
- [7-08-example7/](7-08-example7/)：`constants.cpp` / `main.cpp` —— 直接外部访问常量（不推荐），输出 9.8（对应原文 Example 7）。
- [7-08-example8/](7-08-example8/)：`constants.cpp` / `main.cpp` —— 封装式访问：常量保持内部链接，经 `getGravity()` 暴露，输出 9.8（对应原文 Example 8）。
- [7-08-example9.cpp](7-08-example9.cpp)：函数硬编码使用 `constants::gravity`（复用性较低），输出 49（对应原文 Example 9）。
- [7-08-example10.cpp](7-08-example10.cpp)：把 `gravity` 作为参数传入（更模块化），输出 49（对应原文 Example 10）。

## 附：一个 C++ 笑话

"What's the best naming prefix for a global variable?" —— 答案：`//`

> 说明：本节示例代码为按原文清单与站点标准写法**忠实重建**，以保证可用 `g++ -std=c++20 -Wall` 编译运行；原文代码块本身未逐字获取。

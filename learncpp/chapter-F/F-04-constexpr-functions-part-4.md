# F.4 Constexpr functions (part 4)

> 原文：https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-4/

## 核心概念

- **允许非 const 局部变量**：constexpr/consteval 函数内部可以声明并修改非 constexpr 的局部变量，甚至可以直接修改自己的形参。
- **编译期求值等于"执行"函数体**：当这类函数在编译期运行时，编译器实际上会执行整个函数体，并把结果值代入。
- **形参与局部变量可作为 constexpr 调用的实参**：尽管它们不是常量表达式，但在常量求值语境中编译器已知其全部取值，因此 C++ 允许把它们送入仍会被常量求值的 constexpr 调用。
- **调用非 constexpr 函数是"有条件"合法的**：只有当该 constexpr 函数在**非常量语境**中被求值时才可以；在常量语境中调用会导致编译错误，因为无法产出编译期常量。
- **按求值语境分支**：要让 constexpr 函数在编译期与运行期表现不同，可用 `if (std::is_constant_evaluated())`（C++20）或 `if consteval`（C++23 起）。
- **用形参做语境相关的分支**：一个接受 `bool` 的更通用变体是合法的 —— **只要**调用非 constexpr 函数的那个分支在常量表达式中永远不会被走到。
- **C++23 之前的 ill-formed 规则（题外）**：C++23 之前，constexpr 函数必须对至少一组实参产出常量，否则技术上 ill-formed；但编译器无需给出警告，错误通常只在该函数被用于常量语境时才显现。C++23 取消了该要求。
- **作者的三条建议**：(a) 尽量避免在 constexpr 函数中调用非 constexpr 函数；(b) 用 `if (std::is_constant_evaluated())`（C++20）或 `if consteval`（C++23+）区分不同语境下的行为；(c) 始终在常量语境中测试 constexpr 函数 —— 因为它可能运行期可用却在编译期失败。
- **何时该把函数标记为 constexpr（通用规则）**：如果一个函数"能够作为所要求常量表达式的一部分被求值"，就应标记为 `constexpr`。
- **纯函数（pure function）的定义**：(a) 对相同实参总是产出相同结果；(b) 无副作用（不修改静态局部变量或全局变量、不做 I/O 等）。纯函数一般应设为 constexpr。
- **题外：constexpr 函数不必是纯函数**：从 C++23 起，constexpr 函数可以使用并修改静态局部变量；由于静态局部变量的值跨调用保留，修改它算作副作用。
- **Best practice**：除非有特别理由，否则"能作为常量表达式一部分"的函数就该是 `constexpr`，即便当前并未那样使用；反之，无法作为所要求常量表达式一部分求值的函数**不应**标记为 `constexpr`。
- **为什么不把所有函数都标 constexpr？**：(a) `constexpr` 传递的信号是"该函数能参与常量表达式"，若不能就是错误信号；(b) 它是"函数接口的一部分"，日后移除会破坏依赖它的 constexpr 调用者；(c) constexpr 函数更难调试，因为你无法在其上打断点或单步。
- **为什么给"只在运行期求值"的函数加 constexpr？**：(a) 几乎没有坏处，还可能帮助编译器生成更小/更快的代码；(b) 你日后可能需要在常量表达式语境中使用它，届时未必想得起来补加；(c) 反复练习能强化这条最佳实践。

## 最佳实践

- **Best practice**：除非有特别理由，否则一个能作为常量表达式一部分被求值的函数应设为 `constexpr`（即便当前未如此使用）。
- **Best practice**：无法作为所要求常量表达式一部分被求值的函数，**不应**标记为 `constexpr`。
- **Aside（C++23 之前的规则）**：C++23 之前，对任何实参集都无法产出 constexpr 值的 constexpr 函数技术上 ill-formed，但编译器无需诊断；C++23 取消了该要求。
- **Aside（纯函数）**：C++23 起 constexpr 函数可以使用并修改静态局部变量，这属于副作用 —— 所以 constexpr 函数并不严格要求是纯函数。
- **作者建议**：尽量避免在 constexpr 函数里调用非 constexpr 函数；用 `std::is_constant_evaluated()` / `if consteval` 分隔常量语境行为；始终在常量语境中测试 constexpr 函数。

## 代码示例

本节代码为**重建**（抓取工具无法逐字返回长代码块，以下示例按原文描述与该站标准示例忠实重建，语义与预期输出一致）。原文未给出各示例的预期输出；下述输出为实测结果。

- [F-04-example1.cpp](F-04-example1.cpp) — consteval 函数修改非 const 形参与局部变量（输出 `12`）。
- [F-04-example2.cpp](F-04-example2.cpp) — 把非 constexpr 形参 `b` 传入 `goo(b)`，若 `foo()` 编译期求值则 `goo(b)` 也可编译期求值（输出 `5`）。
- [F-04-example3.cpp](F-04-example3.cpp) — 用 `std::is_constant_evaluated()` 在 constexpr 与非 constexpr 兄弟函数间选择（输出 `1 2`；原文的 `someConstexprFcn()/someNonConstexprFcn()` 为占位名，此处补定义）。
- [F-04-example4.cpp](F-04-example4.cpp) — 用 `bool` 形参分支的变体（输出 `1 2`），合法前提是 `someFunction(false)` 永不在常量表达式中被调用。

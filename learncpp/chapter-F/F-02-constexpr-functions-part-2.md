# F.2 Constexpr functions (part 2)

> 原文：https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-2/

## 核心概念

- **非必须常量表达式中的 constexpr 调用**：constexpr 函数不会自动在编译期求值；当所处语境不要求常量表达式时，编译器可选择编译期或运行期求值。
- **Key insight**：只有当语境要求常量表达式时，constexpr 函数的编译期求值才被**保证**。
- **必须语境中的诊断时机**：只有在函数真正被要求在编译期求值时，编译器才需要判断其可求值性；因此一个函数可能"运行期可用"却无法用于常量表达式。
- **C++23 之前的 ill-formed 规则（进阶）**：C++23 之前，若一个 constexpr 函数对任何一组实参都无法编译期求值，程序是 ill-formed（无需诊断）；P2448R1 撤销了这一要求。
- **形参不是 constexpr**：constexpr（或 consteval）函数的形参不会隐式成为 constexpr，也不能被声明为 constexpr。
- **Key insight**：如果形参是 constexpr，就意味着该函数只能用 constexpr 实参调用；而 constexpr 函数在运行期仍需接受非 constexpr 实参。
- 因此形参不能出现在函数内部的常量表达式中 —— 例如不能作为 constexpr 变量的初值，也不能作为 consteval 调用的实参。
- 形参可以声明为 `const`，使其成为运行期常量。
- **Related content**：关于本身就是常量表达式的参数，见 11.9 小节（Non-type template parameters）。
- **隐式 inline**：编译期求值要求编译器看到完整定义，仅凭前向声明不够。
- **Rule**：编译器必须能看到 constexpr（或 consteval）函数的**完整定义**，而不只是前向声明。
- 由于这类函数可能在多个翻译单元中被需要，它们是**隐式 inline** 的，因此不受单一定义规则（ODR）限制；通常定义在头文件中。
- 仅运行期调用时，前向声明就足以调用定义在另一翻译单元中的函数。
- **Advanced（CWG2166）**：真正的要求是"该 constexpr 函数必须在最终导致其调用的最外层求值之前被定义"，这允许相互递归的 constexpr 函数。
- **小结**：把一个函数标记为 constexpr，只是说它**可以**用于常量表达式，而不是说它**一定**在编译期求值。常量表达式只在被要求处必须编译期求值；其他处由编译器选择；运行期表达式一定在运行期执行。
- **编译期求值的可能性（Key insight）**：
  - **一定**（标准要求）：在要求常量表达式处调用；或被另一个正在编译期求值的函数调用。
  - **很可能**：在不要求常量表达式处调用，且所有实参都是常量表达式。
  - **可能**（as-if 规则）：部分实参不是常量表达式但其值在编译期已知；或一个本身具备编译期求值能力的非 constexpr 函数，实参全为常量表达式。
  - **从不**：部分实参的值在编译期未知。
- 优化级别会影响结果，debug 与 release 构建可能不同；gcc 与 Clang 在不要求常量表达式的语境中，若不开启优化（如 `-O2`）就不会做编译期求值。
- **进阶**：内联或消除调用，可能影响其内容被求值的时机或是否被求值。

## 最佳实践

- **Rule**：编译器必须能看到 constexpr（或 consteval）函数的完整定义，而不只是前向声明。
- **Best practice**：所有 constexpr 函数都应能编译期求值 —— 因为常量表达式语境会要求这一点。
- **Best practice**：始终在**要求常量表达式**的语境中测试你的 constexpr 函数 —— 一个函数可能运行期可用却在编译期失败。
- **Best practice（单文件）**：仅用于单个 `.cpp` 的 constexpr/consteval 函数，应定义在其使用点之前。
- **Best practice（多文件）**：这类函数应定义在头文件中，以便每个源文件都能包含它们。
- **Key insight**：只有当语境要求常量表达式时，constexpr 函数的编译期求值才被保证。
- **Key insight**：如果形参是 constexpr，就意味着该函数只能用 constexpr 实参调用（与 constexpr 函数仍需支持运行期调用矛盾）。

## 代码示例

本节代码为**重建**（抓取工具无法逐字返回长代码块，以下示例按原文描述与该站标准示例忠实重建，语义与预期输出一致）。原文未给出各示例的预期输出。

- [F-02-example1.cpp](F-02-example1.cpp) — constexpr `getValue()` 用在非必须常量表达式的语境（输出 `5`）。
- [F-02-example2-error.cpp](F-02-example2-error.cpp) — constexpr 函数内部调用非 constexpr 函数，运行期可用但放入常量表达式出错，**预期编译失败**。
- [F-02-example3-error.cpp](F-02-example3-error.cpp) — 形参本身不是 constexpr，不能用作内部 constexpr 变量初值或 consteval 实参，**预期编译失败**。
- [F-02-example4.cpp](F-02-example4.cpp) — 前向声明 + 相互引用（CWG2166 场景，输出 `5`）。
- [F-02-example5.cpp](F-02-example5.cpp) — 同一个 `greater()` 的四种求值语境（示例输入 `7` 时输出四行 `6 is greater!`、`6 is greater!`、`6 is greater!`、`7 is greater!`）。

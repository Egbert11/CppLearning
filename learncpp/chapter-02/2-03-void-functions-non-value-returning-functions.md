# 2.3 Void functions (non-value returning functions)

> 原文：https://www.learncpp.com/cpp-tutorial/void-functions-non-value-returning-functions/

## 核心概念

- **void 返回类型**：返回类型为 `void` 表示该函数不向调用者返回值。
- **void 函数定义**：函数不必返回值；那些不返回值的函数就用 `void` 作为返回类型。
- **调用行为**：`main` 调用一个 void 函数时，函数体被执行，随后控制权回到调用者，程序继续。
- **术语**：不返回值的函数称为“非值返回函数（non-value returning function）”或“void 函数”。
- **无需 return 语句**：void 函数执行到末尾会自动返回调用者，因此不需要 `return`。
- **空 return 语句**：void 函数里单独的 `return;` 会在该处返回；但把它放在函数末尾是多余的。
- **需要值的表达式**：有些表达式必须提供一个值；例如 `std::cout <<` 后面必须给出可打印的东西，否则编译错误。
- **为行为调用 vs. 为值调用**：仅是一条函数调用语句时，是“为它的行为而非返回值”调用函数，void 与值返回函数都可以。
- **需要值的上下文（value context）**：在需要值的上下文（如 `std::cout`）中，只能调用值返回函数。
- **从 void 函数返回值**：试图这样做是编译错误。

## 最佳实践

- 不要在非值返回函数的末尾写 return 语句。
- 有些语句需要提供值，有些则不需要（原文 Tip）。

## 代码示例

- [2-03-example1.cpp](2-03-example1.cpp) — 最基本的 void 函数 `printHi()`：打印 `Hi`，无需 return 语句。
- [2-03-example2.cpp](2-03-example2.cpp) — void 函数里多余的 `return;`（放在末尾是冗余的）。
- [2-03-example3-error.cpp](2-03-example3-error.cpp) — 需要值的表达式：`std::cout << 5;` 合法，`std::cout << ;` 是编译错误。
- [2-03-example4-error.cpp](2-03-example4-error.cpp) — 把 void 调用放进需要值的上下文：`std::cout << printHi();` 是编译错误。
- [2-03-example5-error.cpp](2-03-example5-error.cpp) — 对比调用上下文：单独调用 `returnNothing()`/`returnFive()` 都行，`std::cout << returnFive()` 行，`std::cout << returnNothing()` 编译错误。
- [2-03-example6-error.cpp](2-03-example6-error.cpp) — 从 void 函数返回值：`void printHi()` 中写 `return 5;`，编译错误。
- [2-03-quiz1a.cpp](2-03-quiz1a.cpp) — Quiz 1a：`printA()` 与 `printB()` 各自打印一个字母，输出 A、B 各占一行。
- [2-03-quiz1b-error.cpp](2-03-quiz1b-error.cpp) — Quiz 1b：`std::cout << printA() << '\n';` 不能编译，因为 void 返回值不能交给 `std::cout`。

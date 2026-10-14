# 2.2 Function return values (value-returning functions)

> 原文：https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/

## 核心概念

- **导入问题**：`void` 函数可以把用户输入读进来，但一旦返回，这个值就丢了——调用者无法拿到它。
- **返回类型（return type）**：写在函数名前面的类型，说明“返回值的类型”而不是具体值；`void` 表示不返回任何值。
- **返回语句（return statement）**：用 `return` 关键字后跟一个表达式（“返回表达式”）再加分号。
- **`return` 时发生的三件事**：先求出表达式的值（produces a value）；把该值拷贝回调用者（return value）；函数退出、控制权交还调用者。
- **按值返回（return by value）**：上述“把值拷贝回调用者”的过程叫按值返回。
- **术语**：返回表达式“产生”值，返回的则是它的一个副本。
- **可重复性**：值返回函数每次被调用都会返回一个值。
- **值返回函数（value-returning function）**：返回类型不是 `void` 的函数。它**必须**返回该类型的一个值，否则是未定义行为。
- **输出规则**：返回值只有在调用者把它交给 `std::cout` 之类的东西时才会显示在屏幕上，否则会被丢弃。
- **调用者的选择**：调用者可以“使用”返回值（初始化变量、用于表达式），也可以忽略它。
- **复用技巧**：如果这个值要用多次，先存到变量里。
- **`main` 如何工作**：操作系统调用 `main`；语句按顺序执行；`main` 返回一个 int（通常为 `0`）；程序终止。
- **`main` 的特殊规则**：它必须返回 `int`，并且**不允许**被显式调用。
- **状态码（status code）**：`main` 的返回值，也叫退出码（exit code）/返回码（return code），用来表示成功或失败；按惯例 `0` 表示正常执行。
- **可移植性**：非零状态码通常表示失败，但并非严格保证可移植。标准只定义了 `0`、`EXIT_SUCCESS`、`EXIT_FAILURE`（来自 `<cstdlib>` 的宏）。
- **未定义行为**：非 `void` 函数缺少 `return` 语句会产生未定义行为；编译器通常会警告，但复杂情形可能被漏过。
- **`main` 的例外**：`main` 在没有 return 语句时会隐式返回 `0`——这是唯一这样的例外。
- **单值规则**：一次调用函数只能返回一个值；返回表达式可以是任何合法表达式，而不只是字面量。
- **含义由作者定义**：返回值可能是状态码、计算结果等，所以最好用注释说明它的含义。
- **DRY**：“Don't Repeat Yourself（不要重复自己）”——尽量减少冗余；变量、函数、循环都有帮助。它是原则而非铁律；把代码切得过碎反而损害可读性。
- **结论**：返回值让函数把一个值送回调用者；函数有助于减少重复。

## 最佳实践

- 如果程序正常执行，你的 `main` 函数应返回 `0`。
- 确保非 `void` 返回类型的函数在所有情况下都返回一个值。
- 遵循 DRY 原则：在实际可行处消除冗余。

## 代码示例

- [2-02-example1.cpp](2-02-example1.cpp) — 最初的单 `main` 程序：读入一个整数并打印它的两倍。
- [2-02-example2-broken.cpp](2-02-example2-broken.cpp) — 失败的改写：`void getValueFromUser()` 读了输入却不返回，`main` 里的 `num` 拿不到值（能编译但结果错误）。
- [2-02-example3.cpp](2-02-example3.cpp) — `returnFive()` 返回 `5`；演示使用返回值、在表达式中使用返回值以及忽略返回值。
- [2-02-example4.cpp](2-02-example4.cpp) — 修正版：`getValueFromUser()` 改为返回 `int`，`main` 用它的返回值初始化 `num`。
- [2-02-example5-error.cpp](2-02-example5-error.cpp) — 非法用法：尝试调用 `main()` 以及把 `main` 声明为 `void`，两处均为编译错误。
- [2-02-example6.cpp](2-02-example6.cpp) — 可移植的退出码：包含 `<cstdlib>` 并返回 `EXIT_SUCCESS`。
- [2-02-example7-ub.cpp](2-02-example7-ub.cpp) — 未定义行为：`getValueFromUserUB()` 声明为返回 `int` 却没有 return 语句。
- [2-02-example8.cpp](2-02-example8.cpp) — 带注释说明返回值的 `getValueFromUser()`（说明“返回值是用户输入的整数”）。
- [2-02-example9.cpp](2-02-example9.cpp) — 违反 DRY 的程序：两段重复的输入代码分别初始化 `x`、`y`。
- [2-02-example10.cpp](2-02-example10.cpp) — 复用函数：两次调用 `getValueFromUser()` 得到 `x`、`y`，输出 `5 + 7 = 12`。
- [2-02-quiz1a.cpp](2-02-quiz1a.cpp) — Quiz 1a：`return7() + return9()`，输出 `16`。
- [2-02-quiz1c.cpp](2-02-quiz1c.cpp) — Quiz 1c：`return7(); return9();` 单独调用但不用返回值（能编译、无输出）。
- [2-02-quiz1d.cpp](2-02-quiz1d.cpp) — Quiz 1d：`getNumbers()` 中先 `return 5;` 再 `return 7;`，第二次 return 永不执行，两次都打印 `5`。

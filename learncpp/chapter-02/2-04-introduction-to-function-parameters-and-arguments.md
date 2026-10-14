# 2.4 Introduction to function parameters and arguments

> 原文：https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/

## 核心概念

- **导入问题**：像 `printDouble()` 这样的辅助函数如果直接引用 `main()` 里的 `num` 会无法编译，因为该标识符在函数内部不可见。改成在函数内部声明一个局部 `num{}` 虽能编译，却永远打印 0，因为函数拿不到用户的输入。
- **函数参数（function parameter）**：“用在函数头中的变量”。它和局部变量很像，区别在于它的初始值由调用者提供。
- **参数语法**：参数写在函数名后的圆括号里、用逗号分隔；零个参数也是合法的。
- **实参（argument）**：“在函数调用时，由调用者传给函数的值”。多个实参同样用逗号分隔。
- **配对机制**：调用发生时，每个参数被创建，并把对应实参的值通过拷贝初始化（copy initialization）拷贝进去；这种机制叫**按值传递（pass by value）**，这样的参数叫**值参数（value parameter）**。
- **规则**：实参的个数一般必须与形参个数一致，否则编译报错。实参可以是任意合法表达式，因为它实质上是参数的初始化器。
- **返回值作实参**：函数的返回值可以直接作为实参，从而省掉一个只是用来中转的临时变量；这种紧凑写法可能读起来不够清晰，但可以接受。
- **参数 + 返回值**：把输入与返回值结合，函数就能接收数据、计算并把结果交回调用者。
- **嵌套调用与求值顺序**：调用中嵌套调用时，内层调用先被求解，其结果才能用来初始化外层参数（例如内层 `multiply` 先算，`add` 再用它的结果）。
- **未引用参数（unreferenced parameter）**：在函数体中未被用到的参数，通常会触发未使用变量的警告。
- **未命名参数（unnamed parameter）**：定义中参数名是可选的，省略参数名即可消除警告。Google C++ 风格指南建议把省略的名字写在注释里。

## 最佳实践

- 当参数存在但函数体内并未使用时，把它写成未命名参数；（可选）在注释里写下它的名字。
- 作者说明（为何会有未使用参数）：函数被修订后某个参数可能变得不再需要，但删除它会破坏所有既有调用——需要改动并回归测试所有调用方，而有些代码你无法控制。保留该参数往往更简单。
- 作者说明（进阶情形）：未引用参数还出现在需要区分 `++`/`--` 前置与后置重载的地方，以及从类型模板参数的类型（而非值）推断信息的地方。

## 代码示例

- [2-04-example1.cpp](2-04-example1.cpp) — 最初的 `getValueFromUser()` 返回输入，`main` 打印它的两倍。
- [2-04-example2-error.cpp](2-04-example2-error.cpp) — `void printDouble()` 引用了看不见的 `num`，无法编译。
- [2-04-example3.cpp](2-04-example3.cpp) — 在 `printDouble()` 里加 `int num{};`，能编译但永远打印 `0 doubled is: 0`。
- [2-04-example4.cpp](2-04-example4.cpp) — 三个函数：无参数、一个整型参数、两个整型参数；并演示无实参/一个实参/两个实参三种调用形式（覆盖原文示例 4 与示例 5）。
- [2-04-example6.cpp](2-04-example6.cpp) — `printValues(6, 7)`：形参 `x`、`y` 通过拷贝初始化获得实参值，输出 6、7。
- [2-04-example7.cpp](2-04-example7.cpp) — 修好的挑战程序：`printDouble(int value)` 收到 `num` 的副本。
- [2-04-example8.cpp](2-04-example8.cpp) — 紧凑写法：直接调用 `printDouble(getValueFromUser());`，把返回值当作实参。
- [2-04-example9.cpp](2-04-example9.cpp) — `add(4, 5)` 返回 `9` 并用 `std::cout` 打印，演示参数与返回值配合。
- [2-04-example10.cpp](2-04-example10.cpp) — `add`/`multiply` 的多种调用形式，含 `add(1 + 2, 3 * 4)`、`add(a, a)`、`add(1, multiply(2, 3))`、`add(1, add(2, 3))`。
- [2-04-example11-warning.cpp](2-04-example11-warning.cpp) — `doSomething(int count)` 未使用参数，触发 `-Wunused-parameter` 警告。
- [2-04-example12.cpp](2-04-example12.cpp) — 未命名参数的写法：`void doSomething(int)` 以及 Google 风格的注释形式 `void doSomething(int /*count*/)`。
- [2-04-quiz1-error.cpp](2-04-quiz1-error.cpp) — Quiz #1：`void multiply(int x, int y)` 却想返回值，`void` 返回类型导致编译错误，应为 `int`。
- [2-04-quiz2-error.cpp](2-04-quiz2-error.cpp) — Quiz #2：`multiply` 只传一个实参却需要两个，且缺少 `return` 语句，两处缺陷。
- [2-04-quiz3.cpp](2-04-quiz3.cpp) — Quiz #3：`multiply(add(1, 2, 3), 4)`，内层先算出 6，答案为 `24`。
- [2-04-quiz4.cpp](2-04-quiz4.cpp) — Quiz #4：`doubleNumber()` 接收一个整数并返回它的两倍。
- [2-04-quiz5.cpp](2-04-quiz5.cpp) — Quiz #5：完整程序——读入一个整数，用 `doubleNumber()` 翻倍并打印。

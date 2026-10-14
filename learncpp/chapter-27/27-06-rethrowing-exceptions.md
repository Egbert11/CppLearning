# 27.6 Rethrowing exceptions

> 原文：https://www.learncpp.com/cpp-tutorial/rethrowing-exceptions/

## 核心概念

1. **重抛要解决的问题**：有时在 `catch` 块里捕获到异常，却无法在当下完全处理——最常见的情形是"先把错误写进日志，再把问题交给调用者处理"。
2. **返回码很好用**：如果函数能用返回值表示失败（例如返回 `nullptr`），处理起来很简单：`catch` 里记日志，然后返回失败值即可。
3. **但返回码并非总能奏效**：像 `getIntValueFromDatabase` 这类返回 `int` 的函数，任何 `int` 值都可能是合法数据，没有多余的返回值可用来表示"失败"。
4. **方案一：抛出全新异常**：在 `catch` 块里可以抛出异常，类型任意，不必与被捕获的异常类型相同。
5. **catch 里抛出的异常去向何方**：`catch` 块捕获不到它自己抛出的异常——只有 `try` 块内抛出的异常才会被与之关联的 `catch` 捕获。因此新异常会沿调用栈向上传播给调用者。
6. **方案二（错误）：`throw exception;`**：抛出的是 catch 形参经拷贝初始化（copy-initialized）得到的副本，而不是原来那个异常对象。
   - 缺点 1（性能）：编译器可以省略这次拷贝，但不被要求这么做，因此可能更慢。
   - 缺点 2（切片）：抛出对象按形参的**静态类型**拷贝初始化。若以 `Base&` 捕获了实际为 `Derived` 的对象，重抛出的会是 `Base`，派生部分被切掉（对象切片）。
7. **方案三（正确）：裸 `throw;`**：在 `catch` 块中用不带操作数的 `throw` 会**原样**重抛同一个异常对象——不发生任何拷贝，也不会切片。若确实需要重抛，应优先使用这种方式。

## 最佳实践

- **Rule**：重抛同一个异常时，单独使用 `throw` 关键字（即 `throw;`，后面不跟任何表达式）。

（本节没有单独的 Best practice / Author's note / Warning 提示框。）

## 代码示例

- [27-06-example1.cpp](27-06-example1.cpp) — 返回码风格：`createDatabase()` 失败时记日志并返回 `nullptr`（可用返回值表示失败时无需重抛）。
- [27-06-example2-warning.cpp](27-06-example2-warning.cpp) — `getIntValueFromDatabase()` 捕获后只记日志、不返回，也无法向调用者报告失败；`g++ -Wall` 会给出 `-Wreturn-type` 警告，运行到该路径属 UB（本机触发 SIGILL）。
- [27-06-example3.cpp](27-06-example3.cpp) — 在 `catch` 中抛出全新异常（`throw 'q';`），由调用者捕获。
- [27-06-example4.cpp](27-06-example4.cpp) — 错误的重抛方式 `throw exception;`（抛出形参副本）。
- [27-06-example5.cpp](27-06-example5.cpp) — 用 `throw b;` 重抛时发生对象切片（第二行输出表明 `Derived` 变成了 `Base`）。
- [27-06-example6.cpp](27-06-example6.cpp) — 用裸 `throw;` 正确重抛，不切片。

> 说明：本节的 `Database`、`g_log` 模拟实现为让原文片段可独立编译而补充，被演示逻辑本身照原文保留。
> 原文中另有一段"以 `Base&` 捕获、`throw exception;` 重抛"的片段（对应切片隐患），其效果已由 example5 完整演示。

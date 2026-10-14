# 8.12 Halts (exiting your program early)

> 原文：https://www.learncpp.com/cpp-tutorial/halts-exiting-your-program-early/

## 核心概念

1. **halt 的定义**：halt 是结束程序执行的流控制语句。与其他流控制结构不同，C++ 用函数而非关键字实现 halt，因此 halt 写成一次函数调用。
2. **从 main() 正常返回时发生什么**：执行到 `main()` 末尾或用 return 语句时，先销毁所有局部变量和参数；随后运行时自动调用 `std::exit()`，把 `main()` 的返回值作为状态码传入。
3. **`std::exit()` 函数**：触发**正常终止**（normal termination），即程序以预期的方式结束。注意"正常终止"与成功/失败无关——成败由状态码表达。
4. **正常终止但失败状态的例子**：程序向用户索要文件名却收到非法值，可以返回非零状态码报告失败，同时仍属正常终止。
5. **`std::exit()` 执行的清理**：先销毁具有静态存储期的对象，然后进行杂项文件清理（若用到文件）；最后把 `std::exit()` 的参数作为状态码交还给操作系统。
6. **显式调用 `std::exit()`**：虽然它在 `main()` 返回后隐式运行，你也可以自己调用它以提前结束程序；需要 `cstdlib` 头文件。
7. **调用之后的语句不执行**：`std::exit()` 一旦执行，程序就已结束，其后的语句永不执行。它可以在任何函数中调用，而不只是 `main()`。
8. **`std::exit()` 跳过局部变量清理**：当前函数以及调用栈更上层函数中的局部变量都**不会**被销毁。因此当代码依赖这些析构函数运行时，显式使用它是有风险的。
9. **`std::atexit()`**：注册一个在通过 `std::exit()` 终止时自动被调用的函数。目的是避免在每个退出点都记得调用清理例程这种易错负担。
10. **清理（cleanup）**：在此语境下包括关闭数据库/网络连接、释放已分配内存、写入日志文件等。
11. **为什么要清理（旁注）**：现代操作系统会回收程序留下的内存，但仍有两个理由：清理是运行时需要的好习惯，且不一致的清理会干扰内存分析工具；其他清理（如刷新文件数据、报告会话信息）对可预期的行为可能是必要的。
12. **正确传参**：注册 `std::atexit()` 时传函数名（`cleanup`），而不是调用（`cleanup()`），因为此刻并不调用它。
13. **`std::atexit()` 附注**：由于 `main()` 结束时 `std::exit()` 会隐式运行，注册的函数也会以这种方式被调用。注册的函数必须不接受参数、不返回值。可注册多个，按**注册的逆序**执行（最后注册的先运行）。
14. **多线程注意事项（进阶）**：在多线程程序中调用 `std::exit()` 可能导致崩溃——退出的线程会清理其他线程仍可能使用的静态对象。因此 C++ 提供 `std::quick_exit()` 与 `std::at_quick_exit()`：前者正常终止但**不清理静态对象**，并可能跳过其他清理；后者与 `std::atexit()` 作用相同，用于 quick exit。
15. **`std::abort()`**：导致**异常终止**（abnormal termination），即发生了让程序无法继续的运行时错误（除以零是一例）。它**不做任何清理**。
16. **`std::terminate()`**：通常与异常相关，多数情况下是在异常未被处理时被隐式调用（以及少数其他异常情形）。默认它调用 `std::abort()`。
17. **何时使用 halt**：答案是基本不用——C++ 中销毁局部对象非常重要（尤其是涉及类时），而上述函数都不清理局部对象。异常提供了更安全的错误处理机制。

## 最佳实践

- **Key insight**：`std::exit` is called implicitly when `main()` returns.
- **Warning**：The `std::exit()` function does not clean up local variables in the current function or up the call stack.
- **Best practice**：Only use a halt if there is no safe or reasonable way to return normally from the main function. If you haven't disabled exceptions, prefer using exceptions for handling errors safely.
- **Tip（大意）**：即使尽量减少显式 halt，程序仍可能意外结束——"程序可能因 bug 崩溃"、用户可能强杀它、可能断电，甚至"太阳可能变成超新星吞噬地球"。设计良好的程序应能容忍随时关闭——因此现代游戏会定期自动保存。

## 代码示例

- [`8-12-example1.cpp`](8-12-example1.cpp)：从 `main()` 显式调用 `std::exit()`，并手动调用清理函数。
- [`8-12-example2.cpp`](8-12-example2.cpp)：用 `std::atexit()` 注册 `cleanup()`，使其自动运行。
- [`8-12-example3.cpp`](8-12-example3.cpp)：用 `std::abort()` 导致异常终止。

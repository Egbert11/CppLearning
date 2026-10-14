# 27.4 Uncaught exceptions and catch-all handlers

> 原文：https://www.learncpp.com/cpp-tutorial/uncaught-exceptions-catch-all-handlers/

## 核心概念

- **未捕获的异常**：函数抛出异常又不自行处理时，它假定调用栈下游的某个函数会处理。
- **无人处理时会发生什么**：若不存在任何处理器，就会调用 `std::terminate()` 终止程序。
- **栈展开并无保证**：这种情况下调用栈"可能展开，也可能不展开"；若不展开，局部变量不会被销毁，预期的清理也就不会发生。
- **为何可能不展开**：保留栈状态能留下"这个未处理异常是如何产生的"的调试信息，便于定位并修复原因。
- **操作系统行为**：操作系统通常会报告这个未处理异常，可能打印消息、弹出对话框，或直接崩溃；具体行为因 OS 而异。
- **catch-all 的两难**：函数可以抛出任意数据类型（因而有无限多种可能的类型），未捕获异常会立即终止程序，而为每一种类型都写处理器又很繁琐。
- **catch-all 处理器定义**：一种用省略号运算符（`...`）代替具体类型作为捕获类型的 catch 块，可捕获任意数据类型的异常，也叫"省略号处理器（ellipsis catch handler）"。
- **位置规则**：catch-all 必须放在 catch 链的最后，好让类型明确的处理器先获得机会。
- **空的 catch-all**：写 `catch(...) {}` 能捕获意料之外的异常、确保到此处为止的栈展开、并阻止程序终止，但不做任何具体的错误处理。
- **包裹 main()**：在 `main()` 主体外包裹 catch-all，可有条理地展开栈（销毁局部量）、避免立即终止，并让你在退出前打印错误、保存状态。
- **捕获后的状态**：若 catch-all 被触发，应假定程序处于不确定状态；立即清理，然后终止。
- **调试的取舍**：许多调试器会在未处理异常处中断，以便你检查栈；catch-all 会处理一切并展开栈，从而丢失这些诊断信息。
- **条件编译的变通**：在 debug 构建中，可用预处理指令把 catch-all 关掉。
- **语法要求**：try 块至少要关联一个 catch；你可以把 try 也编译掉，但更干净的做法是改为编译进另一个 catch 块。
- **DummyException 技巧**：一个"默认构造函数被 = delete 且无其他构造函数"的类永远无法被实例化，因此 `catch(DummyException)` 永远捕不到任何东西，异常保持未处理。

## 最佳实践

- **Warning**：异常未处理时调用栈可能展开、也可能不展开；若不展开，局部变量不会被销毁，当这些变量有非平凡析构函数时就会出问题。
- **As an aside（关于不展开）**：虽然"不展开"看似奇怪，但未处理异常本就是应避免的情况；展开会抹掉导致 throw 的栈状态调试信息。
- **Tip**：若程序使用异常，考虑在 `main` 中放一个 catch-all 处理器，以便在出现未处理异常时保证行为有序。
- **使用 catch-all 的准则**：若 catch-all 捕获到了异常，应假定程序处于不确定状态，立即做清理，然后终止。

## 代码示例

- [27-04-example1.cpp](27-04-example1.cpp)：`main()` 中没有异常处理器；输入 `9` 输出 `The sqrt of 9 is 3`，输入负数则异常无人处理、程序终止。
- [27-04-example2.cpp](27-04-example2.cpp)：catch-all 捕获无专门处理器的类型，输出 `We caught an exception of an undetermined type`。
- [27-04-example3.cpp](27-04-example3.cpp)：用 catch-all 包裹 `main()` 内容，异常时输出 `Abnormal termination`，随后仍调用 `saveGame()`。
- [27-04-example4.cpp](27-04-example4.cpp)：用条件编译在 debug（NDEBUG 未定义）下编译入 catch-all（输出 `Abnormal termination`），release（`-DNDEBUG`）下改为 `catch(DummyException)`，异常无人处理、程序终止。

> 说明：四个示例均逐字取自原文（example1 需从标准输入读取数字）。example4 在 release 构建（加 `-DNDEBUG`）下运行会因异常未被捕获而终止，属预期行为。

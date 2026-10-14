# 27.2 Basic exception handling

> 原文：https://www.learncpp.com/cpp-tutorial/basic-exception-handling/

## 核心概念

- **三个关键字**：C++ 异常依赖 `throw`、`try`、`catch` 三个关键字协同工作，以区分"控制流"与"错误流"（返回码做不到这一点）。
- **throw 语句**：用于发出信号，表示发生了异常或错误情形，也叫"抛出（raise）"异常。
- **抛出的值**：`throw` 后面可以跟任意数据类型的值——通常是错误码、问题描述，或自定义异常类对象。
- **try 块**：用 `try` 定义的一段语句，作为观察者等待其内部语句抛出的异常；它本身不决定如何处理异常。
- **catch 块**：用 `catch` 定义，用于处理某一种数据类型的异常。
- **配对规则**：try 块把异常路由给匹配的 catch 块。一个 try 块"后面必须紧跟至少一个 catch 块"，但可以连续跟多个。
- **处理之后**：一旦被路由到匹配的 catch 块，异常即视为已处理，执行从"最后一个 catch 块之后的第一条语句"继续。
- **catch 参数**：类似函数形参。基本类型可按值捕获；非基本类型"应按 const 引用捕获"，以避免不必要的拷贝，有时也避免对象切片。
- **未使用的参数**：若参数在 catch 中未使用，可以省略参数名，从而"避免编译器给出未使用变量的警告"。
- **不做类型转换**：异常匹配过程中不做类型转换，所以 int 异常不会匹配 double 的 catch。
- **查找规则**：抛出的异常会寻找最近的、包住它的 try 块（必要时沿调用栈向上传播）；若附带的处理器都不匹配，则继续向外查找；直到程序结束仍无处理器，就会以运行时错误终止。
- **匹配限制**：匹配时不发生隐式转换或提升（char 不匹配 int 的 catch，int 不匹配 float 的 catch），但"从派生类到基类的转换会被执行"。
- **立即处理**：throw 会立刻把执行权移到最近的 try 块，因此该块中 throw 之后的代码不会执行。
- **catch 通常做的事**：①打印错误并继续；②返回一个值或错误码；③抛出另一个异常（由更外层的 try 处理，因为 catch 已在原 try 之外）；④在 `main()` 中捕获致命错误后干净地终止程序。

## 最佳实践

本节无正式标注的 Best practice / Warning / Author's note。要点以行内说明形式给出：

- 非基本类型异常应按 const 引用捕获，避免拷贝与可能的切片。
- 未使用的 catch 参数可省略名字，避免未使用变量警告。
- 异常匹配不做隐式转换或提升（但派生类→基类的转换会做）。
- 注意：空的 catch 块也算作"已处理该异常"，尽管有用的 catch 通常会做上面四件事之一。

## 代码示例

- [27-02-example1.cpp](27-02-example1.cpp)：五种 `throw` 值的写法（整型、枚举、C 风格字符串、double 变量、自定义类对象），输出 `We caught an int exception with value: -1`。
- [27-02-example2.cpp](27-02-example2.cpp)：完整 try + 多个 catch（double / int / `const std::string&`），输出 `We caught an int exception with value: -1` 与 `Continuing on our merry way`。
- [27-02-example3.cpp](27-02-example3.cpp)：异常被"立即"处理，throw 之后的语句不会执行，输出 `We caught a double of value: 4.5`。
- [27-02-example4.cpp](27-02-example4.cpp)：贴近实际的平方根示例；输入 `9` 输出 `The sqrt of 9 is 3`，输入 `-4` 输出 `Error: Can not take sqrt of negative number`。

> 说明：example2/3/4 逐字取自原文；example1 原文为并列语法展示，这里补上枚举/自定义类定义与 `main`，真正执行的是第一条 throw（其余随后不可达，仅为完整展示语法而保留）。

# 4.12 Introduction to type conversion and static_cast

> 原文：https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/

## 核心概念

- **类型转换**：把数据从一种类型转换为另一种类型。C++ 一般允许基本类型之间互相转换（例如实参 `5` 从 int 变成 double `5.0`）。
- **打印提醒**：小数部分为 0 的浮点值打印时不含小数（`5.0` 显示为 `5`）。
- **隐式类型转换**：编译器在没有显式请求的情况下完成转换。这里编译器发现形参类型与实参类型不匹配，于是自动转换。
- **转换产生新值**：转换不改变原来的值或对象，只是以原数据为输入产生一个转换结果。
- **Key insight（临时对象）**：类型转换的行为很像一次函数调用，其返回类型就是目标类型；结果在一个临时对象中被返回并交给调用方。传递出去的只是临时对象——源变量仍保持原来的类型和值。
- **进阶读者**：有些转换（如涉及 `const_cast`、`reinterpret_cast` 的）不返回临时对象，而是重新解释已有值或对象的类型。
- **隐式转换的警告**：浮点转整型会丢弃小数部分，编译器会就“可能的数据丢失”给出警告——即便像 `5.0` 这样没有小数部分的值也一样。开启“把警告当作错误”时这些警告会变成编译错误。
- **Tip**：要编译那个产生警告的示例，需临时关闭“把警告当作错误”。
- **Key insight（安全与不安全）**：有些转换总是保值（如 char→int），有些则可能改变值（如 double→int）。不安全的隐式转换通常会产生警告，或用花括号初始化时直接报错。
- **优先花括号初始化**：花括号初始化能阻止用会丢失值的隐式转换来初始化变量（int→double 是安全的；double→int 会报错）。
- **相关**：隐式转换的更多内容见 10.1 课。
- **显式类型转换**：由程序员明确指示编译器进行转换，并对结果负责；即使丢失值也不会给出警告。
- **static_cast 语法**：`static_cast<new_type>(expression)`，取出表达式的值并以 `new_type` 返回。
- **Key insight（尖括号）**：在 C++ 语法中（预处理指令除外），尖括号 `<...>` 最可能括着的是一个类型。
- **相关**：其他类型转换见 10.6 课。
- **static_cast：char→int**：用 `std::cout` 打印 char 会输出字符；转成 int 则打印码点。`static_cast` 的参数按表达式求值，变量本身不受转换影响。
- **符号转换**：有符号↔无符号整数之间可用 static_cast 转换。若值能放进目标类型，则保持不变（只是类型改变）。
- **超出范围的符号转换**：若值无法表示：无符号目标会按模回绕；有符号目标在 C++20 之前是实现定义，C++20 起按模回绕。
- **Warning**：把无符号整数值转换成有符号时，若无法在有符号类型中表示，C++20 之前的结果是实现定义的。
- **std::int8_t / std::uint8_t**：大多数编译器把它们（以及对应的 fast/least 类型）当作 `signed char` / `unsigned char`，因此可能打印成字符而非整数；转成 int 才能保证按整数处理。控制台输入时也可能按字符读取。
- **Quiz 注**：真实程序中应优先使用显式转换而非隐式转换；Quiz #2 仅为考察理解。

## 最佳实践

- **Best practice**：优先使用花括号初始化，它可防止可能丢值的隐式转换（见上）。
- **Key insight**：类型转换“很像调用一个返回类型等于目标类型的函数”，结果是一个临时对象。
- **Key insight**：有些类型转换总是保值，另一些可能改变值；不安全者通常给警告（花括号初始化下为错误）。
- **Key insight**：非预处理语法的 C++ 里，尖括号最可能括着一个类型。
- **Warning**：无符号整数值转有符号时，若无法表示，C++20 之前是实现定义行为。
- **Tip**：临时关闭“把警告当作错误”以编译窄化示例（见 0.11 课）。
- **进阶读者**：`const_cast`、`reinterpret_cast` 等转换不返回临时对象，而是重新解释类型。

## 代码示例

- [4-12-example1.cpp](4-12-example1.cpp)：隐式转换——int 字面量传给 double 形参。
- [4-12-example2.cpp](4-12-example2.cpp)：隐式转换——int 变量传给 double 形参。
- [4-12-example3.cpp](4-12-example3.cpp)：隐式窄化——double 值传给 int 形参（会产生警告）。
- [4-12-example4-error.cpp](4-12-example4-error.cpp)：花括号初始化拒绝不安全的窄化（double→int 会编译错误，故意演示）。
- [4-12-example5.cpp](4-12-example5.cpp)：用 `static_cast` 做显式转换。
- [4-12-example6.cpp](4-12-example6.cpp)：打印 char 得到字符而非数字。
- [4-12-example7.cpp](4-12-example7.cpp)：用 `static_cast<int>` 打印 char 的整数值。
- [4-12-example8.cpp](4-12-example8.cpp)：符号转换——值在两种类型中都可表示。
- [4-12-example9.cpp](4-12-example9.cpp)：符号转换——值不可表示（假设 32 位 int）。
- [4-12-example10.cpp](4-12-example10.cpp)：`std::int8_t` 输出时表现为 char。
- [4-12-example11.cpp](4-12-example11.cpp)：把 `std::int8_t` 转成 int 以强制整数输出。
- [4-12-example12.cpp](4-12-example12.cpp)：`std::int8_t` 控制台输入被按字符读取。
- [4-12-example13.cpp](4-12-example13.cpp)：Quiz #1 解法：打印字符及其 ASCII 码。
- [4-12-example14.cpp](4-12-example14.cpp)：Quiz #2 解法 (a)：初始化时隐式转换。
- [4-12-example15.cpp](4-12-example15.cpp)：Quiz #2 解法 (b)：返回时隐式转换。
- [4-12-example16.cpp](4-12-example16.cpp)：Quiz #2 解法 (c)：把实参拷贝进形参时隐式转换。

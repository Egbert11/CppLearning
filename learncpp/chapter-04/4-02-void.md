# 4.2 Void

> 原文：https://www.learncpp.com/cpp-tutorial/void/

## 核心概念

- **void 意为“无类型”**：void 是最简单的数据类型，表示完全没有类型。
- **void 是不完整类型（incomplete type）**：不完整类型指“已声明但尚未定义”。编译器知道该类型存在，但不知道一个该类型的对象需要多少内存。
- **void 被有意保持为不完整**：因为它代表“没有类型”，所以无法被定义。
- **不完整类型不能实例化**：不能创建不完整类型的变量，编译器会拒绝。
- **void 的常见用途**：① 函数没有返回值；② 函数没有参数（已弃用）；③ void 指针（进阶，见 19.5）。
- **最常见用途——函数不返回值**：在函数名前写 void，表示该函数不返回任何值；这样的函数不需要 return 语句。
- **void 函数返回值是错误**：在 void 函数中 `return` 一个值会触发编译错误（原文给出 Visual Studio 2017 的报错）。
- **已弃用——用 void 表示“无参数”**：C 语言中用 void 放在参数列表表示函数不接收参数。C++ 为向后兼容仍可编译，但这种用法已被弃用。
- **首选的 C++ 风格**：空的参数列表（隐式 void）与之等价，且更受推荐。
- **进阶用途——void 指针**：第三种用途在 19.5（Void pointers）讲解，学指针之前可以先忽略。

## 最佳实践

- 用空的参数列表代替 `void` 来表示函数没有参数。

## 代码示例

- [4-02-example1-error.cpp](4-02-example1-error.cpp) — 用不完整类型 `void` 定义变量会报错（`void value;`），本文件故意无法编译。
- [4-02-example2.cpp](4-02-example2.cpp) — 无返回值的 void 函数 `writeValue()`：打印数值，没有 return 语句。
- [4-02-example3-error.cpp](4-02-example3-error.cpp) — 在 void 函数中写 `return 5;`，编译错误（原文报错：`error C2562: 'noReturn': 'void' function returning a value`）。
- [4-02-example4.cpp](4-02-example4.cpp) — 已弃用的 C 风格写法 `int getValue(void)`，其中 void 表示没有参数。
- [4-02-example5.cpp](4-02-example5.cpp) — 首选的等价写法 `int getValue()`（空参数列表即隐式 void）。

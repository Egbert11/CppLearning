# 4.9 Boolean values

> 原文：https://www.learncpp.com/cpp-tutorial/boolean-values/

## 核心概念

- **布尔类型**：用于表示只有两种结果（真/假、是/否）的情况。之所以叫 Boolean，是为了纪念发明者 George Boole（首字母大写）。
- **布尔变量**：只能保存 `true` 或 `false` 的变量。
- **声明关键字**：用 `bool` 声明。
- **初始化/赋值**：`true` 和 `false` 是字面量关键字。默认初始化（`bool b3{};`）会把它设为 `false`。
- **逻辑非运算符（`!`）**：把布尔值取反（true 变 false，false 变 true），类似整数的一元负号。
- **内部存储**：布尔值并非以单词存储；`true` 存为整数 `1`，`false` 存为 `0`。因此布尔也是一种整型（integral type）。
- **默认打印**：`std::cout` 对 false 打印 `0`，对 true 打印 `1`。
- **`std::boolalpha`**：一个输出操纵器，让 `std::cout` 打印 `true`/`false` 而不是 `0`/`1`；`std::noboolalpha` 可恢复。
- **用整数做花括号初始化**：只允许 `0`（false）和 `1`（true）；其他字面量属于被禁止的窄化转换（narrowing conversion），会编译错误。直接使用 `false`/`true` 更好。
- **一般的整数到布尔转换**：在允许 int 转 bool 的地方，`0` 变成 `false`，其他任何整数都变成 `true`。
- **用 `std::cin` 输入**：默认只接受数字输入：`0` 为 false，`1` 为 true；其他数字会变成 true，非数字输入会变成 false——这两种非 0/1 情况都会使 `std::cin` 进入失败模式。
- **boolalpha 输入**：`std::cin >> std::boolalpha;` 后可读入单词 `true`/`false`，但此时数字输入会被拒绝（失败）。
- **布尔返回值**：用于测试条件的函数常返回 bool；命名通常以 “is”（如 `isEqual`）或 “has”（如 `hasCommonDivisor`）开头。
- **重要性**：布尔值无处不在，使用频率比其他所有基本类型加起来还高。

## 最佳实践

（原文本节没有 “Best practice” 标注，以下为原文的 Note / Warning / 相关提示。）

- **Note**：`bool b1 = 4;` 可能产生警告；要编译该示例需关闭“把警告当作错误”。
- **Warning**：为输入打开 `std::boolalpha` 后，只接受小写的 `false` / `true`，大写变体（如 `True`、`TRUE`）会被拒绝，而且 `0`/`1` 也不再有效。
- 输入与输出的 boolalpha 是相互独立的开关，各自用 `std::boolalpha` / `std::noboolalpha` 切换。
- 相关：失败模式与恢复见 9.5 课 “std::cin and handling invalid input”。

## 代码示例

- [4-09-example1.cpp](4-09-example1.cpp)：声明一个布尔变量。
- [4-09-example2.cpp](4-09-example2.cpp)：布尔变量的初始化、赋值与默认初始化。
- [4-09-example3.cpp](4-09-example3.cpp)：使用逻辑非运算符 `!`。
- [4-09-example4.cpp](4-09-example4.cpp)：打印布尔值（输出 `1 0 0 1`）。
- [4-09-example5.cpp](4-09-example5.cpp)：使用 `std::boolalpha`（输出 `1 0 true false`）。
- [4-09-example6-error.cpp](4-09-example6-error.cpp)：用整数做花括号初始化，第三个（值为 2）会编译错误（故意演示）。
- [4-09-example7.cpp](4-09-example7.cpp)：拷贝初始化允许 int→bool 隐式转换（输出 `true false`）。
- [4-09-example8.cpp](4-09-example8.cpp)：`std::cin` 默认输入行为（输入 `true` 会得到 0）。
- [4-09-example9.cpp](4-09-example9.cpp)：为输入打开 `std::boolalpha`，可读入 `true`/`false`。
- [4-09-example10.cpp](4-09-example10.cpp)：返回 bool 的 `isEqual` 函数。

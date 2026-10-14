# 14.16 Converting constructors and the explicit keyword

> 原文：https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/

## 核心概念

- **隐式类型转换（回顾）**：当存在转换时，编译器会把一个值从一种类型转换为另一种，例如为 `double` 形参把 int `5` 转成 `5.0`。按值传递时，形参被"拷贝初始化"为转换后的值。
- **程序自定义类型需要用户自定义转换**：标准没有为类类型规定内建转换规则，编译器转而寻找可用的函数；该函数称为"用户自定义转换（user-defined conversion）"。
- **转换构造函数（converting constructor）的定义**：一个可被编译器用于隐式转换的构造函数。"默认情况下，所有构造函数都是转换构造函数。"
- **通过构造函数进行拷贝初始化**：`printFoo(5)` 中形参 `f` 用 `Foo(int)` 以 `5` 拷贝初始化。C++17 前会先创建临时对象再拷贝构造；C++17 起该拷贝被强制消除（即使拷贝构造函数被删除也能工作）。
- **只允许一次用户自定义转换**：`Employee` 示例失败是因为需要两次——字符串字面量 → `std::string_view`，再 `std::string_view` → `Employee`。
- **两种修复方式**：使用 `std::string_view` 字面量（`"Joe"sv`，只需一次用户自定义转换），或显式构造对象（`Employee{ "Joe" }`，只剩字面量 → `string_view` 这一步）。
- **Key insight**：隐式转换可以通过直接列表初始化（或直接初始化）轻而易举地改写为显式形式。
- **转换构造函数何时出问题**：`Dollars(int)` 使 `print(5)` 静默转换为 `$5`，调用者看不出有此意图；在复杂代码中这类意外会造成运行时 bug。更好的做法是函数只接受 `Dollars`。
- **`explicit` 关键字**：告诉编译器该构造函数不得用作转换构造函数。两个后果：不能用于拷贝初始化和拷贝列表初始化，因此也不能用于隐式转换。
- **只在声明处写 explicit**：构造函数若拆分为类内声明加类外定义，`explicit` 只出现在声明上。
- **explicit 构造函数仍允许直接初始化**：`Dollars d1(5);` 与 `Dollars d2{5};` 依然合法。
- **explicit 的变通写法**：写 `print(Dollars{5});` 而非 `print(5)`，能编译、能运行，且表达了意图。`static_cast` 返回直接初始化的对象，因此会考虑 explicit 构造函数：`print(static_cast<Dollars>(5));`。
- **按值返回与 explicit 构造函数**：返回值的类型与返回类型不符时会触发隐式转换，而隐式转换不能使用 explicit 构造函数。注意 `return { 5 };` 也算一次转换（此处报错）。
- **explicit 的最佳实践**：默认把任何只接受单个实参的构造函数设为 `explicit`，包括大多数/全部参数都有默认值的多参数构造函数。把隐式转换改写为显式形式只需直接列表初始化，很简单。
- **哪些该 / 不该 explicit**：
  - **不该** explicit：拷贝和移动构造函数（它们不执行转换）。
  - **通常不** explicit：无参数的默认构造函数；只接受多个实参的构造函数。
  - **通常应该** explicit：单实参构造函数。
  - 只有当构造出的对象在语义上等价于实参、且转换开销很低时，单实参构造函数才适合非 explicit。例如 `std::string_view` 从 C 字符串构造是非 explicit 的；而 `std::string` 从 `std::string_view` 构造是 explicit 的，因为构造 string 并不廉价。

> **As an aside**：C++17 之前，`printFoo(5)` 先用 `Foo(int)` 构造临时 `Foo`，再拷贝构造形参 `f`；C++17 起该拷贝被强制消除，`f` 直接用 `5` 拷贝初始化，无需调用拷贝构造函数。

## 最佳实践

- **Best practice**："默认把任何只接受单个实参的构造函数设为 `explicit`。如果两种类型之间的隐式转换在语义上等价且开销低，可以考虑把构造函数设为非 explicit。"
- **Best practice**："不要把拷贝或移动构造函数设为 explicit，因为它们不执行转换。"
- 不该 explicit：拷贝/移动构造函数；通常不 explicit：无参默认构造函数、只接受多个实参的构造函数；通常应 explicit：单实参构造函数。

## 代码示例

- [14-16-example1.cpp](14-16-example1.cpp)：参数为 `double` 时 int `5` 的隐式数值转换（原 Example 1）。
- [14-16-example2.cpp](14-16-example2.cpp)：类参数通过 `Foo(int)` 隐式转换（原 Example 2）。
- [14-16-example3-error.cpp](14-16-example3-error.cpp)：`Employee` 需要两次用户自定义转换，编译失败（原 Example 4，预期编译失败）。
- [14-16-example4.cpp](14-16-example4.cpp)：修复方式一——用 `"Joe"sv` 字面量（原 Example 5）。
- [14-16-example5.cpp](14-16-example5.cpp)：修复方式二——显式构造 `Employee{ "Joe" }`（原 Example 6）。
- [14-16-example6.cpp](14-16-example6.cpp)：`Dollars(int)` 隐式转换，`print(5)` 输出 `$5`（原 Example 7）。
- [14-16-example7-error.cpp](14-16-example7-error.cpp)：构造函数改为 `explicit` 后 `print(5)` 编译失败（原 Example 8，预期编译失败）。
- [14-16-example8.cpp](14-16-example8.cpp)：explicit 构造函数仍支持直接初始化，以及显式构造 `Dollars{5}` / `static_cast<Dollars>(5)`（原 Example 9、10、11）。
- [14-16-example9.cpp](14-16-example9.cpp)：按值返回的合法写法 `return Foo{ };`（原 Example 12 的 ok 部分）。
- [14-16-example10-error.cpp](14-16-example10-error.cpp)：按值返回的非法写法 `return { };` / `return 5;` / `return { 5 };`（原 Example 12 的 error 部分，预期编译失败）。

> 说明：本节代码为按原文描述忠实重建（原文多为例程片段，已补全为可编译程序）。原 Example 3 的 `Foo x { 5 };` 与 `printFoo(5);` 对比为片段，已并入上面"核心概念"。

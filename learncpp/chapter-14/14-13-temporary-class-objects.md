# 14.13 Temporary class objects

> 原文：https://www.learncpp.com/cpp-tutorial/temporary-class-objects/

## 核心概念

- **别保留只使用一次的变量**：若一个变量只存放用一次的结果（如 `add()` 里的 `sum`），它会增加复杂度；可以把初始化表达式直接替换到使用处。
- **函数实参同理**：大多数函数实参也能这样替换，例如直接传 `5 + 3` 而不是先存进 `sum`。
- **仅在接受右值处可行**：这种替换只在允许右值表达式的地方成立；若需要左值，就必须有具名对象。原文示例的函数接受非 const 引用，`addOne(5 + 3); // compile error: not an lvalue`。
- **临时对象（temporary object）**：又称匿名对象（anonymous object）或无名对象（unnamed object），是"没有名字、只在一个表达式期间存在的对象"。
- **创建临时类对象的两种常见方式**：显式写出类型来构造（`IntPair { 5, 6 }`），或让编译器由形参推导类型并隐式转换花括号列表（`print( { 7, 8 } )`）。
- **三种语法的区别**：`IntPair p { 1, 2 };` 创建具名对象 `p`；`IntPair { 1, 2 };` 创建临时对象；`{ 1, 2 };` 让编译器把列表转换为与期望类型（通常是形参或返回类型）匹配的临时对象。
- **其他临时对象**：`std::string { "Hello" };` 创建用文本初始化的临时 string；`std::string {};` 用值初始化 / 默认构造函数创建临时 string。
- **不能用拷贝初始化创建临时对象**：没有这种语法。直接初始化可以：`Foo (1, 2);` 行为类似 `Foo { 1, 2 }`，区别是不阻止窄化转换。它看起来像函数调用，其实不是。
- **无参形式**：`Foo();` 创建值初始化的临时对象，等价于 `Foo {}`；但同样语法用于具名变量时含义不同：`Foo bar{};` 定义值初始化变量，而 `Foo bar();` 声明一个函数——原文称这种不一致"令人困惑"。
- **单参数的不一致**：`Foo(1);` 是对字面量 1 的函数式转换，返回临时 `Foo`，与其他创建临时对象的形式一致；而 `Foo(bar);` 却定义名为 `bar` 的变量（等价 `Foo bar;`），与 `Foo { bar }`、`Foo(1)` 不一致；若 `bar` 已存在则是重定义错误。原因是编译器知道字面量不可能是变量标识符，故对字面量情形一致处理；而括号在声明符中也可作分组（`Foo(bar)` = 类型 `Foo` + 只含 `bar` 的分组）。
- **进阶：括号改变含义**：`Foo * bar();` 声明返回 `Foo*` 的函数；`Foo (*bar)();` 定义名为 `bar` 的函数指针；`Foo (* bar());` 与第一个相同（多余的括号）。
- **按值返回产生临时对象**：被返回的对象是"用 return 语句中标识的值或对象初始化"的临时对象。三种情形：返回具名局部变量、返回显式临时对象、返回被隐式转换的花括号列表。
- **临时对象是右值**：与 `int` 一样，表达式中的临时类对象是右值，只能用在允许右值表达式的地方。
- **生存期**：临时对象在定义处创建，在包含它的完整表达式（full expression，即不是子表达式的表达式）结束时销毁。
- **`static_cast` vs 显式临时对象**：`static_cast<int>(c)` 产生由 `c` 直接初始化的临时 int；`int { c }` 产生由 `c` 列表初始化的临时 int。对类类型（如 `std::string`）可写 `static_cast<std::string>(sv)`、`std::string { sv }`，或 C 风格转换 `std::string ( sv )`——后者可行但被劝阻。
- **Key insight**：括号在函数调用、直接初始化、临时对象的值初始化、C 风格转换、分组、变量定义中含义各不相同，因此"含义并不总是显而易见"；相反，看到花括号就知道是在处理对象。

> **作者注**：本节虽然用类演示，但所有涉及列表初始化的内容"同样适用于用聚合初始化创建的 struct"。
> **作者注**：关于直接初始化的内容"主要是供阅读，而不是必须消化、记忆并解释清楚的东西"；但它有助于理解为什么现代 C++ 更偏好列表初始化。

## 最佳实践

- **Best practice**：转换到基础类型时优先用 `static_cast`，转换到类类型时优先用列表初始化的临时对象。
- 下列情况优先用 `static_cast` 创建临时对象：需要窄化转换；希望到"行为不同的类型"的转换是显而易见的（如 `char` 转 `int`）；想要直接初始化（如避免列表构造函数优先）。
- 下列情况优先用列表初始化创建新对象：想要列表初始化（窄化保护，或使用列表构造函数）；需要为转换额外传入构造函数实参。
- **Related content**：列表构造函数见 16.2 "Introduction to std::vector and list constructors"。

## 代码示例

- [14-13-example1.cpp](14-13-example1.cpp)：`add()` 用中间变量 `sum`（原 Example 1）。
- [14-13-example2.cpp](14-13-example2.cpp)：`add()` 直接返回表达式（原 Example 2）。
- [14-13-example3.cpp](14-13-example3.cpp)：`printValue(sum)` 使用具名变量（原 Example 3）。
- [14-13-example4.cpp](14-13-example4.cpp)：`printValue(5 + 3)` 直接传表达式（原 Example 4）。
- [14-13-example5-error.cpp](14-13-example5-error.cpp)：`addOne(int&)` 传 `5 + 3` 编译失败——右值不能绑定非 const 左值引用（原 Example 5，预期编译失败）。
- [14-13-example6.cpp](14-13-example6.cpp)：`IntPair` 具名对象传入 `print`（原 Example 6）。
- [14-13-example7.cpp](14-13-example7.cpp)：`IntPair` 三种传参形式：具名对象、显式临时对象、隐式转换列表（原 Example 7）。
- [14-13-example8.cpp](14-13-example8.cpp)：`std::string { "Hello" }` 与 `std::string {}` 临时对象（原 Example 9）。
- [14-13-example9.cpp](14-13-example9.cpp)：直接初始化临时对象 `Foo (1, 2);`（原 Example 10）。
- [14-13-example10.cpp](14-13-example10.cpp)：无参形式 `Foo();` vs `Foo bar{};` vs `Foo bar();`（原 Example 11）。
- [14-13-example11.cpp](14-13-example11.cpp)：`Foo(1)` 与 `Foo(bar)` 字面量/标识符的不一致（原 Example 12）。
- [14-13-example12.cpp](14-13-example12.cpp)：按值返回生成临时对象的三种情形 `ret1/ret2/ret3`（原 Example 14）。
- [14-13-example13.cpp](14-13-example13.cpp)：`static_cast<int>(c)` 与 `int { c }`（原 Example 15）。
- [14-13-example14/](14-13-example14/)：多文件示例——`printString.h` + `main.cpp`，把 `std::string_view` 显式转换为 `std::string` 的三种写法（原 Example 16）。

> 说明：本节代码为按原文描述忠实重建（原文多为例程片段，已补全为可编译程序）。
> 原文 Example 8（三种形式的注释总结）与 Example 13（指针/函数声明的进阶片段）为纯注释或片段，未单独生成可编译文件；其内容已并入上面的"核心概念"。

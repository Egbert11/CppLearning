# 14.4 Const class objects and const member functions

> 原文：https://www.learncpp.com/cpp-tutorial/const-class-objects-and-const-member-functions/

## 核心概念

- **const 基本类型对象必须初始化**：`int`、`double`、`char` 等类型可以加 `const` 关键字变成 const，而所有 const 变量都必须在创建时初始化。
- **类类型对象也能是 const**：struct、class、union 都能同样地变成 const，并且同样必须在创建时初始化。
- **优先使用 const（或 constexpr）类对象**：一旦想保证某个对象在创建后不再被改变，把它声明为 const 是通常选择。
- **不能修改 const 对象的成员**：初始化之后，直接改它的数据成员（若为 public）、或经由会设置成员值的成员函数去改，都违反 const 性并产生编译错误。
- **const 对象不能调用非 const 成员函数**：即使是像 `print()` 那样只读的函数，只要没有声明为 const 仍算违规，因为编译器禁止在 const 对象上调用非 const 成员函数。
- **const 成员函数**：const 成员函数是这样一种成员函数——它保证不会修改对象，也不会调用任何非 const 成员函数。做法是在参数列表之后、函数体之前加 `const`。
- **在类外定义时**：`const` 关键字必须同时出现在类内声明与类外定义上。
- **构造函数不能是 const**：它必须初始化对象的成员，这本身就需要修改成员。
- **const 成员函数若违背承诺会报错**：在 const 成员函数体内改数据成员、或调用非 const 成员函数，都会触发编译错误。
- **const 到底限制什么**：限制只针对成员——const 成员函数仍可修改局部变量、修改（非隐式对象的）参数，也可调用非成员函数。
- **const 成员函数也能用于非 const 对象**：由于它能同时用于 const 与非 const 对象，一个从不改变对象状态的函数就应当标为 const。
- **事后去掉 const 是破坏性改动**：一旦成员函数是 const，它就能被 const 对象调用；日后把 const 去掉会破坏所有在 const 对象上调用它的代码。
- **经 const 引用得到的 const 对象**：常见做法是按 const 引用传参——避免拷贝，且能同时接受 const 左值与非 const 右值（此处指 bool 场景下的值类别）；在函数内形参被当作 const，因此只能调用其 const 成员函数。
- **const / 非 const 重载**：const 限定符是函数签名的一部分，所以同一个成员函数可以同时提供 const 与非 const 两个版本。这种用法较少见（原文说 "pretty rare"），通常用于返回值的 const 性需要不同的场合。

## 最佳实践

- **Best practice**：不修改（且将来也不会修改）对象状态的成员函数应当标为 const，这样它能同时用于 const 与非 const 对象。
- **Key insight**：const 成员函数**不可以**——修改隐式对象、调用非 const 成员函数；const 成员函数**可以**——修改非隐式对象的其它对象、调用 const 成员函数、调用非成员函数。
- **Caution（小心）**：谨慎决定给哪些成员函数加 `const`。一旦某成员函数是 const，它就能被 const 对象调用；日后去掉 `const` 会破坏所有在 const 对象上调用它的代码。
- **For advanced readers**：类外定义的成员函数，其 `const` 必须同时写在类内声明与类外定义上（见 15.2）；构造函数不能是 const，因为它要初始化成员（见 14.9）。

## 代码示例

- [14-04-example1-error.cpp](14-04-example1-error.cpp)：const 基本类型必须初始化，未初始化则编译失败。
- [14-04-example2.cpp](14-04-example2.cpp)：const 类类型对象必须以聚合方式初始化。
- [14-04-example3-error.cpp](14-04-example3-error.cpp)：修改 const 对象成员 / 调用会改成员的成员函数，均编译失败。
- [14-04-example4-error.cpp](14-04-example4-error.cpp)：非 const 成员函数 `print()` 不能在 const 对象上调用。
- [14-04-example5.cpp](14-04-example5.cpp)：把 `print()` 标为 const 后问题解决，输出 `2020/10/14`。
- [14-04-example6-error.cpp](14-04-example6-error.cpp)：const 成员函数体内修改成员，编译失败。
- [14-04-example7.cpp](14-04-example7.cpp)：const 成员函数也能被非 const 对象调用，输出 `2020/10/14`。
- [14-04-example8-error.cpp](14-04-example8-error.cpp)：const 引用形参调用非 const 成员函数，编译失败。
- [14-04-example9.cpp](14-04-example9.cpp)：把 `print()` 标为 const 后问题解决，输出 `2020/10/14`。
- [14-04-example10.cpp](14-04-example10.cpp)：const / 非 const 成员函数重载，输出 `non-const` 与 `const`。

> 说明：本节代码为按原文描述**忠实重建**（抓取工具对长代码块有逐字引用上限）。原文本节无可完整逐字抓取的代码块，各示例均按原文的片段描述与注释重建。

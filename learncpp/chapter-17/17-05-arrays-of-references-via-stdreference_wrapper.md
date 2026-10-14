# 17.5 Arrays of references via std::reference_wrapper

> 原文：https://www.learncpp.com/cpp-tutorial/arrays-of-references-via-stdreference_wrapper/

## 核心概念

- **数组可存放任意对象类型**：元素可以是基本类型（如 `int`），也可以是复合类型（如指向 `int` 的指针）。
- **不能创建引用的数组**：引用不是对象，不能作为元素；数组元素还必须可赋值，而引用不能被重新绑定。
  - 写 `std::array<int&, 2>` 是编译错误。
  - 用引用变量初始化 `std::array` 虽然合法，但会悄悄退化成"值的数组"（例如 `std::array<int, 2>`），而不是引用数组。
- **结论具有普遍性**：本课用 `std::array` 举例，但同样适用于所有数组类型。
- **`std::reference_wrapper` 就是变通办法**：它是标准库类模板，声明在 `<functional>` 头文件中，接受一个类型模板参数 `T`，行为类似指向 `T` 的可修改 lvalue 引用。
- **三个显著特性**：
  - `operator=` 会重绑定 wrapper（改变它引用哪个对象），而不是通过它赋值。
  - `std::reference_wrapper<T>` 可隐式转换为 `T&`。
  - 成员函数 `get()` 返回 `T&`，在修改被引用对象的值时很方便。
- **赋值的歧义规则**：必须写 `arr[1].get() = 5` 而不能写 `arr[1] = 5`。编译器分不清你是想把 wrapper 重绑定到值 5（本身也不合法）还是修改被引用对象；`get()` 消除了歧义。
- **打印规则**：打印元素时编译器无法直接输出 `std::reference_wrapper<int>`，于是隐式转换为 `int&` 再打印——这里不需要 `get()`。
- **C++17 之前 `std::ref` / `std::cref` 的处境**：当时没有 CTAD，所有类模板实参都必须写全，创建 wrapper 既冗长又别扭。
- **`std::ref()` 与 `std::cref()` 快捷方式**：分别创建 `std::reference_wrapper` 与 const 包装的 `std::reference_wrapper<const T>`，配合 `auto` 可免去写出模板实参。
- **C++17 起**：CTAD 允许直接推导模板实参，但 `std::ref()`/`std::cref()` 因书写更短仍被广泛使用。

## 最佳实践

- 本节无 Best practice / Author's note / Warning 条目。教训以行内方式给出：引用不能作为数组元素；赋值必须用 `.get() =` 而非普通 `=`。

## 代码示例

- [17-05-example1.cpp](17-05-example1.cpp)：值的数组与指针的 vector 对比。
- [17-05-example2-error.cpp](17-05-example2-error.cpp)：`std::array<int&, 2>` → 编译失败（-error）；同时演示引用变量会退化为值的数组。
- [17-05-example3.cpp](17-05-example3.cpp)：`std::reference_wrapper` 数组，`arr[1].get() = 5` 输出 `55`。
- [17-05-example4.cpp](17-05-example4.cpp)：C++11 显式创建 `std::reference_wrapper` 的两种写法。
- [17-05-example5.cpp](17-05-example5.cpp)：`std::ref` / `std::cref` 配合 `auto`。
- [17-05-example6.cpp](17-05-example6.cpp)：C++17 的 CTAD 写法。

> 说明：本节代码为按原文描述重建（原文多为片段，已包进 `main()` 并标出边界）。

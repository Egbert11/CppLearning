# 26.2 Template non-type parameters

> 原文：https://www.learncpp.com/cpp-tutorial/template-non-type-parameters/

## 核心概念

- **回顾类型参数**：类型参数是一种占位类型，会被传入的实参类型替换，让函数与类不依赖某个具体类型。
- **类型参数不是唯一的种类**：模板类和模板函数都可以再带一种参数，称为**非类型参数（non-type parameter）**。
- **非类型参数的定义**：它的类型事先固定，实参传入的一个 **`constexpr` 值**会被替换到参数位置。
- **允许的类型**（非类型参数可以是）：
  - 整型（integral type）；
  - 枚举类型；
  - 指向类对象的指针或引用；
  - 指向函数的指针或引用；
  - 指向类成员函数的指针或引用；
  - `std::nullptr_t`；
  - 浮点类型（自 C++20 起）。
- **两类参数可混用**：本节示例构造一个静态（非动态）数组类，类型参数决定元素类型，整型非类型参数决定数组长度。
- **为什么不需要动态分配**：对任一具体实例化，长度必须是 `constexpr`；编译器会把字面量（如 12）代入，成员于是成为 `int[12]`，可以静态分配。
- **标准库中的对应物**：`std::array` 就是这样工作的——`std::array<int, 5>` 中 `int` 是类型参数、`5` 是非类型参数。
- **规则**：非类型实参必须是 `constexpr`；用非 `constexpr` 值实例化模板是无效的，编译器会报错。

## 最佳实践

本节无 Best practice / Warning / Author's note 方框。最接近提醒的是：示例 2 的内联注释指出用非 `constexpr` 值实例化会导致编译错误，"这样不行"。

## 代码示例

- [26-02-example1.cpp](26-02-example1.cpp)：`StaticArray<T, size>`，一个类型参数加一个整型非类型参数，含类外定义的 `getArray()`；输出 `11 10 9 8 7 6 5 4 3 2 1 0` 与 `4.4 4.5 4.6 4.7`（原 Example 1）。
- [26-02-example2-error.cpp](26-02-example2-error.cpp)：用运行时变量 `x` 作非类型实参，**预期编译失败**（原 Example 2）。

> 说明：本节代码取自原文 HTML 逐字抽取（`<pre>` 块），与原文一致。

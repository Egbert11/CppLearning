# 15.5 Class templates with member functions

> 原文：https://www.learncpp.com/cpp-tutorial/class-templates-with-member-functions/

## 核心概念

- **函数模板回顾**：`template <typename T>` 这样的模板参数声明定义了一个类型参数，可充当函数参数的类型。
- **类模板回顾**：类型模板参数也可以用来决定类类型（struct、class、union）的数据成员类型。
- **本节重点**：把两者结合，考察带有成员函数的类模板。
- **参数可共享**：为类声明的类型参数，既可用于数据成员，也可用于成员函数的参数类型。
- **构造函数取代聚合初始化**：有了私有成员，类就不再是聚合类型，因此必须用构造函数来构造对象，而不能用花括号聚合初始化。
- **按 const 引用传递**：因为 `T` 可能是拷贝代价大的类型，构造函数参数应写 `const T&` 而非按值传递。
- **类内定义**：当成员函数定义在类模板内部时，不需要再单独写模板参数声明——它隐式复用类的模板参数。
- **此处无需推导指引**：对非聚合类，一个匹配的构造函数就足以让编译器完成 CTAD（类模板实参推导）。
- **类外定义**：类外定义需要重新写出 `template <typename T>`，并用完全模板化的类名限定（"`Pair<T>::isEqual`，而不是 `Pair::isEqual`"）。
- **注入类名（injected class name）**：在类的作用域内，非限定类名就是完全模板化名的简写，因此构造函数可以命名为 `Pair` 并被视为 `Pair<T>`。
- **CTAD 注意事项**：CTAD 不作用于函数参数，但在函数参数里用注入类名是没问题的，因为那只是简写，而不是进行推导。
- **放置规则**：编译器必须同时看到类定义和成员函数模板定义，所以两者通常放在同一处——同一文件中，成员定义紧挨类下方；若在头文件中，就都放进该头文件。
- **隐式 inline 实例化**：由模板隐式实例化而来的函数隐式是 inline，因此头文件中定义的成员函数模板可被多个文件包含而不会产生链接冲突。
- **Quiz #2 的原理**：只有 const 成员函数能在 const 对象上调用，因为非 const 函数可能修改对象。

## 最佳实践

- **Best practice**：任何定义在类定义之外的成员函数模板，都应定义在类定义下方（同一文件内）。
- **Key insight #1**：在函数参数位置使用注入类名是可行的，因为它只是完全模板化名的简写，并非使用 CTAD。
- **Key insight #2**：由模板隐式实例化而来的成员函数隐式是 inline，因此头文件中定义它们并包含到多个文件是安全的。
- **Related content**：关于 CTAD 与推导指引，见 13.14。

本节无 Warning / Author's note 条目。

## 代码示例

- [15-05-example1.cpp](15-05-example1.cpp)：函数模板 `max(T, T)`（原 Example 1）。
- [15-05-example2.cpp](15-05-example2.cpp)：`struct Pair` 加推导指引，并用 CTAD（原 Example 2）。
- [15-05-example3.cpp](15-05-example3.cpp)：`class Pair` 的构造函数与类外定义的 `isEqual`，用 `Pair<T>::` 限定（原 Example 3、4）。
- [15-05-example4.cpp](15-05-example4.cpp)：把 `isEqual` 的参数写成注入类名 `const Pair&`（原 Example 4 的变体）。
- [15-05-quiz1.cpp](15-05-quiz1.cpp)：Quiz #1 解答——`Triad<T, U, V>` 类模板，输出 `[1, 2, 3]`、`1`、`[1, 2.3, Hello]`（原 Example 5）。
- [15-05-quiz2-error.cpp](15-05-quiz2-error.cpp)：Quiz #2 原理演示——在 const 对象上调用非 const 成员函数，预期编译失败（原文 Quiz #2 无代码，此文件为据此重建）。

> 说明：本节代码为按原文描述重建。

## 编译说明

单文件示例使用：

```
g++ -std=c++20 -Wall 15-05-quiz1.cpp -o quiz1
```

`15-05-quiz2-error.cpp` 为预期编译失败示例，请勿修复。

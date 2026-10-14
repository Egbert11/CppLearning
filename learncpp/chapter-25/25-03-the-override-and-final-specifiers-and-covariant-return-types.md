# 25.3 The override and final specifiers, and covariant return types

> 原文：https://www.learncpp.com/cpp-tutorial/the-override-and-final-specifiers-and-covariant-return-types/

## 核心概念

- **两个与继承相关的标识符**：`override` 与 `final` 不是关键字，而是"具有特殊含义的标识符"，通常称作说明符（specifier）。
- **覆写的精确匹配规则**：派生类的虚函数只有签名与返回类型完全一致时才算覆写。
- **无声的不匹配隐患**：参数类型不同（如 `short` vs `int`）或多加了 `const`，都不构成覆写，于是仍会调用基类版本；这类 bug 在大型程序里很难发现。
- **`override` 的作用**：加在任意虚函数上，告诉编译器强制检查"这确实是一次覆写"。
- **`override` 的位置**：放在成员函数声明末尾，也就是函数级 `const` 所在的位置。
- **与 `const` 的顺序**：当函数同时是 `const` 与 `override` 时，`const` 必须在前：`const override` 正确，`override const` 错误。
- **编译器的强制检查**：把并非覆写的函数标为 `override`，或把 `override` 用在非虚函数上，都会产生编译错误。
- **为何总是使用它**：没有性能代价，且能验证你确实覆写了预期函数；此外 `override` 隐含 `virtual`，因此无需再写 `virtual` 关键字。
- **`final` 的作用**：告诉编译器禁止覆写某虚函数或禁止从某类继承；违反时产生编译错误。
- **`final` 的位置**：函数上与 `override` 相同；封类时写在类名之后。
- **协变返回类型（covariant return types）**：返回类型匹配规则的一个例外——若基类的返回类型是指向类的指针/引用，则覆写可以返回指向派生类的指针/引用。
- **不会动态选择类型**："C++ 无法动态选择类型"，返回类型始终对应"实际被调用的那一版函数"。
- **向上转型行为**：通过基类指针调用会执行派生覆写，但返回的 `Derived*` 被向上转成 `Base*`，因此随后调用的是非虚的 `Base::printType()`。
- **把第二个函数也设为虚函数的效果**：若 `printType()` 是虚函数，虚派发就会转而选择 `Derived::printType()`。
- **更广的适用性**：协变返回常用于"返回自身类指针/引用"的函数，只要覆写的返回类型派生自基类返回类型即可使用。

## 最佳实践

- **Best practice**：在基类的虚函数上使用 `virtual` 关键字。
- **Best practice**：在派生类的覆写函数上使用 `override` 说明符（但不要再写 `virtual` 关键字）；其中包括虚析构函数。
- **Rule**：如果一个成员函数既是 `const` 又是 `override`，`const` 必须写在前面。
- **Author's note（协变返回类型）**：因为 C++ 不能动态选择类型，你得到的类型总是与"实际被调用的那一版函数"相对应。

## 代码示例

- [25-03-example1.cpp](25-03-example1.cpp)：两种"看似覆写实则不是"的情形（`short` 参数、多 `const`），输出 `A` / `A`（原 Example 1）。
- [25-03-example2-error.cpp](25-03-example2-error.cpp)：用 `override` 强制报错，产生两个编译错误（原 Example 2）。
- [25-03-example3-error.cpp](25-03-example3-error.cpp)：`final` 用在虚函数上，后续覆写报错（原 Example 3）。
- [25-03-example4-error.cpp](25-03-example4-error.cpp)：`final` 用在类上，继承报错（原 Example 4）。
- [25-03-example5.cpp](25-03-example5.cpp)：协变返回类型，输出 `called Derived::getThis()` / `returned a Derived` / `called Derived::getThis()` / `returned a Base`（原 Example 5）。
- [25-03-quiz1.cpp](25-03-quiz1.cpp)：测验一，混合非虚 `print()`/虚 `vprint()` 与协变 `get()`，输出 `BB` / `AA` / `AB`。

> 说明：本节代码为按原文描述重建（原文长代码块超出抓取引文上限）。`25-03-example1.cpp` 产生的 `-Woverloaded-virtual` 警告正是"签名不匹配"陷阱的体现。

# 26.6 Partial template specialization for pointers

> 原文：https://www.learncpp.com/cpp-tutorial/partial-template-specialization-for-pointers/

## 核心概念

- **回顾类模板特化**：一个模板类 `Storage` 存值并打印；`print()` 有一个针对 `double` 的全特化。
- **指针类型下的隐藏缺陷**：这个类能编译，但当 `T` 是指针时行为错误——它打印的是地址而不是所指的值。
- **原因**：对 `double*` 实参，`s` 变成 `Storage<double*>`，`m_value` 存的是地址的副本，`print()` 输出的正是它。
- **第一步修复：为 `double*` 全特化**：加一个全特化后，`print()` 会解引用指针并打印值。
- **但此修复不可推广**：每种指针类型都得写一个全特化，且根本无法覆盖指向自定义类型的指针。
- **函数偏特化不可行**：像 `Storage<T*>::print()` 这样的成员函数属于偏特化，但"函数不能被偏特化"（截至 C++23）——只有类可以。
- **可行方案：偏特化整个类**：定义 `Storage<T*>` 偏特化，于是 `Storage<T*>::print()` 成为普通、非特化的成员函数，合法。
- **推导与顺序说明**：参数声明为 `T`，因此 `T` 会推成非指针类型（需要指针的地方改用 `T*`）；偏特化必须定义在主模板之后。
- **所有权/生命周期问题**：`m_value` 是 `T*`，指向传入对象，若该对象先析构，`Storage<T*>` 就会悬垂——主模板是拷贝语义，这个却是引用语义，"是滋生 bug 的配方"。
- **缓解一——把它当作视图来用**：明确其具有引用语义、调用者必须保证对象存活；局限在于偏特化不能改名（必须与主模板同名）。
- **缓解二——禁止指针用法**：调用者可以自己解引用后改用 `Storage<T>`。类不能被删除，且把 `static_assert` 放进 `Storage<T*>` 里也拦不全，因为 `std::nullptr_t` 不是指针类型、不会匹配 `Storage<T*>`。
- **更好的做法：把 `static_assert` 放在主模板上**：这样指针与 `nullptr` 类型会被直接拒绝。
- **缓解三——用 `std::unique_ptr` 做堆拷贝**：让 `Storage<T*>` 持有一个 `unique_ptr` 副本，省去手写构造/拷贝/赋值/析构。
- **收尾规则**：当一个类需要对指针与非指针实参区别对待、且对使用者不可见时，偏特化非常有用。

## 最佳实践

本节无形式化的 Best practice / Warning / Author's note 方框。原文的内联提醒包括：

- 函数（含成员函数）不能被偏特化，只能偏特化类。
- `Storage<T*>` 具有引用语义，需注意悬垂；用 `unique_ptr` 拷贝可恢复值语义。
- `static_assert` 放在主模板上才能同时拦住裸指针与 `nullptr`。

## 代码示例

- [26-06-example1.cpp](26-06-example1.cpp)：基础 `Storage<T>` + `print()` 的 `double` 全特化；输出 `5` / `6.700000e+000`（原 Example 1）。
- [26-06-example2.cpp](26-06-example2.cpp)：用 `double*` 实例化，打印出地址（数值依实现而定，不可复现）（原 Example 2）。
- [26-06-example3.cpp](26-06-example3.cpp)：为 `double*` 做全特化，解引用后打印；输出 `1.200000e+00`（原 Example 3）。
- [26-06-example4-error.cpp](26-06-example4-error.cpp)：试图偏特化成员函数 `Storage<T*>::print()`，**预期编译失败**（原 Example 4）。
- [26-06-example5.cpp](26-06-example5.cpp)：偏特化整个类 `Storage<T*>`，`print()` 成为普通成员函数；输出 `1.200000e+00`（原 Example 5）。
- [26-06-example6-error.cpp](26-06-example6-error.cpp)：主模板加 `static_assert` 拦住指针与 `nullptr`，**预期编译失败**（原 Example 6）。
- [26-06-example7.cpp](26-06-example7.cpp)：`Storage<T*>` 用 `std::unique_ptr` 堆拷贝，恢复值语义；输出 `1.2` / `1.2`（原 Example 7）。

> 说明：本节代码取自原文 HTML 逐字抽取（`<pre>` 块），与原文一致；example2、example4、example6 为把原片段补全上下文以便独立编译。
> 平台差异：科学计数法指数位宽依实现而定（原文 MSVC `1.200000e+000`，本机 GCC/MinGW `1.200000e+00`）；example2 打印的地址 `0x…` 属实现/运行期决定，不可复现。
> 预期错误的实测信息（GCC 15.2）：example4 报 `invalid use of incomplete type 'class Storage<T*>'`（GCC 以拒绝“用偏特化类类型定义成员函数”的方式表达“函数不能被偏特化”）；example6 报 `static assertion failed: Storage<T*> and Storage<nullptr> disallowed`。

# 22.4 std::move

> 原文：https://www.learncpp.com/cpp-tutorial/stdmove/

## 核心概念

- **动机**：一旦你经常使用移动语义，就会遇到"想移动、手头却只有左值"的情况。示例里的 `mySwapCopy()` 交换函数产生三次拷贝（一次拷贝构造、两次拷贝赋值），对 `std::string` 这类类型很浪费。
- **`std::move` 的定义**：一个 C++11 标准库函数，它"（用 `static_cast`）把实参转换为右值引用，从而可以调用移动语义"。它让你把一个左值转换成更愿意走移动而非拷贝的东西。
  - 注意：`std::move` 本身**不移动任何东西**，它只是把表达式转换成右值（类型转换），真正的移动由随后选中的移动构造/移动赋值完成。
- **头文件**：定义在 `<utility>` 中，写作 `#include <utility> // for std::move`。
- **移动版 swap 如何工作**：`mySwapMove` 的形参 `a`、`b` 是左值引用，默认会选中拷贝行为；用 `std::move` 包住它们后，就会选中移动构造与移动赋值。三次移动取代三次拷贝。
- **`std::move` 与容器**：往 `std::vector<std::string>` 里填充时，`v.push_back(str)`（左值）会拷贝；`v.push_back(std::move(str))` 会调用右值重载，让元素窃取 `str` 的值，更高效。
- **被移动对象的标准规则**："Unless otherwise specified, moved-from objects… shall be placed in a valid but unspecified state."（除特别说明外，被移动走的对象应处于"有效但未指定"的状态。）因此不能依赖它留下的具体值；示例中打印出的空字符串是实现相关的。
- **两种流派**：一派主张被移动对象应被重置为默认/零状态（不拥有任何资源）；另一派主张"什么最方便就怎么做"，不必为了清空而付出额外代价。
- **对被移动对象安全的操作**："safe to call any function that does not depend on the current value of the object"（调用任何不依赖对象当前值的函数都是安全的）：可以重新赋值，可以调用 `clear()`/`reset()`/`empty()`；但要避免 `operator[]`、`front()`，因为它们要求容器确实持有元素。
- **`std::move` 的其它用途**：选择排序、冒泡排序这类会交换元素对的算法，可以用移动代替拷贝；也可以用来把某个智能指针管理的资源转移给另一个智能指针。
- **相关工具**：`std::move_if_noexcept()`——"如果对象有 noexcept 的移动构造函数，就返回可移动的右值，否则返回可拷贝的左值"（详见 27.10）。
- **结论**：凡是"想把它当成右值来触发移动语义而非拷贝语义"的地方，就使用 `std::move`。

## 最佳实践

本节没有独立的 Best practice / Warning 框，但有一条 Key insight：

- **Key insight**：`std::move()` 向编译器表明"该对象的值你已经不再需要了"。因此"Only use std::move() on persistent objects whose value you want to move"（只对"你确实想移走其值的持久对象"使用 `std::move()`），之后不要再对它做任何假设；同时"It is okay to give a moved-from object a new value"——移走值之后，可以（例如用 `operator=`）给被移动对象赋一个新值。

## 代码示例

- [22-04-example1.cpp](22-04-example1.cpp)：`mySwapCopy()` 用三次拷贝完成交换，输出 `abc/de` → `de/abc`（原 Example 1）。
- [22-04-example2.cpp](22-04-example2.cpp)：`mySwapMove()` 用 `std::move` 把三次拷贝换成三次移动，输出相同但更高效（原 Example 2）。
- [22-04-example3.cpp](22-04-example3.cpp)：往 vector 里 `push_back` 左值 vs `std::move(str)`，展示拷贝与移动两条路径，以及被移动对象状态的不确定性（原 Example 3）。

> 说明：本节代码为按原文描述重建。

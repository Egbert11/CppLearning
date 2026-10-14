# 22.3 Move constructors and move assignment

> 原文：https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/

## 核心概念

- **拷贝语义回顾**：拷贝构造函数用一个同类型对象构造新对象；拷贝赋值把值拷贝进一个已存在的对象。若你不提供，编译器会自动生成这两个函数，且它们执行**浅拷贝**；因此持有动态内存的类应当自己提供**深拷贝**版本。
- **代价问题**：在示例中，按值返回一个局部对象再赋值给已有对象，会引起三次分配和三次析构，因为深拷贝构造函数与深拷贝赋值各执行了一次。
- **移动操作是什么**：C++11 新增**移动构造函数**与**移动赋值运算符**。它们的目的不是复制对象，而是**转移资源所有权**，通常代价低得多。
- **参数上的区别**：拷贝操作接收 `const` 左值引用（几乎能绑定任何东西）；移动操作接收非 `const` 右值引用，因此只绑定右值。
- **移动如何工作**：把源的指针浅拷贝到目标，然后把源指针置空，源因此变为空。
- **`noexcept`**：按"Related content"提示，"Move constructors and move assignment should be marked as `noexcept`."（移动构造与移动赋值应标记为 `noexcept`。）这是向编译器表明这些函数不会抛异常。
- **何时选用移动**：当移动函数存在、且实参是右值（通常是字面量或临时对象）时，会执行移动构造/移动赋值；否则使用拷贝版本——即实参是左值时，或实参是右值但未声明移动函数时。
- **隐式移动操作**：编译器自动生成它们，当且仅当：没有用户声明的拷贝构造或拷贝赋值、没有用户声明的移动构造或移动赋值、且没有用户声明的析构函数。
- **逐成员移动行为**：每个成员若有合适的移动操作就被移动，否则被拷贝。因此指针成员在没有手写移动函数时会被**拷贝**而非移动。
- **核心洞见**：实参是左值时，拷贝是唯一安全的选择（该值之后可能还会被使用）；实参是右值（一个在表达式结束时就消亡的临时对象）时，窃取其资源既安全又廉价。右值引用让代码能够区分这两种情况。
- **有效性规则**："Move functions should always leave both objects in a valid state."（移动函数应始终让两个对象都处于有效状态。）被移动走的对象最终仍会被析构，如果它的指针还和目标指向同一处，就会产生悬垂指针和未定义行为。
- **被移走的左值也能返回**：标准有一条特殊规则——"按值从函数返回的自动对象即使本来是左值也可以被移动"，因为它们反正会被销毁。拷贝省略可能把这次拷贝/移动完全消除，此时两个构造函数都不会被调用。
- **禁用拷贝**：只能移动的类会删除拷贝构造与拷贝赋值；教程指出 `std::unique_ptr` 就是这种模式的标准库版本。
- **性能演示**：一百万元素的动态数组，拷贝耗时 0.00825559 s、移动耗时 0.0056 s，作者算出快了 32.1%。
- **删除移动操作**：`= delete` 对移动与拷贝一样适用。删除拷贝构造会抑制隐式移动构造，于是该类既不可拷贝也不可移动；教程建议对移动操作显式处理（delete 或 default）。
- **五法则（rule of five）**：如果拷贝构造、拷贝赋值、移动构造、移动赋值、析构函数中的任何一个被定义或删除，那么它们**全都**应该被定义或删除。
- **只删除移动是有害的**：被删除的移动构造仍是一个**已声明**的函数，因此参与重载决议，并在按值返回时优先于未被删除的拷贝构造；这会让类在"不适用强制拷贝省略"的场景下无法按值返回——这样的程序报错 "error: Move constructor was deleted"。
- **用 copy-and-swap 实现移动**：与一个即将被销毁的对象交换资源，既能拿到想要的资源，又能让将死的对象负责清理旧资源。
- **`std::swap` 递归陷阱**：在移动构造或移动赋值里使用 `std::swap` 会无限递归，因为 `std::swap` 本身就会调用这些移动操作；症状是不断刷出 "Move ctor" 直到栈溢出。
- **修复方式**：自己写一个只交换底层成员（例如对 `std::string` 成员调用 `std::swap`）的 `swap`，而不是对包含它的类类型调用 `std::swap`。

## 最佳实践

- **Warning**："The implicit move constructor and move assignment will copy pointers, not move them."（隐式移动构造与移动赋值会**拷贝**指针，而不会移动它们。）需要指针成员被移动时，必须自己定义这些操作。
- **Key insight**："Move semantics is an optimization opportunity."（移动语义是一次优化机会。）
- **Key insight**："Move functions should always leave both objects in a valid state."——被移动走的对象之后仍会被析构，必须保持有效。
- **Key insight**：**rule of five**——五个特殊成员函数要一起定义或一起删除。
- **Related content**：移动操作应标记为 `noexcept`（理由涉及 `std::move_if_noexcept`，见第 27 章相关内容）。
- **Practice guidance**：只删除移动操作会让类在"不适用强制拷贝省略"时无法按值返回，因为被删除的函数仍参与重载决议。

## 代码示例

- [22-03-example1.cpp](22-03-example1.cpp)：`Auto_ptr3` 提供**深拷贝**的拷贝构造与拷贝赋值；搭配 `Resource` 与 `generateResource()`，可见多次分配/析构（原 Example 1）。
- [22-03-example2.cpp](22-03-example2.cpp)：`Auto_ptr4` 在拷贝之外**新增**移动构造与移动赋值，分配/析构次数显著减少（原 Example 2）。
- [22-03-example3.cpp](22-03-example3.cpp)：`Auto_ptr5` 删除拷贝、保留 `noexcept` 移动，成为"只能移动"的智能指针，须用 `std::move` 转移（原 Example 3）。
- [22-03-example4.cpp](22-03-example4.cpp)：`DynamicArray` 模板，深拷贝语义（`alloc` + `std::copy_n` + 自赋值检查）（原 Example 4）。
- [22-03-example5.cpp](22-03-example5.cpp)：`Timer` + `cloneArrayAndDouble`，测量**拷贝**版的耗时（原 Example 5，结果依机器而定）。
- [22-03-example6.cpp](22-03-example6.cpp)：删除拷贝、改用移动版 `DynamicArray`，同样测量耗时以对比（原 Example 6，结果依机器而定）。
- [22-03-example7-error.cpp](22-03-example7-error.cpp)：`Name` 的四个特殊成员全部 `= delete`，对临时对象赋值报 "use of deleted function"（预期编译失败）。
- [22-03-example8-error.cpp](22-03-example8-error.cpp)：`Name` 拷贝 `= default`、移动 `= delete`，按值返回局部对象报 "Move constructor was deleted"（预期编译失败）。
- [22-03-example9-broken.cpp](22-03-example9-broken.cpp)：移动函数里用 `std::swap(*this, name)` 造成无限递归，最终栈溢出（坏实践演示，请勿运行）。
- [22-03-example10.cpp](22-03-example10.cpp)：写一个只交换成员的 `swap` 修复上面的递归，输出正确（原 Example 10）。

> 说明：本节代码为按原文描述重建。原文 Example 3 提到"按值传入一个 `Auto_ptr5` 左值会编译失败"，该失败用法不单独生成文件，见上文说明。

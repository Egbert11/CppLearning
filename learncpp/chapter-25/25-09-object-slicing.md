# 25.9 Object slicing

> 原文：https://www.learncpp.com/cpp-tutorial/object-slicing/

## 核心概念

- **基类引用/指针指向派生对象**：`Base& ref{ derived };` 与 `Base* ptr{ &derived };` 只能看到 Base 子对象，但派生部分依然存在；虚函数仍派发到最派生的重写版本，所以三种写法都打印 `Derived`。
- **对象切片（object slicing）**：把派生类对象赋值给基类对象时，只复制了基类那一部分，派生部分被「切掉」。
- **被切后的对象仍是 Base**：它的虚表指针仍指向 Base，因此 `getName()` 解析到 `Base::getName()`，打印 `base is a Base and has value 5`。
- **按值传参也会切片**：形如 `void printName(const Base base)` 的按值形参会切片实参；调用 `printName(d)` 打印 `I am a Base`。
- **函数的修复**：把形参改为 `const Base&`，同样的调用就打印 `I am a Derived`。
- **`std::vector` 中的切片**：`std::vector<Base>` 存入 `Derived{6}` 会被切片，打印 `I am a Base with value 6`。
- **为什么不能用引用 vector**：`std::vector<Base&>` 无法编译——vector 元素必须可赋值，而引用只能初始化一次。
- **指针 vector 变通**：`std::vector<Base*>` 能保持多态；缺点是现在允许 `nullptr`、语义变成指针，且动态分配的对象需要显式 `delete`。
- **`std::reference_wrapper` 变通**：一个「模拟可重新赋值引用」的类；用 `.get()` 取出元素，输出与指针版相同。
- **Frankenobject（缝合怪）**：`Base& b{ d2 }; b = d1;` 时，拷贝赋值不是虚函数，只把 d1 的 Base 部分拷贝进 d2，结果 `d2` **由多个对象的部分拼成**。
- **难以预防**：原文指出除了避免这种赋值之外，「没有简单的办法」防止它。
- **结论**：切片通常只会带来麻烦；应优先使用引用（或指针）形参，避免对派生类按值传参。

## 最佳实践

- **Tip**：如果基类本来就不打算被独立实例化（例如它只是个接口类），可以通过删除基类的拷贝构造函数和拷贝赋值运算符，使基类**不可拷贝**，从而避免切片。
- **结论**：切片「很可能只会带来头疼」，应尽量避免——使用引用或指针形参，避免对派生类按值传参。

（原文没有正式标注的 "Best practice" / "Warning" 栏目，以上为原文的 Tip 与 Conclusion。）

## 代码示例

- [25-09-example1.cpp](25-09-example1.cpp)：基类引用/指针指向派生对象，虚函数正常派发。
- [25-09-example2.cpp](25-09-example2.cpp)：直接赋值给 Base 对象导致切片。
- [25-09-example3.cpp](25-09-example3.cpp)：按值形参切片实参。
- [25-09-example4.cpp](25-09-example4.cpp)：改用引用形参后切片消失。
- [25-09-example5.cpp](25-09-example5.cpp)：`std::vector<Base>` 中的切片。
- [25-09-example6-error.cpp](25-09-example6-error.cpp)：`std::vector<Base&>` 无法编译（预期编译失败）。
- [25-09-example7.cpp](25-09-example7.cpp)：用 `std::vector<Base*>` 保持多态。
- [25-09-example8.cpp](25-09-example8.cpp)：用 `std::vector<std::reference_wrapper<Base>>` 保持多态。
- [25-09-example9-broken.cpp](25-09-example9-broken.cpp)：Frankenobject（坏实践示例，可编译但语义错误）。

代码说明：各示例代码取自 learncpp 原文逐字提取；对原文中只给出 `main()` 或用例函数的片段（示例 2–5、7），文件内补入了同小节前例给出的 `Base`/`Derived` 定义以便编译，并在文件头注释中标注。`25-09-example6-error.cpp` 另补入最小 `Base` 定义，使报错落在「vector 元素不能是引用」这一点。

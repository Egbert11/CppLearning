# 25.10 Dynamic casting

> 原文：https://www.learncpp.com/cpp-tutorial/dynamic-casting/

## 核心概念

- **回顾转换**：本节建立在之前的显式类型转换与 `static_cast`（10.6）之上，引入第二个转换运算符 `dynamic_cast`。
- **为什么需要 `dynamic_cast`**：使用多态时，常常手里只有基类指针，却需要访问只有派生类才有的数据；而基类对这种情况没有合理的虚函数答案。
- **向上转换（upcasting）**：C++ 允许派生类指针隐式转换为基类指针（如 `getObject()` 所做的）。
- **`dynamic_cast`**：最常见的用途是把基类指针转换为派生类指针，这一转换称为**向下转换（downcasting）**；语法与 `static_cast` 类似。
- **指针转换失败**：若无法完成转换，结果是空指针；不加检查地解引用会引发未定义行为（很可能崩溃）。
- **规则（原文）**：「始终检查你的 dynamic_cast 是否真的成功——即检查结果是否为空指针。」
- **运行期开销**：`dynamic_cast` 在程序运行期间做一致性检查，因此有性能开销。
- **向下转换可能失败的情形**：protected 或 private 继承；类没有声明或继承任何虚函数（因而没有虚表）；以及某些涉及虚基类的情况。
- **用 `static_cast` 向下转换**：不做运行期类型校验，更快但更危险；错误的基类→派生类转换会「成功」，随后使用即未定义行为。
- **自行校验类型**：一个返回枚举的虚函数 `getClassID()` 可以为 `static_cast` 提供依据；但既然已经付出一次虚调用的代价，`dynamic_cast` 反而更简单。
- **继承深度注意**：若某类派生自 `Derived`，用 `ClassID::derived` 检查会失败，但 `dynamic_cast` 转成 `Derived` 仍会成功——因为更深的类型「确实是一个」`Derived`。
- **带引用的 `dynamic_cast`**：与指针类似；但 C++ 没有空引用，失败时抛出 `std::bad_cast` 异常。
- **`dynamic_cast` 与 `static_cast` 的选择**：除向下转换外优先用 `static_cast`；向下转换时通常 `dynamic_cast` 更好；还可以考虑干脆用虚函数代替转换。
- **向下转换 vs 虚函数**：一般优先虚函数；但在基类无法修改（如来自标准库）、需要派生类专有功能、或基类没有合适的返回值（纯虚函数可能可行）时，向下转换更合适。
- **RTTI 警告**：`dynamic_cast` 依赖运行期类型信息（RTTI），RTTI 有明显的空间开销，某些编译器允许把它关掉以优化，而关闭会破坏 `dynamic_cast`。

## 最佳实践

- **Rule（原文）**：始终检查 dynamic_cast 的结果是否为空指针，确认转换确实成功。
- **Warning（原文「A warning about dynamic_cast and RTTI」）**：RTTI 占用空间，有的编译器可将其关闭，一旦关闭 `dynamic_cast` 就失效。
- 正文建议：除向下转换外优先 `static_cast`；向下转换优先 `dynamic_cast`；若能用虚函数解决则尽量避免转换。

## 代码示例

- [25-10-example1.cpp](25-10-example1.cpp)：引出问题——只有 `Base*`，如何打印 `Derived` 的 `name`。
- [25-10-example2.cpp](25-10-example2.cpp)：用 `dynamic_cast` 向下转换并访问 `Derived::getName()`。
- [25-10-example3.cpp](25-10-example3.cpp)：转换后检查结果是否为空指针。
- [25-10-example4.cpp](25-10-example4.cpp)：手写类型标识 `getClassID()` + `static_cast` 的替代方案。
- [25-10-example5.cpp](25-10-example5.cpp)：对引用使用 `dynamic_cast`（失败会抛异常）。
- [25-10-example6-ub.cpp](25-10-example6-ub.cpp)：转换失败但不检查即解引用（未定义行为，运行会崩溃）。
- [25-10-example7.cpp](25-10-example7.cpp)：对引用的转换失败被捕获为 `std::bad_cast`。

代码说明：示例 1–5 的代码取自 learncpp 原文逐字提取（对只给 `main()` 的片段补入了原文 Example 1 的类定义）；示例 6、7 为按原文正文描述重建的补充演示，已在文件头注明。

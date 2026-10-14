# 12.11 Pass by address (part 2)

> 原文：https://www.learncpp.com/cpp-tutorial/pass-by-address-part-2/

## 核心概念

- **用按地址传递实现可选参数**：指针形参可以默认初始化为 `nullptr`，让调用方在“没有值”时省略该实参。函数解引用前先测试指针（如 `if (id)`），从而在值未知时不会发生空指针解引用。
- **函数重载往往是更好的替代**：可以不写指针形参，而是写两个重载——一个不带参数、一个直接带值。这样既不必担心空指针解引用，也能接受字面量等右值。
- **改变指针形参的指向不影响调用方**：传递地址会把地址从实参复制到形参；重新赋值形参（如 `ptr2 = nullptr`）只改变局部副本，调用方的指针不变。
- **“按引用传地址”**：若要函数改变某个指针实参**指向哪个对象**，应把形参声明为**指针的引用**（`int*&`）。此时形参绑定到调用方的指针，赋值会传回到实参。
- **语法旁注**：`int*&` 正确，`int&*` 错误，因为“不存在指向引用的指针”——指针必须保存对象的地址，而引用不是对象。写成反形式编译器会报错。
- **为什么不再偏好 `0` 和 `NULL`**：字面量 `0` 既可能被理解为整数、也可能是空指针字面量，语义有歧义。`NULL` 的定义不受标准固定，它“可以是 `0`、`0L`、`((void*)0)` 或别的什么东西”。
- **对重载解析的后果**：在 `print(int)` 与 `print(int*)` 两个重载下，`print(0)` 总选整数版本；`print(NULL)` 依实现可能选任一版本或产生歧义调用错误（Visual Studio 选 `print(int)`；gcc 与 Clang 报错）。
- **`nullptr` 消除歧义**：它总是匹配指针类型，所以 `print(nullptr)` 总调用 `print(int*)`。
- **`std::nullptr_t`**：因为 `nullptr` 在重载中可与整数区分，它有自己的类型 `std::nullptr_t`，定义于 `<cstddef>`。它“只能持有 `nullptr` 一个值”，适合做只接受 `nullptr` 字面量的形参。
- **重载按类型而非值匹配**：`print(ptr)`（`ptr` 是持有 `nullptr` 的 `int*`）仍选 `print(int*)`；指针类型不会隐式转换为 `std::nullptr_t`。
- **“只有按值传递”**：编译器通常用指针实现引用，所以按引用传递“本质上就是按地址传递”。按地址传递是把地址从调用方复制到被调方，即按值传递一个地址。因此 C++ 实际上一切皆按值传递；能够修改实参，是解引用所传地址的结果。

## 最佳实践

- 本节无“Best practice / Author's note / Warning”提示框。原文将两个小节标题标注为可选（optional）：“Why using `0` or `NULL` is no longer preferred (optional)”与“std::nullptr_t (optional)”；另有一处 “As an aside…” 说明 `int*&` 与 `int&*` 的语法。

## 代码示例

- [12-11-example1.cpp](12-11-example1.cpp)：以 `nullptr` 默认值的指针形参实现可选参数（原 Example 1）。
- [12-11-example2.cpp](12-11-example2.cpp)：用函数重载实现同样的可选参数（原 Example 2）。
- [12-11-example3.cpp](12-11-example3.cpp)：重新赋值指针形参不影响调用方（原 Example 3）。
- [12-11-example4.cpp](12-11-example4.cpp)：用“指针的引用”`int*&` 让函数改变实参指针（原 Example 4）。
- [12-11-example5-error.cpp](12-11-example5-error.cpp)：`print(NULL)` 在 gcc/Clang 上重载歧义 —— 预期编译失败（原 Example 5）。
- [12-11-example6.cpp](12-11-example6.cpp)：`std::nullptr_t` 形参与重载匹配（原 Example 6）。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。

# 25.7 Pure virtual functions, abstract base classes, and interface classes

> 原文：https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/

## 核心概念

- **纯虚函数（pure virtual function / abstract function）**：用 `= 0` 声明、没有函数体的虚函数，相当于一个「占位符」，期待派生类重写它。
- **只有虚函数才能是纯虚的**：给非虚函数写 `= 0` 会产生编译错误（见示例 1）。
- **后果一：抽象基类**：只要类中含有至少一个纯虚函数，该类就是**抽象类（abstract class）**，不能被实例化。因为若允许实例化，调用那个没有定义的纯虚函数将无从解析。
- **后果二：派生类必须实现**：派生类如果没有为每个继承来的纯虚函数提供函数体，它自己也是抽象类。
- **动机示例**：`Animal` 提供返回占位值 `"???"` 的虚函数 `speak()`，会让「忘记重写」的派生类（如 `Cow`）静默继承错误行为。
- **成为抽象类后无需再保护构造函数**：因为纯虚函数已经阻止直接实例化，基类构造函数不再必须写成 protected（但写了也无妨）。
- **编译器诊断**：实例化未实现纯虚函数的类会报错，如 `variable type 'Cow' is an abstract class`，并附上未实现的方法提示。
- **纯虚函数仍可多态调用**：和普通虚函数一样，可以通过基类引用/指针调用，动态派发到派生类重写版本。
- **析构提醒**：任何含纯虚函数的类也应有一个虚析构函数。
- **纯虚函数也可以有定义**：函数既能带 `= 0`，又能有（out-of-line 的）定义；类仍是抽象的，派生类仍必须重写它。
- **定义必须写在类外**：给纯虚函数提供函数体时必须 out-of-line，不能内联。
- **Visual Studio 例外**：MSVC 允许在纯虚函数声明处直接写内联函数体，但这是不符合 C++ 标准的（且无法关闭）。
- **有定义时的用途**：适合「基类想提供默认实现、同时强制派生类给出自己版本」的场景，派生类可以简单地委托给基类版本。
- **纯虚析构函数**：析构函数也可以声明为纯虚，但仍必须提供定义，以便派生对象析构时能运行它。
- **接口类（interface class）**：没有任何成员变量、且**所有**函数都是纯虚函数的类。它只规定「需要哪些功能」，把实现完全交给派生类。惯例上以大写 `I` 开头命名。
- **接口的好处**：面向接口（如 `IErrorLog`）而不是具体类（如 `FileErrorLog`）编写函数，调用者就能传入任意符合接口的类型，代码更独立、更灵活。
- **虚表依然存在**：抽象类同样保留虚表，以便构造函数/析构函数在本类范围内解析虚调用；纯虚函数在虚表中的条目通常是空指针或指向一个通用错误例程（有时称为 `__purecall`）。

## 最佳实践

原文中与本节的提醒：

- **A reminder**：任何含纯虚函数的类都应该同时拥有一个虚析构函数。
- **For Visual Studio users**：在纯虚函数声明处内联给出定义是 MSVC 的非标准扩展，无法禁用。
- **接口备注**：为接口类编写时别忘了加上虚析构函数。

（原文没有正式标注的 "Best practice" 或 "Author's note" 栏目。）

## 代码示例

- [25-07-example1-error.cpp](25-07-example1-error.cpp)：纯虚函数用法，以及「非虚函数不能置 0」的编译错误（预期编译失败）。
- [25-07-example2-error.cpp](25-07-example2-error.cpp)：实例化含纯虚函数的抽象基类导致编译错误（预期编译失败）。
- [25-07-example3.cpp](25-07-example3.cpp)：改动前的设计——`Animal`/`Cat`/`Dog`，`speak()` 带默认返回值 `"???"`。
- [25-07-example4.cpp](25-07-example4.cpp)：`Cow` 忘记重写 `speak()`，输出 `Betsy says ???`。
- [25-07-example5-error.cpp](25-07-example5-error.cpp)：`speak()` 改为纯虚后 `Cow` 未实现，`Cow` 也是抽象类（预期编译失败）。
- [25-07-example6.cpp](25-07-example6.cpp)：`Cow` 正确重写，输出 `Betsy says Moo`。
- [25-07-example7.cpp](25-07-example7.cpp)：通过基类引用调用纯虚函数，动态派发到 `Cow::speak()`。
- [25-07-example8.cpp](25-07-example8.cpp)：纯虚函数带 out-of-line 定义，`Dragonfly` 委托给基类默认实现，输出 `Sally says buzz`。
- [25-07-example9-error.cpp](25-07-example9-error.cpp)：MSVC 允许的内联纯虚函数定义（非标准，GCC 报错，预期编译失败）。
- [25-07-example10.cpp](25-07-example10.cpp)：接口类 `IErrorLog`，以及 `mySqrt` 面向接口而非具体类的示例。

代码说明：各示例正文代码均取自 learncpp 原文逐字提取（见文件头注释）；`25-07-example3.cpp`、`25-07-example10.cpp` 中为使其成为可运行完整程序而补充的 `main()` / `FileErrorLog` 已在文件内标注。

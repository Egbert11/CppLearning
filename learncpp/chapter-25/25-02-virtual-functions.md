# 25.2 Virtual functions and polymorphism

> 原文：https://www.learncpp.com/cpp-tutorial/virtual-functions/

## 核心概念

- **基类指针的问题**：指向基类的指针/引用只能触及基类版本的函数，即使底层对象是派生类。
- **虚函数**：一种特殊的成员函数，会"解析到被引用/指向对象的实际类型所对应的最派生版本"。只需在声明前加 `virtual`。
- **覆写（override）**：派生类函数与基类版本具有相同的**签名（名字、参数类型、是否 const）与返回类型**时即构成覆写。
- **解析方式**：把基类函数标为虚函数后，程序会针对对象的实际类型去寻找更派生的合适版本。
- **解析范围**：只考虑"静态引用类型到动态对象类型之间"的那些函数；层级的无关类被忽略。
- **需要指针/引用**：虚派发只在通过指针或引用调用时发生。直接对对象调用总是用对象自身的类型（拷贝时发生切片则会丢失派生部分）。
- **多态（polymorphism）**：一个实体具有多种形态；词义即"多种形态"。
- **编译期多态 vs 运行期多态**：重载与模板解析发生在编译期；虚函数解析发生在运行期。
- **Animal 示例**：把 `speak()` 声明为虚函数后，单个 `report()` 函数和 `Animal*` 数组无需修改就能处理任意派生类型——原文称这可能是最大的收益。
- **签名必须精确匹配**：签名不匹配的派生函数通常仍能编译，却会无声地让虚解析失效；下一小节讲解如何防范。
- **隐式虚函数**：一旦某函数是虚函数，所有匹配的派生覆写都会自动成为虚函数（即使省略关键字）；反之不成立。
- **返回类型**：正常情况下虚函数与其覆写的返回类型必须一致，否则编译失败。
- **构造/析构中不要调用虚函数**：此时派生部分尚未构造（构造期）或已被销毁（析构期），于是会执行基类版本。
- **代价**：虚函数调用比普通调用慢；编译器还要为每个含虚函数的对象多分配一个指针，给本可以很小的对象增加开销。

## 最佳实践

- **Best practice**：Never call virtual functions from constructors or destructors.（绝不要在构造函数或析构函数中调用虚函数。）
- **Rule**：如果某函数是虚函数，则派生类中所有匹配的覆写都隐式是虚函数；反过来，派生类的覆写不会让基类函数变虚。
- **Warning**：派生类的签名必须与基类虚函数签名"精确匹配"，否则代码"很可能照样编译通过，但虚函数不会按预期解析"。
- **Tip**：较新的编译器可能对"有虚函数却有可访问的非虚析构函数"报错；解决办法是在基类加 `virtual ~Base() = default;`（25.4 讲解）。
- **Key insight**：虚函数解析只在"通过指向类类型对象的指针或引用调用成员函数"时才起作用。

## 代码示例

- [25-02-example1.cpp](25-02-example1.cpp)：非虚函数，`Base&` 调用得到 `Base`（原 Example 1，输出 `rBase is a Base`）。
- [25-02-example2.cpp](25-02-example2.cpp)：加上 `virtual` 后得到 `Derived`（原 Example 2，输出 `rBase is a Derived`）。
- [25-02-example3.cpp](25-02-example3.cpp)：四级继承 A→B→C→D，`A&` 绑定 C 对象输出 `C`（原 Example 3）。
- [25-02-example4.cpp](25-02-example4.cpp)：直接调用用对象自身类型；拷贝进基类对象会切片（原 Example 4）。
- [25-02-example5.cpp](25-02-example5.cpp)：非虚 `speak()` 的 Animal，通过基类引用输出 `???`（原 Example 5）。
- [25-02-example6.cpp](25-02-example6.cpp)：虚 `speak()` 的 Animal，输出 `Meow` / `Woof`（原 Example 6）。
- [25-02-example7.cpp](25-02-example7.cpp)：一个 `Animal*` 数组，六只动物各发己声（原 Example 7）。
- [25-02-example8-error.cpp](25-02-example8-error.cpp)：返回类型不匹配（`int` vs `double`），预期编译失败（原 Example 8）。
- [25-02-quiz1.cpp](25-02-quiz1.cpp)：测验一 parts a–f 六种情形，输出依次为 `B / C / A / C / A / A`。

> 说明：本节代码为按原文描述重建（原文长代码块超出抓取引文上限）。`25-02-example8-error.cpp` 与 `quiz1e` 揭示的 `-Woverloaded-virtual` 警告正是本小节要说明的"签名不匹配"陷阱。

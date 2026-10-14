# 25.x Chapter 25 summary and quiz

> 原文：https://www.learncpp.com/cpp-tutorial/chapter-25-summary-and-quiz/

> 说明：本小节官方编号为 **25.x**（章节总结与测验）。按本仓库命名规范，其文件顺延使用 **25.12** 作为编号。

## 本章知识速览

（本章 25.1–25.11 的要点汇总）

1. 基类指针/引用可以绑定到派生类对象，使一个函数或数组能操作该基类的任意派生类型。
2. 没有虚函数时，这样的指针/引用只能访问基类成员及其自身版本的函数。
3. 虚函数会在基类与派生类之间挑选**最派生**的版本（重写/override）；重写通常要求签名与返回类型一致，协变返回类型是个例外。
4. 有意重写时应加上 `override` 指示符，以便编译器捕获签名不匹配。
5. `final` 指示符阻止继续重写某个函数，或阻止从某个类继续派生。
6. 只要使用了继承，析构函数就应该是虚函数，这样通过基类指针 `delete` 时能运行正确的析构函数。
7. 可以用作用域解析运算符绕过虚解析，例如 `base.Base::getName()`。
8. 早绑定适用于编译器/链接器能直接解析的直接调用；迟绑定（函数指针）把决定推迟到运行时。
9. 虚函数使用迟绑定加虚表（virtual table）。
10. 代价是：调用更慢，且每个持有虚函数的对象因虚表而增大一个指针。
11. 追加 `= 0` 使函数成为纯虚/抽象；所在类成为抽象类、不能实例化，继承它的类必须给出具体定义，否则自己也是抽象类。纯虚函数仍可有函数体。
12. 接口类没有成员变量、只有纯虚函数；这类类名常以大写 `I` 开头。
13. 虚基类在一个对象中无论被继承多少次都只包含一次。
14. 把派生对象赋值给基类对象只会复制基类部分——即「对象切片」。
15. `dynamic_cast` 把基类指针转换为派生类指针（向下转换）；转换失败会得到空指针。
16. 为继承体系重载 `operator<<` 的最简单做法是：为最基类编写该重载，并把打印职责委托给一个虚成员函数。

## 核心概念

本节为章节总结 + 测验，要点见上方「本章知识速览」。测验部分见下。

## 最佳实践

本节无（总结页没有 Best practice / Warning 等标注栏目）。

## 代码示例

本节的题目本身附带代码，解答代码见下列文件（均为原文逐字提取）：

- [25-12-quiz1a-broken.cpp](25-12-quiz1a-broken.cpp)：Q1a 的缺陷程序（能编译，实际打印 `Base`）。
- [25-12-quiz1b-broken.cpp](25-12-quiz1b-broken.cpp)：Q1b 的缺陷程序（能编译，实际打印 `Base`）。
- [25-12-quiz1c-broken.cpp](25-12-quiz1c-broken.cpp)：Q1c 的缺陷程序（能编译，实际打印 `Base`）。
- [25-12-quiz1d-error.cpp](25-12-quiz1d-error.cpp)：Q1d 的缺陷程序（从 `final` 基类派生，预期编译失败）。
- [25-12-quiz1e-error.cpp](25-12-quiz1e-error.cpp)：Q1e 的缺陷程序（派生类成了抽象类，预期编译失败）。
- [25-12-quiz1f-ub.cpp](25-12-quiz1f-ub.cpp)：Q1f 的缺陷程序（基类无虚析构函数，删除派生对象为未定义行为）。
- [25-12-quiz2b.cpp](25-12-quiz2b.cpp)：Q2b 解答——`Triangle`/`Circle` 重写 `print()`。
- [25-12-quiz2c.cpp](25-12-quiz2c.cpp)：Q2c 解答——`std::vector<Shape*>` + `getLargestRadius()`。
- [25-12-quiz2d.cpp](25-12-quiz2d.cpp)：Q2d（加分）解答——改用 `std::vector<std::unique_ptr<Shape>>`。

## 测验

### Q1：下列每个程序都有某种缺陷（请直接观察，不要编译），指出缺陷所在。每个程序本意都是打印 `Derived`。

- **1a**（[code](25-12-quiz1a-broken.cpp)）：`Base` 的 `getName()` 不是虚函数，`Derived` 也未用 `override`；通过 `Base&` 调用的是 `Base::getName()`。
  - 缺陷：缺少 `virtual`（也没加 `override` 让编译器帮忙发现）。
- **1b**（[code](25-12-quiz1b-broken.cpp)）：`Base::getName()` 是 `virtual` 但非 `const`；`Derived::getName()` 是 `virtual` 且 `const`。
  - 缺陷：两者签名不同，`Derived` 的不是重写，`Base&` 调用得到 `Base::getName()`。
- **1c**（[code](25-12-quiz1c-broken.cpp)）：`override` 写对了，但 `Base b{ d };` 把对象**按值**拷贝成了 `Base`。
  - 缺陷：对象切片，派生部分丢失。
- **1d**（[code](25-12-quiz1d-error.cpp)）：`class Base final`，而 `Derived` 仍从 `Base` 继承。
  - 缺陷：不能从 `final` 基类派生（编译错误）。
- **1e**（[code](25-12-quiz1e-error.cpp)）：`Derived` 自己把 `getName()` 声明为纯虚函数（`= 0`）。
  - 缺陷：`Derived` 也成了抽象类，不能实例化（编译错误）。
- **1f**（[code](25-12-quiz1f-ub.cpp)）：`Base` 有虚函数却没有虚析构函数；`new Derived` 后经 `Base*` 删除。
  - 缺陷：通过基类指针删除派生对象时派生析构函数不会运行，属未定义行为（应给 `Base` 加虚析构函数）。

### Q2

- **2a**：创建一个名为 `Shape` 的抽象类，包含三个成员：一个接收并返回 `std::ostream&` 的纯虚 `print` 函数、一个重载的 `operator<<`，以及一个空的虚析构函数。
- **2b**（[解答](25-12-quiz2b.cpp)）：从 `Shape` 派生 `Triangle`（含 3 个 `Point`）与 `Circle`（含一个中心 `Point` 加一个整数半径），重写 `print()`，使给定 `main` 输出：
  ```
  Circle(Point(1, 2), radius 7)
  Triangle(Point(1, 2), Point(3, 4), Point(5, 6))
  ```
- **2c**（[解答](25-12-quiz2c.cpp)）：用这些类，把形状放进 `std::vector<Shape*>`，逐个打印、调用 `getLargestRadius(v)`，并逐个删除。预期输出含 `The largest radius is: 7`。
  - 提示：给 `Circle` 加 `getRadius()`，用 `dynamic_cast` 把 `Shape*` 向下转换为 `Circle*`。
- **2d（加分）**（[解答](25-12-quiz2d.cpp)）：把上一题改用 `std::vector<std::unique_ptr<Shape>>`，注意 `std::unique_ptr` 不可拷贝。
  - 提示一：不能用 `std::initializer_list`，因为它要求拷贝。
  - 提示二：`std::unique_ptr::get()` 返回其管理的裸指针。

（原文的测验页只提供「Show Solution / Show Hint」折叠块，没有 Best practice / Warning 等标注栏目。）

# 15.9 Friend classes and friend member functions

> 原文：https://www.learncpp.com/cpp-tutorial/friend-classes-and-friend-member-functions/

## 核心概念

- **友元类定义**：友元类是"可以访问另一个类的私有和保护成员"的类。
- **声明友元类**：在 `Storage` 内写 `friend class Display;`，即授予 `Display` 访问 `Storage` 私有成员的权限，于是 `Display` 的成员函数可以读取任一 `Storage` 对象的 `m_nValue` 与 `m_dValue`。
- **仍不能访问 `*this`**：即使成为友元，`Display` 也无法访问 `Storage` 的 `*this` 指针，因为 `*this` 在技术上是一个函数参数。
- **友元不是相互的**：`Display` 是 `Storage` 的友元，并不代表 `Storage` 也是 `Display` 的友元；要互相访问，两个类必须各自声明对方。
- **友元不可传递**：若 A 是 B 的友元、B 是 C 的友元，A 并不会因此成为 C 的友元。
- **友元不可继承**（进阶读者）：若 A 把 B 设为友元，从 B 派生的类并不会成为 A 的友元。
- **友元声明兼作前向声明**：`friend class` 声明同时前向声明了被友元化的类，因此无需再单独写前向声明。
- **友元成员函数**：也可以只友元化单个成员函数（写该成员函数的名字），而不是整个类；实践中这一做法更棘手。
- **需要完整定义**：要友元化单个成员函数，编译器必须已经看到"该成员函数所属类"的完整定义，而不能只有前向声明。
- **第一个修正——调整类顺序**：把 `Display` 的定义移到 `Storage` 之前，使编译器在检查友元声明时已认识 `Display`。
- **第二个问题**：若 `Display` 在前，但 `displayStorage` 的参数是 `Storage&`，编译器此时还不知道 `Storage` 是什么。
- **第二个修正**：补上 `class Storage;` 前向声明，并把 `Display::displayStorage()` 的定义移出类体、放到完整的 `Storage` 定义之后。
- **关键规则**：前向声明足以支持"引用"某个类，但访问该类的成员需要它的完整定义。
- **推荐做法**：把每个类放进各自的头文件，成员定义放进对应的 `.cpp`，从而完全避免重排顺序。

## 最佳实践

本节无 Best practice / Warning 条目；相关要点以 Author's note 与"进阶读者"提示形式给出：

- **Author's note**：在讨论"友元不可相互/不可传递"之后，作者附了一句轻松的话，对可能"深有同感"的读者表示理解。
- **For advanced readers**：友元不可继承——从友元类派生的类不会获得该友元关系。

## 代码示例

- [15-09-example1.cpp](15-09-example1.cpp)：友元类 `Storage`/`Display`，输出 `6.7 5` 与 `5 6.7`（原 Example 1）。
- [15-09-example2-error.cpp](15-09-example2-error.cpp)：`Storage` 在前、友元化 `Display::displayStorage`——预期编译失败（原 Example 2）。
- [15-09-example3-error.cpp](15-09-example3-error.cpp)：把 `Display` 整体前移后错误方式改变——预期编译失败（原 Example 3）。
- [15-09-example4.cpp](15-09-example4.cpp)：单文件正确解法（前向声明 + 类外定义），输出 `6.7 5`（原 Example 4）。
- [15-09-example5.cpp](15-09-example5.cpp)：小测验起始程序（`Vector3d`/`Point3d`，`moveByVector` 暂空），两次打印相同（原 Example 5）。
- [15-09-quiz1.cpp](15-09-quiz1.cpp)：测验第 1 步——友元类，输出 `Point(1 , 2 , 3)` 与 `Point(3 , 4 , 0)`（原 Example 6）。
- [15-09-quiz2.cpp](15-09-quiz2.cpp)：测验第 2 步——仅友元化成员函数，输出同上（原 Example 7）。
- [15-09-quiz3/](15-09-quiz3/)：测验第 3 步——拆成五文件（`Point3d.h/.cpp`、`Vector3d.h/.cpp`、`main.cpp`）（原 Example 8）。

> 说明：本节代码为按原文描述重建。

## 编译说明

单文件示例使用：

```
g++ -std=c++20 -Wall 15-09-example1.cpp -o example1
```

多文件示例用通配符编译：

```
g++ -std=c++20 -Wall 15-09-quiz3/*.cpp -o quiz3
```

`15-09-example2-error.cpp` 与 `15-09-example3-error.cpp` 为预期编译失败示例，请勿修复。

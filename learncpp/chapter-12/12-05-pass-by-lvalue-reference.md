# 12.5 Pass by lvalue reference

> 原文：https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/

## 核心概念

- **回顾按值传递**：传给函数的实参被拷贝进形参，形参在函数结束时销毁。基本类型拷贝廉价，因此无害。
- **有些对象拷贝昂贵**：多数标准库类型（如 `std::string`）是类类型，复制通常昂贵；只为一个马上销毁的副本付代价是浪费。
- **按引用传递（pass by reference）**：把形参声明为引用类型。调用时引用形参绑定到实参，因为引用是别名，不发生拷贝。
- **关键点**：按引用传递让实参无需在每次调用时被复制就能传入函数。
- **值形参 vs 引用形参**：对值形参取地址得到与实参不同的地址（是两个对象，故发生拷贝）；对引用形参取地址得到**相同**地址，说明引用被当作实参本身。
- **通过非 const 引用修改实参**：按值传递时函数内的修改只影响局部副本；按引用传递时对形参的修改会改到原实参，并在函数返回后保留。
- **关键点**：**按非 const 引用传递，让我们能写出修改传入实参的函数。**
- **实用例子**：让玩家对象按引用传入"造成伤害"的函数，就能直接改动真实玩家的血量；按值传递只能改到副本。
- **非 const 引用形参的限制**：对非 const 的引用只能绑定可修改左值，因此 const 变量和字面量/右值都传不进去，这大幅限制了"按非 const 引用传递"的用途。

## 最佳实践

本节无 Best practice / Warning / Author's note 条目。相关 callout：

- **Key insight**：按引用传递让实参在每次调用时都无需被复制。
- **Key insight**：按非 const 引用传递，允许我们写出修改传入实参的函数。

## 代码示例

- [12-05-example1.cpp](12-05-example1.cpp)：按值传递 `int`（廉价拷贝）（原 Example 1）。
- [12-05-example2.cpp](12-05-example2.cpp)：按值传递 `std::string`（昂贵拷贝，输出 Hello, world!）（原 Example 2）。
- [12-05-example3.cpp](12-05-example3.cpp)：改为按引用传递 `std::string&`（原 Example 3）。
- [12-05-example4.cpp](12-05-example4.cpp)：比较值形参/引用形参/实参的地址（地址随运行变化）（原 Example 4）。
- [12-05-example5.cpp](12-05-example5.cpp)：按值传递不修改实参（输出 5、5）（原 Example 5）。
- [12-05-example6.cpp](12-05-example6.cpp)：按引用传递修改实参（输出 5、6）（原 Example 6）。
- [12-05-example7-error.cpp](12-05-example7-error.cpp)：非 const 引用形参只接受可修改左值 —— 预期编译失败（原 Example 7）。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。

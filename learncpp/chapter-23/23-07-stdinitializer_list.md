# 23.7 std::initializer_list

> 原文：https://www.learncpp.com/cpp-tutorial/stdinitializer_list/

## 核心概念

- **数组的列表初始化语法**：普通数组与动态分配的数组都能用花括号列表赋值，如 `int array[] { 5, 4, 3, 2, 1 };`。
- **容器类没有这个能力**：像 IntArray 这样的自定义类没有能理解花括号列表的构造函数，于是 `IntArray array { 5, 4, 3, 2, 1 };` 无法编译。
- **手工绕过**：没有这种构造函数时，只能先用长度构造，再逐个元素赋值。
- **自动转换**：当编译器遇到初始化列表，会把它转成 `std::initializer_list` 对象——所以提供一个接收该类型的构造函数，就能启用花括号初始化。
- **头文件要求**：`std::initializer_list` 声明在 `<initializer_list>` 头文件中。
- **必须指定元素类型**：需要用尖括号写明持有的类型（如 `std::initializer_list<int>`），除非对象是被立即初始化，所以裸的 `std::initializer_list` 很少见。
- **获取大小**：它有一个"（命名有误导性的）`size()` 函数，返回列表中元素个数"，可用来获取传入的长度。
- **按值传递**：和 `std::string_view` 一样，它是一个轻量视图；拷贝它不会复制底层元素。
- **委托构造技巧**：列表构造函数把个数转发给 `IntArray(int)` 构造函数，因为 `size()` 返回无符号的 `size_t`，需要转换。
- **拷贝元素**：构造函数体用 `<algorithm>` 里的 `std::copy()` 把列表元素搬进内部数组。
- **没有下标运算符**：`std::initializer_list` 不提供 `operator[]`；这个问题曾向标准委员会提出，但一直未处理。
- **变通 1**：用范围 for 循环遍历列表。
- **变通 2**：用 `begin()` 取得随机访问迭代器并按下标访问，如 `list.begin()[count]`。
- **列表构造函数优先**："List initialization favors matching list constructors over matching non-list constructors."（列表初始化优先匹配列表构造函数）。
- **直接初始化 vs 列表初始化**：直接初始化会忽略列表构造函数，所以 `IntArray a1(5)` 选中 `IntArray(int)`（长度 5）；花括号 `IntArray a2{ 5 }` 选中列表构造函数（长度 1）。
- **委托构造的 caveat**：必须用直接初始化来委托，否则构造函数会试图委托给自身而编译失败。
- **`std::vector` 同理**：`std::vector<int> array(5)` 得到 5 个值初始化的元素；`array{ 5 }` 得到 1 个值为 5 的元素。
- **改造的危险**：给一个原本没有列表构造函数的类添加它，可能**悄悄改变现有代码**调用的构造函数。
- **赋值支持**：`std::initializer_list` 也能驱动赋值——只需重载 `operator=` 接收列表参数。
- **必需的防护**：如果有列表构造函数，那么该类应同时提供列表赋值运算符、提供正确的深拷贝拷贝赋值运算符，或 delete 拷贝赋值运算符。
- **原因**：否则编译器会通过列表构造函数造出一个临时对象，再浅拷贝它，使目标的数据指针悬垂，使用或销毁时造成未定义行为。
- **小结**：`std::initializer_list` 构造函数让自定义类支持列表初始化，同一类型也支持其他接收列表的函数（如赋值）。

## 最佳实践

- **Best practice（容器初始化）**：初始化"有列表构造函数"的容器时——"Use brace initialization when intending to call the list constructor"（要调列表构造函数就用花括号，传入元素值）；"Use direct initialization when intending to call a non-list constructor"（要调非列表构造函数就用直接初始化，传入非元素值）。
- **Key insight**："List initialization favors matching list constructors over matching non-list constructors."
- **Warning**："Adding a list constructor to an existing class that did not have one may break existing programs."（给原本没有列表构造函数的类添加它，可能破坏现有程序。）
- **Best practice（赋值）**："If you provide list construction, it's a good idea to provide list assignment as well."（若提供列表构造，最好也提供列表赋值。）

## 代码示例

- [23-07-example1.cpp](23-07-example1.cpp)：栈数组用花括号列表初始化，范围 for 打印 `5 4 3 2 1`（原 Example 1）。
- [23-07-example2.cpp](23-07-example2.cpp)：动态分配数组的列表初始化（原 Example 2）。
- [23-07-example3-error.cpp](23-07-example3-error.cpp)：无列表构造函数的 IntArray 用花括号初始化 → 编译失败（-error，原 Example 3）。
- [23-07-example4.cpp](23-07-example4.cpp)：没有列表构造函数时的手动逐个赋值兜底（原 Example 4）。
- [23-07-example5/](23-07-example5/)：带 `std::initializer_list<int>` 构造函数、并 delete 拷贝操作的 `IntArray.h` + `main.cpp`（原 Example 5/6/7）。
- [23-07-example6.cpp](23-07-example6.cpp)：IntArray 的直接初始化 vs 花括号初始化（`a1(5)` 长度 5，`a2{5}` 长度 1）（原 Example 8）。
- [23-07-example7.cpp](23-07-example7.cpp)：`std::vector<int>` 的直接初始化 vs 花括号初始化（原 Example 9）。
- [23-07-example8.cpp](23-07-example8.cpp)：`Foo` 只有 `Foo(int,int)` 时，`Foo{1,2}` 调用它（原 Example 10）。
- [23-07-example9.cpp](23-07-example9.cpp)：给 `Foo` 添加列表构造函数后，`Foo{1,2}` 改调列表构造函数（原 Example 11）。
- [23-07-example10-ub.cpp](23-07-example10-ub.cpp)：未提供（或 delete）深拷贝拷贝赋值的 IntArray，`array = { ... }` 触发未定义行为（-ub，原 Example 12）。
- [23-07-quiz1.cpp](23-07-quiz1.cpp)：测验解答——提供列表赋值运算符的 IntArray，输出 `5 4 3 2 1` 与 `1 3 5 7 9 11`（原 Example 13/14）。

> 说明：本节代码为按原文描述重建（原文长代码块超出抓取引文上限）。

## 编译说明

多文件示例用通配符编译：

```
g++ -std=c++20 -Wall 23-07-example5/*.cpp -o example5
```

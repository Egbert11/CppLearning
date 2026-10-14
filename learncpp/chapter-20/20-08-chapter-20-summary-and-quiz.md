# 20.x Chapter 20 summary and quiz（官方编号 20.x）

> 原文：https://www.learncpp.com/cpp-tutorial/chapter-20-summary-and-quiz/

## 本章知识速览

- **实参传递方式**：可以按值、按引用或按地址传递。建议：基本数据类型和枚举量用按值传递；结构体/类、或需要函数修改实参时用按引用传递；指针和内置数组用按地址传递。
- **形参的 const 正确性**：尽可能把按引用和按地址传递的形参声明为 const。
- **返回值方式**：可以按值、按引用或按地址返回；按值返回通常就够用。按引用/地址返回适合动态分配的数据、结构体或类，但"若按引用或地址返回，务必确保不会返回将要离开作用域的东西"。
- **函数指针**："函数指针允许我们把一个函数传给另一个函数。"这让调用者可以定制行为，例如如何排序列表。
- **动态内存**："动态内存在堆上分配。"
- **调用栈**：它跟踪每一个已被调用但尚未返回的函数。局部变量位于栈上，栈的容量很小；`std::vector` 可以模拟栈的行为。
- **递归**："递归函数就是调用自身的函数。"每个递归函数都需要一个终止条件。
- **命令行参数**：它们让用户或其它程序在启动时送入数据。参数总是以 C 风格字符串形式到达，需要数字时必须做转换。
- **省略号参数**：它们允许可变数量的参数，但会关闭类型检查，也不知道到底传了几个参数。"这些细节由程序自己负责跟踪。"
- **lambda**："Lambda 函数是可以嵌套在其它函数内部的函数。"它们不需要名字，与算法库配合得很好。

## 测验

**Question #1**：为以下情形写出函数原型，并在需要处补上 const：
- a) 函数 `max()`，接收两个 `double`，返回较大的那个。
- b) 函数 `swap()`，交换两个整数。
- c) 函数 `getLargestElement()`，接收一个动态分配的 int 数组（以及长度参数），返回最大值，使调用者能修改返回的那个元素。

**Question #2**：以下程序各自有什么问题？
- a) `doSomething()` 从局部数组返回 `array[3]`。
- b) `sumTo()` 用 `value - 1` 递归却没有 base case。
- c) 两个 `divide(float, float)` 重载，一个返回 `float`，一个返回 `double`。
- d) `main()` 里声明局部 `int array[100000000]{}` 并用 range-for 打印。
- e) `main(int argc, char* argv[])` 里写 `int age{ argv[1] };`。

**Question #3**：为给定的 `binarySearch(const int* array, int target, int min, int max)` 签名与测试 harness 实现二分查找：(a) 迭代版；(b) 递归版。它应返回目标元素的下标，若不存在则返回 `-1`。提示：当 min 超过 max 时就说明目标不存在。

### 测验解答要点

- **1a**：`double max(double x, double y);`
- **1b**：`void swap(int& x, int& y);`
- **1c**：`int& getLargestElement(int* array, int length);` —— 这里的数组参数不能加 const，因为对一个 const 元素返回非 const 引用会破坏 const 正确性。
- **2a**：函数返回了对局部变量的引用，该变量在函数返回时被销毁（悬垂引用）。
- **2b**：没有终止条件；`value` 会变成负数并一直递归，直到栈溢出。
- **2c**：名字相同、参数列表也相同，所以它们不是有区别的重载（重定义错误）；另外还存在除零风险。
- **2d**：数组对栈来说太大了，应改为动态分配。
- **2e**：`argv[1]` 可能不存在，而且它是字符串，不能直接赋值给 int。
- **3a**（迭代）：当 `min <= max` 时循环，用 `std::midpoint`（C++20 之前用 `min + ((max - min) / 2)`，避免溢出）求中点，用 `max = midpoint - 1` / `min = midpoint + 1` 收缩区间，命中则返回 midpoint，否则返回 `-1`；包含 `assert(array)`。
- **3b**（递归）：当 `min > max` 时返回 `-1`，否则向可能包含目标的半边递归，命中时返回 midpoint。

## 代码示例

- [20-08-quiz1.cpp](20-08-quiz1.cpp)：Quiz 1 解答——三个函数原型。
- [20-08-quiz2a-warning.cpp](20-08-quiz2a-warning.cpp)：Quiz 2a——返回局部数组元素的引用（预期产生警告）。
- [20-08-quiz2b-overflow.cpp](20-08-quiz2b-overflow.cpp)：Quiz 2b——没有终止条件的递归（**请勿运行**）。
- [20-08-quiz2c-error.cpp](20-08-quiz2c-error.cpp)：Quiz 2c——无法区分的重载（预期编译失败）。
- [20-08-quiz2d-overflow.cpp](20-08-quiz2d-overflow.cpp)：Quiz 2d——栈上数组过大（**请勿运行**）。
- [20-08-quiz2e-error.cpp](20-08-quiz2e-error.cpp)：Quiz 2e——`char*` 直接赋给 `int`（预期编译失败）。
- [20-08-quiz3a.cpp](20-08-quiz3a.cpp)：Quiz 3a 解答——迭代版二分查找 + 测试 harness。
- [20-08-quiz3b.cpp](20-08-quiz3b.cpp)：Quiz 3b 解答——递归版二分查找 + 测试 harness。

> 本节无 Best practice / Author's note / Warning 框。有一个 Tip：`std::binary_search` 判断值是否在有序列表中存在，`std::equal_range` 返回首个与最后一个匹配元素的迭代器；测验中不要用它们，但今后应当使用。
>
> 本节 Quiz 3 的解答代码按原文解答重建。

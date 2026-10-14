# 16.6 Arrays and loops

> 原文：https://www.learncpp.com/cpp-tutorial/arrays-and-loops/

## 核心概念

- **变量扩展性难题**：用各自命名的变量求成绩平均，需要大量声明、数据变化时要手动更新，还可能忘记改除数而引入语义错误。
- **数组/容器减轻负担**：用 `std::vector` 取代一堆独立变量，可减少声明的名字，且除数可由 `size()` 得到而无需手工维护。
- **手动写下标不能扩展**：逐个列出元素意味着计算只对该长度的数组有效。
- **下标可以是运行期值**：数组下标不必是常量表达式，变量也能作为索引。
- **索引构成递增序列**：由于索引按 0、1、2… 递增，可以用循环计数器取代字面量下标。
- **遍历的定义**：按某种顺序走过容器的每个元素叫遍历（traversal，也叫 iterating over/through）。
- **Author's note（类型）**：容器类用 `size_t` 表示长度与索引，本节也照此处理；有符号长度/索引留到 16.7。
- **模板 + 数组 + 循环 = 可扩展**：数组存储许多对象而无需各自命名；循环遍历而无需逐个列出；模板参数化元素类型——三者结合后，无论元素类型或个数如何都能工作。
- **模板的要求**：只要类型 `T` 支持函数内用到的运算符，`calculateAverage()` 就能编译；否则编译器会在实例化时报错。
- **为什么转成 `int`**：元素个数本质是整数，除以 `int` 比除以 `T` 在语义上更清晰。
- **四种常见遍历目标**：(a) 计算新值（求和/平均）；(b) 查找（匹配、计数、求最大）；(c) 对每个元素操作（打印、缩放）；(d) 重排元素。前三者只需单层循环。
- **重排更难**：通常需要循环套循环；优先使用标准库已有的算法（后续介绍）。
- **差一错误规则**：索引从 `0` 开始，循环条件写 `index < length`。用 `index <= length` 会在 `index == length` 时执行循环体，造成越界下标与未定义行为。
- **测验技巧**：查找函数可用 `-1` 作为"无效索引"哨兵；输入校验循环用 `std::cin.clear()` 与 `std::cin.ignore(...)` 丢弃坏输入/多余输入；`findMax` 应以第一个元素初始化（值初始化会让"全为负"的数组出错）；FizzBuzz 用并行的 `divisors` 与 `words` 两个 vector，并用 `assert` 断言两者长度一致。

## 最佳实践

本节无独立标注的 Best practice 条目，但有下列警示/提示：

- **差一警告（off-by-one）**：差一错误（循环体多执行或少执行一次）很容易犯，循环条件应偏好 `index < length` 而非 `index <= length`。
- **Tip（FizzBuzz）**：由于这两个 vector 是常量，用 `constexpr std::array` 比 `std::vector` 更好；`std::array` 见 17.1。
- **Related content**：for 循环见 8.10。
- **Author's note**：本节用 `size_t`（与容器类一致）；有符号长度/索引见 16.7。

## 代码示例

- [16-06-example1.cpp](16-06-example1.cpp)：用 5 个独立变量求平均，输出 `The class average is: 77`（原 Example 1）。
- [16-06-example2.cpp](16-06-example2.cpp)：改用 `std::vector` 但逐个写下标（原 Example 2）。
- [16-06-example3.cpp](16-06-example3.cpp)：用 `std::vector` 加 for 循环累加求和（原 Example 3）。
- [16-06-example4.cpp](16-06-example4.cpp)：函数模板 `calculateAverage()`，对 int 与 double 的 vector 各算一次，输出 `The class 1 average is: 77` 与 `The class 2 average is: 81.75`（原 Example 4）。
- [16-06-quiz1.cpp](16-06-quiz1.cpp)：Quiz #1 解答——用循环打印全部元素，输出 `4 6 7 3 8 2 1 9`（原 Example 5）。
- [16-06-quiz2.cpp](16-06-quiz2.cpp)：Quiz #2 解答——`printArray` 函数模板（原 Example 6）。
- [16-06-quiz3.cpp](16-06-quiz3.cpp)：Quiz #3 解答——`findIndex()` 返回索引或 `-1`，以及带输入校验的 `getValidNumber()`（原 Example 7）。
- [16-06-quiz4.cpp](16-06-quiz4.cpp)：Quiz #4 解答（额外加分）——泛型 `getValidNumber(std::string_view prompt, T low, T high)`（原 Example 8）。
- [16-06-quiz5.cpp](16-06-quiz5.cpp)：Quiz #5 解答——`findMax()`：空 vector 返回 `T{}`，否则以 `arr[0]` 初始化并自索引 1 起循环，输出 `92` / `-13` / `0`（原 Example 9）。
- [16-06-quiz6.cpp](16-06-quiz6.cpp)：Quiz #6 解答——`fizzbuzz()`：并行的 `divisors` 与 `words`、`assert` 长度一致、嵌套循环（原 Example 10）。

> 说明：原 Quiz 的起始骨架（占位注释）不可独立编译，故不生成 cpp。本节代码为按原文描述重建。

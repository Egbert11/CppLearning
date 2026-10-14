# 18.3 Introduction to standard library algorithms

> 原文：https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/

## 核心概念

- **手写循环的问题**：初学者常为排序、计数、查找而写自定义循环。这类循环容易出错、也更难维护，因为不容易读懂。
- **为何使用库算法**：标准库为这些常见操作提供了现成函数。它们经过预先测试、高效、适用于许多容器类型，且常支持并行化（用多个 CPU 线程更快完成任务）。
- **算法的三大类别**：*inspectors*（只查看、不修改容器数据——查找、计数）、*mutators*（修改数据——排序、洗牌）、*facilitators*（由数据的成员值产生结果——例如把值相乘的对象，或决定排序顺序的对象）。
- **位置与前提**：这些函数位于算法库；原文指出其数量远超本节覆盖范围。它们都使用迭代器，因此假定读者已了解基本迭代器（见 18.2）。
- **`std::find`**：查找第一个匹配的值。接受三个实参：起始迭代器、结束迭代器、要查找的值。返回指向找到元素的迭代器；若无匹配则返回容器的 end 迭代器。
- **`std::find_if`**：当需要的是条件而非精确值（如子串匹配）时使用。不传值，而传一个可调用对象；它会对每个元素调用，匹配返回 true，否则返回 false。
- **`std::count` / `std::count_if`**：定位并统计某个值、或满足某条件的元素出现的每一次。
- **`std::sort`**：默认升序；但有一个重载接受第三个实参——比较函数，它在“第一个参数应排在第二个之前”时返回 true，从而实现自定义排序。
- **函数指针机制**：不带括号的函数名只是一个指针，不是调用。`std::sort` 会用任意元素对去调用真正的函数；具体用哪些元素对是未指定的，因为底层算法没有定义。
- **`std::greater` 提示**：降序很常见，因此 `<functional>` 提供了现成类型 `std::greater`。它必须用花括号实例化（`std::greater{}`），因为它是类型而非可调用函数；C++17 之前必须写出元素类型。
- **进阶比较函数说明**：改进版选择排序示例把比较器存为 `std::function<bool(int, int)>`，并把直接的“小于”判断替换为对比较器的调用，让调用者决定排序顺序。原文建议在第 20 章之前把该类型当作“魔法”看待。
- **`std::for_each`**：对区间内每个元素应用所提供的函数；适合对列表重复同一操作。
- **`for_each` vs 范围 for**：算法更清晰地表达意图，并避免手写循环可能犯的错（省略 `auto` 时的隐式转换、忘记 `&`、传错变量）。它还能借 `std::next` 跳过开头或结尾的元素（范围 for 做不到），并且可以并行化。
- **性能与执行顺序保证**：许多算法对执行有所保证，通常是性能或顺序。`std::for_each` 保证每个元素被访问一次、按正向顺序。较少的算法承诺顺序，因此对不承诺的不要假设顺序。顺序保证由 `std::for_each`、`std::copy`、`std::copy_backward`、`std::move`、`std::move_backward` 提供；许多使用前向迭代器的算法隐式顺序执行。
- **C++20 的 ranges**：到处传 `arr.begin()` 和 `arr.end()` 很繁琐；C++20 的 ranges 允许直接传容器，使代码更短更清楚。
- **结论**：算法库提供大量功能，使代码更简单、更稳健。因为大多数函数用法相似，学会几个就能触类旁通。

## 最佳实践

- **Best practice**：在使用某个算法之前，先确认其性能与执行顺序的保证适用于当前用例。
- **Best practice**：优先使用算法库中的函数，而不是自己动手实现同样的功能。
- **Tip**：降序很常见，C++ 在 `<functional>` 中提供了 `std::greater`；`std::greater{}` 需要花括号，因为它是一个类型，必须先实例化为匿名对象再传给 `std::sort`。
- **As an aside**：原文附有一个外部视频链接，简要讲解各类算法（本节无其它 Best practice / Author's note / Warning 标注）。

## 代码示例

- [18-03-example1.cpp](18-03-example1.cpp)：`std::find` 查找并替换（读入两个整数），输入 `5 234` 输出 `13 90 99 234 40 80`；输入 `0 234` 输出 `Could not find 0` 与 `13 90 99 5 40 80`。
- [18-03-example2.cpp](18-03-example2.cpp)：`std::find_if` 搭配谓词 `containsNut`，输出 `Found walnut`。
- [18-03-example3.cpp](18-03-example3.cpp)：`std::count_if` 统计含 "nut" 的元素，输出 `Counted 2 nut(s)`。
- [18-03-example4.cpp](18-03-example4.cpp)：`std::sort` 配自定义比较函数 `greater`（降序），输出 `99 90 80 40 13 5`。
- [18-03-example5.cpp](18-03-example5.cpp)：用现成的 `std::greater{}` 代替自定义比较函数，输出 `99 90 80 40 13 5`。
- [18-03-example6.cpp](18-03-example6.cpp)：进阶——接受 `[begin, end)` 区间的泛型选择排序函数，输出 `1 2 4 5 9`。
- [18-03-example7.cpp](18-03-example7.cpp)：进阶——排序函数接受 `std::function<bool(int,int)>` 比较器，以 `std::greater{}` 调用得到降序 `9 5 4 2 1`。
- [18-03-example8.cpp](18-03-example8.cpp)：`std::for_each` 对每个元素翻倍，输出 `2 4 6 8`。
- [18-03-example9.cpp](18-03-example9.cpp)：C++20 `std::ranges::for_each` 直接传容器，以及用 `std::next` 跳过首元素，输出 `2 4 6 8` 与 `1 4 6 8`。

> 本节代码为按原文描述重建。

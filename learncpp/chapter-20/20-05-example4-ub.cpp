// 来源小节：20.5 Ellipsis (and why to avoid them)
// 示例说明：演示省略号的四类错误用法（原文的 Example 2-5）：
//           1) 传 double（8 字节）却用 va_arg(list, int) 读取 —— 类型不匹配；
//           2) 传完全无意义的实参（字符串、字符、指针）也能通过编译；
//           3) count 比实际参数个数大 —— 从栈上读到垃圾数据；
//           4) count 比实际参数个数小 —— 多余的值被静默丢弃。
// 原文链接：https://www.learncpp.com/cpp-tutorial/ellipsis-and-why-to-avoid-them/
// 说明：本节代码为按原文描述重建。
// **未定义行为**：省略号没有类型声明，编译器无法检查；用错误的类型读取 va_arg 是 UB，
// 因为类型决定了位模式如何被解释（double 是 8 字节，按 int 读会得到两个 4 字节的垃圾）。
// 以下是"输出依实现而定"的演示，原文在作者机器上的输出：
//   findAverage(6, 1.0, 2, 3, 4, 5, 6)                          -> 1.78782e+008
//   findAverage(6, 1.0, 2, "Hello, world!", 'G', &value, &findAverage) -> 1.79766e+008
//   findAverage(6, 1, 2, 3, 4, 5)     (count 太大)              -> 699773
//   findAverage(6, 1, 2, 3, 4, 5, 6, 7) (count 太小)            -> 3.5

#include <iostream>
#include <cstdarg> // needed to use ellipsis

double findAverage(int count, ...)
{
    int sum{ 0 };

    std::va_list list;
    va_start(list, count);

    for (int arg{ 0 }; arg < count; ++arg)
    {
        sum += va_arg(list, int);
    }

    va_end(list);

    return static_cast<double>(sum) / count;
}

int main()
{
    // --- 原文示例片段 ---
    // 1) A double among ints: type mismatch -> garbage
    std::cout << findAverage(6, 1.0, 2, 3, 4, 5, 6) << '\n';

    // 2) Nonsense arguments that still compile (garbage in, garbage out)
    int value{ 7 };
    std::cout << findAverage(6, 1.0, 2, "Hello, world!", 'G', &value, &findAverage) << '\n';

    // 3) Count is larger than the number of arguments passed: reads garbage off the stack
    std::cout << findAverage(6, 1, 2, 3, 4, 5) << '\n';

    // 4) More arguments than count claims: the extra value is silently dropped
    std::cout << findAverage(6, 1, 2, 3, 4, 5, 6, 7) << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}

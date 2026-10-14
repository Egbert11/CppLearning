// 来源小节：20.5 Ellipsis (and why to avoid them)
// 示例说明：用省略号（...）实现可变参数函数 findAverage()，并用固定的 count 参数
//           记录后面跟了多少个省略号参数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/ellipsis-and-why-to-avoid-them/
// 说明：本节代码在原文中为完整代码块，已逐字保留（仅统一了缩进）。
// 预期输出：
//   3
//   3.5

#include <iostream>
#include <cstdarg> // needed to use ellipsis

// The ellipsis must be the last parameter
// count is how many additional arguments we're passing
double findAverage(int count, ...)
{
    int sum{ 0 };

    // We access the ellipsis through a va_list, so let's declare one
    std::va_list list;

    // We initialize the va_list using va_start.  The first argument is
    // the list to initialize.  The second argument is the last non-ellipsis
    // parameter.
    va_start(list, count);

    // Loop through all the ellipsis values
    for (int arg{ 0 }; arg < count; ++arg)
    {
        // We use va_arg to get values out of our ellipsis
        // The first argument is the va_list we're using
        // The second argument is the type of the value
        sum += va_arg(list, int);
    }

    // Cleanup the va_list when we're done.
    va_end(list);

    return static_cast<double>(sum) / count;
}

int main()
{
    std::cout << findAverage(5, 1, 2, 3, 4, 5) << '\n';
    std::cout << findAverage(6, 1, 2, 3, 4, 5, 6) << '\n';

    return 0;
}

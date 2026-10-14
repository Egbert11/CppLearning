// 来源小节：20.5 Ellipsis (and why to avoid them)
// 示例说明：用哨兵值（sentinel，此处是 -1）取代 count 参数来记录省略号参数结束。
//           由于必须有一个固定参数，第一个数单独处理。
// 原文链接：https://www.learncpp.com/cpp-tutorial/ellipsis-and-why-to-avoid-them/
// 说明：本节代码在原文中为完整代码块，已逐字保留（仅统一了缩进）。
// 注意：忘记传哨兵值会导致无限循环或崩溃；只有当存在一个"超出正常范围"的值时哨兵才可行。

#include <iostream>
#include <cstdarg> // needed to use ellipsis

// The ellipsis must be the last parameter
double findAverage(int first, ...)
{
    // We have to deal with the first number specially
    int sum{ first };

    // We access the ellipsis through a va_list, so let's declare one
    std::va_list list;

    // We initialize the va_list using va_start.  The first argument is
    // the list to initialize.  The second argument is the last non-ellipsis
    // parameter.
    va_start(list, first);

    int count{ 1 };
    // Loop indefinitely
    while (true)
    {
        // We use va_arg to get values out of our ellipsis
        // The first argument is the va_list we're using
        // The second argument is the type of the value
        int arg{ va_arg(list, int) };

        // If this parameter is our sentinel value, stop looping
        if (arg == -1)
            break;

        sum += arg;
        ++count;
    }

    // Cleanup the va_list when we're done.
    va_end(list);

    return static_cast<double>(sum) / count;
}

int main()
{
    std::cout << findAverage(1, 2, 3, 4, 5, -1) << '\n';
    std::cout << findAverage(1, 2, 3, 4, 5, 6, -1) << '\n';

    return 0;
}

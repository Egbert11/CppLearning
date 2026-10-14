// 来源小节：20.5 Ellipsis (and why to avoid them)
// 示例说明：用"解码字符串"（decoder string）编码省略号参数的数量与类型，
//           从而支持混合类型（如 'i' 表示 int，'d' 表示 double）。
//           这正是 printf 的做法，晦涩且一旦不匹配就会出错。
// 原文链接：https://www.learncpp.com/cpp-tutorial/ellipsis-and-why-to-avoid-them/
// 说明：本节代码在原文中为完整代码块，已逐字保留（仅统一了缩进）。
// 预期输出：
//   3
//   3.5
//   3.2

#include <iostream>
#include <string_view>
#include <cstdarg> // needed to use ellipsis

// The ellipsis must be the last parameter
double findAverage(std::string_view decoder, ...)
{
    double sum{ 0 };

    // We access the ellipsis through a va_list, so let's declare one
    std::va_list list;

    // We initialize the va_list using va_start.  The first argument is
    // the list to initialize.  The second argument is the last non-ellipsis
    // parameter.
    va_start(list, decoder);

    for (auto codetype : decoder)
    {
        switch (codetype)
        {
        case 'i':
            sum += va_arg(list, int);
            break;

        case 'd':
            sum += va_arg(list, double);
            break;
        }
    }

    // Cleanup the va_list when we're done.
    va_end(list);

    return sum / std::size(decoder);
}

int main()
{
    std::cout << findAverage("iiiii", 1, 2, 3, 4, 5) << '\n';
    std::cout << findAverage("iiiiii", 1, 2, 3, 4, 5, 6) << '\n';
    std::cout << findAverage("iiddi", 1, 2, 3.5, 4.5, 5) << '\n';

    return 0;
}

// 来源小节：8.11 Break and continue
// 示例说明：与示例 9 相同的逻辑，改用 continue，无需嵌套块
// 原文链接：https://www.learncpp.com/cpp-tutorial/break-and-continue/
// 预期输出：1 2 3 5 6 7 9（各一行）

#include <iostream>

int main()
{
    for (int count{ 0 }; count < 10; ++count)
    {
        // if the number is divisible by 4, skip this iteration
        if ((count % 4) == 0)
            continue;

        // no nested block needed

        std::cout << count << '\n';
    }

    return 0;
}

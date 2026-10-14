// 来源小节：8.11 Break and continue
// 示例说明：用 continue 跳过能被 4 整除的迭代
// 原文链接：https://www.learncpp.com/cpp-tutorial/break-and-continue/
// 预期输出：1 2 3 5 6 7 9（各一行）

#include <iostream>

int main()
{
    for (int count{ 0 }; count < 10; ++count)
    {
        // if the number is divisible by 4, skip this iteration
        if ((count % 4) == 0)
            continue; // go to next iteration

        // If the number is not divisible by 4, keep going
        std::cout << count << '\n';

        // The continue statement jumps to here
    }

    return 0;
}

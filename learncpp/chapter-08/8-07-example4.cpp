// 来源小节：8.7 Goto statements
// 示例说明：进阶——goto 少有的合理用途：一次性跳出多层嵌套循环，而又不退出整个函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/goto-statements/
//
// 编译：g++ -std=c++20 -Wall 8-07-example4.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出（前若干行）：
//   1 * 1 is 1
//   1 * 2 is 2
//   1 * 3 is 3
//   1 * 4 is 4
//   Incrementing the first factor.
//   2 * 1 is 2
//   2 * 2 is 4
//   ...
//   3 * 3 is 9
//   Found product divisible by 9.  Ending early.
//   And we're done.

#include <iostream>

int main()
{
    for (int i = 1; i < 5; ++i)
    {
        for (int j = 1; j < 5; ++j)
        {
            std::cout << i << " * " << j << " is " << i*j << '\n';

            // If the product is divisible by 9, jump to the "end" label
            if (i*j % 9 == 0)
            {
                std::cout << "Found product divisible by 9.  Ending early.\n";
                goto end;
            }
        }

        std::cout << "Incrementing the first factor.\n";
    }

end:
    std::cout << "And we're done." << '\n';

    return 0;
}

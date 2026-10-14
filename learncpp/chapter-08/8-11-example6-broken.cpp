// 来源小节：8.11 Break and continue
// 示例说明：while 循环中使用 continue 的死循环 bug。
//           当 count 达到 5 时 continue 跳过后面的 ++count，count 永不再增长。
// 原文链接：https://www.learncpp.com/cpp-tutorial/break-and-continue/
// 注意：这是有意演示的无限循环，运行不会自行结束——请勿运行到结束。
// 预期输出（然后无限循环）：0 1 2 3 4

#include <iostream>

int main()
{
    int count{ 0 };
    while (count < 10)
    {
        if (count == 5)
            continue; // jump to end of loop body

        std::cout << count << '\n';

        ++count; // this statement is never executed after count reaches 5

        // The continue statement jumps to here
    }

    return 0;
}

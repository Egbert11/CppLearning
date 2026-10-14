// 来源小节：8.10 For statements
// 示例说明：条件用 operator!= 的循环。循环体跳过 10 后，i 变为 11，
//           条件 i != 10 永远为真，循环永不结束，形成死循环。
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/
// 注意：这是有意演示的无限循环，运行不会自行结束——请勿运行到结束。
// 预期输出（然后无限循环）：0 1 2 3 4 5 6 7 8 9 11 12 13 ...

#include <iostream>

int main()
{
    for (int i { 0 }; i != 10; ++i) // condition uses operator!=
    {
        std::cout << i << ' ';

        // if i is 9, then we set it to 11 to jump over the sentinel value of 10
        if (i == 9)
            ++i; // jump over value 10 -> i becomes 10, then the loop's ++i makes it 11
    }

    std::cout << '\n';

    return 0;
}

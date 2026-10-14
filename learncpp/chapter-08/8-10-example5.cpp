// 来源小节：8.10 For statements
// 示例说明：每次迭代把循环变量增加 2
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/
// 预期输出：0 2 4 6 8 10

#include <iostream>

int main()
{
    for (int i{ 0 }; i <= 10; i += 2) // increment by 2 each iteration
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}

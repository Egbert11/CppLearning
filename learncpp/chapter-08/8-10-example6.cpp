// 来源小节：8.10 For statements
// 示例说明：同一行为分别用 operator< 和 operator!= 写出的两个循环
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/
// 预期输出（两行相同）：0 1 2 3 4 5 6 7 8 9
// 说明：本例中 i 不会跳过 10，故两个循环都能正常终止。

#include <iostream>

int main()
{
    for (int i { 0 }; i < 10; ++i) // uses operator<
        std::cout << i << ' ';

    std::cout << '\n';

    for (int i { 0 }; i != 10; ++i) // uses operator!=
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}

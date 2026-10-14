// 来源小节：9.2 Code coverage
// 示例说明：if / else if / else 链——需要三次调用（分别命中 x>y、x<y、x==y）
//           才能达到完整的分支覆盖。
// 原文链接：https://www.learncpp.com/cpp-tutorial/code-coverage/
//
// 编译：g++ -std=c++20 -Wall 9-02-example3.cpp -o a
// 预期输出：
//   7 is greater than 5
//   5 is less than 7
//   5 is equal to 5
//
// 本节代码为按原文描述重建。

#include <iostream>

void compare(int x, int y)
{
    if (x > y)
        std::cout << x << " is greater than " << y << '\n';  // case 1
    else if (x < y)
        std::cout << x << " is less than " << y << '\n';     // case 2
    else
        std::cout << x << " is equal to " << y << '\n';      // case 3
}

int main()
{
    // three calls needed for full branch coverage
    compare(7, 5);  // case 1
    compare(5, 7);  // case 2
    compare(5, 5);  // case 3

    return 0;
}

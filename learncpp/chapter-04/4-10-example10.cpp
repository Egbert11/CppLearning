// 来源小节：4.10 Introduction to if statements
// 示例说明：在 abs() 中有条件地使用提前返回（仅当 x < 0 时提前返回）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/
// 输出：
//   4
//   3

#include <iostream>

// returns the absolute value of x
int abs(int x)
{
    if (x < 0)
        return -x; // early return (only when x < 0)

    return x;
}

int main()
{
    std::cout << abs(4) << '\n';  // prints 4
    std::cout << abs(-3) << '\n'; // prints 3

    return 0;
}

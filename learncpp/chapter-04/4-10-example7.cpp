// 来源小节：4.10 Introduction to if statements
// 示例说明：用 if-else 改进的 isEqual，输出可读的比较结论。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/
// 两次运行：
//   Enter an integer: 5
//   Enter another integer: 5
//   5 and 5 are equal
//
//   Enter an integer: 6
//   Enter another integer: 4
//   6 and 4 are not equal

#include <iostream>

// returns true if x and y are equal, false otherwise
bool isEqual(int x, int y)
{
    return x == y; // operator== returns true if x equals y, and false otherwise
}

int main()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y {};
    std::cin >> y;

    if (isEqual(x, y))
        std::cout << x << " and " << y << " are equal\n";
    else
        std::cout << x << " and " << y << " are not equal\n";

    return 0;
}

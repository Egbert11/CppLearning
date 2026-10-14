// 来源小节：4.10 Introduction to if statements
// 示例说明：上一课的 isEqual 程序（直接用 cout 打印布尔结果，不用 if）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/

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

    std::cout << std::boolalpha; // print bools as true or false

    std::cout << x << " and " << y << " are equal? ";
    std::cout << isEqual(x, y); // will return true or false

    std::cout << '\n';

    return 0;
}

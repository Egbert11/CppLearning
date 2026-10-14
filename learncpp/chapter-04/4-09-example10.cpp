// 来源小节：4.9 Boolean values
// 示例说明：返回 bool 的 isEqual 函数，判断两个整数是否相等。
// 原文链接：https://www.learncpp.com/cpp-tutorial/boolean-values/
// 示例输出：
//   Enter an integer: 5
//   Enter another integer: 5
//   5 and 5 are equal? true
//
//   Enter an integer: 6
//   Enter another integer: 4
//   6 and 4 are equal? false

#include <iostream>

// returns true if x and y are equal, false otherwise
bool isEqual(int x, int y)
{
    return x == y; // operator== returns true if x equals y, and false otherwise
}

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    std::cout << std::boolalpha; // print bools as true or false

    std::cout << x << " and " << y << " are equal? ";
    std::cout << isEqual(x, y) << '\n'; // will return true or false

    return 0;
}

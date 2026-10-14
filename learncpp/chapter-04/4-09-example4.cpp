// 来源小节：4.9 Boolean values
// 示例说明：打印布尔值（默认按 0/1 输出）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/boolean-values/
// 预期输出：
//   1
//   0
//   0
//   1

#include <iostream>

int main()
{
    std::cout << true << '\n';  // true evaluates to 1
    std::cout << !true << '\n'; // !true evaluates to 0

    bool b {false};
    std::cout << b << '\n';  // b is false, which evaluates to 0
    std::cout << !b << '\n'; // !b is true, which evaluates to 1

    return 0;
}

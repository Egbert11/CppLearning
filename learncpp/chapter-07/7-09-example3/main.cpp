// 来源小节：7.9 Inline functions and variables
// 示例说明：main.cpp —— 前向声明 circumference()，并内联定义 pi()，打印 pi() 与 circumference(2.0)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 4）。
// 注意：pi() 在 main.cpp 与 math.cpp 中都以 inline 定义；两处定义必须完全相同。
//       若去掉两处 inline，则违反 ODR，会得到链接错误（重复定义 pi()）。
// 编译：g++ -std=c++20 -Wall 7-09-example3/main.cpp 7-09-example3/math.cpp -o main
// 预期输出：
// 3.14159
// 12.5664

#include <iostream>

double circumference(double radius); // 前向声明

inline double pi() { return 3.14159; }

int main()
{
    std::cout << pi() << '\n';
    std::cout << circumference(2.0) << '\n';

    return 0;
}

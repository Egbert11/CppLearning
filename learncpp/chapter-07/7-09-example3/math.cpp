// 来源小节：7.9 Inline functions and variables
// 示例说明：math.cpp —— 再次内联定义 pi()，并定义 circumference()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 4）。
// 编译：g++ -std=c++20 -Wall 7-09-example3/main.cpp 7-09-example3/math.cpp -o main

inline double pi() { return 3.14159; }

double circumference(double radius)
{
    return 2.0 * pi() * radius;
}

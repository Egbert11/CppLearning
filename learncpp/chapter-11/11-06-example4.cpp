// 来源小节：11.6 Function templates
// 示例说明：完整的函数模板 max<T>——用 int 与 double 实参分别实例化出不同函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-templates/
//
// 编译：g++ -std=c++20 -Wall 11-06-example4.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 预期输出：
//   2
//   2.5

#include <iostream>

template <typename T> // this is the template parameter declaration defining T as a type template parameter
T max(T x, T y) // this is the function template definition for max<T>
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max(1, 2) << '\n';     // instantiates and calls max<int>
    std::cout << max(1.5, 2.5) << '\n'; // instantiates and calls max<double>

    return 0;
}

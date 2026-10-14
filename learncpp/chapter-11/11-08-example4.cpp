// 来源小节：11.8 Function templates with multiple template types
// 示例说明：非模板函数 double max(double, double) 可以接受 max(2, 3.5)，
//           因为普通重载决议会把 int 隐式转换为 double
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/
// 本节代码为按原文描述重建
// 预期输出：3.5

#include <iostream>

double max(double x, double y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max(2, 3.5) << '\n'; // 普通函数：int 被隐式转换为 double

    return 0;
}

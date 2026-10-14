// 来源小节：4.8 Floating point numbers
// 示例说明：打印浮点数。展示 cout 省略小数零（5.0 打成 5）以及对很大的数改用科学计数法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/floating-point-numbers/
// 预期输出：
//   5
//   6.7
//   9.87654e+06
// 说明：本文件为重建代码。

#include <iostream>

int main()
{
    std::cout << 5.0 << '\n';
    std::cout << 6.7f << '\n';
    std::cout << 9876543.21 << '\n';

    return 0;
}

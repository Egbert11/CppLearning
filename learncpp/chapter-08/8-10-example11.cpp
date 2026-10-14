// 来源小节：8.10 For statements
// 示例说明：多个计数器——init 中定义 x、y，end-expression 用逗号运算符同时更新
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/
// 预期输出：每行一对，从 "0 9" 到 "9 0"

#include <iostream>

int main()
{
    for (int x{ 0 }, y{ 9 }; x < 10; ++x, --y)
        std::cout << x << ' ' << y << '\n';

    return 0;
}

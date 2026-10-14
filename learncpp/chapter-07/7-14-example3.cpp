// 来源小节：7.14 Unnamed and inline namespaces
// 示例说明：未加任何命名空间的基线函数，用于引出后面的"版本管理"话题。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unnamed-and-inline-namespaces/
//
// 本节示例为按原文描述重建（对应原文 Example 3）。
// 预期输出：v1

#include <iostream>

void doSomething()
{
    std::cout << "v1\n";
}

int main()
{
    doSomething();

    return 0;
}

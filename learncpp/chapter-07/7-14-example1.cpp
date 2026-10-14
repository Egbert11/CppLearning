// 来源小节：7.14 Unnamed and inline namespaces
// 示例说明：匿名命名空间中的函数可在本文件内不加前缀直接调用（等同内部链接）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unnamed-and-inline-namespaces/
//
// 本节示例为按原文描述重建（对应原文 Example 1）。
// 预期输出：v1

#include <iostream>

namespace // 匿名命名空间
{
    void doSomething() // 只能在本文件中访问
    {
        std::cout << "v1\n";
    }
}

int main()
{
    doSomething(); // 可以不加命名空间前缀调用 doSomething()

    return 0;
}

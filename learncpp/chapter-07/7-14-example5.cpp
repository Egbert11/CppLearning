// 来源小节：7.14 Unnamed and inline namespaces
// 示例说明：V1 为普通、V2 为 inline；非限定调用 doSomething() 现在解析到 V2。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unnamed-and-inline-namespaces/
//
// 本节示例为按原文描述重建（对应原文 Example 5）。
// 预期输出：
// V1
// V2
// V2

#include <iostream>

namespace V1 // 声明一个普通命名空间 V1
{
    void doSomething()
    {
        std::cout << "V1\n";
    }
}

inline namespace V2 // 声明一个名为 V2 的内联命名空间
{
    void doSomething()
    {
        std::cout << "V2\n";
    }
}

int main()
{
    V1::doSomething(); // 调用 V1 版本的 doSomething()
    V2::doSomething(); // 调用 V2 版本的 doSomething()

    doSomething(); // 调用内联版本的 doSomething()（即 V2）

    return 0;
}

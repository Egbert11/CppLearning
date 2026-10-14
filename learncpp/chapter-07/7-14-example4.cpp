// 来源小节：7.14 Unnamed and inline namespaces
// 示例说明：V1 为 inline、V2 为普通命名空间；非限定调用 doSomething() 解析到内联版本（V1）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unnamed-and-inline-namespaces/
//
// 本节示例为按原文描述重建（对应原文 Example 4）。
// 预期输出：
// V1
// V2
// V1

#include <iostream>

inline namespace V1 // 声明一个名为 V1 的内联命名空间
{
    void doSomething()
    {
        std::cout << "V1\n";
    }
}

namespace V2 // 声明一个普通命名空间 V2
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

    doSomething(); // 调用内联版本的 doSomething()（即 V1）

    return 0;
}

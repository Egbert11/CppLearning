// 来源小节：7.14 Unnamed and inline namespaces
// 示例说明：既 inline 又匿名的命名空间。其内容具有内部链接，且没有名字，
//           因此无法用 V2:: 前缀访问（本示例中不存在 V2 这个名字）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unnamed-and-inline-namespaces/
//
// 本节示例为按原文描述重建（对应原文 Example 6）。
// 预期输出：
// V1
// V2

#include <iostream>

namespace V1 // 声明一个普通命名空间 V1
{
    void doSomething()
    {
        std::cout << "V1\n";
    }
}

inline namespace // 声明一个内联的匿名命名空间
{
    void doSomething() // 具有内部链接
    {
        std::cout << "V2\n";
    }
}

int main()
{
    V1::doSomething(); // 调用 V1 版本的 doSomething()
    // 本例中没有 V2，因此无法使用 V2:: 作为命名空间前缀

    doSomething(); // 调用内联版本的 doSomething()（即匿名命名空间中的那个）

    return 0;
}

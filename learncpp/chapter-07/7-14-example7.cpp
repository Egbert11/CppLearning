// 来源小节：7.14 Unnamed and inline namespaces
// 示例说明：更推荐的写法 —— 在 inline 的 V2 内嵌套匿名命名空间，效果与"inline 匿名"相同，
//           但保留了一个显式命名空间名 V2（可用 V2:: 前缀）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unnamed-and-inline-namespaces/
//
// 本节示例为按原文描述重建（对应原文 Example 7）。
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
    namespace // 匿名命名空间
    {
        void doSomething() // 具有内部链接
        {
            std::cout << "V2\n";
        }
    }
}

int main()
{
    V1::doSomething(); // 调用 V1 版本的 doSomething()
    V2::doSomething(); // 调用 V2 版本的 doSomething()

    doSomething(); // 调用内联版本的 doSomething()（即 V2）

    return 0;
}

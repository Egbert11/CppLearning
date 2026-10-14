// 来源小节：20.7 Lambda captures
// 示例说明：lambda 是对象，可以被拷贝；拷贝会复制当时的内部状态，于是状态会分叉。
//           Warning：被捕获的变量是 lambda 的对象成员，所以它们的值会跨多次调用持续存在。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lambda-captures/
// 说明：本节代码为按原文描述重建。
// 预期输出：
//   1
//   2
//   2

#include <iostream>

int main()
{
    int i{ 0 };

    // --- 原文示例片段 ---
    // Create a new lambda named count
    auto count{ [i]() mutable {
        std::cout << ++i << '\n';
    } };

    count(); // invoke count -- prints 1

    auto otherCount{ count }; // create a copy of count (which currently holds i == 1)

    // invoke both count and the copy
    count();      // prints 2
    otherCount(); // prints 2 (the copy has its own, independent i)
    // --- 原文示例片段结束 ---

    return 0;
}

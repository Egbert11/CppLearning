// 来源小节：20.7 Lambda captures
// 示例说明：解决拷贝问题的方式一——直接把 lambda 存进 std::function 变量，
//           这样就不再每次构造临时对象，状态得以保持。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lambda-captures/
// 说明：本节代码为按原文描述重建。
// 预期输出：
//   1
//   2
//   3

#include <functional>
#include <iostream>

void myInvoke(const std::function<void()>& fn)
{
    fn();
}

int main()
{
    int i{ 0 };

    // --- 原文示例片段 ---
    // Store the lambda in a std::function so there is no per-call copy
    std::function count{ [i]() mutable {
        std::cout << ++i << '\n';
    } };

    myInvoke(count);
    myInvoke(count);
    myInvoke(count);
    // --- 原文示例片段结束 ---

    return 0;
}

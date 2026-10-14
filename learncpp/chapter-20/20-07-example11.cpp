// 来源小节：20.7 Lambda captures
// 示例说明：库函数可能拷贝函数对象。把有 mutable 捕获的 lambda 传给
//           const std::function<void()>& 形参时，每次调用都会从 count 重新构造一个临时
//           std::function，于是每次都从初始状态开始。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lambda-captures/
// 说明：本节代码为按原文描述重建。
// 预期输出：
//   1
//   1
//   1

#include <functional>
#include <iostream>

// --- 原文示例片段 ---
void myInvoke(const std::function<void()>& fn)
{
    fn();
}
// --- 原文示例片段结束 ---

int main()
{
    int i{ 0 };

    // Increments and prints its local copy of @i.
    auto count{ [i]() mutable {
        std::cout << ++i << '\n';
    } };

    // Each call converts @count into a fresh temporary std::function,
    // so every call starts from the same captured state.
    myInvoke(count);
    myInvoke(count);
    myInvoke(count);

    return 0;
}

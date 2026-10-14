// 来源小节：20.7 Lambda captures
// 示例说明：解决拷贝问题的方式二——用 std::ref 包一层，把 lambda 按引用传给库函数。
//           即使形参是按值传递的也能生效。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lambda-captures/
// 说明：本节代码为按原文描述重建。
// Rule：标准库函数可能拷贝函数对象；若 lambda 含有 mutable 捕获，请用 std::ref 按引用传递。
// 预期输出：
//   1
//   2
//   3

#include <functional>
#include <iostream>

// Note: now the parameter is taken by value
void myInvoke(std::function<void()> fn)
{
    fn();
}

int main()
{
    int i{ 0 };

    auto count{ [i]() mutable {
        std::cout << ++i << '\n';
    } };

    // --- 原文示例片段 ---
    // std::ref wraps the lambda in a std::reference_wrapper so the copy
    // made by myInvoke refers to the same lambda object.
    myInvoke(std::ref(count));
    myInvoke(std::ref(count));
    myInvoke(std::ref(count));
    // --- 原文示例片段结束 ---

    return 0;
}

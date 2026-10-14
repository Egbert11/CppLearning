// ============================================================
// 来源小节：22.1 Introduction to smart pointers and move semantics
// 示例说明：坏实践演示——函数中途 return 会跳过末尾的 delete，
//           从而每次调用都泄漏一个 Resource。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-smart-pointers-move-semantics/
// 预期输出（输入 0 时）：
//   Resource acquired
//   Enter an integer: 0
//   （不会出现 "Resource destroyed" —— 发生内存泄漏）
// 备注：本节代码为按原文描述重建（原 Example 2）。勿照抄这种写法。
// ============================================================
#include <iostream>

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

void someFunction()
{
    Resource* ptr{ new Resource() };

    int x{};
    std::cout << "Enter an integer: ";
    std::cin >> x;

    if (x == 0)
        return; // the function returns early, and ptr won't be deleted!

    // do stuff with ptr here

    delete ptr;
}

int main()
{
    someFunction();

    return 0;
}

// ============================================================
// 来源小节：22.1 Introduction to smart pointers and move semantics
// 示例说明：坏实践演示——在 delete 之前抛出异常，函数直接终止，
//           末尾的 delete 永远不会执行，造成内存泄漏。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-smart-pointers-move-semantics/
// 预期输出（输入 0 时）：
//   Resource acquired
//   Enter an integer: 0
//   Exception thrown!
//   （不会出现 "Resource destroyed" —— 发生内存泄漏）
// 备注：本节代码为按原文描述重建（原 Example 3）。勿照抄这种写法。
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
        throw 0; // 函数提前退出，ptr 不会被 delete！

    // do stuff with ptr here

    delete ptr;
}

int main()
{
    try
    {
        someFunction();
    }
    catch (int)
    {
        std::cout << "Exception thrown!\n";
    }

    return 0;
}

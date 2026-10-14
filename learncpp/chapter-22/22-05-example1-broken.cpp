// ============================================================
// 来源小节：22.5 std::unique_ptr
// 示例说明：坏实践演示——裸指针 new 之后中途 throw，函数提前退出，
//           末尾的 delete 不会执行，Resource 泄漏。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
// 预期输出（输入 0 时）：
//   Resource acquired
//   Caught exception
//   （不会出现 "Resource destroyed" —— 内存泄漏）
// 备注：本节代码为按原文描述重建（原 Example 1）。
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
    auto* ptr{ new Resource() };

    int x{};
    std::cout << "Enter an integer: ";
    std::cin >> x;

    if (x == 0)
        throw 0; // the function returns early, and ptr won't be deleted!

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
        std::cout << "Caught exception\n";
    }

    return 0;
}

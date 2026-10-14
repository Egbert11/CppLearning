// ============================================================
// 来源小节：22.1 Introduction to smart pointers and move semantics
// 示例说明：手动管理动态内存——用 new 分配 Resource，用完 delete 释放。
//           "哑指针"的正常用法，但必须自己记得在每条退出路径上释放。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-smart-pointers-move-semantics/
// 预期输出：
//   Resource acquired
//   Resource destroyed
// 备注：本节代码为按原文描述重建（合并原文 Example 1）。
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
    Resource* ptr{ new Resource() }; // 动态分配一个 Resource

    // do stuff with ptr here

    delete ptr; // 手动释放
}

int main()
{
    someFunction();
    return 0;
}

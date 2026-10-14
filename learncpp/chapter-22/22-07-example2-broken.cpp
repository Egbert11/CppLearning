// ============================================================
// 来源小节：22.7 Circular dependency issues with std::shared_ptr, and std::weak_ptr
// 示例说明：坏实践演示——Resource 里有一个指向"包含它的对象自身"的
//           std::shared_ptr，形成最简化的自循环；资源永远不会被销毁。
// 原文链接：https://www.learncpp.com/cpp-tutorial/circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr/
// 预期输出：
//   Resource acquired
//   （不会出现 "Resource destroyed" —— 自循环导致泄漏）
// 备注：本节代码为按原文描述重建（原 Example 2）。
// ============================================================
#include <iostream>
#include <memory> // for std::shared_ptr

class Resource
{
public:
    std::shared_ptr<Resource> m_ptr{}; // initially created empty

    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    auto ptr1{ std::make_shared<Resource>() };

    ptr1->m_ptr = ptr1; // m_ptr is now sharing the Resource that contains it

    return 0;
}

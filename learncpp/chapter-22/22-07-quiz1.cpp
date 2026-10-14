// ============================================================
// 来源小节：22.7 Circular dependency issues with std::shared_ptr, and std::weak_ptr（本节测验·解答）
// 示例说明：把 Example 2 中 Resource 的 m_ptr 从 std::shared_ptr 改为
//           std::weak_ptr<Resource>，使 m_ptr 不再维持 Resource 的存活，
//           从而打破自循环引用，资源得以正常销毁。
// 原文链接：https://www.learncpp.com/cpp-tutorial/circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr/
// 预期输出：
//   Resource acquired
//   Resource destroyed
// 备注：本节代码为按原文描述重建（原 Example 6，即测验解答）。
// ============================================================
#include <iostream>
#include <memory> // for std::shared_ptr and std::weak_ptr

class Resource
{
public:
    std::weak_ptr<Resource> m_ptr{}; // use std::weak_ptr so m_ptr doesn't keep the Resource alive

    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    auto ptr1{ std::make_shared<Resource>() };

    ptr1->m_ptr = ptr1; // m_ptr is now observing the Resource that contains it

    return 0;
}

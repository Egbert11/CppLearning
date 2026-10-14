// ============================================================
// 来源小节：22.6 std::shared_ptr
// 示例说明：用 std::make_shared 创建 ptr1，再拷贝出 ptr2。写法更安全
//           （不可能意外造出两个互不知情的指针），输出与 Example 1 相同。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdshared_ptr/
// 预期输出：
//   Resource acquired
//   Killing one shared pointer
//   Killing another shared pointer
//   Resource destroyed
// 备注：本节代码为按原文描述重建（原 Example 3）。
// ============================================================
#include <iostream>
#include <memory> // for std::shared_ptr

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    // allocate a Resource object and have it owned by std::shared_ptr
    auto ptr1{ std::make_shared<Resource>() };
    {
        auto ptr2{ ptr1 }; // create ptr2 using copy of ptr1

        std::cout << "Killing one shared pointer\n";
    } // ptr2 goes out of scope here, but nothing happens

    std::cout << "Killing another shared pointer\n";

    return 0;
} // ptr1 goes out of scope here, and the allocated Resource is destroyed

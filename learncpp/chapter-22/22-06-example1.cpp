// ============================================================
// 来源小节：22.6 std::shared_ptr
// 示例说明：两个 shared_ptr 通过"拷贝构造"共同拥有同一 Resource。
//           ptr2 离开内层作用域时不释放资源；ptr1 离开时才释放。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdshared_ptr/
// 预期输出：
//   Resource acquired
//   Killing one shared pointer
//   Killing another shared pointer
//   Resource destroyed
// 备注：本节代码为按原文描述重建（原 Example 1）。
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
    Resource* res{ new Resource };
    std::shared_ptr<Resource> ptr1{ res };
    {
        std::shared_ptr<Resource> ptr2{ ptr1 }; // make another std::shared_ptr pointing to the same thing

        std::cout << "Killing one shared pointer\n";
    } // ptr2 goes out of scope here, but nothing happens

    std::cout << "Killing another shared pointer\n";

    return 0;
} // ptr1 goes out of scope here, and the allocated Resource is destroyed

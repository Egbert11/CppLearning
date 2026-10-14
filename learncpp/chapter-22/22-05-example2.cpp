// ============================================================
// 来源小节：22.5 std::unique_ptr
// 示例说明：把 new 出来的 Resource 交给栈上的 std::unique_ptr 拥有，
//           离开作用域时自动释放，无需手动 delete。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
// 预期输出：
//   Resource acquired
//   Resource destroyed
// 备注：本节代码为按原文描述重建（原 Example 2）。
// ============================================================
#include <iostream>
#include <memory> // for std::unique_ptr

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    // allocate a Resource object and have it owned by std::unique_ptr
    std::unique_ptr<Resource> res{ new Resource() };

    return 0;
} // res goes out of scope here, and the allocated Resource is destroyed

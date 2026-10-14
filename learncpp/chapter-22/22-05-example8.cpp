// ============================================================
// 来源小节：22.5 std::unique_ptr
// 示例说明：把 unique_ptr 按值传入函数会转移所有权——必须用 std::move；
//           资源在函数返回（形参析构）时被销毁，早于函数后半段输出。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
// 预期输出：
//   Resource acquired
//   I am a resource
//   Resource destroyed
//   Ending program
// 备注：本节代码为按原文描述重建（原 Example 8）。
// ============================================================
#include <iostream>
#include <memory>  // for std::unique_ptr
#include <utility> // for std::move

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

std::ostream& operator<<(std::ostream& out, const Resource&)
{
    out << "I am a resource";
    return out;
}

// This function takes ownership of the Resource, which isn't what we want
void takeOwnership(std::unique_ptr<Resource> res)
{
    if (res)
        std::cout << *res << '\n';
} // the Resource is destroyed here

int main()
{
    auto ptr{ std::make_unique<Resource>() };

    // takeOwnership(ptr);          // This doesn't work, need to use move semantics
    takeOwnership(std::move(ptr));  // ok: use move semantics

    std::cout << "Ending program\n";

    return 0;
}

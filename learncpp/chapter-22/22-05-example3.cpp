// ============================================================
// 来源小节：22.5 std::unique_ptr
// 示例说明：unique_ptr 禁用拷贝，转移所有权必须用 std::move；
//           转移后源变为 null。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
// 预期输出：
//   Resource acquired
//   res1 is not null
//   res2 is null
//   Ownership transferred
//   res1 is null
//   res2 is not null
//   Resource destroyed
// 备注：本节代码为按原文描述重建（原 Example 3）。
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

int main()
{
    std::unique_ptr<Resource> res1{ new Resource{} }; // Resource created here
    std::unique_ptr<Resource> res2{};                // Start as nullptr

    std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
    std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

    // res2 = res1;              // Won't compile: copy assignment is disabled
    res2 = std::move(res1);      // res2 assumes ownership, res1 is set to null

    std::cout << "Ownership transferred\n";

    std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
    std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

    return 0;
} // Resource destroyed here when res2 goes out of scope

// ============================================================
// 来源小节：22.5 std::unique_ptr
// 示例说明：先用 `if (res)`（隐式转 bool）确认 unique_ptr 非空，
//           再用 `*res` 解引用所管理的 Resource。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
// 预期输出：
//   Resource acquired
//   I am a resource
//   Resource destroyed
// 备注：本节代码为按原文描述重建（原 Example 4）。
// ============================================================
#include <iostream>
#include <memory> // for std::unique_ptr

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

int main()
{
    std::unique_ptr<Resource> res{ new Resource{} };

    if (res) // use implicit cast to bool to ensure res contains a Resource
        std::cout << *res << '\n'; // print the Resource that res is owning

    return 0;
}

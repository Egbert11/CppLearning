// ============================================================
// 来源小节：22.5 std::unique_ptr
// 示例说明：如果函数只是"使用"资源而不涉及其所有权，就传资源本身
//           （这里用 get() 取出裸指针），让函数不必关心调用方的所有权方案。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
// 预期输出：
//   Resource acquired
//   I am a resource
//   Ending program
//   Resource destroyed
// 备注：本节代码为按原文描述重建（原 Example 9）。
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

// The function only uses the resource, so we'll accept a pointer to the resource,
// not a reference to the whole std::unique_ptr<Resource>
void useResource(const Resource* res)
{
    if (res)
        std::cout << *res << '\n';
    else
        std::cout << "No resource\n";
}

int main()
{
    auto ptr{ std::make_unique<Resource>() };

    useResource(ptr.get()); // note: get() used here to get a pointer to the Resource

    std::cout << "Ending program\n";

    return 0;
} // The Resource is destroyed here

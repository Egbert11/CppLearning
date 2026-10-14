// ============================================================
// 来源小节：22.5 std::unique_ptr
// 示例说明：unique_ptr 可以按值从函数返回——C++14 及更早用移动语义转移
//           所有权，C++17 起返回值会被拷贝省略。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
// 预期输出：
//   Resource acquired
//   Resource destroyed
// 备注：本节代码为按原文描述重建（原 Example 7），补上 Resource 定义与输出。
// ============================================================
#include <iostream>
#include <memory> // for std::unique_ptr

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

std::unique_ptr<Resource> createResource()
{
    return std::make_unique<Resource>();
}

int main()
{
    auto ptr{ createResource() };

    // do whatever

    return 0;
}

// ============================================================
// 来源小节：22.5 std::unique_ptr
// 示例说明：未定义行为演示——手动 delete 了 unique_ptr 正在管理的资源，
//           之后 unique_ptr 析构时又会 delete 一次，导致二次释放。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
// 预期输出：
//   Resource acquired
//   Resource destroyed
//   Resource destroyed   <-- 二次释放，UB，通常随后崩溃
// 备注：本节代码为按原文描述重建（原 Example 11）。属于未定义行为，
//       实际结果依实现而定，请勿运行/勿照抄。
// ============================================================
#include <iostream>
#include <memory>

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    Resource* res{ new Resource() };
    std::unique_ptr<Resource> res1{ res };
    delete res; // 绕过 unique_ptr 手动删除 -> UB

    return 0;
} // res1 析构时再次 delete

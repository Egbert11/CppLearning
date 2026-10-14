// ============================================================
// 来源小节：22.5 std::unique_ptr
// 示例说明：未定义行为演示——两个 unique_ptr 各自以为自己是资源的唯一
//           拥有者，作用域结束时都去 delete 同一对象，导致二次释放。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
// 预期输出：
//   Resource acquired
//   Resource destroyed
//   Resource destroyed   <-- 二次释放，UB，通常随后崩溃
// 备注：本节代码为按原文描述重建（原 Example 10）。属于未定义行为，
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
    std::unique_ptr<Resource> res2{ res }; // 两个 unique_ptr 拥有同一资源 -> UB

    return 0;
}

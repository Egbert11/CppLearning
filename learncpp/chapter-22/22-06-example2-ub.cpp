// ============================================================
// 来源小节：22.6 std::shared_ptr
// 示例说明：未定义行为演示——用同一个裸指针 res 分别构造 ptr1 与 ptr2。
//           两者各自分配独立控制块，都以为自己唯一拥有资源，于是各自
//           析构时都去 delete 一次，造成二次释放（原文称随后会崩溃）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdshared_ptr/
// 预期输出：
//   Resource acquired
//   Killing one shared pointer
//   Resource destroyed
//   Killing another shared pointer
//   Resource destroyed   <-- 二次释放，UB，通常随后崩溃
// 备注：本节代码为按原文描述重建（原 Example 2）。属于未定义行为，
//       实际结果依实现而定，请勿运行/勿照抄。
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
    Resource* res{ new Resource };
    std::shared_ptr<Resource> ptr1{ res };
    {
        std::shared_ptr<Resource> ptr2{ res }; // create ptr2 directly from res (instead of ptr1)

        std::cout << "Killing one shared pointer\n";
    } // ptr2 goes out of scope here, and the allocated Resource is destroyed

    std::cout << "Killing another shared pointer\n";

    return 0;
} // ptr1 goes out of scope here, and the allocated Resource is destroyed again

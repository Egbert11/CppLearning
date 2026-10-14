// ============================================================
// 来源小节：22.7 Circular dependency issues with std::shared_ptr, and std::weak_ptr
// 示例说明：对比 weak_ptr 与裸指针——对象销毁后，裸指针仍"看起来非空"
//           （悬垂，无法察觉）；weak_ptr 的 expired() 能正确报告对象已失效。
// 原文链接：https://www.learncpp.com/cpp-tutorial/circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr/
// 预期输出：
//   Resource acquired
//   Resource destroyed
//   Our dumb ptr is: non-null
//   Resource acquired
//   Resource destroyed
//   Our weak ptr is: expired
// 备注：本节代码为按原文描述重建（原 Example 5）。
// ============================================================
#include <iostream>
#include <memory> // for std::shared_ptr and std::weak_ptr

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

std::weak_ptr<Resource> getWeakPtr()
{
    auto ptr{ std::make_shared<Resource>() };
    return ptr; // 返回 weak_ptr；此函数返回时 shared_ptr 被销毁 -> 资源销毁
}

// 危险的写法：返回裸指针，函数返回后该指针悬垂
Resource* getDumbPtr()
{
    auto ptr{ std::make_shared<Resource>() };
    return ptr.get(); // 返回后 shared_ptr 析构，返回的裸指针悬垂
}

int main()
{
    auto dumb{ getDumbPtr() };
    std::cout << "Our dumb ptr is: " << ((dumb == nullptr) ? "nullptr\n" : "non-null\n");

    auto weak{ getWeakPtr() };
    std::cout << "Our weak ptr is: " << (weak.expired() ? "expired\n" : "not expired\n");

    return 0;
}

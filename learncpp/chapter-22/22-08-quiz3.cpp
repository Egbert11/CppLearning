// ============================================================
// 来源小节：22.x Chapter 22 summary and quiz（测验第 3 题·解答）
// 示例说明：原始代码用同一个裸指针分别构造两个 std::shared_ptr，
//           两者都以为自己是唯一拥有者，析构时二次释放同一资源（UB）。
//           正确做法：用 std::make_shared 创建第一个 shared_ptr，
//           第二个通过"拷贝"第一个来共享所有权。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-22-summary-and-quiz/
// 预期输出：
//   Resource acquired
//   Resource destroyed
// 备注：本节代码为按原文描述重建（测验解答）。下方注释里保留了
//       有问题的原始写法供对照。
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
    // ---- 有问题的原始写法（勿使用）：同一裸指针构造两个独立 shared_ptr ----
    // auto* res{ new Resource{} };
    // std::shared_ptr<Resource> ptr1{ res };
    // std::shared_ptr<Resource> ptr2{ res }; // 各自独立拥有 -> 二次释放

    // ---- 符合最佳实践的写法 ----
    auto ptr1{ std::make_shared<Resource>() };
    auto ptr2{ ptr1 }; // copy ptr1 to share ownership

    return 0;
}

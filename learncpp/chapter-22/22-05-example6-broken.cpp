// ============================================================
// 来源小节：22.5 std::unique_ptr
// 示例说明：坏实践演示——原文用来解释"为什么 make_unique 更安全"的表达式：
//             some_function(std::unique_ptr<T>(new T), function_that_can_throw_exception());
//           在 C++17 之前实参求值顺序未指定：若先求值 new T 得到裸指针、
//           随后另一个实参抛异常，那么新建对象可能还来不及交给 unique_ptr
//           就泄漏了。这里把它补成可编译程序以便观察。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
// 预期输出（本实现下第二实参先求值抛出）：
//   Caught exception
//   （"Resource acquired" 与 "Resource destroyed" 均不出现）
// 备注：本节代码为按原文描述重建（原 Example 6）。属于危险写法示意。
// ============================================================
#include <iostream>
#include <memory>

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

void some_function(std::unique_ptr<Resource> res, int)
{
    (void)res;
}

int function_that_can_throw_exception()
{
    throw 1; // 假设它可能抛异常
}

int main()
{
    try
    {
        // --- 原文示例片段 ---
        some_function(std::unique_ptr<Resource>(new Resource), function_that_can_throw_exception());
        // --- 原文示例片段 ---
    }
    catch (int)
    {
        std::cout << "Caught exception\n";
    }

    return 0;
}

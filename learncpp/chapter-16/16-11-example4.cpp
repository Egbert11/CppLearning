// ============================================================
// 来源小节：16.11 std::vector and stack behavior
// 示例说明：对比 push_back() 与 emplace_back()：
//           - 对象已存在时二者效率相近，优先 push_back()；
//           - 需要创建临时对象时 emplace_back() 直接原地构造、无复制；
//           - push_back() 不接受 explicit 构造函数，emplace_back() 接受。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-stack-behavior/
// 预期输出：Foo count: 5
// 备注：本节代码为按原文描述重建。
//   原文此例中含一行预期编译错误：stack.push_back({ 2 });  // Foo(int) 是 explicit
//   为使本文件可编译，该行已注释掉；若取消注释，编译将失败。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Foo
{
private:
    std::string m_a {};
    int m_b {};

public:
    Foo(std::string_view a, int b)
        : m_a { a }, m_b { b }
    {}

    explicit Foo(int b)
        : m_a {}, m_b { b }
    {}
};

int main()
{
    std::vector<Foo> stack {};

    // When we already have an object, push_back and emplace_back are similar in efficiency
    Foo f { "a", 2 };
    stack.push_back(f);    // prefer this one
    stack.emplace_back(f);

    // When we need to create a temporary object to push, emplace_back is more efficient
    stack.push_back({ "a", 2 }); // creates a temporary object, and then copies it into the vector
    stack.emplace_back("a", 2);  // forwards the arguments so the object can be created directly in the vector (no copy made)

    // push_back won't use explicit constructors, emplace_back will
    // stack.push_back({ 2 }); // compile error: Foo(int) is explicit
    stack.emplace_back(2);  // ok

    std::cout << "Foo count: " << stack.size() << '\n';

    return 0;
}

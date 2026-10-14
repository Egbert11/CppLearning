// ============================================================
// 来源小节：14.7 Member functions returning references to data members
// 示例说明：返回私有成员的非 const 引用（坏做法）——调用者借此直接改写 m_value，
//           绕过了访问控制系统，等价于把私有成员变成公有成员。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-functions-returning-references-to-data-members/
// 备注：本节代码为按原文描述忠实重建。这是坏实践演示（能编译、能运行），请勿模仿。
// ============================================================
#include <iostream>

class Foo
{
private:
    int m_value{ 4 }; // private member

public:
    int& value() { return m_value; } // returns a non-const reference (don't do this)
};

int main()
{
    Foo f{};                // f.m_value is initialized to default value 4
    f.value() = 5;          // The equivalent of m_value = 5
    std::cout << f.value(); // prints 5

    return 0;
}

// 预期输出：
// 5

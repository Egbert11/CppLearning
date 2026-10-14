// ============================================================
// 来源小节：24.6 Adding new functionality to a derived class（原 Example 5）
// 示例说明：演示【预期编译失败】——在【基类】对象上调用只有在派生类里才存在的
//           getValue()。继承是单向的：基类不知道派生类新增了什么。
// 原文链接：https://www.learncpp.com/cpp-tutorial/adding-new-functionality-to-a-derived-class/
// 预期错误（g++ 报错信息类似）：
//   error: 'class Base' has no member named 'getValue'
// 备注：本节代码为按原文描述重建。此文件预期编译失败，请勿修复。
// ============================================================
#include <iostream>

class Base
{
protected:
    int m_value{};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    void identify() const { std::cout << "I am a Base\n"; }
};

class Derived : public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

    int getValue() const { return m_value; }
};

int main()
{
    Base base{ 5 };
    std::cout << "base has value " << base.getValue() << '\n'; // ERROR: Base has no getValue()

    return 0;
}

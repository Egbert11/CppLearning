// ============================================================
// 来源小节：24.5 Inheritance and access specifiers（原 Example 5）
// 示例说明：Pri 私有继承 Base。基类的 public / protected 成员在 Pri 中一律变成
//           private：Pri 自身仍可访问它们，但外部无法通过 Pri 对象访问。这里用
//           Pri 自己的公有函数间接对外暴露这些值，说明它们确实还在。
// 原文链接：https://www.learncpp.com/cpp-tutorial/inheritance-and-access-specifiers/
// 预期输出：
//   Pri internal values: 1 2
// 备注：本节代码为按原文描述重建。原示例中 pri.m_public 等属非法访问，这里不复现。
// ============================================================
#include <iostream>

class Base
{
public:
    int m_public{};
protected:
    int m_protected{};
private:
    int m_private{};
};

class Pri : private Base // note: private inheritance
{
    // Private inheritance means:
    // Public inherited members become private (so m_public is treated as private)
    // Protected inherited members become private (so m_protected is treated as private)
    // Private inherited members stay inaccessible (so m_private is inaccessible)
public:
    Pri()
    {
        m_public = 1;       // okay: m_public is now private in Pri
        m_protected = 2;    // okay: m_protected is now private in Pri
        // m_private = 3;   // not okay: derived classes can't access private members in the base class
    }

    void show() const
    {
        std::cout << "Pri internal values: " << m_public << ' ' << m_protected << '\n';
    }
};

int main()
{
    Pri pri;
    pri.show();

    // pri.m_public = 1;    // not okay: m_public is now private in Pri
    // pri.m_protected = 2; // not okay: m_protected is now private in Pri

    return 0;
}

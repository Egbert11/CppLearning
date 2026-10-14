// ============================================================
// 来源小节：24.5 Inheritance and access specifiers（原 Example 6）
// 示例说明：链式继承。D2 私有继承 Base，因此 Base 的 public/protected 成员在 D2
//           中变为 private；D3 公开继承 D2，但无法访问 D2 从 Base 私有继承来的成员。
//           D3 只能访问 D2 自己的 m_public2（public）与 m_protected2（protected）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/inheritance-and-access-specifiers/
// 预期输出：
//   D3 sees D2 members: 11 12
// 备注：本节代码为按原文描述重建。
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

class D2 : private Base // note: private inheritance
{
    // Private inheritance means:
    // Public inherited members become private
    // Protected inherited members become private
    // Private inherited members stay inaccessible
public:
    int m_public2{};
protected:
    int m_protected2{};
private:
    int m_private2{};
};

class D3 : public D2
{
    // Public inheritance means:
    // Public inherited members stay public
    // Protected inherited members stay protected
    // Private inherited members stay inaccessible
public:
    int m_public3{};
protected:
    int m_protected3{};
private:
    int m_private3{};

public:
    void show()
    {
        // D3 can reach D2's own public/protected members...
        m_public2 = 11;
        m_protected2 = 12;
        // ...but has NO access to any of Base's members (they became private in D2):
        // m_public = 1;    // not allowed
        // m_protected = 2; // not allowed
        // m_private = 3;   // not allowed

        std::cout << "D3 sees D2 members: " << m_public2 << ' ' << m_protected2 << '\n';
    }
};

int main()
{
    D3 d3;
    d3.show();

    return 0;
}

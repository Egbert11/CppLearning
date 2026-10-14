// ============================================================
// 来源小节：15.1 The hidden "this" pointer and member function chaining
// 示例说明：this 指向"当前调用成员函数的那个对象"。构造函数里 this
//           分别指向 a、b；成员函数调用时 this 又在 a、b 之间切换。
//           对象内部只保存数据，this 是函数参数而不是数据成员，
//           所以不会增大对象体积。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-hidden-this-pointer-and-member-function-chaining/
// 预期输出：a.getID()=3, b.getID()=4
// 备注：本节代码为按原文示例忠实重建。
// ============================================================
#include <iostream>

class Simple
{
private:
    int m_id{};

public:
    Simple(int id)
        : m_id{ id }
    {
    }

    int getID() const { return m_id; }
    void setID(int id) { m_id = id; }
};

int main()
{
    Simple a{ 1 }; // 在 Simple 构造函数内部 this = &a
    Simple b{ 2 }; // 在 Simple 构造函数内部 this = &b
    a.setID(3);    // 在成员函数 setID() 内部 this = &a
    b.setID(4);    // 在成员函数 setID() 内部 this = &b

    std::cout << "a.getID()=" << a.getID() << ", b.getID()=" << b.getID() << '\n';

    return 0;
}

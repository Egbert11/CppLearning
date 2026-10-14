// ============================================================
// 来源小节：15.1 The hidden "this" pointer and member function chaining
// 示例说明：Simple 类使用"隐式 this"——成员函数里直接写 m_id，
//           编译器自动补上 this->。main() 中 simple.setID(2) 后
//           simple.print() 打印 2。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-hidden-this-pointer-and-member-function-chaining/
// 预期输出：2
// 备注：本节代码为按原文示例忠实重建（原文给出完整代码）。
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

    void print() const { std::cout << m_id; }
};

int main()
{
    Simple simple{ 1 };
    simple.setID(2);

    simple.print();

    return 0;
}

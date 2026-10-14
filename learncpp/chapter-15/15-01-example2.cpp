// ============================================================
// 来源小节：15.1 The hidden "this" pointer and member function chaining
// 示例说明：与 example1 相同的 Simple 类，但 print() 里显式写出
//           this->m_id，说明 `m_id` 与 `this->m_id` 完全等价。
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

    // 用 `this` 指针访问隐式对象，再用 operator-> 选择成员 m_id
    void print() const { std::cout << this->m_id; }
};

int main()
{
    Simple simple{ 1 };
    simple.setID(2);

    simple.print();

    return 0;
}

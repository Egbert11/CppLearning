// ============================================================
// 来源小节：19.3 Destructors
// 示例说明：用输出语句展示构造与析构的时机（栈对象 + 动态分配对象）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/destructors/
// 预期输出：
//   Constructing Simple 1
//   1
//   Constructing Simple 2
//   2
//   Destructing Simple2
//   Destructing Simple1
// 备注：本节代码为按原文描述重建。原文解释：指针 pSimple 在 main 结束前被 delete，
//       所以 "Simple 2" 先于栈上的 "Simple 1" 被析构。
// ============================================================
#include <iostream>

class Simple
{
private:
    int m_nID{};

public:
    Simple(int nID)
        : m_nID{ nID }
    {
        std::cout << "Constructing Simple " << nID << '\n';
    }

    ~Simple()
    {
        std::cout << "Destructing Simple" << m_nID << '\n';
    }

    int getID() { return m_nID; }
};

int main()
{
    // 在栈上分配一个 Simple
    Simple simple{ 1 };
    std::cout << simple.getID() << '\n';

    // 动态分配一个 Simple
    Simple* pSimple{ new Simple{ 2 } };

    std::cout << pSimple->getID() << '\n';

    // pSimple 是动态分配的，必须手动删除
    delete pSimple;

    return 0;
} // simple 在此处离开作用域

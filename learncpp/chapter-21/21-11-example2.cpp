// 来源小节：21.11 Overloading typecasts
// 示例说明：为 Cents 重载类型转换，定义成员函数 operator int()（注意 operator 与 int 之间
//           的空格）。之后编译器在类型不匹配时会自动调用它；也可用 static_cast<int> 显式调用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-typecasts/
// 说明：本节代码为按原文描述重建。
// 预期输出：
//   7
//   7

#include <iostream>

class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents = 0)
        : m_cents{ cents }
    {
    }

    // Overloaded int cast
    operator int() const { return m_cents; }

    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }
};

void printInt(int value)
{
    std::cout << value;
}

int main()
{
    // --- 原文示例片段 ---
    Cents cents{ 7 };
    printInt(cents); // print 7

    std::cout << '\n';

    std::cout << static_cast<int>(cents) << '\n'; // print 7
    // --- 原文示例片段结束 ---

    return 0;
}

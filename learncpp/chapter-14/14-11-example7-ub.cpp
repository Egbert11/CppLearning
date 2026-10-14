// ============================================================
// 来源小节：14.11 Default constructors and default arguments
// 示例说明：三类默认构造函数的差异——只有“用户提供”的默认构造函数会让
//           值初始化不零初始化，于是 m_a 保持未初始化；= default 与隐式版本
//           会先零初始化，m_a、m_b 都为 0。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-constructors-and-default-arguments/
// 备注：本节代码为按原文描述忠实重建。打印 User 的未初始化 m_a 是未定义行为，
//       作者机器上输出 782510864，实际值依实现而定，切勿依赖。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 9）---
class User
{
private:
    int m_a;    // no initializer
    int m_b {}; // default member initializer

public:
    User() {} // user-provided default constructor (empty body)

    int a() const { return m_a; }
    int b() const { return m_b; }
};

class Default
{
private:
    int m_a;    // no initializer
    int m_b {};

public:
    Default() = default; // not user-provided -> value init zero-initializes first

    int a() const { return m_a; }
    int b() const { return m_b; }
};

class Implicit
{
private:
    int m_a;    // no initializer
    int m_b {};

public:
    // no declared constructor -> implicitly defined default constructor
    int a() const { return m_a; }
    int b() const { return m_b; }
};

int main()
{
    User user{};
    Default def{};
    Implicit imp{};

    std::cout << user.a() << ' ' << user.b() << '\n';
    std::cout << def.a()  << ' ' << def.b()  << '\n';
    std::cout << imp.a()  << ' ' << imp.b()  << '\n';

    return 0;
}

// 预期输出（作者机器上；User 行 m_a 为未定义行为，依实现而定）：
// 782510864 0
// 0 0
// 0 0

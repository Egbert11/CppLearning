// ============================================================
// 来源小节：24.9 Multiple inheritance（原 Example 6）
// 示例说明：菱形问题（diamond of doom）。Scanner 与 Printer 都继承自 PoweredDevice，
//           而 Copier 同时继承 Scanner 与 Printer，于是 Copier 里含有【两份】
//           PoweredDevice 子对象。这里仅展示结构（未访问这些基类，故可编译）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multiple-inheritance/
// 预期输出：
//   sizeof(Copier) likely equals the sum of two PoweredDevice subobjects
//   (implementation-defined, so exact value is not asserted)
// 备注：本节代码为按原文描述重建。解决菱形问题的办法（虚基类）见 25.8 节。
// ============================================================
#include <iostream>

class PoweredDevice
{
public:
    int m_powered{};
};

class Scanner : public PoweredDevice
{
};

class Printer : public PoweredDevice
{
};

class Copier : public Scanner, public Printer
{
};

int main()
{
    Copier c;

    // Copier contains two separate PoweredDevice subobjects (one via Scanner, one via Printer)
    // Accessing c.m_powered would be ambiguous; you must qualify, e.g. c.Scanner::m_powered.
    c.Scanner::m_powered = 1;
    c.Printer::m_powered = 2;

    std::cout << "Copier spans two PoweredDevice subobjects: "
              << c.Scanner::m_powered << " and " << c.Printer::m_powered << '\n';

    return 0;
}

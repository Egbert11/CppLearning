// ---------------------------------------------------------------------------
// 来源小节：25.8 Virtual base classes
// 原文链接：https://www.learncpp.com/cpp-tutorial/virtual-base-classes/
// 示例说明：虚基类——将 PoweredDevice 声明为 virtual 基类后，无论它被继承
//           多少次，一个对象里只存在一份 PoweredDevice 子对象，且只构造一次。
//           最派生类 Copier 负责构造虚基类。
// 预期输出：
//   PoweredDevice: 3
//   Scanner: 1
//   Printer: 2
// 代码为原文逐字提取。
// ---------------------------------------------------------------------------

#include <iostream>

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
        std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner: virtual public PoweredDevice // note: PoweredDevice is now a virtual base class
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice{ power } // this line is required to create Scanner objects, but ignored in this case
    {
        std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer: virtual public PoweredDevice // note: PoweredDevice is now a virtual base class
{
public:
    Printer(int printer, int power)
        : PoweredDevice{ power } // this line is required to create Printer objects, but ignored in this case
    {
        std::cout << "Printer: " << printer << '\n';
    }
};

class Copier: public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : PoweredDevice{ power }, // PoweredDevice is constructed here
        Scanner{ scanner, power }, Printer{ printer, power }
    {
    }
};

int main()
{
    Copier copier{ 1, 2, 3 };

    return 0;
}

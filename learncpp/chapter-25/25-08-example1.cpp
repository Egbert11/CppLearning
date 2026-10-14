// ---------------------------------------------------------------------------
// 来源小节：25.8 Virtual base classes
// 原文链接：https://www.learncpp.com/cpp-tutorial/virtual-base-classes/
// 示例说明：钻石继承问题——Copier 同时继承 Scanner 与 Printer，两者都继承
//           PoweredDevice，于是 Copier 里出现了两份 PoweredDevice 子对象，
//           PoweredDevice 被构造两次。
// 预期输出：
//   PoweredDevice: 3
//   Scanner: 1
//   PoweredDevice: 3
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

class Scanner: public PoweredDevice
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice{ power }
    {
        std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer: public PoweredDevice
{
public:
    Printer(int printer, int power)
        : PoweredDevice{ power }
    {
        std::cout << "Printer: " << printer << '\n';
    }
};

class Copier: public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : Scanner{ scanner, power }, Printer{ printer, power }
    {
    }
};

int main()
{
    Copier copier{ 1, 2, 3 };

    return 0;
}

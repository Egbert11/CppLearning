// ============================================================
// 来源小节：24.9 Multiple inheritance（原 Example 5）
// 示例说明：用显式作用域解决歧义——c54G.USBDevice::getID() 指明调用 USBDevice 的
//           getID() 版本，从而消除 Example 4 中的歧义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multiple-inheritance/
// 预期输出：
//   5442
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class USBDevice
{
private:
    long m_id{};

public:
    USBDevice(long id)
        : m_id{ id }
    {
    }

    long getID() const { return m_id; }
};

class NetworkDevice
{
private:
    long m_id{};

public:
    NetworkDevice(long id)
        : m_id{ id }
    {
    }

    long getID() const { return m_id; }
};

class WirelessAdapter : public USBDevice, public NetworkDevice
{
public:
    WirelessAdapter(long usbId, long networkId)
        : USBDevice{ usbId }, NetworkDevice{ networkId }
    {
    }
};

int main()
{
    WirelessAdapter c54G{ 5442, 181742 };
    std::cout << c54G.USBDevice::getID() << '\n';

    return 0;
}

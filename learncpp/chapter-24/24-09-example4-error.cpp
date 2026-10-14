// ============================================================
// 来源小节：24.9 Multiple inheritance（原 Example 4）
// 示例说明：演示【预期编译失败】——USBDevice 与 NetworkDevice 都声明了 getID()，
//           WirelessAdapter 同时继承二者，于是对象里有两份 getID()。不加限定的
//           c54G.getID() 产生歧义，编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multiple-inheritance/
// 预期错误（g++ 报错信息类似）：
//   error: request for member 'getID' is ambiguous
// 备注：本节代码为按原文描述重建。此文件预期编译失败，请勿修复。
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
    std::cout << c54G.getID(); // Which getID() do we call? -> ambiguous, compile error

    return 0;
}

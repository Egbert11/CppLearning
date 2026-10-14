// ============================================================
// 来源小节：15.4 Introduction to destructors
// 示例说明：改进版 NetworkData——让析构函数自动调用 sendData()，
//           这样对象被销毁时数据一定被发出，用户不必再记得手动清理。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-destructors/
// 预期输出：Sending data to someipAddress: somedata1somedata2
// 备注：本节代码为按原文描述重建并补全。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class NetworkData
{
private:
	std::string m_serverName{};
	std::string m_data{};

public:
	NetworkData(std::string_view serverName)
		: m_serverName{ serverName }
	{
	}

	~NetworkData()
	{
		sendData(); // make sure all data is sent before object is destroyed
	}

	void addData(std::string_view data)
	{
		m_data += data;
	}

	void sendData()
	{
		std::cout << "Sending data to " << m_serverName << ": " << m_data << '\n';
	}
};

int main()
{
	NetworkData n("someipAddress");
	n.addData("somedata1");
	n.addData("somedata2");

	// 不再需要手动调用 sendData()：main 返回时析构函数会自动发送数据
	return 0;
}

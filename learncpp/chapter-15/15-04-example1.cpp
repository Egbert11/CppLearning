// ============================================================
// 来源小节：15.4 Introduction to destructors
// 示例说明：一个需要"清理"的类——NetworkData 会缓冲数据，必须调用
//           sendData() 才能把数据发出去。清理工作依赖用户记得调用它，
//           一旦忘记就会出错。原文此处给的是（故意）不完整的片段，
//           这里补全为可编译版本以便演示"手动清理"的问题。
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

	void addData(std::string_view data)
	{
		m_data += data; // 先把数据缓冲起来
	}

	void sendData()
	{
		// 假设这里真的把 m_data 发送到服务器
		std::cout << "Sending data to " << m_serverName << ": " << m_data << '\n';
	}
};

int main()
{
	NetworkData n("someipAddress");
	n.addData("somedata1");
	n.addData("somedata2");

	// 必须记得手动调用 sendData()，否则缓冲的数据永远不会发出
	n.sendData();

	return 0;
}

// ============================================================
// 来源小节：15.4 Introduction to destructors
// 示例说明：演示"手动清理"的隐患——函数可能在中途提前 return，
//           于是 sendData() 永远得不到调用，缓冲的数据被丢掉。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-destructors/
// 预期输出：early return, data was never sent!
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
		m_data += data;
	}

	void sendData()
	{
		std::cout << "Sending data to " << m_serverName << ": " << m_data << '\n';
	}
};

bool someFunction()
{
	bool someCondition{ true };

	NetworkData n("someipAddress");
	n.addData("somedata1");
	n.addData("somedata2");

	if (someCondition)
		return false; // 提前返回，跳过了 sendData()，数据丢失

	n.sendData();
	return true;
}

int main()
{
	if (!someFunction())
		std::cout << "early return, data was never sent!\n";

	return 0;
}

// ============================================================
// 来源小节：15.8 Friend non-member functions
// 示例说明：同一个非成员函数 printWeather() 可以同时成为两个类的友元
//           （Temperature 和 Humidity），从而同时访问两者的私有数据。
//           注意 Humidity 的前向声明：Temperature 的友元声明里用到了
//           Humidity，所以在它之前要先前向声明 class Humidity;。
// 原文链接：https://www.learncpp.com/cpp-tutorial/friend-non-member-functions/
// 预期输出：The temperature is 12 and the humidity is 10
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Humidity; // Humidity 的前向声明

class Temperature
{
private:
	int m_temp { 0 };

public:
	explicit Temperature(int temp)
		: m_temp { temp }
	{
	}

	friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

class Humidity
{
private:
	int m_humidity { 0 };

public:
	explicit Humidity(int humidity)
		: m_humidity { humidity }
	{
	}

	friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

void printWeather(const Temperature& temperature, const Humidity& humidity)
{
	std::cout << "The temperature is " << temperature.m_temp <<
		" and the humidity is " << humidity.m_humidity << '\n';
}

int main()
{
	Humidity hum { 10 };
	Temperature temp { 12 };

	printWeather(temp, hum);

	return 0;
}

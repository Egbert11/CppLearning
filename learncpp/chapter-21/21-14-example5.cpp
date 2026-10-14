// 来源小节：21.14 Overloading operators and function templates
// 示例说明：为 Cents 补齐模板体用到的运算符（operator<<、operator+=、operator/=），
//           程序即可编译并把结果打印为“11 cents”。average() 模板本身无需改动。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-operators-and-function-templates/
// 说明：本节代码为按原文描述重建。
// 预期输出：11 cents

#include <iostream>

class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents)
        : m_cents{ cents }
    {
    }

    Cents& operator+= (const Cents& cents)
    {
        m_cents += cents.m_cents;
        return *this;
    }

    Cents& operator/= (int value)
    {
        m_cents /= value;
        return *this;
    }

    friend std::ostream& operator<< (std::ostream& ostr, const Cents& c)
    {
        ostr << c.m_cents << " cents";
        return ostr;
    }
};

template <typename T>
T average(const T* myArray, int numValues)
{
    T sum{ 0 };
    for (int count{ 0 }; count < numValues; ++count)
        sum += myArray[count];

    sum /= numValues;
    return sum;
}

int main()
{
    Cents centsArray[] { Cents { 5 }, Cents { 10 }, Cents { 15 }, Cents { 14 } };
    std::cout << average(centsArray, 4) << '\n';

    return 0;
}

// 来源小节：21.14 Overloading operators and function templates
// 示例说明：把 average() 用在 Cents 上。Cents 已有 operator<<（打印没问题），但没有
//           operator+=，于是实例化函数里的 sum += myArray[count] 无法编译。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-operators-and-function-templates/
// 说明：本节代码为按原文描述重建。此文件预期编译失败（勿修复！）：
//       error: no match for 'operator+=' (operand types are 'Cents' and 'const Cents')
//       规则：模板函数体用到的每个运算符，都要为实参类型定义（本例还需 operator/=）。

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

// 来源小节：21.x Chapter 21 summary and quiz（测验 4 额外加分解答）
// 示例说明：FixedPoint2 —— 两位小数的定点数（范围约 -32768.99 ~ 32767.99），无浮点精度误差。
//           Step 1：用 int16_t 存非小数部分、int8_t 存小数部分（百分之一）；
//           Step 2：负数统一由两部分携带负号，提供 operator<< 与（explicit 的）转 double；
//           Step 3：构造时用取整/取余把越界的小数部分折叠进位（m_base += m_decimal/100）;
//           Step 4：增加接收 double 的委托构造函数（trunc / round 取整）；
//           Step 5：重载 operator==、operator>>、一元 operator-、二元 operator+。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-21-summary-and-quiz/
// 说明：本节代码为按原文描述重建。testDecimal 用“小容差”比较，以避免浮点末位差异造成的误报。
// 预期输出（逐行）：
//   34.56
//   -34.56
//   -34.56
//   4.08
//   5.67
//   -0.48
//   0.48
//   0.96
//   1
//   OK: 5.667 rounds to 5.67
//   OK: 3.108 rounds to 3.11

#include <cmath>      // for std::trunc, std::round, std::abs
#include <cstdint>
#include <iostream>
#include <string>

class FixedPoint2
{
private:
    std::int16_t m_base{};   // the non-fractional part
    std::int8_t m_decimal{}; // the fractional part (in hundredths)

public:
    FixedPoint2(std::int16_t base = 0, std::int8_t decimal = 0)
        : m_base{ base }
        , m_decimal{ decimal }
    {
        // if either part is negative, the entire number should be negative
        if (m_base < 0 || m_decimal < 0)
        {
            if (m_base > 0)
                m_base = -m_base;
            if (m_decimal > 0)
                m_decimal = -m_decimal;
        }

        // Handle the case where the decimal part is out of bounds (e.g. > 100 or < -100)
        m_base += m_decimal / 100;   // integer division truncates toward zero
        m_decimal = m_decimal % 100; // remainder keeps the fractional part in range
    }

    // Step 4: construct from a double
    FixedPoint2(double d)
        : FixedPoint2{
              static_cast<std::int16_t>(std::trunc(d)),
              static_cast<std::int8_t>(std::round(d * 100) - std::trunc(d) * 100)
          }
    {
    }

    explicit operator double() const
    {
        return m_base + (static_cast<double>(m_decimal) / 100.0);
    }

    friend bool operator==(const FixedPoint2& fp1, const FixedPoint2& fp2)
    {
        return (fp1.m_base == fp2.m_base && fp1.m_decimal == fp2.m_decimal);
    }

    FixedPoint2 operator-() const
    {
        return FixedPoint2{ -static_cast<double>(*this) };
    }

    friend FixedPoint2 operator+(const FixedPoint2& fp1, const FixedPoint2& fp2)
    {
        return FixedPoint2{ static_cast<double>(fp1) + static_cast<double>(fp2) };
    }

    friend std::istream& operator>>(std::istream& in, FixedPoint2& fp)
    {
        double d{};
        in >> d;
        fp = FixedPoint2{ d };
        return in;
    }
};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp)
{
    out << static_cast<double>(fp);
    return out;
}

// This function is for testing purposes only (Step 3)
void testDecimal(double x, const std::string& expected, const std::string& error)
{
    double result{ static_cast<double>(FixedPoint2{ x }) };
    if (std::abs(result - std::stod(expected)) > 1e-9)
    {
        std::cerr << "ERROR: " << error << '\n';
        std::cerr << "\tExpected " << expected << " got " << result << '\n';
    }
    else
        std::cout << "OK: " << error << '\n';
}

int main()
{
    // Step 2: print and conversion to double
    std::cout << FixedPoint2{ 34, 56 } << '\n';  // 34.56
    std::cout << FixedPoint2{ -34, 56 } << '\n'; // -34.56
    std::cout << FixedPoint2{ 34, -56 } << '\n'; // -34.56

    // Step 3: fractional overflow folds into the base
    std::cout << FixedPoint2{ 3, 108 } << '\n';  // 4.08

    // Step 4: constructed from a double
    std::cout << FixedPoint2{ 5.667 } << '\n';   // 5.67

    // Step 5: unary minus, equality, binary plus
    FixedPoint2 a{ -0.48 };
    std::cout << a << '\n';              // -0.48
    std::cout << -a << '\n';             // 0.48
    std::cout << -(a + a) << '\n';       // 0.96
    std::cout << (a == FixedPoint2{ -0.48 }) << '\n'; // 1

    testDecimal(5.667, "5.67", "5.667 rounds to 5.67");
    testDecimal(3.108, "3.11", "3.108 rounds to 3.11");

    return 0;
}

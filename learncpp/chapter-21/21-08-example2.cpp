// 来源小节：21.8 Overloading the increment and decrement operators
// 示例说明：Digit 同时重载前缀与后缀 ++/--。带一个 int 参数的是后缀版（占位参数不命名），
//           无参数的是前缀版；后缀先保存旧值副本，再调用前缀版完成自增，最后返回旧值副本，
//           且必须按值返回（不能返回对局部临时量的引用）。后缀通常比前缀慢。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-increment-and-decrement-operators/
// 说明：本节代码取自原文（逐字保留）。
// 预期输出：5667665

#include <iostream>

class Digit
{
private:
    int m_digit{};
public:
    Digit(int digit=0)
        : m_digit{digit}
    {
    }

    Digit& operator++(); // prefix has no parameter
    Digit& operator--(); // prefix has no parameter

    Digit operator++(int); // postfix has an int parameter
    Digit operator--(int); // postfix has an int parameter

    friend std::ostream& operator<< (std::ostream& out, const Digit& d);
};

// No parameter means this is prefix operator++
Digit& Digit::operator++()
{
    // If our number is already at 9, wrap around to 0
    if (m_digit == 9)
        m_digit = 0;
    // otherwise just increment to next number
    else
        ++m_digit;

    return *this;
}

// No parameter means this is prefix operator--
Digit& Digit::operator--()
{
    // If our number is already at 0, wrap around to 9
    if (m_digit == 0)
        m_digit = 9;
    // otherwise just decrement to next number
    else
        --m_digit;

    return *this;
}

// int parameter means this is postfix operator++
Digit Digit::operator++(int)
{
    // Create a temporary variable with our current digit
    Digit temp{*this};

    // Use prefix operator to increment this digit
    ++(*this); // apply operator

    // return temporary result
    return temp; // return saved state
}

// int parameter means this is postfix operator--
Digit Digit::operator--(int)
{
    // Create a temporary variable with our current digit
    Digit temp{*this};

    // Use prefix operator to decrement this digit
    --(*this); // apply operator

    // return temporary result
    return temp; // return saved state
}

std::ostream& operator<< (std::ostream& out, const Digit& d)
{
	out << d.m_digit;
	return out;
}

int main()
{
    Digit digit { 5 };

    std::cout << digit;
    std::cout << ++digit; // calls Digit::operator++();
    std::cout << digit++; // calls Digit::operator++(int);
    std::cout << digit;
    std::cout << --digit; // calls Digit::operator--();
    std::cout << digit--; // calls Digit::operator--(int);
    std::cout << digit;

    return 0;
}

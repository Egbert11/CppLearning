// ============================================================
// 来源小节：13.10 Passing and returning structs
// 示例说明：测验 2 解答——Fraction 结构体，读取两个分数相乘并打印结果。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-and-returning-structs/
// 备注：本节代码为按原文描述忠实重建。getFraction() 必须按值返回，避免悬垂引用。
// ============================================================
#include <iostream>

struct Fraction
{
    int numerator { 0 };
    int denominator { 1 };
};

Fraction getFraction()
{
    Fraction temp {};
    std::cout << "Enter a value for the numerator: ";
    std::cin >> temp.numerator;
    std::cout << "Enter a value for the denominator: ";
    std::cin >> temp.denominator;
    std::cout << '\n';

    return temp; // return by value (to avoid a dangling reference to temp)
}

constexpr Fraction multiply(const Fraction& f1, const Fraction& f2)
{
    return { f1.numerator * f2.numerator, f1.denominator * f2.denominator };
}

void printFraction(const Fraction& f)
{
    std::cout << f.numerator << '/' << f.denominator << '\n';
}

int main()
{
    Fraction f1{ getFraction() };
    Fraction f2{ getFraction() };

    std::cout << "Your fractions multiplied together: ";
    printFraction(multiply(f1, f2));

    return 0;
}

// 预期输出（示例输入 1/2 与 3/4）：
// Enter a value for the numerator: 1
// Enter a value for the denominator: 2
//
// Enter a value for the numerator: 3
// Enter a value for the denominator: 4
//
// Your fractions multiplied together: 3/8

// ============================================================
// 来源小节：14.x Chapter 14 summary and quiz（官方编号 14.x）
// 示例说明：把 13.10 课的 Fraction struct 程序原样列出，作为测验 2 的对照
//           （全部使用自由函数与聚合初始化）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-14-summary-and-quiz/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 3，来自 13.10 课）---
struct Fraction
{
    int numerator{ 0 };
    int denominator{ 1 };
};

Fraction getFraction()
{
    Fraction temp{};
    std::cout << "Enter a value for numerator: ";
    std::cin >> temp.numerator;
    std::cout << "Enter a value for denominator: ";
    std::cin >> temp.denominator;
    std::cout << '\n';

    return temp;
}

Fraction multiply(const Fraction& f1, const Fraction& f2)
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
// --- 原文示例片段结束 ---

// 示例运行（输入 2 3 4 5 时）：
// Enter a value for numerator: 2
// Enter a value for denominator: 3
//
// Enter a value for numerator: 4
// Enter a value for denominator: 5
//
// Your fractions multiplied together: 8/15

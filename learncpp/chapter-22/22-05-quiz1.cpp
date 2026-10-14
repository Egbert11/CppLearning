// ============================================================
// 来源小节：22.5 std::unique_ptr（本节测验·解答）
// 示例说明：把测验的裸指针版本改为 std::make_unique 管理 Fraction；
//           打印函数仍只接收 Fraction 指针（用 get() 取出），这样函数
//           不必关心调用方使用哪种（若有的）智能指针，也不需要手动 delete。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
// 预期输出：
//   3/5
// 备注：本节代码为按原文描述重建（原 Example 13，即测验解答）。
// ============================================================
#include <iostream>
#include <memory> // for std::unique_ptr / std::make_unique

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator{ numerator }, m_denominator{ denominator }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
    {
        out << f1.m_numerator << '/' << f1.m_denominator;
        return out;
    }
};

// This function uses a Fraction object, so we just pass the Fraction itself
// That way we don't have to worry about what kind of smart pointer (if any) the caller may be using
void printFraction(const Fraction* ptr)
{
    if (ptr)
        std::cout << *ptr << '\n';
    else
        std::cout << "No fraction\n";
}

int main()
{
    auto ptr{ std::make_unique<Fraction>(3, 5) };

    printFraction(ptr.get());

    return 0;
}

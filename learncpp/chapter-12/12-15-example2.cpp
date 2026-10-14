// ============================================================
// 来源小节：12.15 std::optional
// 示例说明：用哨兵值（sentinel）报告错误：reciprocal() 在 x == 0 时返回
//           0.0。缺点：调用方必须知道用的是哪个哨兵，且若某个合法结果恰好
//           等于哨兵值，就会产生“半谓词问题（semipredicate problem）”。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdoptional/
// 备注：本节代码为按原文描述忠实重建（原 Example 2）。
// ============================================================
#include <iostream>

// The reciprocal of x is 1/x, returns 0.0 if x=0
double reciprocal(double x)
{
    if (x == 0.0)
        return 0.0; // 0.0 is a sentinel value

    return 1.0 / x;
}

void testReciprocal(double d)
{
    double result { reciprocal(d) };
    std::cout << "The reciprocal of " << d << " is " << result << '\n';
}

int main()
{
    testReciprocal(5.0);
    testReciprocal(-4.0);
    testReciprocal(0.0);

    return 0;
}

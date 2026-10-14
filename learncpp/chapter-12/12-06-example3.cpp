// ============================================================
// 来源小节：12.6 Pass by const lvalue reference
// 示例说明：把一个 int 传给"按值 double 形参"和"const double& 形参"，
//           两种情况都会先产生一个 double 临时量；调用方不必区分两种
//           形参写法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/
// 备注：本节代码为按原文描述忠实重建（原 Example 3）。
// ============================================================
#include <iostream>

void printVal(double d)
{
    std::cout << d << '\n';
}

void printRef(const double& d)
{
    std::cout << d << '\n';
}

int main()
{
    printVal(5); // 5 converted to temporary double, copied to parameter d
    printRef(5); // 5 converted to temporary double, bound to parameter d

    return 0;
}

// 预期输出：
// 5
// 5

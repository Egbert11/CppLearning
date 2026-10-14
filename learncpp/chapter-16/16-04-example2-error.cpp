// ============================================================
// 来源小节：16.4 Passing std::vector
// 示例说明：把 std::vector<double> 传给期望 std::vector<int> 的参数会编译失败，
//           因为二者不是可互相转换的类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-stdvector/
// 预期错误：编译错误——无法把 std::vector<double> 绑定到 const std::vector<int>&。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
#include <iostream>
#include <vector>

void passByRef(const std::vector<int>& arr)
{
    std::cout << arr[0] << '\n';
}

int main()
{
    std::vector primes{ 2, 3, 5, 7, 11 };
    passByRef(primes);  // ok: this is a std::vector<int>

    std::vector dbl{ 1.1, 2.2, 3.3 };
    passByRef(dbl); // compile error: std::vector<double> is not convertible to std::vector<int>

    return 0;
}

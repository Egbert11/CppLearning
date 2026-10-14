// ============================================================
// 来源小节：16.4 Passing std::vector
// 示例说明：CTAD 可用于变量定义（main 里的 primes 合法），但不能用于推断函数参数，
//           故函数参数写成 `const std::vector& arr` 会编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-stdvector/
// 预期错误：编译错误——class template argument deduction 不能用于函数参数。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
#include <iostream>
#include <vector>

void passByRef(const std::vector& arr) // compile error: CTAD can't be used to infer function parameters
{
    std::cout << arr[0] << '\n';
}

int main()
{
    std::vector primes{ 2, 3, 5, 7, 11 }; // okay: use CTAD to infer std::vector<int>
    passByRef(primes);

    return 0;
}

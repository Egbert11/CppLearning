// ============================================================
// 来源小节：16.4 Passing std::vector
// 示例说明：C++20 缩写函数模板——用 `const auto&` 参数以更少语法达到同样效果。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-stdvector/
// 预期输出：
//   2
//   1.1
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

void passByRef(const auto& arr) // abbreviated function template (C++20)
{
    std::cout << arr[0] << '\n';
}

int main()
{
    std::vector primes{ 2, 3, 5, 7, 11 };
    passByRef(primes); // ok: compiler will instantiate passByRef(const std::vector<int>&)

    std::vector dbl{ 1.1, 2.2, 3.3 };
    passByRef(dbl);    // ok: compiler will instantiate passByRef(const std::vector<double>&)

    return 0;
}

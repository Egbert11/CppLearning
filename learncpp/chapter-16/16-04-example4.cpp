// ============================================================
// 来源小节：16.4 Passing std::vector
// 示例说明：用函数模板把元素类型参数化，编译器为 int 与 double 各实例化一份。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-stdvector/
// 预期输出：
//   2
//   1.1
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

template <typename T>
void passByRef(const std::vector<T>& arr)
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

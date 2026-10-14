// ============================================================
// 来源小节：16.4 Passing std::vector
// 示例说明：按 const 引用传递 vector；由于元素类型属于类型信息，
//           函数参数必须显式写出 <int>。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-stdvector/
// 预期输出：2
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

void passByRef(const std::vector<int>& arr) // we must explicitly specify <int> here
{
    std::cout << arr[0] << '\n';
}

int main()
{
    std::vector primes{ 2, 3, 5, 7, 11 };
    passByRef(primes);

    return 0;
}

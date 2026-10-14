// ============================================================
// 来源小节：17.3 Passing and returning std::array
// 示例说明：std::array 像普通对象一样按值传递会拷贝，通常按 (const) 引用传递；
//           函数形参必须写全元素类型与长度。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray/
// 预期输出：9
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

void passByRef(const std::array<int, 5>& arr) // we must specify the length
{
    std::cout << arr[0] << '\n';
}

int main()
{
    std::array arr{ 9, 7, 5, 3, 1 }; // uses CTAD to deduce std::array<int, 5>
    passByRef(arr);

    return 0;
}

// ============================================================
// 来源小节：17.3 Passing and returning std::array
// 示例说明：C++20 起可用 `auto N` 作为非类型模板参数，让编译器从实参推导
//           非类型参数的类型，无需记住它究竟是 std::size_t 还是别的类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray/
// 预期输出：9
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

template <typename T, auto N> // C++20: N's type is deduced from the argument
void passByRef(const std::array<T, N>& arr)
{
    std::cout << arr[0] << '\n';
}

int main()
{
    std::array arr{ 9, 7, 5, 3, 1 };
    passByRef(arr);

    return 0;
}

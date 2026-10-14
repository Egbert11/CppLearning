// ============================================================
// 来源小节：17.3 Passing and returning std::array
// 示例说明：把元素类型 T 与长度 N 都作为模板参数，同一个函数模板就能支持
//           任意元素类型与长度；static_assert(N != 0) 拒绝零长数组。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray/
// 预期输出：9
//            1.2
//            1.2
// 备注：本节代码为按原文描述重建。注意非类型模板参数必须用 std::size_t，
//       不能用 int——模板不会做转换，写 int 会导致无法匹配。
// ============================================================
#include <array>
#include <cstddef>
#include <iostream>

template <typename T, std::size_t N> // note: std::size_t not int!
void passByRef(const std::array<T, N>& arr)
{
    static_assert(N != 0); // fail if zero-length
    std::cout << arr[0] << '\n';
}

int main()
{
    std::array arr{ 9, 7, 5, 3, 1 }; // CTAD -> std::array<int, 5>
    passByRef(arr); // OK

    std::array arr2{ 1.2, 3.4, 5.6, 7.8, 9.0 }; // CTAD -> std::array<double, 5>
    passByRef(arr2); // OK

    std::array<double, 6> arr3{ 1.2, 3.4, 5.6, 7.8, 9.0, 10.1 };
    passByRef(arr3); // OK

    return 0;
}

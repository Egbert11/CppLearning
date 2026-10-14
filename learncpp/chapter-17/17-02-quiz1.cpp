// ============================================================
// 来源小节：17.2 std::array length and indexing
// 示例说明：Quiz #1 解答——打印数组长度，并分别用 operator[]、at()、
//           std::get<>() 访问下标 1 的元素。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing/
// 预期输出：The length is 5
//            eee
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    constexpr std::array arr { 'h', 'e', 'l', 'l', 'o' };
    std::cout << "The length is " << std::size(arr) << '\n';
    std::cout << arr[1] << arr.at(1) << std::get<1>(arr) << '\n';

    return 0;
}

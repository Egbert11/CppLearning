// ============================================================
// 来源小节：17.2 std::array length and indexing
// 示例说明：绕开上述语言缺陷的变通办法——把函数写成模板，用非类型模板参数
//           捕获长度，这样长度在编译期就是常量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing/
// 预期输出：length: 5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <cstddef>
#include <iostream>

template <auto Length>
void printLength(const std::array<int, Length>& arr)
{
    std::cout << "length: " << Length << '\n';
}

int main()
{
    std::array arr { 9, 7, 5, 3, 1 };
    printLength(arr);

    return 0;
}

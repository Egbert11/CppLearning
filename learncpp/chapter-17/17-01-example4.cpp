// ============================================================
// 来源小节：17.1 Introduction to std::array
// 示例说明：std::array 允许长度为 0，此时它是"无数据"的特殊类；对它调用
//           任何访问数据的成员（包括 operator[]）都是未定义行为，只能用
//           empty() 判断是否为空。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/
// 预期输出：1
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    std::array<int, 0> arr {}; // creates a zero-length std::array

    std::cout << arr.empty() << '\n'; // true if arr is zero-length

    return 0;
}

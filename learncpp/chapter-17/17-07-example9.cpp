// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：C 风格数组可以是 const 或 constexpr（如其他 const 变量一样必须
//           初始化），其元素之后不能修改。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期输出：16 11
// 备注：本节代码为按原文描述重建；对 prime[0] 赋值会编译失败，见
//       17-07-example10-error.cpp。
// ============================================================
#include <iostream>

namespace ProgramData
{
    constexpr int squares[5] { 1, 4, 9, 16, 25 };
}

int main()
{
    const int prime[5] { 2, 3, 5, 7, 11 };

    // prime[0] = 17; // compile error: can't modify a const array

    std::cout << ProgramData::squares[3] << ' ' << prime[4] << '\n';

    return 0;
}

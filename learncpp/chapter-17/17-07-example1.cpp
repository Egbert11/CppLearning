// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：C 风格数组是核心语言内置的（不需要头文件）；声明时用方括号给出
//           长度，长度是 std::size_t 类型的整型常量表达式。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期输出：0
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

int main()
{
    int testScore[30] {}; // allocate 30 ints, value-initialized to 0

    // std::array<int, 30> arr{}; // the std::array version would need <array>

    std::cout << testScore[0] << '\n';

    return 0;
}

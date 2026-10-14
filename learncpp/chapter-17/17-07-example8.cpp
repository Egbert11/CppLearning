// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：显式写出长度（且与初值个数一致）与省略长度两种写法效果相同；
//           推荐在显式初始化每个元素时省略长度，使长度自动跟随初值个数，
//           避免二者不匹配。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期输出：5 5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

int main()
{
    const int prime1[5] { 2, 3, 5, 7, 11 }; // redundant length: we have exactly 5 initializers
    const int prime2[] { 2, 3, 5, 7, 11 };  // length deduced from initializer count

    std::cout << std::size(prime1) << ' ' << std::size(prime2) << '\n';

    return 0;
}

// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：使用自定义的 SignedArrayView 对 std::vector 提供有符号索引，
//           并用有符号循环变量倒序遍历。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 预期输出：1 3 5 7 9
// 备注：本节代码为按原文描述重建。本文件与 SignedArrayView.h 一起编译：
//       g++ -std=c++20 -Wall 16-07-example17/*.cpp
// ============================================================
#include <iostream>
#include <vector>

#include "SignedArrayView.h"

int main()
{
    std::vector arr{ 9, 7, 5, 3, 1 };

    SignedArrayView sarr{ arr }; // Create a signed view of our std::vector

    for (auto index{ sarr.ssize() - 1 }; index >= 0; --index)
        std::cout << sarr[index] << ' '; // index using a signed type

    return 0;
}

// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：无符号倒序循环——条件 index >= 0 恒为真，且 index 减到 0 后
//           再减一会环绕成极大值，导致越界下标与未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 预期输出：先打印 9 1 2 8 3 7 6 4，随后 index 环绕并越界——未定义行为，
//           可能崩溃或打印垃圾值（依实现而定）。
// 备注：本文件为未定义行为演示（-ub），能编译；请勿依赖其输出。
//       本机 MSYS2 工具链默认启用 _GLIBCXX_ASSERTIONS，越界断言会在第一次越界访问时
//       直接 abort，此时已缓冲的输出可能看不到。
// ============================================================
#include <iostream>
#include <vector>

void printReverse(const std::vector<int>& arr)
{
    // index is unsigned
    for (std::size_t index{ arr.size() - 1 }; index >= 0; --index) // index >= 0 is always true
        std::cout << arr[index] << ' ';

    std::cout << '\n';
}

int main()
{
    std::vector arr { 4, 6, 7, 3, 8, 2, 1, 9 };
    printReverse(arr);

    return 0;
}

// 来源小节：7.6 Internal linkage
// 示例说明：main.cpp 里另有一个内部链接的 g_x，与 a.cpp 的 g_x 相互独立。
//           （对应原文 Example 2 的 main.cpp）
// 原文链接：https://www.learncpp.com/cpp-tutorial/internal-linkage/
//
// 预期输出：3

#include <iostream>

static int g_x { 3 }; // this separate internal g_x is only accessible within main.cpp

int main()
{
    std::cout << g_x << '\n'; // uses main.cpp's g_x, prints 3

    return 0;
}

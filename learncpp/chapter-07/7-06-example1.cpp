// 来源小节：7.6 Internal linkage
// 示例说明：内部链接的全局变量——非 const 全局变量默认外部链接，可用 static 改为内部；
//           const / constexpr 全局变量默认就是内部链接。（对应原文 Example 1）
// 原文链接：https://www.learncpp.com/cpp-tutorial/internal-linkage/
//
// 预期输出：0 1 2
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

static int g_x{}; // non-constant globals have external linkage by default,
                  // but can be given internal linkage via the static keyword

const int g_y{ 1 }; // const globals have internal linkage by default
constexpr int g_z{ 2 }; // constexpr globals have internal linkage by default

int main()
{
    std::cout << g_x << ' ' << g_y << ' ' << g_z << '\n';
    return 0;
}

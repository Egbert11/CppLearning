// ============================================================
// 来源小节：16.3 std::vector and the unsigned length and subscript problem
// 示例说明：operator[] 不做边界检查，访问下标 9 是未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem/
// 预期输出：先输出 7，随后 prime[9] 为未定义行为——输出不定，
//           可能打印垃圾值、崩溃或不崩溃（依实现而定）。
// 备注：本文件为未定义行为演示（-ub），能编译；请勿把其输出当作可依赖结果。
//       本机 MSYS2 工具链默认启用 _GLIBCXX_ASSERTIONS，operator[] 的越界断言会
//       直接 abort（因而可能看不到已缓冲的输出）。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector prime{ 2, 3, 5, 7, 11 };

    std::cout << prime[3];  // print the value of element with index 3 (7)
    std::cout << prime[9];  // invalid index (undefined behavior)

    return 0;
}

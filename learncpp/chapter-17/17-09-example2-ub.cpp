// ============================================================
// 来源小节：17.9 Pointer arithmetic and subscripting
// 示例说明：指针减法——ptr、ptr-1、ptr-2 指向前一个对象（原 Example 2）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting/
// 预期输出（作者机器，4 字节 int）：
//   00AFFD80 00AFFD7C 00AFFD78
// 后缀：-ub。对非数组的单一变量做指针算术属未定义行为（见 Example 1 说明），
//       实际地址输出依平台与运行而定。
// ============================================================
#include <iostream>

int main()
{
    int x{};
    const int* ptr{ &x }; // ptr points to x

    std::cout << ptr << ' ' << (ptr - 1) << ' ' << (ptr - 2) << '\n';

    return 0;
}

// ============================================================
// 来源小节：17.9 Pointer arithmetic and subscripting
// 示例说明：自增/自减指针——++ptr 等价于 ptr = ptr + 1（原 Example 3）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting/
// 预期输出（作者机器，4 字节 int）：
//   00AFFD80 00AFFD84 00AFFD80
// 后缀：-ub。对非数组的单一变量做指针算术属未定义行为（见 Example 1 说明）。
// ============================================================
#include <iostream>

int main()
{
    int x{};
    const int* ptr{ &x }; // ptr points to x

    std::cout << ptr << ' ';

    ++ptr; // ptr = ptr + 1
    std::cout << ptr << ' ';

    --ptr; // ptr = ptr - 1
    std::cout << ptr << '\n';

    return 0;
}

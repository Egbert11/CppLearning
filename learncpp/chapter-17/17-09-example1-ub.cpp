// ============================================================
// 来源小节：17.9 Pointer arithmetic and subscripting
// 示例说明：指针加法——ptr、ptr+1、ptr+2 依次指向后一个对象（原 Example 1）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting/
// 预期输出（作者机器，4 字节 int）：
//   00AFFD80 00AFFD84 00AFFD88
// 后缀：-ub。对非数组的单一变量做指针算术，按标准属于未定义行为；
//       指针与结果必须处在同一数组内（或末尾后一个位置）才是良定义的。
//       多数实现不会阻止，实际输出（地址）依平台与运行而定。
// ============================================================
#include <iostream>

int main()
{
    int x{};
    const int* ptr{ &x }; // ptr points to x

    std::cout << ptr << ' ' << (ptr + 1) << ' ' << (ptr + 2) << '\n';

    return 0;
}

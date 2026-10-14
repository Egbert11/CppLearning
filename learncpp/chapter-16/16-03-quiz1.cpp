// ============================================================
// 来源小节：16.3 std::vector and the unsigned length and subscript problem
// 示例说明：Quiz #1 解答——输出数组长度，并用 operator[] 与 at() 两种方式打印下标 1 的元素。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem/
// 预期输出：
//   The array has 5 elements.
//   ee
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector arr { 'h', 'e', 'l', 'l', 'o' };
    std::cout << "The array has " << std::size(arr) << " elements.\n";
    std::cout << arr[1] << arr.at(1) << '\n';

    return 0;
}

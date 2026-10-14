// ============================================================
// 来源小节：16.3 std::vector and the unsigned length and subscript problem
// 示例说明：改为对 data() 返回的底层 C 风格数组指针下标——C 风格数组同时接受
//           有符号和无符号索引，因此不产生符号转换警告。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem/
// 预期输出：7
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector prime{ 2, 3, 5, 7, 11 };

    int index { 3 };                          // non-constexpr signed value
    std::cout << prime.data()[index] << '\n'; // okay: no sign conversion warnings

    return 0;
}

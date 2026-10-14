// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：改为对 data() 返回的底层 C 风格数组指针下标——C 风格数组同时
//           接受有符号和无符号下标，因此不产生符号转换警告。
//           本节称这是"最佳索引方案"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 预期输出：9 7 5 3 1
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector arr{ 9, 7, 5, 3, 1 };

    for (int index{ static_cast<int>(arr.size()) - 1 }; index >= 0; --index)
        std::cout << arr.data()[index] << ' '; // use data() to avoid sign conversion warning

    std::cout << '\n';

    return 0;
}

// ============================================================
// 来源小节：19.4 Pointers to pointers and dynamic multidimensional arrays
// 示例说明：用 auto 推导"指向数组的指针"，省去繁琐的类型书写。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-to-pointers/
// 预期输出：3
// 备注：本节代码为按原文描述重建（原文 Example 10）。
// ============================================================
#include <iostream>

int main()
{
    constexpr int x { 10 };
    auto array { new int[x][5] }; // so much simpler!

    array[9][4] = 3;

    std::cout << array[9][4] << '\n';

    delete[] array;

    return 0;
}

// ============================================================
// 来源小节：19.2 Dynamically allocating arrays
// 示例说明：C++11 之前没有初始化列表可用于动态数组，只能循环逐个赋值——"Super annoying!"
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamically-allocating-arrays/
// 预期输出：9 7 5 3 1
// 备注：本节代码为按原文描述重建（原文的"老式"初始化示例）。
// ============================================================
#include <iostream>

int main()
{
    int* array = new int[5]; // 分配 5 个 int，未初始化

    // 逐个赋值（C++11 之前唯一方便的写法）
    array[0] = 9;
    array[1] = 7;
    array[2] = 5;
    array[3] = 3;
    array[4] = 1;

    for (int i = 0; i < 5; ++i)
        std::cout << array[i] << ' ';
    std::cout << '\n';

    delete[] array;

    return 0;
}

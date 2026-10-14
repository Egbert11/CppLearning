// ============================================================
// 来源小节：19.2 Dynamically allocating arrays
// 示例说明：C++11 起可用初始化列表初始化动态数组（长度与列表之间没有 operator=），
//           并用 auto 省去重复书写类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamically-allocating-arrays/
// 预期输出：9 7 5 3 1（两行）
// 备注：本节代码为按原文描述重建（原文的 C++11 初始化列表示例）。
// ============================================================
#include <iostream>

int main()
{
    int fixedArray[5] = { 9, 7, 5, 3, 1 }; // initialize a fixed array before C++11

    // 注意：数组长度和初始化列表之间没有 operator=
    int* array{ new int[5]{ 9, 7, 5, 3, 1 } }; // initialize a dynamic array since C++11

    for (int i = 0; i < 5; ++i)
        std::cout << fixedArray[i] << ' ';
    std::cout << '\n';

    for (int i = 0; i < 5; ++i)
        std::cout << array[i] << ' ';
    std::cout << '\n';

    delete[] array;

    // To avoid redundant type specification, we can use auto
    auto* array2{ new int[5]{ 9, 7, 5, 3, 1 } }; // 用 auto 推导元素类型
    std::cout << array2[0] << ' ' << array2[4] << '\n';
    delete[] array2;

    return 0;
}

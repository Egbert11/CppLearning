// ============================================================
// 来源小节：19.4 Pointers to pointers and dynamic multidimensional arrays
// 示例说明：当最右侧维度是编译期常量时，可用"指向数组的指针"一次分配二维数组。
//           括号不能省：int* array[5] 是"含 5 个 int* 的数组"，
//           int (*array)[5] 才是"指向含 5 个 int 的数组的指针"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-to-pointers/
// 预期输出：3
// 备注：本节代码为按原文描述重建（原文 Example 9）。
// ============================================================
#include <iostream>

int main()
{
    constexpr int x { 10 };

    int (*array)[5] { new int[x][5] }; // rightmost dimension must be constexpr

    array[9][4] = 3; // This is the same as (array[9])[4] = 3;

    std::cout << array[9][4] << '\n';

    delete[] array; // 单块分配，单次释放

    return 0;
}

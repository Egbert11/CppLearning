// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：C 风格数组用 operator[] 下标访问；与标准库容器不同，下标可以是
//           任意整型（有符号或无符号），甚至无作用域枚举。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期输出：7
//            7 7
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

int main()
{
    int arr[5]; // declare an array of 5 ints (elements are uninitialized)
    arr[1] = 7; // assign value 7 to element 1

    std::cout << arr[1] << '\n';

    const int arr2[] { 9, 8, 7, 6, 5 };

    int s { 2 };          // signed index is allowed
    unsigned int u { 2 }; // unsigned index is also allowed
    std::cout << arr2[s] << ' ' << arr2[u] << '\n';

    return 0;
}

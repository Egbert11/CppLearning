// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：在函数模板里用 size_type 作循环变量；因为 std::vector<T>::size_type
//           是依赖名，用作类型时必须加 typename 前缀。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 预期输出：4 6 7 3 8 2 1 9
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

template <typename T>
void printArray(const std::vector<T>& arr)
{
    // typename required: std::vector<T>::size_type is a dependent name
    for (typename std::vector<T>::size_type index { 0 }; index < arr.size(); ++index)
        std::cout << arr[index] << ' ';

    std::cout << '\n';
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
    printArray(arr);

    return 0;
}

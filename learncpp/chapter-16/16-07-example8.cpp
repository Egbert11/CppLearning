// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：函数参数是引用类型，decltype(arr) 得到的是引用，需用
//           std::remove_reference_t 去掉引用后才能访问 ::size_type。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 预期输出：4 6 7 3 8 2 1 9
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <type_traits>
#include <vector>

template <typename T>
void printArray(const std::vector<T>& arr)
{
    using array_type = std::remove_reference_t<decltype(arr)>;

    for (typename array_type::size_type index { 0 }; index < arr.size(); ++index)
        std::cout << arr[index] << ' ';

    std::cout << '\n';
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
    printArray(arr);

    return 0;
}

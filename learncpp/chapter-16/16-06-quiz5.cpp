// ============================================================
// 来源小节：16.6 Arrays and loops
// 示例说明：Quiz #5 解答——findMax()：空 vector 返回 T{}，否则以 arr[0] 初始化并自索引 1 起循环
//           （避免用值初始化，否则全为负的数组会算错）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-and-loops/
// 预期输出：
//   92
//   -13
//   0
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

template <typename T>
T findMax(const std::vector<T>& arr)
{
    if (arr.size() == 0)
        return T{};

    T max { arr[0] }; // assume the first element is the largest
    for (std::size_t index{ 1 }; index < arr.size(); ++index)
    {
        if (arr[index] > max)
            max = arr[index];
    }

    return max;
}

int main()
{
    std::vector data1 { 84, 92, 76, 81, 56 };
    std::cout << findMax(data1) << '\n';

    std::vector data2 { -13, -50, -20, -40 };
    std::cout << findMax(data2) << '\n';

    std::vector<int> data3 { };
    std::cout << findMax(data3) << '\n';

    return 0;
}

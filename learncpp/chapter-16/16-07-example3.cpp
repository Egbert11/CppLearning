// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：用有符号索引求平均——长度用 static_cast<int>(arr.size())，
//           下标访问时再用 static_cast<std::size_t>(index) 转回。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 预期输出：The class average is: 77
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

template <typename T>
T calculateAverage(const std::vector<T>& arr)
{
    int length{ static_cast<int>(arr.size()) };

    T sum{ 0 };
    for (int index{ 0 }; index < length; ++index)
        sum += arr[static_cast<std::size_t>(index)];

    return sum / length;
}

int main()
{
    std::vector class1 { 84, 92, 76, 81, 56 };
    std::cout << "The class average is: " << calculateAverage(class1) << '\n';

    return 0;
}

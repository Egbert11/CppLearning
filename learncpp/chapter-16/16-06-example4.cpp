// ============================================================
// 来源小节：16.6 Arrays and loops
// 示例说明：函数模板 calculateAverage()，对 int 和 double 的 vector 通用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-and-loops/
// 预期输出：
//   The class 1 average is: 77
//   The class 2 average is: 81.75
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

template <typename T>
T calculateAverage(const std::vector<T>& arr)
{
    int length { static_cast<int>(arr.size()) };

    T sum { 0 };
    for (int index{ 0 }; index < length; ++index)
        sum += arr[index];

    return sum / length;
}

int main()
{
    std::vector class1 { 84, 92, 76, 81, 56 };
    std::cout << "The class 1 average is: " << calculateAverage(class1) << '\n';

    std::vector class2 { 84.5, 92.25, 76.5, 73.75 };
    std::cout << "The class 2 average is: " << calculateAverage(class2) << '\n';

    return 0;
}

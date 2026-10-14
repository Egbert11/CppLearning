// 来源小节：21.14 Overloading operators and function templates
// 示例说明：函数模板 average() 用 sum += ... 累加、再 sum /= numValues 求平均。
//           对 int、double 等内建类型开箱即用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-operators-and-function-templates/
// 说明：本节代码为按原文描述重建。
// 预期输出：
//   3
//   5.535

#include <iostream>

template <typename T>
T average(const T* myArray, int numValues)
{
    T sum{ 0 };
    for (int count{ 0 }; count < numValues; ++count)
        sum += myArray[count];

    sum /= numValues;
    return sum;
}

int main()
{
    int intArray[] { 5, 3, 2, 1, 4 };
    std::cout << average(intArray, 5) << '\n';

    double doubleArray[] { 3.12, 3.45, 9.23, 6.34 };
    std::cout << average(doubleArray, 4) << '\n';

    return 0;
}

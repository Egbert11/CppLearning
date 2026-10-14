// ============================================================
// 来源小节：18.3 Introduction to standard library algorithms
// 示例说明：std::sort 自定义比较器。std::sort 默认升序，但有一个重载接受
//           第三个参数——比较函数，它在“第一个参数应排在第二个之前”时返回
//           true，从而实现自定义排序。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/
// 预期输出：99 90 80 40 13 5
// 备注：本节代码为按原文描述重建。使用函数名即函数指针，std::sort 会以任意
//       元素对调用它。
// ============================================================
#include <algorithm>
#include <array>
#include <iostream>

bool greater(int a, int b)
{
    // Order @a before @b if @a is greater than @b.
    return a > b;
}

int main()
{
    std::array arr{ 13, 90, 99, 5, 40, 80 };

    // Pass greater to std::sort
    std::sort(arr.begin(), arr.end(), greater);

    for (int i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}

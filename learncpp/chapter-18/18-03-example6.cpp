// ============================================================
// 来源小节：18.3 Introduction to standard library algorithms
// 示例说明：进阶——把手写的选择排序改造成接受 [begin, end) 区间的泛型函数，
//           使用 std::next 取得下一个元素、用 std::swap 交换，从而可对任意
//           连续区间排序。函数名为 sort，故在主函数中以 ::sort 调用以区别于
//           std::sort。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/
// 预期输出：1 2 4 5 9
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <algorithm> // for std::swap
#include <iostream>
#include <iterator> // for std::next, std::begin, std::end

void sort(int* begin, int* end)
{
    for (auto startElement{ begin }; startElement != end; ++startElement)
    {
        auto smallestElement{ startElement };

        for (auto currentElement{ std::next(startElement) }; currentElement != end; ++currentElement)
        {
            if (*currentElement < *smallestElement)
            {
                smallestElement = currentElement;
            }
        }

        std::swap(*startElement, *smallestElement);
    }
}

int main()
{
    int array[]{ 2, 1, 9, 4, 5 };

    ::sort(std::begin(array), std::end(array));

    for (auto i : array)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}

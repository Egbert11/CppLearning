// ============================================================
// 来源小节：18.3 Introduction to standard library algorithms
// 示例说明：进阶——进一步让排序接受一个比较函数 std::function<bool(int,int)>，
//           把原来的“小于”判断替换成对比较器的调用，由调用者决定顺序。
//           （原文建议：第 20 章之前可先把 std::function 当成“魔法”使用。）
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/
// 预期输出（传 std::greater{}，降序）：9 5 4 2 1
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <algorithm> // for std::swap
#include <functional> // for std::function, std::greater
#include <iostream>
#include <iterator> // for std::next, std::begin, std::end

void sort(int* begin, int* end, std::function<bool(int, int)> compare)
{
    for (auto startElement{ begin }; startElement != end; ++startElement)
    {
        auto smallestElement{ startElement };

        for (auto currentElement{ std::next(startElement) }; currentElement != end; ++currentElement)
        {
            if (compare(*currentElement, *smallestElement))
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

    // Use the global scope operator (::) to avoid a collision with std::sort.
    ::sort(std::begin(array), std::end(array), std::greater{});

    for (auto i : array)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}

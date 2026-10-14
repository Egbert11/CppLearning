// ============================================================
// 来源小节：12.x Chapter 12 summary and quiz（本章总结小节）
// 示例说明：测验第 5 题解答。写一个按引用接收两个 int 的 sort2，使调用后
//           第一个持有较小的值、第二个持有较大的值（必要时用 std::swap，
//           也可以自己写交换）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-12-summary-and-quiz/
// 预期输出：
//   7 5
//   5 7
//   5 7
// 备注：本节代码为按原文清单忠实重建（测验 5 解答）。
// ============================================================
#include <algorithm> // for std::swap
#include <iostream>

void sort2(int& lesser, int& greater)
{
    // If the values are not sorted, we need to swap them so they are
    if (lesser > greater)
        std::swap(lesser, greater);

    // If we wrote our own swap instead, we could do so like this:
    // int swap { lesser };
    // lesser = greater;
    // greater = swap;
}

int main()
{
    int x { 7 };
    int y { 5 };

    std::cout << x << ' ' << y << '\n'; // should print 7 5

    sort2(x, y); // make sure sort works when values need to be swapped
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    sort2(x, y); // make sure sort works when values don't need to be swapped
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    return 0;
}

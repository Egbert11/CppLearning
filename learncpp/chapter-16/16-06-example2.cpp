// ============================================================
// 来源小节：16.6 Arrays and loops
// 示例说明：改用 std::vector 存成绩，但仍逐个写下标累加。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-and-loops/
// 预期输出：The class average is: 77
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector testScore { 84, 92, 76, 81, 56 };
    std::size_t length { testScore.size() };

    int average { (testScore[0] + testScore[1] + testScore[2] + testScore[3] + testScore[4]) / static_cast<int>(length) };

    std::cout << "The class average is: " << average << '\n';

    return 0;
}

// ============================================================
// 来源小节：16.6 Arrays and loops
// 示例说明：用 std::vector 加 for 循环遍历累加，最后再统一除以长度。
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

    int average { 0 };
    for (std::size_t index{ 0 }; index < length; ++index) // index from 0 to length-1
        average += testScore[index];                     // add the value of the current element
    average /= static_cast<int>(length);                 // divide by the number of elements

    std::cout << "The class average is: " << average << '\n';

    return 0;
}

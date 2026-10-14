// ============================================================
// 来源小节：16.6 Arrays and loops
// 示例说明：用 5 个各自命名的变量保存成绩并求平均——扩展性差的写法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-and-loops/
// 预期输出：The class average is: 77
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

int main()
{
    int testScore1{ 84 };
    int testScore2{ 92 };
    int testScore3{ 76 };
    int testScore4{ 81 };
    int testScore5{ 56 };

    int average { (testScore1 + testScore2 + testScore3 + testScore4 + testScore5) / 5 };

    std::cout << "The class average is: " << average << '\n';

    return 0;
}

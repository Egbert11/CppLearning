// ============================================================
// 来源小节：14.3 Member functions
// 示例说明：测验第 1 题解答——IntPair 增加成员函数 print()，格式为
//           Pair(first, second)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-functions/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

struct IntPair
{
    int first{};
    int second{};

    void print()
    {
        std::cout << "Pair(" << first << ", " << second << ")\n";
    }
};

int main()
{
    IntPair p1 { 1, 2 };
    IntPair p2 { 3, 4 };

    std::cout << "p1: ";
    p1.print();

    std::cout << "p2: ";
    p2.print();

    return 0;
}

// 预期输出：
// p1: Pair(1, 2)
// p2: Pair(3, 4)

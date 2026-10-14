// ============================================================
// 来源小节：14.3 Member functions
// 示例说明：测验第 2 题解答——为 IntPair 增加成员函数 isEqual()，比较两个
//           IntPair 的对应成员是否都相等。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-functions/
// 备注：本节代码为按原文描述忠实重建。原文解答的形参为按值传递 IntPair a。
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

    bool isEqual(IntPair a)
    {
        return (first == a.first) && (second == a.second);
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

    std::cout << "p1 and p1 are " << (p1.isEqual(p1) ? "" : "not ") << "equal\n";
    std::cout << "p1 and p2 are " << (p1.isEqual(p2) ? "" : "not ") << "equal\n";

    return 0;
}

// 预期输出：
// p1: Pair(1, 2)
// p2: Pair(3, 4)
// p1 and p1 are equal
// p1 and p2 are not equal

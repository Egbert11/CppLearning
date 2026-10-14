// ============================================================
// 来源小节：12.15 std::optional
// 示例说明：用 std::numeric_limits<int>::lowest() 作为错误哨兵。问题：每个
//           调用点都要与 lowest() 比较（冗长难看），且当参数本来就产生该值
//           时结果有歧义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdoptional/
// 备注：本节代码为按原文描述忠实重建（原 Example 3）。
//       原文只给出该函数的定义，这里补一个 main 以便独立编译。
// ============================================================
#include <iostream>
#include <limits> // for std::numeric_limits

// returns std::numeric_limits<int>::lowest() on failure
int doIntDivision(int x, int y)
{
    if (y == 0)
        return std::numeric_limits<int>::lowest();

    return x / y;
}

int main()
{
    int result { doIntDivision(20, 5) };
    if (result == std::numeric_limits<int>::lowest())
        std::cout << "failed\n";
    else
        std::cout << result << '\n';

    return 0;
}

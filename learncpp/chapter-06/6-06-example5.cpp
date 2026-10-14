// ============================================================
// 来源小节：6.6 The conditional operator
// 示例说明：用返回该值的辅助函数达到同样效果（可行，但多了不少代码）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-conditional-operator/
// 备注：本节代码为按原文描述忠实重建。输出：The class size is: 20
// ============================================================
#include <iostream>

// --- 原文示例片段 ---
int getClassSize(bool inBigClassroom)
{
    if (inBigClassroom)
        return 30;
    else
        return 20;
}

int main()
{
    constexpr bool inBigClassroom { false };
    const int classSize { getClassSize(inBigClassroom) };

    std::cout << "The class size is: " << classSize << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}

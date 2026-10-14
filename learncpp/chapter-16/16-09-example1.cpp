// ============================================================
// 来源小节：16.9 Array indexing and length using enumerators
// 示例说明：纯整数下标不说明含义——读者无法从 testScores[2] 看出它代表谁。
// 原文链接：https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators/
// 预期输出：（无输出）
// 备注：本节代码为按原文描述重建（原文为片段，此处补全为可编译程序）。
// ============================================================
#include <vector>

int main()
{
    std::vector testScores { 78, 94, 66, 77, 14 };

    testScores[2] = 76; // who does this represent?

    return 0;
}

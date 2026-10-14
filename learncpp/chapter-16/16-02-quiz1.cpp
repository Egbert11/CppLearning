// ============================================================
// 来源小节：16.2 Introduction to std::vector and list constructors
// 示例说明：Quiz #1 解答——用列表初始化构造包含前五个平方数的 vector，
//           并由 CTAD 推导出 std::vector<int>。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/
// 预期输出：1 25
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector squares{ 1, 4, 9, 16, 25 }; // list init + CTAD -> std::vector<int>

    std::cout << squares[0] << ' ' << squares[4] << '\n';

    return 0;
}

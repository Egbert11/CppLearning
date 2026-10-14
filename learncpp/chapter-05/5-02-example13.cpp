// ============================================================
// 来源小节：5.2 Literals
// 示例说明：起始值 0、递增 1 这类含义显然、不太会改变的字面量，
//           一般不算魔法数字。
// 原文链接：https://www.learncpp.com/cpp-tutorial/literals/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段（示例 13）---
    int idGenerator { 0 };         // okay: we're starting our id generator with value 0
    idGenerator = idGenerator + 1; // okay: we're just incrementing our generator
    // --- 原文示例片段结束 ---

    std::cout << idGenerator << '\n';

    return 0;
}

// ============================================================
// 来源小节：12.4 Lvalue references to const
// 示例说明："bombs" 示例——引用绑定到转换产生的临时量（int），它并不
//           是原对象（short bombs）。因此把 bombs 减到 0 后，透过 you
//           看到的仍是当初的 1，if (you) 为真。这说明"引用就是原对象"
//           的假设在绑定临时量时会失效。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/
// 备注：本节代码为按原文描述忠实重建（原 Example 7）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    short bombs { 1 };         // I can has bomb! (note: type is short)

    const int& you { bombs };  // You can has bomb too (note: type is int&)
    --bombs;                   // Bomb all gone

    if (you)                   // You still has?
    {
        std::cout << "Bombs away!  Goodbye, cruel world.\n"; // Para bailar la bomba
    }
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// Bombs away!  Goodbye, cruel world.
// （you 绑定的是由 bombs 转换出的 int 临时量，值是 1，故 if 为真。）

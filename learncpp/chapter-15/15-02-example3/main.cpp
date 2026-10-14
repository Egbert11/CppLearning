// ============================================================
// 来源小节：15.2 Classes and header files
// 文件说明：多文件示例的 main，包含 Date.h 并使用 Date 类。
// 原文链接：https://www.learncpp.com/cpp-tutorial/classes-and-header-files/
// 预期输出：Date(2015, 10, 14)
// 备注：本节代码为按原文描述重建。
// ============================================================
#include "Date.h"

int main()
{
    const Date d{ 2015, 10, 14 };
    d.print();

    return 0;
}

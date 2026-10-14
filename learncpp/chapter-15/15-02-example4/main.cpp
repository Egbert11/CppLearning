// ============================================================
// 来源小节：15.2 Classes and header files
// 文件说明：使用 inline 版 Date.h 的 main。
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

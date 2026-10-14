// ============================================================
// 来源小节：5.2 Literals
// 示例说明：上下文已说明含义的换算系数（1000）可读性足够，不算魔法数字。
// 原文链接：https://www.learncpp.com/cpp-tutorial/literals/
// ============================================================
#include <iostream>

int kmtoM(int km)
{
    return km * 1000; // okay: it's obvious 1000 is a conversion factor
}

int main()
{
    std::cout << "5 km = " << kmtoM(5) << " m\n";
    return 0;
}

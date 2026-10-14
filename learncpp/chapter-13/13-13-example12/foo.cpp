// ============================================================
// 来源小节：13.13 Class templates
// 文件说明：foo.cpp 包含 pair.h，实例化并对 Pair<int> 调用 max（原 Example 16）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include "pair.h"

#include <iostream>

void foo()
{
    Pair<int> p1{ 5, 6 }; // instantiates Pair<int> and creates object p1
    std::cout << max(p1) << " is larger\n";
}

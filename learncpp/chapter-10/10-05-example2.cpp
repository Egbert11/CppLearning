// 来源小节：10.5 Arithmetic conversions
// 示例说明：两个 short 相加——short 不在等级列表上，两者都做整型提升为 int，
//           结果是 int 9。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arithmetic-conversions/
//
// 编译：g++ -std=c++20 -Wall 10-05-example2.cpp -o a
// 注：typeid().name() 输出实现相关；原文输出 "int 9"，GCC 下类型名显示为 'i'。
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <typeinfo>

int main()
{
    // --- 原文示例片段 ---
    short a{ 4 };
    short b{ 5 };

    std::cout << typeid(a + b).name() << ' ' << a + b << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}

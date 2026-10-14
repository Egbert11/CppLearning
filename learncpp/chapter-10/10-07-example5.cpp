// 来源小节：10.7 Typedefs and type aliases
// 示例说明：复杂函数指针类型——typedef 与 using 别名对照。别名写法更易读。
//           （对应原文示例 9）
// 原文链接：https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
//
// 编译：g++ -std=c++20 -Wall 10-07-example5.cpp -o a
// 预期输出：6
//
// 本节代码为按原文描述重建。

#include <iostream>

// --- 原文示例片段 ---
typedef int (*FcnType)(double, char); // typedef 版本
using FcnType2 = int (*)(double, char); // using 版本，更易读
// --- 原文示例片段结束 ---

int multiplyToInt(double d, char c)
{
    return static_cast<int>(d) * c;
}

int main()
{
    FcnType f1 = multiplyToInt;
    FcnType2 f2 = multiplyToInt;

    std::cout << f1(2.0, 3) << ' ' << f2(2.0, 3) << '\n'; // 6 6

    return 0;
}

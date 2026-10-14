// 来源小节：10.9 Type deduction for functions
// 示例说明：显式声明返回类型 int，编译器会检查 return 表达式能否转换为 int。
//           （对应原文示例 1）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-functions/
//
// 编译：g++ -std=c++20 -Wall 10-09-example1.cpp -o a
// 预期输出：11
//
// 本节代码为按原文描述重建。

#include <iostream>

// --- 原文示例片段 ---
int add(int x, int y)
{
    return x + y;
}
// --- 原文示例片段结束 ---

int main()
{
    std::cout << add(5, 6) << '\n'; // 11
    return 0;
}

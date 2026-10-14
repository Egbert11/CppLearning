// 来源小节：11.3 Function overload resolution and ambiguous matches
// 示例说明：foo(0) 与 foo(3.14159) 相对 foo(unsigned int)/foo(float) 都需要数值转换 -> 歧义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/
//
// 编译：g++ -std=c++20 -Wall 11-03-example10-error.cpp -o a
//
// 本文件为"预期编译失败"示例（后缀 -error），请勿修复：
//   预期错误：call of overloaded 'foo(int)' is ambiguous；以及 foo(double) 的同类歧义。
//
// 本节代码为按原文描述重建。

void foo(unsigned int)
{
}

void foo(float)
{
}

int main()
{
    foo(0);       // int can be numerically converted to unsigned int or to float -> ambiguous
    foo(3.14159); // double can be numerically converted to unsigned int or to float -> ambiguous

    return 0;
}

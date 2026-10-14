// 来源小节：11.3 Function overload resolution and ambiguous matches
// 示例说明：foo(5L) 中 5L 为 long，转 int 与转 double 都是数值转换（步骤 3），彼此无优劣 -> 歧义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/
//
// 编译：g++ -std=c++20 -Wall 11-03-example9-error.cpp -o a
//
// 本文件为"预期编译失败"示例（后缀 -error），请勿修复：
//   预期错误：call of overloaded 'foo(long int)' is ambiguous。
//   （Visual Studio 报错为 error C2668: 'foo': ambiguous call to overloaded function）
//
// 本节代码为按原文描述重建。

void foo(int)
{
}

void foo(double)
{
}

int main()
{
    foo(5L); // 5L is type long: ambiguous (conversion to int or to double)

    return 0;
}

// 来源小节：11.3 Function overload resolution and ambiguous matches
// 示例说明：foo(int) 与 foo(const int&) 对实参 x 都算精确匹配（后者靠平凡转换），二者无优劣 -> 歧义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/
//
// 编译：g++ -std=c++20 -Wall 11-03-example4-error.cpp -o a
//
// 本文件为"预期编译失败"示例（后缀 -error），请勿修复：
//   预期错误：ambiguous call to overloaded function（对 foo 的调用有歧义）。
//
// 本节代码为按原文描述重建。

void foo(int)
{
}

void foo(const int&)
{
}

int main()
{
    int x { 1 };
    foo(x); // ambiguous match with foo(int) and foo(const int&)

    return 0;
}

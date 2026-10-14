// 来源小节：11.5 Default arguments
// 示例说明：两个都带默认值的重载使空调用 foo() 产生歧义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-arguments/
//
// 编译：g++ -std=c++20 -Wall 11-05-example11-error.cpp -o a
//
// 本文件为"预期编译失败"示例（后缀 -error），请勿修复：
//   预期错误：foo() -> "call of overloaded 'foo()' is ambiguous"。
//
// 本节代码为按原文描述重建。

void foo(int x = 0)
{
}

void foo(double d = 0.0)
{
}

int main()
{
    foo(); // ambiguous function call

    return 0;
}

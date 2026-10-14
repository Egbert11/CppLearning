// 来源小节：11.3 Function overload resolution and ambiguous matches
// 示例说明：非重载函数也可能"无匹配"——foo() 找到匹配即通过；goo() 找不到匹配会编译错误。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/
//
// 编译：g++ -std=c++20 -Wall 11-03-example8.cpp -o a
//
// 本节代码为按原文描述重建。
// 注：原文还调用 goo(); 那是"no match found"的编译错误示例，这里注释掉以保持本文件可编译。

#include <iostream>

void foo()
{
    std::cout << "foo()\n";
}

int main()
{
    foo(); // okay: match found
    // goo(); // compile error: no match found

    return 0;
}

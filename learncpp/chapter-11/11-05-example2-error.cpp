// 来源小节：11.5 Default arguments
// 示例说明：默认实参只能用 = 给出；括号初始化与花括号初始化都是编译错误。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-arguments/
//
// 编译：g++ -std=c++20 -Wall 11-05-example2-error.cpp -o a
//
// 本文件为"预期编译失败"示例（后缀 -error），请勿修复：
//   预期错误：goo 的 `int x ( 5 )` 与 boo 的 `int x { 5 }` 都不是合法的默认实参语法。
//
// 本节代码为按原文描述重建。

void foo(int x = 5);   // ok
void goo(int x ( 5 )); // compile error
void boo(int x { 5 }); // compile error

int main()
{
    return 0;
}

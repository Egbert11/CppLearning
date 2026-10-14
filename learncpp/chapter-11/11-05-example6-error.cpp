// 来源小节：11.5 Default arguments
// 示例说明：默认实参不能在同一翻译单元内重复声明——声明与定义只能有一处写默认值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-arguments/
//
// 编译：g++ -std=c++20 -Wall 11-05-example6-error.cpp -o a
//
// 本文件为"预期编译失败"示例（后缀 -error），请勿修复：
//   预期错误：redefinition of default argument（重复定义默认实参）。
//
// 本节代码为按原文描述重建。

#include <iostream>

void print(int x, int y=4); // forward declaration

void print(int x, int y=4) // compile error: redefinition of default argument
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

int main()
{
    return 0;
}

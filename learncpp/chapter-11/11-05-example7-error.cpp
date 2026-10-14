// 来源小节：11.5 Default arguments
// 示例说明：默认实参必须在依赖它的调用之前出现；前向声明处未写默认值时，调用报实参过少。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-arguments/
//
// 编译：g++ -std=c++20 -Wall 11-05-example7-error.cpp -o a
//
// 本文件为"预期编译失败"示例（后缀 -error），请勿修复：
//   预期错误：print(3) -> "too few arguments to function"（此时默认实参尚未声明）。
//
// 本节代码为按原文描述重建。

#include <iostream>

void print(int x, int y); // forward declaration, no default argument

int main()
{
    print(3); // compile error: default argument for y hasn't been defined yet

    return 0;
}

void print(int x, int y=4)
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

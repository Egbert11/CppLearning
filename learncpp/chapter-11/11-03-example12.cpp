// 来源小节：11.3 Function overload resolution and ambiguous matches
// 示例说明：多参数时的解析——所有候选对第一形参(char)都精确匹配；第二实参 'a'(char)
//           经数值提升匹配 int，提升优先于到 double/float 的转换，故胜出的是 print(char, int)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/
//
// 编译：g++ -std=c++20 -Wall 11-03-example12.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 预期输出：
//   print(char, int)

#include <iostream>

void print(char, int)
{
    std::cout << "print(char, int)\n";
}

void print(char, double)
{
    std::cout << "print(char, double)\n";
}

void print(char, float)
{
    std::cout << "print(char, float)\n";
}

int main()
{
    print('x', 'a'); // both args match char exactly for the first param;
                     // 'a' is promoted to int for the second -> print(char, int)

    return 0;
}

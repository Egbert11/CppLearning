// 来源小节：2.5 Introduction to local scope
// 示例说明：add() 中的 z 是局部变量；函数参数 x、y 同样是局部变量。
//           （覆盖原文示例 1 与示例 2：z 是局部变量 / 形参也是局部变量。）
//           预期输出：11
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/
//
// 编译：g++ -std=c++20 -Wall 2-05-example1.cpp -o a

#include <iostream>

int add(int x, int y) // function parameters x and y are local variables
{
    int z{ x + y }; // z is a local variable

    return z;
}

int main()
{
    std::cout << add(5, 6) << '\n';

    return 0;
}

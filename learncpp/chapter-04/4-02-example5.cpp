// 来源小节：4.2 Void
// 示例说明：首选的等价写法 —— 空的参数列表即隐式 void，表示函数没有参数。
//           与 4-02-example4.cpp 对比：二者行为相同，但本写法更受推荐。
//           预期交互：读入一个整数并打印它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/void/
//
// 编译：g++ -std=c++20 -Wall 4-02-example5.cpp -o a

#include <iostream>

int getValue() // empty function parameters is an implicit void
{
    int x{};
    std::cin >> x;

    return x;
}

int main()
{
    std::cout << getValue() << '\n';
    return 0;
}

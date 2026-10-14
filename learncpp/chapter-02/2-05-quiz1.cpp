// 来源小节：2.5 Introduction to local scope
// 示例说明：Quiz #1 —— doIt() 的 x、y 与 main 的 x、y 是各自独立的变量：
//           main 传给 doIt 的 x 在函数内被修改，但不会影响 main 的 x。
//           预期输出：
//           main: x = 1 y = 2
//           doIt: x = 1 y = 4
//           doIt: x = 3 y = 4
//           main: x = 1 y = 2
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/
//
// 编译：g++ -std=c++20 -Wall 2-05-quiz1.cpp -o a

#include <iostream>

void doIt(int x)
{
    int y{ 4 }; // doIt's own local y
    std::cout << "doIt: x = " << x << " y = " << y << '\n';

    x = 3; // modifies doIt's x only, not main's x
    std::cout << "doIt: x = " << x << " y = " << y << '\n';
}

int main()
{
    int x{ 1 };
    int y{ 2 };

    std::cout << "main: x = " << x << " y = " << y << '\n';

    doIt(x);

    std::cout << "main: x = " << x << " y = " << y << '\n';

    return 0;
}

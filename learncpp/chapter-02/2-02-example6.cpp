// 来源小节：2.2 Function return values (value-returning functions)
// 示例说明：使用可移植的退出码 EXIT_SUCCESS（来自 <cstdlib>）代替字面量 0。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-02-example6.cpp -o a

#include <cstdlib> // for EXIT_SUCCESS

int main()
{
    // your code goes here

    return EXIT_SUCCESS;
}

// 来源小节：2.7 Forward declarations and definitions
// 示例说明：用前置声明修复原始程序 —— 在 main() 上方声明 add()，虽然 add() 的函数体在后面才定义。
//           预期输出：The sum of 3 and 4 is: 7
// 原文链接：https://www.learncpp.com/cpp-tutorial/forward-declarations/
//
// 编译：g++ -std=c++20 -Wall 2-07-example4.cpp -o a

#include <iostream>

int add(int x, int y); // forward declaration of add() (using a function declaration)

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // this works because we forward declared add() above
    return 0;
}

int add(int x, int y) // even though the body of add() isn't defined until here
{
    return x + y;
}

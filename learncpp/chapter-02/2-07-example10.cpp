// 来源小节：2.7 Forward declarations and definitions
// 示例说明：Quiz #4 解答 —— doMath(...) 的前置声明（推荐带上参数名）与它的定义。
//           预期输出：The result is: 3
// 原文链接：https://www.learncpp.com/cpp-tutorial/forward-declarations/
//
// 编译：g++ -std=c++20 -Wall 2-07-example10.cpp -o a

#include <iostream>

// Do not forget the semicolon at the end, since these are statements.
int doMath(int first, int second, int third, int fourth);

int main()
{
    std::cout << "The result is: " << doMath(1, 2, 3, 4) << '\n'; // 1 + 2 * 3 / 4 = 1 + 6/4 = 1 + 1 = 3
    return 0;
}

int doMath(int first, int second, int third, int fourth)
{
     return first + second * third / fourth;
}

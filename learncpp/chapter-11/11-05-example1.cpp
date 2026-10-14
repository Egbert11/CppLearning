// 来源小节：11.5 Default arguments
// 示例说明：形参 y 带默认实参 4；调用 print(3) 等价于 print(3, 4)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-arguments/
//
// 编译：g++ -std=c++20 -Wall 11-05-example1.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   x: 1
//   y: 2
//   x: 3
//   y: 4

#include <iostream>

void print(int x, int y=4) // 4 is the default argument
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

int main()
{
    print(1, 2); // y will use user-supplied argument 2
    print(3);    // y will use default argument 4, as if we had called print(3, 4)

    return 0;
}

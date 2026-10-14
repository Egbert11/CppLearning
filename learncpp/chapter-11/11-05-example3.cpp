// 来源小节：11.5 Default arguments
// 示例说明：多个默认实参——从右往左依次省略时使用默认值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-arguments/
//
// 编译：g++ -std=c++20 -Wall 11-05-example3.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   Values: 1 2 3
//   Values: 1 2 30
//   Values: 1 20 30
//   Values: 10 20 30

#include <iostream>

void print(int x=10, int y=20, int z=30)
{
    std::cout << "Values: " << x << " " << y << " " << z << '\n';
}

int main()
{
    print(1, 2, 3); // all explicit arguments
    print(1, 2);    // rightmost argument defaulted
    print(1);       // two rightmost arguments defaulted
    print();        // all arguments defaulted

    return 0;
}

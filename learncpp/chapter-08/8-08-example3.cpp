// 来源小节：8.8 Introduction to loops and while statements
// 示例说明：条件一开始就为假——15 <= 10 不成立，循环体一次都不执行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/
//
// 编译：g++ -std=c++20 -Wall 8-08-example3.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   done!

#include <iostream>

int main()
{
    int count{ 15 };
    while (count <= 10)
    {
        std::cout << count << ' ';
        ++count;
    }

    std::cout << "done!\n";

    return 0;
}

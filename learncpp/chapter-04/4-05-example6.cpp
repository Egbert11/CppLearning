// 来源小节：4.5 Unsigned integers, and why to avoid them
// 示例说明：有符号/无符号比较陷阱。-1 被隐式转换成 4294967295，因此 s < u 为假，走 else 分支。
//           原文输出：1 is less than -1
//           注意：g++ -Wall 会对该比较给出 -Wsign-compare 警告
//           （warning: comparison of integer expressions of different signedness），但程序仍能编译运行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/
//
// 编译：g++ -std=c++20 -Wall 4-05-example6.cpp -o a

#include <iostream>

// assume int is 4 bytes
int main()
{
    signed int s { -1 };
    unsigned int u { 1 };

    if (s < u) // -1 is implicitly converted to 4294967295, and 4294967295 < 1 is false
        std::cout << "-1 is less than 1\n";
    else
        std::cout << "1 is less than -1\n"; // this statement executes

    return 0;
}

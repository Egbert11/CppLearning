// 来源小节：4.2 Void
// 示例说明：在 void 函数中返回一个值 —— 本文件故意无法编译。
//           原文给出的报错（Visual Studio 2017）：error C2562: 'noReturn': 'void' function returning a value
//           g++ 报错信息形如：error: return-statement with a value, in function returning 'void' [-fpermissive]
// 原文链接：https://www.learncpp.com/cpp-tutorial/void/
//
// 编译：g++ -std=c++20 -Wall 4-02-example3-error.cpp -o a   （预期编译失败）

#include <iostream>

void noReturn(int x) // void here means no return value
{
    std::cout << "The value of x is: " << x << '\n';

    return 5; // error
}

int main()
{
    noReturn(5);
    return 0;
}

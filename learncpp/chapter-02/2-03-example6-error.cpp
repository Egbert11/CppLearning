// 来源小节：2.3 Void functions (non-value returning functions)
// 示例说明：从 void 函数返回值 —— void 表示不返回值，写 return 5; 是编译错误。
//           【预期编译错误】编译本文件应失败，错误类似：
//           error: return-statement with a value, in function returning 'void'
//           本示例按原文意图保留错误写法，不要“修正”它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/void-functions-non-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-03-example6-error.cpp -o a   （会报错，属预期）

#include <iostream>

void printHi()
{
    std::cout << "In printHi()" << '\n';

    return 5; // compile error: we're not allowed to return a value from a void function
}

int main()
{
    printHi();

    return 0;
}

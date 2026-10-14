// 来源小节：2.3 Void functions (non-value returning functions)
// 示例说明：需要值的表达式 —— std::cout << 5; 合法（5 是要打印的字面量），
//           而 std::cout << ; 因为没给定要打印的值而编译错误。
//           【预期编译错误】编译本文件应失败，错误类似：
//           error: expected primary-expression before ';' token
//           本示例按原文意图保留错误写法，不要“修正”它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/void-functions-non-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-03-example3-error.cpp -o a   （会报错，属预期）

#include <iostream>

int main()
{
    std::cout << 5; // ok: 5 is a literal value to be printed
    std::cout << ;  // compile error: no value provided for std::cout to print

    return 0;
}

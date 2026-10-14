// 来源小节：2.3 Void functions (non-value returning functions)
// 示例说明：把 void 调用放进需要值的上下文 —— printHi(); 单独调用没问题，
//           但 std::cout << printHi(); 编译错误，因为 std::cout 不能打印 void 值。
//           【预期编译错误】编译本文件应失败，错误类似：
//           error: no match for 'operator<<' (operand types are 'std::ostream' and 'void')
//           本示例按原文意图保留错误写法，不要“修正”它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/void-functions-non-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-03-example4-error.cpp -o a   （会报错，属预期）

#include <iostream>

void printHi()
{
    std::cout << "Hi" << '\n';
}

int main()
{
    printHi(); // okay: function call to printHi() (void return value is not used)

    std::cout << printHi(); // compile error: std::cout can't print a void value

    return 0;
}

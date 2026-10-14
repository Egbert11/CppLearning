// 来源小节：2.3 Void functions (non-value returning functions)
// 示例说明：对比不同的调用上下文：
//           - returnNothing(); 和 returnFive(); 单独调用都没问题；
//           - std::cout << returnFive(); 没问题（打印 5）；
//           - std::cout << returnNothing(); 是编译错误（std::cout 无法打印 void）。
//           【预期编译错误】最后一行会报错，错误类似：
//           error: no match for 'operator<<' (operand types are 'std::ostream' and 'void')
//           本示例按原文意图保留错误写法，不要“修正”它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/void-functions-non-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-03-example5-error.cpp -o a   （会报错，属预期）

#include <iostream>

// void means the function does not return a value to the caller
void returnNothing()
{
}

// int means the function returns an integer value to the caller
int returnFive()
{
    return 5;
}

int main()
{
    // okay: these functions can be called in a context that does not need a value
    returnNothing(); // okay: return value of returnNothing() is void
    returnFive();    // okay: return value of returnFive() is int (the value 5 is discarded)

    // okay: returnFive() returns int, which std::cout can print
    std::cout << returnFive() << '\n'; // prints 5

    // compile error: returnNothing() returns void, and std::cout can't print a void value
    std::cout << returnNothing(); // compile error

    return 0;
}

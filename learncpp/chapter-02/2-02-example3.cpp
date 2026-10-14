// 来源小节：2.2 Function return values (value-returning functions)
// 示例说明：returnFive() 演示返回值：第一次把返回值交给 std::cout 打印，第二次在表达式中使用，
//           第三次直接调用而忽略返回值（返回值被丢弃）。
//           预期输出：
//           5
//           7
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/
//
// 编译：g++ -std=c++20 -Wall 2-02-example3.cpp -o a

#include <iostream>

// int is the return type
// A return type of int means the function will return some integer value to the caller (the specific value determined by the return statement)
int returnFive()
{
    // the return statement provides the value that will be returned
    return 5; // return the value 5 back to the caller
}

int main()
{
    std::cout << returnFive() << '\n';     // prints 5
    std::cout << returnFive() + 2 << '\n'; // prints 7

    returnFive(); // okay: the return value of 5 is ignored

    return 0;
}

// 来源小节：4.2 Void
// 示例说明：void 返回类型表示函数不返回值。writeValue() 打印数值，且没有 return 语句。
//           预期输出：The value of x is: 5
// 原文链接：https://www.learncpp.com/cpp-tutorial/void/
//
// 编译：g++ -std=c++20 -Wall 4-02-example2.cpp -o a

#include <iostream>

void writeValue(int x) // void here means no return value
{
    std::cout << "The value of x is: " << x << '\n';
    // no return statement, because this function doesn't return a value
}

int main()
{
    writeValue(5);
    return 0;
}

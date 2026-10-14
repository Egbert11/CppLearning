// 来源小节：11.5 Default arguments
// 示例说明：重载函数中使用默认实参——print() 因 print(std::string_view) 无默认值而解析到 print(char)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-arguments/
//
// 编译：g++ -std=c++20 -Wall 11-05-example9.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 预期输出：
//   Hello, world
//   a
//   (一个空格)

#include <iostream>
#include <string_view>

void print(std::string_view s)
{
    std::cout << s << '\n';
}

void print(char c = ' ')
{
    std::cout << c << '\n';
}

int main()
{
    print("Hello, world"); // resolves to print(std::string_view)
    print('a');            // resolves to print(char)
    print();               // resolves to print(char)

    return 0;
}

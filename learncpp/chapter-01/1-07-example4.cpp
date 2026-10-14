// 来源小节：1.7 Keywords and naming identifiers
// 示例说明：原文测验——逐一判定若干变量声明的命名是否惯例/合法，答案写在注释中。
// 原文链接：https://www.learncpp.com/cpp-tutorial/keywords-and-naming-identifiers/
//
// 编译：g++ -std=c++20 -Wall 1-07-example4.cpp -o example4

#include <iostream>

int main()
{
    int sum {};                         // 惯例（假设求和对象明显）
    // int _apples {};                  // 非惯例：变量名不应以下划线开头
    // int VALUE {};                    // 非惯例：单词名应全部小写
    // int my variable name {};         // 非法：变量名不能含空格
    // int TotalCustomers {};           // 非惯例：变量名应以小写字母开头
    // int void {};                     // 非法：void 是关键字
    int numFruit {};                    // 惯例
    // int 3some {};                    // 非法：变量名不能以数字开头
    int meters_of_pipe {};              // 惯例

    sum = 1;
    numFruit = 2;
    meters_of_pipe = 3;

    std::cout << sum << ' ' << numFruit << ' ' << meters_of_pipe << '\n';
    return 0;
}

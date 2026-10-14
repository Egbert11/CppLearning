// 来源小节：2.1 Introduction to functions
// 示例说明：坏实践 —— 把函数 foo() 定义在 main() 内部，即“嵌套函数”，C++ 不允许。
//           【预期编译错误】编译本文件应失败，错误类似：
//           error: 'void foo()' cannot be defined inside function 'int main()'
//           （不同编译器措辞不同，本质是“函数不能定义在另一函数内部”。）
//           本示例按原文意图保留错误写法，请不要“修正”它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-functions/
//
// 编译：g++ -std=c++20 -Wall 2-01-example4-error.cpp -o a   （会报错，属预期）

#include <iostream>

int main()
{
    void foo() // Illegal: this function is nested inside function main()
    {
        std::cout << "foo!\n";
    }

    foo(); // function call to foo()

    return 0;
}

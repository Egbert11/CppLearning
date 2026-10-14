// 来源小节：2.1 Introduction to functions
// 示例说明：定义一个用户自定义函数 doPrint()，并在 main() 中调用它。
//           演示函数头、函数体以及函数调用（caller = main，callee = doPrint）。
//           预期输出：
//           Starting main()
//           In doPrint()
//           Ending main()
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-functions/
//
// 编译：g++ -std=c++20 -Wall 2-01-example1.cpp -o a

#include <iostream> // for std::cout

// Definition of user-defined function doPrint()
void doPrint() // doPrint() is the called function in this example
{
    std::cout << "In doPrint()\n";
}

// Definition of function main()
int main()
{
    std::cout << "Starting main()\n";
    doPrint(); // Interrupt main() by making a function call to doPrint().  main() is the caller.
    std::cout << "Ending main()\n"; // this statement is executed after doPrint() ends

    return 0;
}

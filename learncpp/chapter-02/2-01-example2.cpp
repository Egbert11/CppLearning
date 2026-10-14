// 来源小节：2.1 Introduction to functions
// 示例说明：在 main() 中连续两次调用同一个 doPrint()，演示函数可以被反复调用。
//           预期输出：
//           Starting main()
//           In doPrint()
//           In doPrint()
//           Ending main()
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-functions/
//
// 编译：g++ -std=c++20 -Wall 2-01-example2.cpp -o a

#include <iostream> // for std::cout

void doPrint()
{
    std::cout << "In doPrint()\n";
}

// Definition of function main()
int main()
{
    std::cout << "Starting main()\n";
    doPrint(); // doPrint() called for the first time
    doPrint(); // doPrint() called for the second time
    std::cout << "Ending main()\n";

    return 0;
}

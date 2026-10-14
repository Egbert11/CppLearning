// 来源小节：2.1 Introduction to functions
// 示例说明：main() 调用 doA()，doA() 再调用 doB()，演示函数调用可以层层嵌套。
//           预期输出：
//           Starting main()
//           Starting doA()
//           In doB()
//           Ending doA()
//           Ending main()
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-functions/
//
// 编译：g++ -std=c++20 -Wall 2-01-example3.cpp -o a

#include <iostream> // for std::cout

void doB()
{
    std::cout << "In doB()\n";
}

void doA()
{
    std::cout << "Starting doA()\n";

    doB();

    std::cout << "Ending doA()\n";
}

// Execution of a program starts in main()
int main()
{
    std::cout << "Starting main()\n";

    doA();

    std::cout << "Ending main()\n";

    return 0;
}

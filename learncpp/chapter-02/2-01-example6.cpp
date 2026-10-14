// 来源小节：2.1 Introduction to functions
// 示例说明：本节 Quiz #2 —— 依照调用顺序跟踪输出。
//           main() 先调用 doA()（其中再调用 doB()），然后自己直接调用 doB()。
//           预期输出：
//           Starting main()
//           In doA()
//           In doB()
//           In doB()
//           Ending main()
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-functions/
//
// 编译：g++ -std=c++20 -Wall 2-01-example6.cpp -o a

#include <iostream>

void doB()
{
    std::cout << "In doB()\n";
}

void doA()
{
    std::cout << "In doA()\n";
    doB();
}

// Execution of a program starts in main()
int main()
{
    std::cout << "Starting main()\n";

    doA(); // calls doA(), which calls doB()
    doB(); // calls doB() directly

    std::cout << "Ending main()\n";

    return 0;
}

// 来源小节：2.13 How to design your first programs
// 示例说明：原文 Example 3 —— 逐个实现函数：先完整实现 getUserInput()，
//           并在 main() 中加临时测试代码验证返回值（测好后删除测试代码）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/how-to-design-your-first-programs/
//
// 编译：g++ -std=c++20 -Wall 2-13-example3.cpp -o a

#include <iostream>

// Full implementation of the getUserInput function
int getUserInput()
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;

    return input;
}

int main()
{
    // Get first number from user
    int value{ getUserInput() }; // Note we've included code here to test the return value!
    std::cout << value << '\n'; // debug code to ensure getUserInput() is working, we'll remove this later

    // Get mathematical operation from user
//    getMathematicalOperation();

    // Get second number from user
//    getUserInput();

    // Calculate result
//    calculateResult();

    // Print result
//    printResult();

    return 0;
}

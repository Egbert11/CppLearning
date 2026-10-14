// 来源小节：2.5 Introduction to local scope
// 示例说明：作用域演示 —— x 在定义点“进入作用域”，在 main 的右花括号处“离开作用域”；
//           在 doSomething() 中 x 完全不在作用域内。
//           预期输出：
//           How are you?
//           I'm fine
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/
//
// 编译：g++ -std=c++20 -Wall 2-05-example4.cpp -o a

#include <iostream>

// x is not in scope anywhere in this function
void doSomething()
{
    std::cout << "Hello!\n";
}

int main()
{
    std::cout << "How are you?\n";

    int x{ 0 }; // x enters scope here and can now be used within main()
    std::cout << "I'm fine\n";

    return 0;
} // x goes out of scope here and can no longer be used

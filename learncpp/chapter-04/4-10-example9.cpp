// 来源小节：4.10 Introduction to if statements
// 示例说明：无条件的提前返回（没有用处：return 之后的语句是死代码，永远不会打印 B）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/
// 原示例是一个 void print() 片段，这里补一个 main() 调用它。
// 注意：函数体中 return 之后的语句会被编译器视为不可达代码（可能产生警告）。

#include <iostream>

void print()
{
    std::cout << "A" << '\n';

    return; // the function will always return to the caller here

    std::cout << "B" << '\n'; // this will never be printed
}

int main()
{
    print();
    return 0;
}

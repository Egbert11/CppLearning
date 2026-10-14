// 来源小节：4.10 Introduction to if statements
// 示例说明：非布尔条件——整数 x(4) 被转换为 bool。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/
// 输出：hi（因为 4 非零，转换为 true）

#include <iostream>

int main()
{
    int x { 4 };
    if (x) // nonsensical, but for the sake of example...
        std::cout << "hi\n";
    else
        std::cout << "bye\n";

    return 0;
}

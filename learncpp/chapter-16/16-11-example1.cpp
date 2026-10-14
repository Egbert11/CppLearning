// ============================================================
// 来源小节：16.11 std::vector and stack behavior
// 示例说明：用 push_back()/back()/pop_back() 演示 vector 的"栈"接口，
//           并用 printStack 同时打印容量与长度以便观察增长行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-stack-behavior/
// 预期输出（GCC 或 Clang；容量因实现而异）：
//   Empty   Capacity: 0  Length 0
//   1       Capacity: 1  Length 1
//   1 2     Capacity: 2  Length 2
//   1 2 3   Capacity: 4  Length 3
//   Top: 3
//   1 2     Capacity: 4  Length 2
//   1       Capacity: 4  Length 1
//   Empty   Capacity: 4  Length 0
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

void printStack(const std::vector<int>& stack)
{
    if (stack.empty()) // if stack.size == 0
        std::cout << "Empty";

    for (auto element : stack)
        std::cout << element << ' ';

    // \t is a tab character, to help align the text
    std::cout << "\tCapacity: " << stack.capacity() << "  Length " << stack.size() << "\n";
}

int main()
{
    std::vector<int> stack {}; // empty stack

    printStack(stack);

    stack.push_back(1); // push_back() pushes an element on the stack
    printStack(stack);

    stack.push_back(2);
    printStack(stack);

    stack.push_back(3);
    printStack(stack);

    std::cout << "Top: " << stack.back() << '\n'; // back() returns the last element

    stack.pop_back(); // pop_back() pops an element off the stack
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    return 0;
}

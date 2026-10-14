// ============================================================
// 来源小节：16.11 std::vector and stack behavior
// 示例说明：用 reserve(6) 只把容量预置为 6、长度仍为 0，
//           于是后续 push 全部落在容量之内，不再触发重新分配。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-stack-behavior/
// 预期输出（原作者机器上的结果）：
//   Empty   Capacity: 0  Length 0
//   Empty   Capacity: 6  Length 0
//   1       Capacity: 6  Length 1
//   1 2     Capacity: 6  Length 2
//   1 2 3   Capacity: 6  Length 3
//   Top: 3
//   1 2     Capacity: 6  Length 2
//   1       Capacity: 6  Length 1
//   Empty   Capacity: 6  Length 0
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

    std::cout << "\tCapacity: " << stack.capacity() << "  Length " << stack.size() << "\n";
}

int main()
{
    std::vector<int> stack {};

    printStack(stack);

    stack.reserve(6); // reserve space for 6 elements (but do not change length)
    printStack(stack);

    stack.push_back(1);
    printStack(stack);

    stack.push_back(2);
    printStack(stack);

    stack.push_back(3);
    printStack(stack);

    std::cout << "Top: " << stack.back() << '\n';

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    return 0;
}

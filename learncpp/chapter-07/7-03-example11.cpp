// 来源小节：7.3 Local variables
// 示例说明：用 std::swap()（<utility>）替代三行手写交换，效果等价。（对应原文 Example 11）
// 原文链接：https://www.learncpp.com/cpp-tutorial/local-variables/
//
// 预期输出（输入 4 然后 2）：
//   Enter an integer: 4
//   Enter a larger integer: 2
//   Swapping the values
//   The smaller value is 2
//   The larger value is 4
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>
#include <utility> // for std::swap

int main()
{
    std::cout << "Enter an integer: ";
    int smaller{};
    std::cin >> smaller;

    std::cout << "Enter a larger integer: ";
    int larger{};
    std::cin >> larger;

    if (smaller > larger)
    {
        std::cout << "Swapping the values\n";
        std::swap(larger, smaller); // replaces the three-statement manual swap
    }

    std::cout << "The smaller value is " << smaller << '\n';
    std::cout << "The larger value is " << larger << '\n';

    return 0;
}

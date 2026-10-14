// 来源小节：7.3 Local variables
// 示例说明：本节 Quiz 第 1 题解答——读取两个整数并保证第一个较小；若次序不对，用一个
//           受限于内层块的临时变量 temp 交换它们（temp 在块结束即销毁）。
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

int main()
{
    std::cout << "Enter an integer: ";
    int smaller{};
    std::cin >> smaller;

    std::cout << "Enter a larger integer: ";
    int larger{};
    std::cin >> larger;

    // if user did it wrong
    if (smaller > larger)
    {
        std::cout << "Swapping the values\n";

        int temp{ larger }; // temp defined only where it is needed
        larger = smaller;
        smaller = temp;
    } // temp destroyed here

    std::cout << "The smaller value is " << smaller << '\n';
    std::cout << "The larger value is " << larger << '\n';

    return 0;
} // smaller and larger destroyed here

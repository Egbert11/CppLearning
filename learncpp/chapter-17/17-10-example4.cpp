// ============================================================
// 来源小节：17.10 C-style strings
// 示例说明：推荐用 std::cin.getline() 配合 std::size() 读入固定缓冲区（原 Example 4）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-strings/
// 交互示例，无固定预期输出（输入什么就回显什么）。
// ============================================================
#include <iostream>
#include <iterator> // for std::size

int main()
{
    char rolls[255] {}; // declare array large enough to hold 254 characters + null terminator
    std::cout << "Enter your rolls: ";
    std::cin.getline(rolls, std::size(rolls));
    std::cout << "You entered: " << rolls << '\n';

    return 0;
}

// ============================================================
// 来源小节：17.10 C-style strings
// 示例说明：用 operator>> 读入固定缓冲区（原 Example 3）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-strings/
// 后缀：-broken（坏实践演示）。C++20 之前，operator>> 会尽可能多地抽取字符，
//       过长的输入会写穿固定数组、造成缓冲区溢出（未定义行为，可能被攻击者利用）。
//       C++20 起 operator>> 只对未退化的 C 风格字符串生效，会限制在数组长度内，
//       因此本文件在 C++20 下可编译且安全；这里保留原样以说明历史上为何危险。
// ============================================================
#include <iostream>

int main()
{
    char rolls[255] {}; // declare array large enough to hold 254 characters + null terminator
    std::cout << "Enter your rolls: ";
    std::cin >> rolls;
    std::cout << "You entered: " << rolls << '\n';

    return 0;
}

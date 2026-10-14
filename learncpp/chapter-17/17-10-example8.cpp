// ============================================================
// 来源小节：17.10 C-style strings
// 示例说明：std::strlen() 对数组和退化后的指针都可用，返回不含空终止符的字符串长度（原 Example 8）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-strings/
// 预期输出：
//   length = 6
//   length = 6
// ============================================================
#include <cstring> // for std::strlen
#include <iostream>

int main()
{
    char str[255]{ "string" }; // 6 characters + null terminator
    std::cout << "length = " << std::strlen(str) << '\n'; // prints length = 6

    char *ptr { str };
    std::cout << "length = " << std::strlen(ptr) << '\n'; // prints length = 6

    return 0;
}

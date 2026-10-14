// ============================================================
// 来源小节：17.10 C-style strings
// 示例说明：直接输出 C 风格字符串，以及通过函数（形参退化为指针）输出（原 Example 2）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-strings/
// 预期输出：
//   string
//   string
// ============================================================
#include <iostream>

void print(char ptr[])
{
    std::cout << ptr << '\n'; // output string
}

int main()
{
    char str[]{ "string" };
    std::cout << str << '\n'; // outputs string

    print(str);

    return 0;
}

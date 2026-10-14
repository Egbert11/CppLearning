// ============================================================
// 来源小节：17.10 C-style strings
// 示例说明：std::size() 对数组返回数组长度（255），但对退化后的指针无法编译（原 Example 7）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-strings/
// 预期错误：std::size(ptr) 处无法编译（std::size() 不能作用于指针）。请勿"修复"。
//           第一个输出应为 "length = 255"（std::size 返回的是数组长度，不是字符串长度）。
// ============================================================
#include <iostream>
#include <iterator> // for std::size

int main()
{
    char str[255]{ "string" }; // 6 characters + null terminator
    std::cout << "length = " << std::size(str) << '\n'; // prints length = 255

    char *ptr { str };
    std::cout << "length = " << std::size(ptr) << '\n'; // compile error

    return 0;
}

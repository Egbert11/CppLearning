// ============================================================
// 来源小节：17.11 C-style string symbolic constants
// 示例说明：相同的字符串字面量可能被编译器合并为同一份（原 Example 3）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-string-symbolic-constants/
// 备注：示例仅声明两个指向相同字面量的指针。编译器是否合并依实现而定，
//       因此两个指针保存的地址"可能相同也可能不同"，程序不应依赖这一点。
// ============================================================
#include <iostream>

int main()
{
    const char* name1{ "Alex" };
    const char* name2{ "Alex" }; // compiler may merge the two identical literals

    std::cout << name1 << ' ' << name2 << '\n';
    std::cout << std::boolalpha << (name1 == name2) << '\n'; // implementation-defined

    return 0;
}

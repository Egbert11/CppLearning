// ============================================================
// 来源小节：13.4 Converting an enumeration to and from a string
// 示例说明：字符串转枚举无法用 switch（不能对字符串 switch），因此用一连串
//           if 比较；无效输入用 std::optional 返回"无值"，比专门加一个
//           invalid 枚举量更好。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-an-enumeration-to-and-from-a-string/
// 备注：本节代码为按原文描述忠实重建。此实现只匹配小写。
// ============================================================
#include <iostream>
#include <optional> // for std::optional
#include <string>
#include <string_view>

enum Pet
{
    cat,   // 0
    dog,   // 1
    pig,   // 2
    whale, // 3
};

constexpr std::string_view getPetName(Pet pet)
{
    switch (pet)
    {
    case cat:   return "cat";
    case dog:   return "dog";
    case pig:   return "pig";
    case whale: return "whale";
    default:    return "???";
    }
}

constexpr std::optional<Pet> getPetFromString(std::string_view sv)
{
    // We can only switch on an integral value (or enum), not a string
    // so we have to use if-statements here
    if (sv == "cat")   return cat;
    if (sv == "dog")   return dog;
    if (sv == "pig")   return pig;
    if (sv == "whale") return whale;

    return {};
}

int main()
{
    std::cout << "Enter a pet: cat, dog, pig, or whale: ";
    std::string s{};
    std::cin >> s;

    std::optional<Pet> pet { getPetFromString(s) };

    if (!pet)
        std::cout << "You entered an invalid pet\n";
    else
        std::cout << "You entered: " << getPetName(*pet) << '\n';

    return 0;
}

// 预期交互（输入 dog）：
// Enter a pet: cat, dog, pig, or whale: dog
// You entered: dog

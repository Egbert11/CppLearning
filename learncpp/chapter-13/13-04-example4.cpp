// ============================================================
// 来源小节：13.4 Converting an enumeration to and from a string
// 示例说明：读整数输入并做范围检查后再 static_cast 成枚举。只有确认输入落在
//           枚举量范围内，才能安全转换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-an-enumeration-to-and-from-a-string/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
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

int main()
{
    std::cout << "Enter a pet (0=cat, 1=dog, 2=pig, 3=whale): ";

    int input{};
    std::cin >> input; // input an integer

    if (input < 0 || input > 3)
        std::cout << "You entered an invalid pet\n";
    else
    {
        Pet pet{ static_cast<Pet>(input) }; // static_cast our integer to a Pet
        std::cout << "You entered: " << getPetName(pet) << '\n';
    }

    return 0;
}

// 预期交互（输入 2）：
// Enter a pet (0=cat, 1=dog, 2=pig, 3=whale): 2
// You entered: pig

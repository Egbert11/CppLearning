// ============================================================
// 来源小节：13.5 Introduction to overloading the I/O operators
// 示例说明：为 operator>> 写重载，教 std::istream 如何读取一个 Pet。
//           std::cin 的类型是 std::istream，故左参数与返回类型都是 std::istream&；
//           枚举参数是非 const 引用（out 参数），否则赋值只会改到副本上。
//           找不到匹配时用 in.setstate(std::ios_base::failbit) 置失败状态，
//           与 std::cin 的正常行为一致，调用者可据此检测流状态。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-overloading-the-i-o-operators/
// 备注：本节代码为按原文描述忠实重建。提取失败时标准 operator>> 会把基本类型
//       零初始化（原文注释里的 pet = {}; 即模拟此行为）。
// ============================================================
#include <iostream>
#include <optional>
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
    if (sv == "cat")   return cat;
    if (sv == "dog")   return dog;
    if (sv == "pig")   return pig;
    if (sv == "whale") return whale;

    return {};
}

// Teach operator>> how to read a Pet
// This function returns an istream& so callers can chain calls to it
std::istream& operator>>(std::istream& in, Pet& pet)
{
    std::string s{};
    in >> s; // get input from the stream

    std::optional<Pet> match { getPetFromString(s) };
    if (match) // do we have a match?
    {
        pet = *match;
        return in;
    }

    // We didn't find a match so enter an error:
    in.setstate(std::ios_base::failbit); // set the stream to a failed state
    return in;

    // If we passed pet by value, the assignment above would only modify a copy,
    // so pet must be an out parameter (non-const reference).
    // On extraction failure, operator>> zero-initializes fundamental types, i.e.:
    // pet = {};
}

std::ostream& operator<<(std::ostream& out, Pet pet)
{
    return out << getPetName(pet);
}

int main()
{
    std::cout << "Enter a pet: cat, dog, pig, or whale: ";
    Pet pet{};
    std::cin >> pet;

    if (std::cin) // if we found a match
        std::cout << "You chose: " << pet << '\n';
    else
    {
        std::cin.clear();  // reset the failed state
        std::string ignore{};
        std::cin >> ignore; // ignore the invalid input
        std::cout << "Your pet was not valid\n";
    }

    return 0;
}

// 预期交互（输入 dog）：
// Enter a pet: cat, dog, pig, or whale: dog
// You chose: dog

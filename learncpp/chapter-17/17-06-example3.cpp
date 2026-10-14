// ============================================================
// 来源小节：17.6 std::array and enumerations
// 示例说明：用 switch/if 链把枚举映射到字符串时，字符串字面量被重复写了两遍
//           （getPetName 与 getPetFromString 各一份），新增枚举项时必须手动
//           同步多处，容易出错——这正是用数组替换的背景动机。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-and-enumerations/
// 预期输出：cat dog pig whale
//            whale
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string_view>

namespace Pets
{
    enum Type
    {
        cat,
        dog,
        pig,
        whale,
        max_pets
    };
}

constexpr std::string_view getPetName(Pets::Type pet)
{
    switch (pet)
    {
    case Pets::cat:   return "cat";
    case Pets::dog:   return "dog";
    case Pets::pig:   return "pig";
    case Pets::whale: return "whale";
    default:          return "???";
    }
}

constexpr Pets::Type getPetFromString(std::string_view name)
{
    // duplicated literals: must be kept in sync with getPetName()
    if (name == "cat")   return Pets::cat;
    if (name == "dog")   return Pets::dog;
    if (name == "pig")   return Pets::pig;
    if (name == "whale") return Pets::whale;
    return Pets::max_pets; // unknown
}

int main()
{
    for (int i{ 0 }; i < Pets::max_pets; ++i)
        std::cout << getPetName(static_cast<Pets::Type>(i)) << ' ';
    std::cout << '\n';

    std::cout << getPetName(getPetFromString("whale")) << '\n';

    return 0;
}

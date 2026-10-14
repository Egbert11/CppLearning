// ============================================================
// 来源小节：16.x Chapter 16 summary and quiz —— 测验 2 解答（Step 2 完整版）
// 示例说明：定义游戏物品枚举与数量 vector，用计数枚举量做断言，输出总物品数；
//           再用循环逐项输出数量与名称，并按数量正确处理单复数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz/
// 预期输出：
//   You have 16 total items
//   You have 1 health potion
//   You have 5 torches
//   You have 10 arrows
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <cassert>
#include <iostream>
#include <string_view>
#include <type_traits> // for std::is_integral and std::is_enum
#include <vector>

namespace Items
{
    enum Type
    {
        health_potion,
        torch,
        arrow,
        max_items
    };
}

std::string_view getItemNameSingular(Items::Type type)
{
    switch (type)
    {
    case Items::health_potion: return "health potion";
    case Items::torch:         return "torch";
    case Items::arrow:         return "arrow";

    default:                   return "???";
    }
}

std::string_view getItemNamePlural(Items::Type type)
{
    switch (type)
    {
    case Items::health_potion: return "health potions";
    case Items::torch:         return "torches";
    case Items::arrow:         return "arrows";

    default:                   return "???";
    }
}

// Convert an integral or enum value to its underlying integral type, for indexing
template <typename T>
constexpr auto toUZ(T t)
{
    static_assert(std::is_integral_v<T> || std::is_enum_v<T>);

    return static_cast<std::underlying_type_t<T>>(t);
}

void printInventoryItem(const std::vector<int>& inventory, Items::Type type)
{
    bool plural { inventory[toUZ(type)] != 1 };
    std::cout << "You have " << inventory[toUZ(type)] << ' ';
    std::cout << (plural ? getItemNamePlural(type) : getItemNameSingular(type)) << '\n';
}

int countTotalItems(const std::vector<int>& inventory)
{
    int sum { 0 };
    for (auto e : inventory)
        sum += e;
    return sum;
}

int main()
{
    std::vector inventory { 1, 5, 10 }; // 1 health potion, 5 torches, 10 arrows
    assert(std::size(inventory) == Items::max_items);

    std::cout << "You have " << countTotalItems(inventory) << " total items\n";

    for (std::size_t i { 0 }; i < inventory.size(); ++i)
        printInventoryItem(inventory, static_cast<Items::Type>(i));

    return 0;
}

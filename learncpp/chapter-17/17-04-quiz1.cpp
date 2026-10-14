// ============================================================
// 来源小节：17.4 std::array of class types, and brace elision
// 示例说明：Quiz #1 解答——用 CTAD 与"单层花括号 + 逐元素显式 Item{...}"
//           初始化一个 constexpr std::array<Item, 4> 并打印。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-of-class-types-and-brace-elision/
// 预期输出：The store has 5 gold worth of sword.
//            The store has 3 gold worth of shield.
//            The store has 1 gold worth of potion.
//            The store has 1 gold worth of torch.
//            The store has a total of 10 gold.
// 备注：本节代码为按原文描述重建；具体商品与数值按原文描述重拟。
// ============================================================
#include <array>
#include <cstddef>
#include <iostream>
#include <string_view>

namespace Items
{
    struct Item
    {
        std::string_view name{};
        int gold{};
    };

    template <std::size_t N>
    void printStore(const std::array<Item, N>& store)
    {
        int totalGold{ 0 };
        for (const auto& item : store)
        {
            std::cout << "The store has " << item.gold << " gold worth of " << item.name << ".\n";
            totalGold += item.gold;
        }
        std::cout << "The store has a total of " << totalGold << " gold.\n";
    }
}

int main()
{
    // CTAD + brace elision: each initializer names the element type explicitly
    constexpr std::array store {
        Items::Item{ "sword", 5 },
        Items::Item{ "shield", 3 },
        Items::Item{ "potion", 1 },
        Items::Item{ "torch", 1 }
    };

    Items::printStore(store);

    return 0;
}

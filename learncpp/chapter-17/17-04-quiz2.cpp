// ============================================================
// 来源小节：17.4 std::array of class types, and brace elision
// 示例说明：Quiz #2 解答——与 Quiz #1 相同的 struct 与 printStore，但数组
//           显式声明为 std::array<Item, 4> 且各初始化列表不写出元素类型，
//           因此必须使用双层花括号，不能依赖花括号省略。
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
    // No CTAD, no brace elision: the element type is not named per initializer,
    // so an extra pair of braces is required.
    constexpr std::array<Items::Item, 4> store {{
        { "sword", 5 },
        { "shield", 3 },
        { "potion", 1 },
        { "torch", 1 }
    }};

    Items::printStore(store);

    return 0;
}

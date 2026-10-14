// 来源小节：17.x Chapter 17 summary and quiz（测验 2 解答，最终 Step #3）
// 示例说明：Roscoe 魔药店。用 enum + constexpr std::array 表示药水种类/名称/价格，
//           Player 类记录金子和库存，whichPotion()/buy()/printInventory() 构成游戏循环。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz/
// 编译：g++ -std=c++20 -Wall 17-14-quiz2/*.cpp
// 这是交互式程序，需要用户输入。本节代码为按原文描述重建。

#include <array>
#include <cassert>
#include <iostream>
#include <limits>
#include <string_view>

#include "Random.h"

namespace Potion
{
    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        max_potions
    };

    constexpr std::array types { healing, mana, speed, invisibility }; // An array of our enumerators

    // We could also write this as "constexpr std::array<int, max_potions> cost { 20, 30, 12, 50 };"
    constexpr std::array cost { 20, 30, 12, 50 }; // The cost of the potions in gold

    constexpr std::array<std::string_view, max_potions> name { "healing", "mana", "speed", "invisibility" };

    static_assert(std::size(types) == max_potions);
    static_assert(std::size(cost) == max_potions);
    static_assert(std::size(name) == max_potions);

    void shop()
    {
        std::cout << "Here is our selection for today:\n";

        for (auto p: types)
            std::cout << p << ") " << name[p] << " costs " << cost[p] << '\n';
    }
}

class Player
{
private:
    static constexpr int s_minStartingGold { 80 };
    static constexpr int s_maxStartingGold { 120 };

    std::string m_name { };
    int m_gold { Random::get(s_minStartingGold, s_maxStartingGold) };

    std::array<int, Potion::max_potions> m_inventory { };

public:
    explicit Player(std::string_view name) : m_name { name } { }

    int gold() const { return m_gold; }
    int inventory(Potion::Type p) const { return m_inventory[p]; }

    bool buy(Potion::Type p)
    {
        if (m_gold < Potion::cost[p])
            return false;

        m_gold -= Potion::cost[p];
        ++m_inventory[p];
        return true;
    }
};

// Handle invalid input
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Convert a char to an int (e.g. '3' -> 3)
int charNumToInt(char c)
{
    return c - '0';
}

Potion::Type whichPotion()
{
    std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
    char input{};
    while (true)
    {
        std::cin >> input;
        if (!std::cin)
        {
            std::cin.clear(); // reset error flags
            ignoreLine();     // remove any extraneous input
            std::cout << "That was invalid input. Please try again: ";
            continue;
        }

        // If the user entered 'q', quit
        if (input == 'q')
            return Potion::max_potions;

        // Convert the char to an int
        int num { charNumToInt(input) };

        // Make sure it's in-range
        if (num >= 0 && num < Potion::max_potions)
        {
            // Make sure the user typed a single digit
            if (std::cin.peek() != '\n')
            {
                ignoreLine();
                std::cout << "That was invalid input. Please try again: ";
                continue;
            }
            return static_cast<Potion::Type>(num);
        }

        std::cout << "That was invalid input. Please try again: ";
        ignoreLine();
    }
}

void printInventory(const Player& player)
{
    for (int i = 0; i < Potion::max_potions; ++i)
    {
        if (player.inventory(static_cast<Potion::Type>(i)) > 0)
            std::cout << "You have " << player.inventory(static_cast<Potion::Type>(i))
                      << " " << Potion::name[i] << " potions.\n";
    }
}

int main()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n";
    std::cout << "Enter your name: ";

    std::string name{};
    std::getline(std::cin >> std::ws, name);

    Player player{ name };

    std::cout << "Hello, " << name << ", you have " << player.gold() << " gold.\n\n";

    while (true)
    {
        Potion::shop();
        std::cout << '\n';

        Potion::Type p { whichPotion() };
        if (p == Potion::max_potions)
        {
            std::cout << '\n';
            break;
        }

        std::cout << "You've chosen to buy " << Potion::name[p] << " for " << Potion::cost[p] << " gold.\n";

        if (player.buy(p))
        {
            std::cout << "You purchased a " << Potion::name[p] << " potion. You have "
                      << player.gold() << " gold left.\n\n";
        }
        else
        {
            std::cout << "You can not afford that.\n\n";
        }
    }

    std::cout << "Thanks for shopping at Roscoe's potion emporium!\n";
    printInventory(player);

    return 0;
}

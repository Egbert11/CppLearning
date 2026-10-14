// ============================================================
// 来源小节：24.x Chapter 24 summary and quiz（测验 3 挑战题·解答）
// 示例说明：完整的打怪游戏。Creature 为基类，Player 与 Monster 派生自它。
//           Player 击败怪物获得金币并升级；达到 20 级获胜，生命归零则失败。
//           额外加分部分加入了 Health/Strength/Poison 三种、小/中/大三种尺寸的药水，
//           每场胜利后有 30% 概率获得。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz/
// 预期输出（每次运行随机，示例片段）：
//   Welcome, Alex.
//   You have 10 health and are carrying 0 gold.
//
//   A orc (o) was created.
//   (R)un or (F)ight: f
//   You hit the orc for 1 damage.
//   ...
//   You died at level 3 and with 35 gold.
//   Too bad you can't take it with you!
// 备注：本节代码为按原文描述重建。为便于单文件编译，这里内置了一个极简随机数
//       辅助命名空间，替代原文的 Random.h。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>
#include <array>
#include <random>

// ---- 极简随机数辅助（替代原文的 Random.h）----
namespace Random
{
    std::mt19937& engine()
    {
        static std::mt19937 mt{ std::random_device{}() };
        return mt;
    }

    int get(int min, int max)
    {
        std::uniform_int_distribution dist{ min, max };
        return dist(engine());
    }
}

class Creature
{
protected:
    std::string m_name;
    char m_symbol{};
    int m_health{};
    int m_damage{};
    int m_gold{};

public:
    Creature(std::string_view name, char symbol, int health, int damage, int gold)
        : m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_damage{ damage }, m_gold{ gold }
    {
    }

    const std::string& getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHealth() const { return m_health; }
    int getDamage() const { return m_damage; }
    int getGold() const { return m_gold; }

    void reduceHealth(int health) { m_health -= health; }
    void addHealth(int health) { m_health += health; }
    void addDamage(int damage) { m_damage += damage; }
    bool isDead() const { return m_health <= 0; }
    void addGold(int gold) { m_gold += gold; }
};

class Potion
{
public:
    enum Type { health, strength, poison, max_types };
    enum Size { small, medium, large, max_sizes };

private:
    Type m_type{};
    Size m_size{};

public:
    Potion(Type type, Size size)
        : m_type{ type }, m_size{ size }
    {
    }

    Type getType() const { return m_type; }
    Size getSize() const { return m_size; }

    static std::string_view typeName(Type type)
    {
        switch (type)
        {
        case health:   return "Health";
        case strength: return "Strength";
        case poison:   return "Poison";
        default:       return "???";
        }
    }

    static std::string_view sizeName(Size size)
    {
        switch (size)
        {
        case small:  return "Small";
        case medium: return "Medium";
        case large:  return "Large";
        default:     return "???";
        }
    }

    static Potion getRandomPotion()
    {
        return Potion{
            static_cast<Type>(Random::get(0, max_types - 1)),
            static_cast<Size>(Random::get(0, max_sizes - 1))
        };
    }
};

class Player : public Creature
{
    int m_level{ 1 };

public:
    Player(std::string_view name)
        : Creature{ name, '@', 10, 1, 0 }
    {
    }

    void levelUp()
    {
        ++m_level;
        ++m_damage;
    }

    int getLevel() const { return m_level; }
    bool hasWon() const { return m_level >= 20; }

    void drinkPotion(const Potion& potion)
    {
        switch (potion.getType())
        {
        case Potion::health:
            switch (potion.getSize())
            {
            case Potion::small:  addHealth(2); break;
            case Potion::medium: addHealth(2); break;
            case Potion::large:  addHealth(5); break;
            default: break;
            }
            break;
        case Potion::strength:
            addDamage(1);
            break;
        case Potion::poison:
            reduceHealth(1);
            break;
        default:
            break;
        }

        std::cout << "You drank a " << Potion::sizeName(potion.getSize())
                  << " potion of " << Potion::typeName(potion.getType()) << ".\n";
    }
};

class Monster : public Creature
{
public:
    enum Type
    {
        dragon,
        orc,
        slime,
        max_types
    };

    struct MonsterData
    {
        std::string_view name;
        char symbol;
        int health;
        int damage;
        int gold;
    };

    static const MonsterData monsterData[max_types];

    Monster(Type type)
        : Creature{ monsterData[type].name, monsterData[type].symbol,
                    monsterData[type].health, monsterData[type].damage,
                    monsterData[type].gold }
    {
        std::cout << "A " << m_name << " (" << m_symbol << ") was created.\n";
    }

    static Monster getRandomMonster()
    {
        return Monster{ static_cast<Type>(Random::get(0, max_types - 1)) };
    }
};

const Monster::MonsterData Monster::monsterData[Monster::max_types]
{
    { "dragon", 'D', 20, 4, 100 },
    { "orc",    'o',  4, 2,  25 },
    { "slime",  's',  1, 1,  10 }
};

// ---- 游戏逻辑 ----

// Handle the player attacking the monster
void attackMonster(Player& player, Monster& monster)
{
    if (player.isDead())
        return;

    std::cout << "You hit the " << monster.getName() << " for "
              << player.getDamage() << " damage.\n";
    monster.reduceHealth(player.getDamage());

    if (monster.isDead())
    {
        std::cout << "You killed the " << monster.getName() << ".\n";
        player.levelUp();
        std::cout << "You are now level " << player.getLevel() << ".\n";
        player.addGold(monster.getGold());
        std::cout << "You found " << monster.getGold() << " gold.\n";

        // 30% chance of finding a potion after a won fight (extra credit)
        if (Random::get(1, 10) <= 3)
        {
            Potion potion{ Potion::getRandomPotion() };
            std::cout << "You found a mysterious potion. Drink it? (d)rink or (f)lee: ";
            char choice{};
            std::cin >> choice;
            if (choice == 'd')
                player.drinkPotion(potion);
            else
                std::cout << "You ignored the potion.\n";
        }
    }
}

// Handle the monster attacking the player
void attackPlayer(Player& player, Monster& monster)
{
    if (monster.isDead())
        return;

    std::cout << "The " << monster.getName() << " hit you for "
              << monster.getDamage() << " damage.\n";
    player.reduceHealth(monster.getDamage());
}

// Handle a full fight with one monster
void fightMonster(Player& player)
{
    Monster monster{ Monster::getRandomMonster() };

    while (!monster.isDead() && !player.isDead())
    {
        std::cout << "(R)un or (F)ight: ";
        char choice{};
        std::cin >> choice;

        if (choice == 'r' || choice == 'R')
        {
            if (Random::get(1, 2) == 1)
            {
                std::cout << "You successfully fled.\n";
                return;
            }
            std::cout << "You failed to flee.\n";
            attackPlayer(player, monster);
            continue;
        }

        attackMonster(player, monster);
        attackPlayer(player, monster);
    }
}

int main()
{
    std::cout << "Enter your name: ";
    std::string playerName;
    std::cin >> playerName;

    Player player{ playerName };
    std::cout << "Welcome, " << player.getName() << ".\n";
    std::cout << "You have " << player.getHealth() << " health and are carrying "
              << player.getGold() << " gold.\n";

    while (!player.isDead() && !player.hasWon())
        fightMonster(player);

    if (player.isDead())
    {
        std::cout << "You died at level " << player.getLevel() << " and with "
                  << player.getGold() << " gold.\n";
        std::cout << "Too bad you can't take it with you!\n";
    }
    else
    {
        std::cout << "You won the game with " << player.getGold() << " gold!\n";
    }

    return 0;
}

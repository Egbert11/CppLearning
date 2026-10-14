// ============================================================
// 来源小节：13.x Chapter 13 summary and quiz（本仓库文件号 13-16）
// 示例说明：测验 1 解答——Monster 结构体（限定作用域枚举 + 名字 + 生命值）与打印函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-13-summary-and-quiz/
// 备注：本节代码为按原文清单与站点标准写法重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

enum class MonsterType
{
    ogre,
    dragon,
    orc,
    giant_spider,
    slime,
};

struct Monster
{
    MonsterType type{};
    std::string name{};
    int health{};
};

std::string_view getMonsterTypeString(MonsterType type)
{
    switch (type)
    {
    case MonsterType::ogre:         return "Ogre";
    case MonsterType::dragon:       return "Dragon";
    case MonsterType::orc:          return "Orc";
    case MonsterType::giant_spider: return "Giant Spider";
    case MonsterType::slime:        return "Slime";
    }

    return "Unknown";
}

void printMonster(const Monster& monster)
{
    std::cout << "This " << getMonsterTypeString(monster.type) <<
        " is named " << monster.name <<
        " and has " << monster.health << " health.\n";
}

int main()
{
    Monster ogre{ MonsterType::ogre, "Torg", 145 };
    Monster slime{ MonsterType::slime, "Blurp", 23 };

    printMonster(ogre);
    printMonster(slime);

    return 0;
}

// 预期输出：
// This Ogre is named Torg and has 145 health.
// This Slime is named Blurp and has 23 health.

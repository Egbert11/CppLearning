// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：测验 1 解答。定义一个名为 MonsterType 的无作用域枚举，包含
//           orc、goblin、troll、ogre、skeleton，并创建该类型的变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
enum MonsterType
{
    orc,
    goblin,
    troll,
    ogre,
    skeleton,
};

int main()
{
    [[maybe_unused]] MonsterType monster { troll };
    return 0;
}

// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：测验 2 解答。把 MonsterType 放进一个名为 Monster 的命名空间，
//           这样枚举量不会污染全局命名空间，使用时需写 Monster::troll。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
namespace Monster
{
    enum MonsterType
    {
        orc,
        goblin,
        troll,
        ogre,
        skeleton,
    };
}

int main()
{
    [[maybe_unused]] Monster::MonsterType monster { Monster::troll };
    return 0;
}

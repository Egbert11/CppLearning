// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：枚举的典型用途——一小组彼此相关、且对象每次只取其一的常量：
//           星期、方位、花色。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
enum DaysOfWeek
{
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
};

enum CardinalDirections
{
    north,
    east,
    south,
    west,
};

enum CardSuits
{
    clubs,
    diamonds,
    hearts,
    spades,
};

int main()
{
    [[maybe_unused]] DaysOfWeek today { tuesday };
    [[maybe_unused]] CardinalDirections facing { north };
    [[maybe_unused]] CardSuits card { hearts };

    return 0;
}

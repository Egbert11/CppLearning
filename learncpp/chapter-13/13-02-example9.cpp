// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：游戏里用枚举 ItemType 表示"玩家当前手上拿的物品"，一次只可能是
//           其中之一，因此很适合用枚举。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

enum ItemType
{
    sword,
    torch,
    potion,
};

int main()
{
    ItemType holding { torch };

    switch (holding)
    {
    case sword:  std::cout << "You are holding a sword\n"; break;
    case torch:  std::cout << "You are holding a torch\n"; break;
    case potion: std::cout << "You are holding a potion\n"; break;
    }

    return 0;
}

// 预期输出：
// You are holding a torch

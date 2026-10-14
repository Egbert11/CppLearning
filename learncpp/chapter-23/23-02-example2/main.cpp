// ============================================================
// 来源小节：23.2 Composition
// 示例说明：多文件组合示例的驱动程序。Creature 由 std::string 名字
//           与 Point2D 位置"组合"而成；程序反复移动该生物。
// 原文链接：https://www.learncpp.com/cpp-tutorial/composition/
// 预期输出（原文转录）：
//   Enter a name for your creature: Marvin
//   Marvin is at (4, 7)
//   Enter new X location for creature (-1 to quit): 6
//   Enter new Y location for creature (-1 to quit): 12
//   Marvin is at (6, 12)
//   Enter new X location for creature (-1 to quit): 3
//   Enter new Y location for creature (-1 to quit): 2
//   Marvin is at (3, 2)
//   Enter new X location for creature (-1 to quit): -1
// 备注：本节代码为按原文描述重建（原 Example 2/3/4 的多文件程序）。
// ============================================================
#include <string>
#include <iostream>
#include "Creature.h"
#include "Point2D.h"

int main()
{
    std::cout << "Enter a name for your creature: ";
    std::string name;
    std::cin >> name;
    Creature creature{ name, { 4, 7 } };

    while (true)
    {
        // print the creature's name and location
        std::cout << creature << '\n';

        std::cout << "Enter new X location for creature (-1 to quit): ";
        int x{ 0 };
        std::cin >> x;
        if (x == -1)
            break;

        std::cout << "Enter new Y location for creature (-1 to quit): ";
        int y{ 0 };
        std::cin >> y;
        if (y == -1)
            break;

        creature.moveTo(x, y);
    }

    return 0;
}

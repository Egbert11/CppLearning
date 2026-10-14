// ============================================================
// 来源小节：17.4 std::array of class types, and brace elision
// 示例说明：用 CTAD 初始化——每个初始化列表都显式写出元素类型 House，于是
//           编译器得以推导出 std::array<House, 3>。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-of-class-types-and-brace-elision/
// 预期输出：House number 13 has 7 rooms.
//            House number 14 has 10 rooms.
//            House number 15 has 8 rooms.
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

struct House
{
    int number{};
    int stories{};
    int roomsPerStory{};
};

int main()
{
    constexpr std::array houses { // use CTAD to deduce the template arguments <House, 3>
        House{ 13, 1, 7 },
        House{ 14, 2, 5 },
        House{ 15, 2, 4 }
    };

    for (const auto& house : houses)
    {
        std::cout << "House number " << house.number
                  << " has " << (house.stories * house.roomsPerStory)
                  << " rooms.\n";
    }

    return 0;
}

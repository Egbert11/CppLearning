// ============================================================
// 来源小节：17.4 std::array of class types, and brace elision
// 示例说明：std::array 的元素可以是类类型（如 struct）。先默认构造数组，
//           再对每个元素用花括号列表赋值——编译器会把右侧转换为 House。
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
    std::array<House, 3> houses{};

    houses[0] = { 13, 1, 7 };
    houses[1] = { 14, 2, 5 };
    houses[2] = { 15, 2, 4 };

    for (const auto& house : houses)
    {
        std::cout << "House number " << house.number
                  << " has " << (house.stories * house.roomsPerStory)
                  << " rooms.\n";
    }

    return 0;
}

// ============================================================
// 来源小节：17.4 std::array of class types, and brace elision
// 示例说明：修正写法——外层花括号初始化 std::array 结构体，多出来的一层
//           花括号初始化其内部的 C 风格数组成员，然后每个元素各有一对自己的
//           花括号。这就是"额外的花括号"（double braces）。
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
    // note: double braces
    constexpr std::array<House, 3> houses {{
        { 13, 1, 7 },
        { 14, 2, 5 },
        { 15, 2, 4 }
    }};

    for (const auto& house : houses)
    {
        std::cout << "House number " << house.number
                  << " has " << (house.stories * house.roomsPerStory)
                  << " rooms.\n";
    }

    return 0;
}

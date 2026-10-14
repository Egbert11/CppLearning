// ============================================================
// 来源小节：17.4 std::array of class types, and brace elision
// 示例说明：省略元素类型、只用一层花括号会失败——编译器把第一个花括号列表
//           当作整个 C 风格数组成员的初始化器，随后报"初始化值过多"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-of-class-types-and-brace-elision/
// 预期错误：编译错误——too many initializers for 'std::array<House, 3>'。
// 备注：本文件为预期编译失败示例（-error），请勿修复。正确写法见
//       17-04-example4.cpp（外层再加一对花括号）。
// ============================================================
#include <array>

struct House
{
    int number{};
    int stories{};
    int roomsPerStory{};
};

int main()
{
    std::array<House, 3> houses { // doesn't work: needs an extra pair of braces
        { 13, 1, 7 },
        { 14, 2, 5 },
        { 15, 2, 4 }
    };

    return houses[0].number;
}

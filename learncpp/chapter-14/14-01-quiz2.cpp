// ============================================================
// 来源小节：14.1 Introduction to object-oriented programming
// 示例说明：测验第 2 题解答——面向对象版本扩充出 snake 只需新增一个
//           Snake 类型；既有类型与代码基本无需改动，体现了可扩展性优势。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-object-oriented-programming/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string_view>

struct Cat
{
    std::string_view name{ "cat" };
    int numLegs{ 4 };
};

struct Dog
{
    std::string_view name{ "dog" };
    int numLegs{ 4 };
};

struct Chicken
{
    std::string_view name{ "chicken" };
    int numLegs{ 2 };
};

struct Snake
{
    std::string_view name{ "snake" };
    int numLegs{ 0 };
};

int main()
{
    constexpr Snake animal;
    std::cout << "a " << animal.name << " has " << animal.numLegs << " legs\n";

    return 0;
}

// 预期输出：
// a snake has 0 legs

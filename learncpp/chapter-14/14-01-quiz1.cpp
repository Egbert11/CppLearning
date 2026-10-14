// ============================================================
// 来源小节：14.1 Introduction to object-oriented programming
// 示例说明：测验第 1 题解答——把过程式版本扩充出 snake：需要修改
//           enum AnimalType 以及 animalName()、numLegs() 两个函数，
//           在大程序里还可能牵连其它所有用到 AnimalType 的函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-object-oriented-programming/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string_view>

enum AnimalType
{
    cat,
    dog,
    chicken,
    snake,
};

constexpr std::string_view animalName(AnimalType type)
{
    switch (type)
    {
    case cat: return "cat";
    case dog: return "dog";
    case chicken: return "chicken";
    case snake: return "snake";
    default:  return "";
    }
}

constexpr int numLegs(AnimalType type)
{
    switch (type)
    {
    case cat: return 4;
    case dog: return 4;
    case chicken: return 2;
    case snake: return 0;

    default:  return 0;
    }
}

int main()
{
    constexpr AnimalType animal{ snake };
    std::cout << "A " << animalName(animal) << " has " << numLegs(animal) << " legs\n";

    return 0;
}

// 预期输出：
// A snake has 0 legs

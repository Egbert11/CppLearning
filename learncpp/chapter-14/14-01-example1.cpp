// ============================================================
// 来源小节：14.1 Introduction to object-oriented programming
// 示例说明：过程式编程（procedural programming）风格——数据（enum AnimalType）
//           与行为（自由函数 animalName()/numLegs()）是彼此分离的两样东西，
//           调用方必须手动把数据作为实参传给函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-object-oriented-programming/
// 备注：本节代码为按原文描述忠实重建（抓取工具对长代码块有逐字引用上限）。
// ============================================================
#include <iostream>
#include <string_view>

enum AnimalType
{
    cat,
    dog,
    chicken,
};

constexpr std::string_view animalName(AnimalType type)
{
    switch (type)
    {
    case cat: return "cat";
    case dog: return "dog";
    case chicken: return "chicken";
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
    default:  return 0;
    }
}

int main()
{
    constexpr AnimalType animal{ cat };
    std::cout << "A " << animalName(animal) << " has " << numLegs(animal) << " legs\n";

    return 0;
}

// 预期输出：
// A cat has 4 legs

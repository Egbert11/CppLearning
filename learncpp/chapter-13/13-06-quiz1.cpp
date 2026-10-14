// ============================================================
// 来源小节：13.6 Scoped enumerations (enum classes)
// 示例说明：测验解答。用 enum class Animal 表示动物，getAnimalName 返回名字，
//           printNumberOfLegs 打印腿数，两部分都带 default 错误处理。
// 原文链接：https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string_view>

enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

constexpr std::string_view getAnimalName(Animal animal)
{
    // std::string_view 可用（C++17）；若用 C++14 可返回 std::string
    switch (animal)
    {
    case Animal::pig:     return "pig";
    case Animal::chicken: return "chicken";
    case Animal::goat:    return "goat";
    case Animal::cat:     return "cat";
    case Animal::dog:     return "dog";
    case Animal::duck:    return "duck";
    default:              return "???";
    }
}

void printNumberOfLegs(Animal animal)
{
    std::cout << "A " << getAnimalName(animal) << " has ";

    switch (animal)
    {
    case Animal::pig:
    case Animal::goat:
    case Animal::cat:
    case Animal::dog:
        std::cout << 4;
        break;
    case Animal::chicken:
    case Animal::duck:
        std::cout << 2;
        break;
    default:
        std::cout << "???";
        break;
    }

    std::cout << " legs.\n";
}

int main()
{
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);

    return 0;
}

// 预期输出：
// A cat has 4 legs.
// A chicken has 2 legs.

// ============================================================
// 来源小节：17.6 std::array and enumerations
// 示例说明：Quiz 解答——为动物枚举建立并行的 types 与 data 数组（都用
//           static_assert 校验长度），重载 operator>> 读入动物名，用
//           printAnimalData 打印信息。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-and-enumerations/
// 预期输出（输入 dog）：
//            Enter an animal: dog
//            A dog has 4 legs and says woof.
//            A chicken has 2 legs and says cluck.
//            A cat has 4 legs and says meow.
//            An elephant has 4 legs and says pawoo.
//            A duck has 2 legs and says quack.
//            A snake has 0 legs and says hissss.
// 备注：本节代码为按原文描述重建；动物数据按原文描述重拟。
// ============================================================
#include <array>
#include <iostream>
#include <string>
#include <string_view>

namespace Animal
{
    enum Type
    {
        chicken,  // 0
        dog,      // 1
        cat,      // 2
        elephant, // 3
        duck,     // 4
        snake,    // 5
        max_animals
    };

    struct Data
    {
        std::string_view name{};
        int legs{};
        std::string_view sound{};
    };

    constexpr std::array types { chicken, dog, cat, elephant, duck, snake };
    constexpr std::array data
    {
        Data{ "chicken",  2, "cluck" },
        Data{ "dog",      4, "woof" },
        Data{ "cat",      4, "meow" },
        Data{ "elephant", 4, "pawoo" },
        Data{ "duck",     2, "quack" },
        Data{ "snake",    0, "hissss" }
    };

    static_assert(std::size(types) == max_animals);
    static_assert(std::size(data) == max_animals);

    std::istream& operator>>(std::istream& in, Type& type)
    {
        std::string name{};
        in >> name;

        for (std::size_t i{ 0 }; i < data.size(); ++i)
        {
            if (data[i].name == name)
            {
                type = static_cast<Type>(i);
                return in;
            }
        }

        in.setstate(std::ios_base::failbit);
        type = static_cast<Type>(0); // mimic the zero-init of a failed extraction
        return in;
    }

    void printAnimalData(Type animal)
    {
        std::cout << "A " << data[animal].name << " has " << data[animal].legs
                  << " legs and says " << data[animal].sound << ".\n";
    }
}

int main()
{
    std::cout << "Enter an animal: ";
    Animal::Type animal{};
    std::cin >> animal;

    if (!std::cin)
    {
        std::cin.clear();
        std::cout << "Unknown animal\n";
    }

    // print the animal the user entered first (if valid), then the rest
    if (std::cin)
        Animal::printAnimalData(animal);

    for (auto a : Animal::types)
    {
        if (a != animal)
            Animal::printAnimalData(a);
    }

    return 0;
}

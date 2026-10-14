// ============================================================
// 来源小节：13.6 Scoped enumerations (enum classes)
// 示例说明：（进阶）通过重载一元 operator+，实现"显式转换到底层类型"的便利
//           写法（+Animals::elephant），同时不允许意外的隐式转换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/
// 备注：本节代码为按原文描述忠实重建。原文的重载模板未加约束，这里用
//       requires std::is_enum_v<T> 加以约束，避免影响其它类型的一元 +
//       （语义等价，只是更安全）。
// ============================================================
#include <iostream>
#include <type_traits> // for std::is_enum_v, std::underlying_type_t

enum class Animals
{
    chicken,   // 0
    dog,       // 1
    cat,       // 2
    elephant,  // 3
    duck,      // 4
    snake,     // 5

    maxAnimals,
};

// Overload unary operator+ to allow explicit conversion to the underlying type
// without allowing implicit conversion
template <typename T>
    requires std::is_enum_v<T>
constexpr auto operator+(T a) noexcept
{
    return static_cast<std::underlying_type_t<T>>(a);
}

int main()
{
    std::cout << +Animals::elephant << '\n'; // prints 3

    return 0;
}

// 预期输出：
// 3

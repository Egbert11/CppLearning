// ============================================================
// 来源小节：14.1 Introduction to object-oriented programming
// 示例说明：面向对象式（OOP-like）写法——每种动物都是一个自包含的类型，
//           把"属性"（name/numLegs 数据成员）与"行为"（此例为数据本身）
//           打包在同一个类型里；main 只需创建并读取对象成员。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-object-oriented-programming/
// 备注：本节代码为按原文描述忠实重建。引入 struct 把属性打包进类型，
//       扩充功能时只需新增一个类型，几乎不改动既有代码。
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

int main()
{
    constexpr Cat animal;
    std::cout << "a " << animal.name << " has " << animal.numLegs << " legs\n";

    return 0;
}

// 预期输出：
// a cat has 4 legs

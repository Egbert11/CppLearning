// ============================================================
// 来源小节：13.6 Scoped enumerations (enum classes)
// 示例说明：把用户输入的整数显式 static_cast 成有作用域枚举。
// 原文链接：https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

enum class Pet
{
    cat,
    dog,
    pig,
    whale,
};

int main()
{
    std::cout << "Enter a pet (0=cat, 1=dog, 2=pig, 3=whale): ";

    int input{};
    std::cin >> input;

    Pet pet{ static_cast<Pet>(input) }; // static_cast our integer to a Pet

    (void)pet;
    return 0;
}

// 预期交互（输入 2）：
// Enter a pet (0=cat, 1=dog, 2=pig, 3=whale): 2

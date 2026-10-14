// 来源小节：21.7 Overloading the comparison operators
// 示例说明：为 Car 重载 == 与 !=（友元函数）。相等比较 make 与 model 都相同；
//           不等则只要有一项不同。并非每个运算符对这个类型都有意义，
//           所以原文有意不定义 < 和 >。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-comparison-operators/
// 说明：本节代码取自原文（逐字保留）。
// 预期输出：a Corolla and Camry are not the same.

#include <iostream>
#include <string>
#include <string_view>

class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(std::string_view make, std::string_view model)
        : m_make{ make }, m_model{ model }
    {
    }

    friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator!= (const Car& c1, const Car& c2);
};

bool operator== (const Car& c1, const Car& c2)
{
    return (c1.m_make == c2.m_make &&
            c1.m_model == c2.m_model);
}

bool operator!= (const Car& c1, const Car& c2)
{
    return (c1.m_make != c2.m_make ||
            c1.m_model != c2.m_model);
}

int main()
{
    Car corolla{ "Toyota", "Corolla" };
    Car camry{ "Toyota", "Camry" };

    if (corolla == camry)
        std::cout << "a Corolla and Camry are the same.\n";

    if (corolla != camry)
        std::cout << "a Corolla and Camry are not the same.\n";

    return 0;
}

// ============================================================
// 来源小节：24.x Chapter 24 summary and quiz（测验 2a / 2b 解答）
// 示例说明：Fruit 基类含名字与颜色。Apple 继承 Fruit，颜色默认 "red"；
//           Banana 继承 Fruit，固定为 "banana"/"yellow"。
//           2b 新增 GrannySmith 继承 Apple——它需要一个 Apple 的 protected 构造
//           函数，以便传入自定义名字与颜色。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz/
// 预期输出：
//   My apple is red.
//   My banana is yellow.
//   My granny smith apple is green.
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class Fruit
{
private:
    std::string m_name;
    std::string m_color;

public:
    Fruit(std::string_view name, std::string_view color)
        : m_name{ name }, m_color{ color }
    {
    }

    const std::string& getName() const { return m_name; }
    const std::string& getColor() const { return m_color; }
};

class Apple : public Fruit
{
public:
    Apple(std::string_view color = "red")
        : Fruit{ "apple", color }
    {
    }

protected:
    Apple(std::string_view name, std::string_view color)
        : Fruit{ name, color }
    {
    }
};

class Banana : public Fruit
{
public:
    Banana()
        : Fruit{ "banana", "yellow" }
    {
    }
};

class GrannySmith : public Apple
{
public:
    GrannySmith()
        : Apple{ "granny smith apple", "green" }
    {
    }
};

int main()
{
    Apple a{ "red" };
    Banana b{};
    GrannySmith g{};

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << g.getName() << " is " << g.getColor() << ".\n";

    return 0;
}

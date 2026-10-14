// ============================================================
// 来源小节：14.3 Member functions
// 示例说明：成员函数可以接收同类型的另一个对象——kisses() 作用于隐式
//           对象（发起者），而把对方作为 const Person& 形参，用
//           person.name 显式访问其成员。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-functions/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

struct Person
{
    std::string name{};
    int age{};

    void kisses(const Person& person)
    {
        std::cout << name << " kisses " << person.name << '\n';
    }
};

int main()
{
    Person joe{ "Joe", 29 };
    Person kate{ "Kate", 27 };

    joe.kisses(kate);

    return 0;
}

// 预期输出：
// Joe kisses Kate

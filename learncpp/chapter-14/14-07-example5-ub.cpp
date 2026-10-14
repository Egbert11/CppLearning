// ============================================================
// 来源小节：14.7 Member functions returning references to data members
// 示例说明：隐式对象为右值（按值返回的临时 Employee）时，使用返回引用的三种情形：
//           情形 1 立即使用——安全；情形 2 保存返回引用——悬垂，未定义行为；
//           情形 3 拷贝到非引用局部变量——安全。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-functions-returning-references-to-data-members/
// 备注：本节代码为按原文描述忠实重建。情形 2 中 createEmployee() 的返回值在
//       完整表达式结束时被销毁，ref 随即悬垂；打印 ref 是未定义行为，输出依实现而定。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class Employee
{
    std::string m_name{};

public:
    void setName(std::string_view name) { m_name = name; }
    const std::string& getName() const { return m_name; } //  getter returns by const reference
};

// createEmployee() returns an Employee by value (which means the returned value is an rvalue)
Employee createEmployee(std::string_view name)
{
    Employee e;
    e.setName(name);
    return e;
}

int main()
{
    // Case 1: okay: use returned reference to member of rvalue class object in same expression
    std::cout << createEmployee("Frank").getName() << '\n';

    // Case 2: bad: save returned reference to member of rvalue class object for use later
    const std::string& ref { createEmployee("Garbo").getName() }; // reference becomes dangling
                                                                  // when return value of createEmployee() is destroyed
    std::cout << ref << '\n'; // undefined behavior

    // Case 3: okay: copy referenced value to local variable for use later
    std::string val { createEmployee("Hans").getName() }; // makes copy of referenced member
    std::cout << val << '\n'; // okay: val is independent of referenced member

    return 0;
}

// 预期输出（情形 2 依实现而定，切勿依赖）：
// Frank
// <未定义行为，可能为空/乱码>
// Hans

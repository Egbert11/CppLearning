// ============================================================
// 来源小节：23.3 Aggregation
// 示例说明：Department 通过"引用"持有一个 Teacher（聚合关系），
//           演示教师比部门活得更久——部门销毁时不会销毁教师。
// 原文链接：https://www.learncpp.com/cpp-tutorial/aggregation/
// 预期输出：
//   Bob still exists!
// 备注：本节代码为按原文描述重建（原 Example 1）。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class Teacher
{
private:
    std::string m_name{};

public:
    Teacher(std::string_view name)
        : m_name{ name }
    {
    }

    std::string_view getName() const { return m_name; }
};

class Department
{
private:
    const Teacher& m_teacher; // This dept holds only one teacher for simplicity, but it could hold many teachers

public:
    Department(const Teacher& teacher)
        : m_teacher{ teacher }
    {
    }
};

int main()
{
    // Create a teacher outside the scope of the Department
    Teacher bob{ "Bob" }; // create a teacher

    {
        // Create a department and use the constructor parameter to pass
        // the teacher to it.
        Department department{ bob };

    } // department goes out of scope here and is destroyed

    // bob still exists here, but the department doesn't
    std::cout << bob.getName() << " still exists!\n";

    return 0;
}

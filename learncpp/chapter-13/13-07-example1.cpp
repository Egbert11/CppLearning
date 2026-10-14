// ============================================================
// 来源小节：13.7 Introduction to structs, members, and member selection
// 示例说明：用一堆独立变量描述"员工"的失败做法——它们彼此的关系只存在于
//           注释和上下文里，变量多了难以追踪，传参和扩展都很痛苦。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-structs-members-and-member-selection/
// 备注：本节代码为按原文描述忠实重建。原文片段无 main，这里包进 main 以
//       保证可编译；补 [[maybe_unused]] 消除未使用警告。
// ============================================================
#include <string>

int main()
{
    // --- 原文示例片段 ---
    [[maybe_unused]] std::string name;
    [[maybe_unused]] std::string title;
    [[maybe_unused]] int age;
    [[maybe_unused]] int id;
    [[maybe_unused]] int managerId;
    [[maybe_unused]] double wage;
    [[maybe_unused]] int birthdayYear;
    [[maybe_unused]] int birthdayMonth;
    [[maybe_unused]] int birthdayDay;
    [[maybe_unused]] int hireYear;
    [[maybe_unused]] int hireMonth;
    [[maybe_unused]] int hireDay;
    // --- 原文示例片段结束 ---

    return 0;
}

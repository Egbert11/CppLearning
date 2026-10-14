// ============================================================
// 来源小节：23.4 Association
// 示例说明：自反关联（reflexive association）——对象与同类型的
//           其他对象关联。Course 持有 const Course* 指向其先修课，
//           从而可以组成链条。
// 原文链接：https://www.learncpp.com/cpp-tutorial/association/
// 预期输出：
//   Intro to C++ requires: (none)
//   Intermediate C++ requires: Intro to C++
//   Advanced C++ requires: Intermediate C++
// 备注：本节代码为按原文描述重建（原 Example 2，原文仅给类骨架；
//       此处补上 main 以演示链条并给出运行输出）。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class Course
{
private:
    std::string m_name{};
    const Course* m_prerequisite{};

public:
    Course(std::string_view name, const Course* prerequisite = nullptr)
        : m_name{ name }, m_prerequisite{ prerequisite }
    {
    }

    const std::string& getName() const { return m_name; }
    const Course* getPrerequisite() const { return m_prerequisite; }
};

int main()
{
    Course intro{ "Intro to C++" };
    Course intermediate{ "Intermediate C++", &intro };
    Course advanced{ "Advanced C++", &intermediate };

    for (const Course* c : { &intro, &intermediate, &advanced })
    {
        std::cout << c->getName() << " requires: ";
        if (c->getPrerequisite())
            std::cout << c->getPrerequisite()->getName();
        else
            std::cout << "(none)";
        std::cout << '\n';
    }

    return 0;
}

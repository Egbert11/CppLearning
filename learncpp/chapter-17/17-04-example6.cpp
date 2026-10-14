// ============================================================
// 来源小节：17.4 std::array of class types, and brace elision
// 示例说明：综合示例——constexpr std::array<Student, 3> 配合查找函数返回
//           指向元素的 const 指针（因为数组是 constexpr，元素也是 const）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-of-class-types-and-brace-elision/
// 预期输出：You found: Joe
//            You found: nobody
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>
#include <string_view>

struct Student
{
    int id{};
    std::string_view name{};
};

constexpr std::array students {
    Student{ 0, "Alex" },
    Student{ 1, "Joe" },
    Student{ 2, "Bob" }
};

const Student* findStudentById(int id)
{
    for (const auto& s : students)
    {
        if (s.id == id)
            return &s;
    }
    return nullptr;
}

int main()
{
    constexpr std::string_view nobody { "nobody" };

    const Student* s1 { findStudentById(1) };
    std::cout << "You found: " << (s1 ? s1->name : nobody) << '\n';

    const Student* s2 { findStudentById(3) };
    std::cout << "You found: " << (s2 ? s2->name : nobody) << '\n';

    return 0;
}

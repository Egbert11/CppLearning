// ============================================================
// 来源小节：5.2 Literals
// 示例说明：魔法数字（裸字面量 30）含义不清，改用符号常量后意图明确、
//           且只有一个修改点。原文片段未给出 numClassrooms 定义，
//           这里补上以便编译，并用 setMax 模拟原文中的同名调用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/literals/
// ============================================================
#include <iostream>

constexpr int numClassrooms { 3 }; // 原文片段未定义，补齐以便编译

void setMax(int max)
{
    std::cout << "max name length set to " << max << '\n';
}

int main()
{
    // --- 原文示例片段（示例 10：含魔法数字）---
    // const int maxStudentsPerSchool{ numClassrooms * 30 }; // 30 是什么？不清楚
    // setMax(30);                                          // 这里的 30 又是另一种用途
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（示例 11：改写为符号常量）---
    const int maxStudentsPerClass { 30 };
    const int totalStudents { numClassrooms * maxStudentsPerClass }; // now obvious what this 30 means

    const int maxNameLength { 30 };
    setMax(maxNameLength); // now obvious this 30 is used in a different context
    // --- 原文示例片段结束 ---

    std::cout << "total students: " << totalStudents << '\n';

    return 0;
}

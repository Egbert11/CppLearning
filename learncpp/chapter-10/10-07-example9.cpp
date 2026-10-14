// 来源小节：10.7 Typedefs and type aliases
// 示例说明：通过修改一个别名实现"一处改、处处改"的维护效果——把 StudentId 从
//           short 改成 long 后，所有用到 StudentId 的地方随之更新。
//           （对应原文示例 15）
// 原文链接：https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
//
// 编译：g++ -std=c++20 -Wall 10-07-example9.cpp -o a
// 预期输出：1234567
//
// 本节代码为按原文描述重建。

#include <iostream>

// --- 原文示例片段（改动点：short -> long） ---
// using StudentId = short; // 原来的定义
using StudentId = long;     // 改为 long，所有使用处一并生效
// --- 原文示例片段结束 ---

StudentId getStudentId()
{
    return 1234567; // 换成 short 时可能放不下，改 long 后安全
}

int main()
{
    StudentId id{ getStudentId() };
    std::cout << id << '\n';

    return 0;
}

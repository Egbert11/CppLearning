// 来源小节：10.7 Typedefs and type aliases
// 示例说明：用别名让返回类型/形参表达含义，而不只是底层类型；并给出测验解答
//           ——把 int printData(); 改为用 PrintError 别名表示"打印是否出错"。
//           （对应原文示例 14、16）
// 原文链接：https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
//
// 编译：g++ -std=c++20 -Wall 10-07-example8.cpp -o a
// 预期输出：
//   test score: 95
//   printData error code: 0
//
// 本节代码为按原文描述重建。

#include <iostream>

// --- 原文示例片段（示例 14：用别名记录返回值的含义） ---
using TestScore = int; // 让返回类型表明这是"测验分数"而非任意 int
TestScore gradeTest()
{
    return 95;
}
// --- 原文示例片段结束 ---

// --- 原文示例片段（测验解答：示例 16） ---
using PrintError = int; // 让返回类型表明这是"打印错误码"
PrintError printData()
{
    return 0; // 0 表示无错误
}
// --- 原文示例片段结束 ---

int main()
{
    std::cout << "test score: " << gradeTest() << '\n';
    std::cout << "printData error code: " << printData() << '\n';

    return 0;
}

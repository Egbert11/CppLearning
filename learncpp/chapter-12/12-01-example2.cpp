// ============================================================
// 来源小节：12.1 Introduction to compound data types
// 示例说明：把一组员工 ID 存成 id1、id2、id3…… 这种"每个值一个
//           变量名"的做法无法扩展：100 名员工就要 100 个名字，
//           打印或传参都会变得极其痛苦。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-compound-data-types/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int id1 { 42 };
    int id2 { 57 };
    int id3 { 162 };
    // ...and so on
    // --- 原文示例片段结束 ---

    std::cout << id1 << ' ' << id2 << ' ' << id3 << '\n';

    return 0;
}

// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：sizeof 作用于 C 风格数组时返回整个数组占用的字节数，没有任何
//           额外开销——数组对象只保存其元素，"别的什么都没有"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期输出：20（假设 int 为 4 字节）
// 备注：本节代码为按原文描述重建；输出随平台上 int 的字节数而定。
// ============================================================
#include <iostream>

int main()
{
    const int prime[] { 2, 3, 5, 7, 11 };

    std::cout << sizeof(prime) << '\n'; // 5 ints * 4 bytes each = 20

    return 0;
}

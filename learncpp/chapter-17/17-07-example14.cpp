// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：更老的惯用法——用 总字节数 / 单元素字节数 求长度；它一旦拿到
//           已退化的数组指针就会出错，故不如 std::size() 或 length() 安全。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期输出：The array has: 8 elements
// 备注：本节代码为按原文描述重建，仅用于对比说明，不推荐在新代码中使用。
// ============================================================
#include <iostream>

int main()
{
    int array[8] {};

    std::cout << "The array has: " << sizeof(array) / sizeof(array[0]) << " elements\n";

    return 0;
}

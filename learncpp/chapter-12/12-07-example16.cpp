// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：指针大小由架构决定，与所指类型无关——32 位可执行文件中
//           指针都是 4 字节（64 位为 8 字节），因为指针就是一个地址。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 16）。
//       原文示例运行于 32 位可执行文件故输出 4；本机为 64 位，输出 8。
// ============================================================
#include <iostream>

int main()
{
    std::cout << sizeof(char*) << '\n';        // 4 (on a 32-bit executable)
    std::cout << sizeof(int*) << '\n';         // 4
    std::cout << sizeof(long double*) << '\n'; // 4

    return 0;
}

// 预期输出（32 位可执行文件）：4、4、4。
// 在 64 位可执行文件上三者均为 8。

// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：测验 1 的解答——用 short 与指针打印地址、值、大小。
//           32 位可执行文件下地址为 8 位十六进制、sizeof(ptr)==4、
//           sizeof(*ptr)==2（short 占 2 字节）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Quiz 1 解答）。
//       地址与 sizeof 依平台而异；下方注释为 32 位平台的预期值。
// ============================================================
#include <iostream>

int main()
{
    short value{ 7 };      // &value = 0012FF60
    short otherValue{ 3 }; // &otherValue = 0012FF54

    short* ptr { &value };

    std::cout << &value << '\n';  // 0012FF60
    std::cout << value << '\n';   // 7
    std::cout << ptr << '\n';     // 0012FF60
    std::cout << *ptr << '\n';    // 7
    std::cout << '\n';

    *ptr = 9;

    std::cout << &value << '\n';  // 0012FF60
    std::cout << value << '\n';   // 9
    std::cout << ptr << '\n';     // 0012FF60
    std::cout << *ptr << '\n';    // 9
    std::cout << '\n';

    ptr = &otherValue;

    std::cout << &otherValue << '\n'; // 0012FF54
    std::cout << otherValue << '\n';  // 3
    std::cout << ptr << '\n';         // 0012FF54
    std::cout << *ptr << '\n';        // 3
    std::cout << '\n';

    std::cout << sizeof(ptr) << '\n';  // 4 (32-bit)
    std::cout << sizeof(*ptr) << '\n'; // 2

    return 0;
}

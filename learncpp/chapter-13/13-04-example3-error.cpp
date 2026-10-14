// ============================================================
// 来源小节：13.4 Converting an enumeration to and from a string
// 示例说明：直接用 std::cin 读枚举是编译错误——语言不知道如何读取一个 Pet。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-an-enumeration-to-and-from-a-string/
// 备注：本节代码为按原文描述忠实重建。预期编译失败。
// ============================================================
#include <iostream>

enum Pet
{
    cat,   // 0
    dog,   // 1
    pig,   // 2
    whale, // 3
};

int main()
{
    Pet pet { pig };
    std::cin >> pet; // compile error: std::cin doesn't know how to input a Pet

    return 0;
}

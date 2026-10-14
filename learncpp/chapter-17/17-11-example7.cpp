// ============================================================
// 来源小节：17.11 C-style string symbolic constants
// 示例说明：想打印 char 指针的地址时，先 static_cast 到 const void*（原 Example 7）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-string-symbolic-constants/
// 预期输出：
//   Alex               （字符串本身）
//   00AFFD80           （地址，依平台/运行而变）
// ============================================================
#include <iostream>

int main()
{
    const char* ptr{ "Alex" };

    std::cout << ptr << '\n';                           // prints the string
    std::cout << static_cast<const void*>(ptr) << '\n'; // prints the address

    return 0;
}

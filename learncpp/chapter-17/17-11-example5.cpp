// ============================================================
// 来源小节：17.11 C-style string symbolic constants
// 示例说明：std::cout 对不同指针类型的处理——char* 当作字符串打印，其它指针打印地址（原 Example 5）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-string-symbolic-constants/
// 预期输出（作者机器）：
//   003AF738
//   Hello!
//   Alex
// 备注：第一行是 int 数组退化出的 int* 地址，依平台/运行而变；后两行是字符串。
// ============================================================
#include <iostream>

int main()
{
    int narr[]{ 9, 7, 5, 3, 1 };
    char carr[]{ "Hello!" };
    const char* ptr{ "Alex" };

    std::cout << narr << '\n'; // narr decays to int*, so this prints an address
    std::cout << carr << '\n'; // char array prints as a string
    std::cout << ptr << '\n';  // prints the pointed-to string

    return 0;
}

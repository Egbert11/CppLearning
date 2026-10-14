// 来源小节：7.13 Using declarations and using directives
// 示例说明：用户定义的 int cout() 与 std::cout 冲突：导入 std 后，非限定名 cout 有歧义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/
//
// 本节示例为按原文描述重建（对应原文 Example 6）。
// ※ 预期编译失败（勿修复）：g++ 报 "reference to 'cout' is ambiguous"。
//   修复方式：不要用 using namespace std;，改用 using std::cout; 或显式 std::cout。

#include <iostream>

int cout() // 用户自定义的 cout 函数
{
    return 5;
}

using namespace std; // 坏实践：导入整个 std

int main()
{
    cout << "Hello, world!\n"; // 歧义：::cout 还是 std::cout？→ 编译错误

    return 0;
}

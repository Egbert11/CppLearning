// ============================================================
// 来源小节：12.12 Return by reference and return by address
// 示例说明：把一个引用形参按引用返回是安全的：调用方的实参必然存在于调用方
//           作用域中，在被调方返回后仍然存活。这样最多可省去三次复制。
// 原文链接：https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/
// 预期输出：Hello
// 备注：本节代码为按原文描述忠实重建（原 Example 11）。
// ============================================================
#include <iostream>
#include <string>

// We can use operator< on std::string to determine which comes first alphabetically
const std::string& firstAlphabetical(const std::string& a, const std::string& b)
{
    return (a < b) ? a : b; // We can use operator< on std::string to determine which comes first alphabetically
}

int main()
{
    std::string hello { "Hello" };
    std::string world { "World" };

    std::cout << firstAlphabetical(hello, world) << '\n';

    return 0;
}

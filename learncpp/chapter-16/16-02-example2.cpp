// ============================================================
// 来源小节：16.2 Introduction to std::vector and list constructors
// 示例说明：用列表构造函数给出元素值；省略元素类型时用 CTAD（C++17）
//           从字符初始化列表推导出 std::vector<char>。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/
// 预期输出：4 5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> primes{ 2, 3, 5, 7 };          // 4 int elements
    std::vector vowels { 'a', 'e', 'i', 'o', 'u' }; // CTAD (C++17) deduces char

    std::cout << primes.size() << ' ' << vowels.size() << '\n';

    return 0;
}

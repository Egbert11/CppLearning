// ============================================================
// 来源小节：17.11 C-style string symbolic constants
// 示例说明：用 auto / auto* / auto& 从字符串字面量推导类型（原 Example 4）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-string-symbolic-constants/
// 类型推导结果：s1 -> const char*；s2 -> const char*；s3 -> const char(&)[5]
// 预期输出：Alex Alex Alex
// ============================================================
#include <iostream>
#include <type_traits>

int main()
{
    auto s1{ "Alex" };  // deduced: const char*
    auto* s2{ "Alex" }; // deduced: const char*
    auto& s3{ "Alex" }; // deduced: const char(&)[5]

    static_assert(std::is_same_v<decltype(s1), const char*>);
    static_assert(std::is_same_v<decltype(s2), const char*>);
    static_assert(std::is_same_v<decltype(s3), const char(&)[5]>);

    std::cout << s1 << ' ' << s2 << ' ' << s3 << '\n';

    return 0;
}

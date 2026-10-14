// ============================================================
// 来源小节：12.12 Return by reference and return by address
// 示例说明：（进阶）getName() 返回对 static s_name 的引用。两次调用会传入
//           printFirstAlphabetical()。因为两个参数都别名同一个 static 对象，
//           结果为 “Stan comes before Stan”（输入 Stan、Stan 时）。
//           注意：若形参用 std::string_view，底层字符串改变时会失效。
// 原文链接：https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/
// 示例输入：Stan Stan
// 示例输出：Stan comes before Stan
// 备注：本节代码为按原文描述忠实重建（原 Example 8）。
// ============================================================
#include <iostream>
#include <string>

const std::string& getName()
{
    static std::string s_name{};
    std::cout << "Enter a name: ";
    std::cin >> s_name;
    return s_name; // returns a reference to the static local
}

void printFirstAlphabetical(const std::string& s1, const std::string& s2)
{
    if (s1 < s2)
        std::cout << s1 << " comes before " << s2 << '\n';
    else
        std::cout << s2 << " comes before " << s1 << '\n';
}

int main()
{
    printFirstAlphabetical(getName(), getName());

    return 0;
}

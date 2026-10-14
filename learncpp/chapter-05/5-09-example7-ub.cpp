// 来源小节：5.9 std::string_view (part 2)
// 示例说明：危险返回——返回指向函数内局部 std::string 的视图，
//           函数返回后局部变量被销毁，返回的视图随即悬垂。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 8）。
// 运行输出未定义（悬垂视图），仅作演示勿模仿。
// 运行期未定义行为：t、f 在函数返回时销毁，返回的视图悬垂。
// 本文件可正常编译。

#include <iostream>
#include <string>
#include <string_view>

std::string_view getBoolName(bool b)
{
    std::string t { "true" };  // local variable
    std::string f { "false" }; // local variable

    if (b)
        return t;  // return a std::string_view viewing t

    return f; // return a std::string_view viewing f
} // t and f are destroyed here, so the returned view is dangling

int main()
{
    std::cout << getBoolName(true) << ' ' << getBoolName(false) << '\n'; // undefined behavior

    return 0;
}

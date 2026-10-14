// 来源小节：5.9 std::string_view (part 2)
// 示例说明：悬垂视图（dangling）——在嵌套块内把视图指向块内的 std::string，
//           块结束时该字符串被销毁，视图随即悬垂。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 3）。
// 运行输出未定义（悬垂视图），仅作演示勿模仿。
// 运行期未定义行为：打印 sv 时它正指向已销毁的 std::string。
// 本文件可正常编译。

#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string_view sv{};

    {
        std::string s{ "Hello, world!" };
        sv = s; // sv is now viewing s
    } // s is destroyed here, so sv is now dangling

    std::cout << sv << '\n'; // undefined behavior

    return 0;
}

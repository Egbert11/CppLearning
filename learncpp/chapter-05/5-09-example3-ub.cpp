// 来源小节：5.9 std::string_view (part 2)
// 示例说明：悬垂视图（dangling）——用返回 std::string 的函数的返回值初始化视图，
//           该临时返回值在完整表达式结束时被销毁，视图随即悬垂。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 4）。
// 运行输出未定义（悬垂视图），仅作演示勿模仿。
// 运行期未定义行为：打印 name 时它正指向已销毁的临时 std::string。
// 本文件可正常编译。

#include <iostream>
#include <string>
#include <string_view>

std::string getName()
{
    std::string s{ "Alex" };
    return s;
}

int main()
{
    std::string_view name { getName() }; // name initialized with a returned temporary std::string
    std::cout << name << '\n';           // undefined behavior

    return 0;
}

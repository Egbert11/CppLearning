// 来源小节：5.9 std::string_view (part 2)
// 示例说明：修改 std::string 会使既有视图失效——视图可能悬垂（发生重分配）
//           或看到长度错误的数据。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建（对应原文 Example 6）。
// 运行输出未定义（视图已失效），仅作演示勿模仿。
// 运行期未定义行为：修改 s 后其内存可能被重分配，sv 随之悬垂。
// 本文件可正常编译。

#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string s { "Hello, world!" };
    std::string_view sv { s }; // sv is now viewing s

    s = "Hello, a!"; // modifies s, which may invalidate sv

    std::cout << sv << '\n'; // undefined behavior

    return 0;
}

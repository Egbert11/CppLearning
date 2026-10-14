// ============================================================
// 来源小节：12.13 In and out parameters
// 示例说明：与 Example 5 相同，只是把函数名改得更具描述性（modifyFoo），
//           让“会修改参数”这件事稍微明显一点。
// 原文链接：https://www.learncpp.com/cpp-tutorial/in-and-out-parameters/
// 备注：本节代码为按原文描述忠实重建（原 Example 6；Foo 取 std::string）。
// ============================================================
#include <string>

using Foo = std::string; // Foo stands in for a type of your choosing

void modifyFoo(Foo& inout)
{
    // modify inout here
    inout += " (modified)";
}

int main()
{
    Foo foo{ "hello" };
    modifyFoo(foo);

    return 0;
}

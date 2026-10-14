// ============================================================
// 来源小节：12.13 In and out parameters
// 示例说明：用一个非 const 引用实现 in-out 参数：函数既读入又改写同一个
//           形参，因此调用处看不出它会被修改。作者说明：Foo 代表你选择的
//           类型，例如 std::string。
// 原文链接：https://www.learncpp.com/cpp-tutorial/in-and-out-parameters/
// 备注：本节代码为按原文描述忠实重建（原 Example 5；Foo 取 std::string）。
// ============================================================
#include <string>

using Foo = std::string; // Foo stands in for a type of your choosing

void someFcn(Foo& inout)
{
    // modify inout here
    inout += " (modified)";
}

int main()
{
    Foo foo{ "hello" };
    someFcn(foo);

    return 0;
}

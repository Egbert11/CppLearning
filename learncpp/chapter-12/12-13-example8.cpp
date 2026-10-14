// ============================================================
// 来源小节：12.13 In and out parameters
// 示例说明：当返回对象并按值复制代价**极其昂贵**（且处于性能关键路径）时，
//           用 out 参数避免复制，是少数仍值得用 out 参数的情形。
// 原文链接：https://www.learncpp.com/cpp-tutorial/in-and-out-parameters/
// 备注：本节代码为按原文描述忠实重建（原 Example 8；Foo 取 std::string）。
// ============================================================
#include <string>

using Foo = std::string; // Foo stands in for a type of your choosing

void generateExpensiveFoo(Foo& out)
{
    // modify out here
    out = "generated";
}

int main()
{
    Foo foo{}; // must first create the object
    generateExpensiveFoo(foo);

    return 0;
}

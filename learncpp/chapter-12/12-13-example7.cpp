// ============================================================
// 来源小节：12.13 In and out parameters
// 示例说明：避免 out 参数的常规替代——按 const 引用传入、在函数内复制并
//           修改，再按值返回，由调用方赋回。代价是多出拷贝。
// 原文链接：https://www.learncpp.com/cpp-tutorial/in-and-out-parameters/
// 备注：本节代码为按原文描述忠实重建（原 Example 7；Foo 取 std::string）。
// ============================================================
#include <string>

using Foo = std::string; // Foo stands in for a type of your choosing

Foo someFcn(const Foo& in)
{
    Foo foo { in }; // copy here
    // modify foo here
    foo += " (modified)";
    return foo;
}

int main()
{
    Foo foo{ "hello" };
    foo = someFcn(foo);

    return 0;
}

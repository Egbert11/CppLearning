// ============================================================
// 来源小节：16.2 Introduction to std::vector and list constructors
// 示例说明：成员默认初始化器不允许使用圆括号（直接）初始化，故下面写法编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/
// 预期错误：编译错误——成员默认初始化器不能直接用圆括号构造。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
//       正确写法见 16-02-example8.cpp。
// ============================================================
#include <vector>

struct Foo
{
    std::vector<int> v1(8); // compile error: direct initialization not allowed for a member default initializer
};

int main()
{
    return 0;
}

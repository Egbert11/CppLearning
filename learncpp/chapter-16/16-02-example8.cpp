// ============================================================
// 来源小节：16.2 Introduction to std::vector and list constructors
// 示例说明：成员默认初始化器不能写 `v1(8)`，可把构造好的 vector 包进大括号
//           拷贝/列表初始化：`std::vector<int> v{ std::vector<int>(8) };`。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/
// 预期输出：8
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

struct Foo
{
    std::vector<int> v{ std::vector<int>(8) }; // ok
};

int main()
{
    Foo foo;
    std::cout << foo.v.size() << '\n'; // 8

    return 0;
}

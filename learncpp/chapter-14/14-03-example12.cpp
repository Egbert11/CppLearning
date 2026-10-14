// ============================================================
// 来源小节：14.3 Member functions
// 示例说明：若类类型没有数据成员，优先用命名空间——非成员函数不需要任何
//           对象就能调用，且明确表达"这里不管理数据"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-functions/
// 备注：本节代码为按原文描述忠实重建。对比 14-03-example11.cpp 的成员函数写法。
// ============================================================
#include <iostream>

namespace Foo
{
    void printHi()
    {
        std::cout << "Hi!\n";
    }
}

int main()
{
    Foo::printHi(); // no object needed

    return 0;
}

// 预期输出：
// Hi!

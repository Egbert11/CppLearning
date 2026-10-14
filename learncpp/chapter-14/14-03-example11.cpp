// ============================================================
// 来源小节：14.3 Member functions
// 示例说明：只有成员函数、没有数据成员的类类型是可行的，但它仍需一个
//           对象才能调用其成员函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-functions/
// 备注：本节代码为按原文描述忠实重建。对比 14-03-example12.cpp 的命名空间写法。
// ============================================================
#include <iostream>

struct Foo
{
    void printHi()
    {
        std::cout << "Hi!\n";
    }
};

int main()
{
    Foo f{};
    f.printHi(); // requires an object

    return 0;
}

// 预期输出：
// Hi!

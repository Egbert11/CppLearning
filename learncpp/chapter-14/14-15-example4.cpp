// ============================================================
// 来源小节：14.15 Class initialization and copy elision
// 示例说明：按值传参与按值返回中的拷贝消除——rvo() 返回临时对象（C++17 强制
//           消除拷贝），nrvo() 返回具名局部变量（可被消除）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-initialization-and-copy-elision/
// 备注：本节代码为按原文描述忠实重建。
//
// 说明：在 C++14 且关闭消除时，本程序会调用 4 次拷贝构造函数；
//       Visual Studio 2022 消除其中 3 次，GCC 全部消除。
//       C++17 下 rvo() 到 s1 的拷贝被强制消除，nrvo() 到 s2 的拷贝可能被消除。
// ============================================================
#include <iostream>

class Something
{
public:
    Something() = default;

    Something(const Something&)
    {
        std::cout << "Copy constructor called\n";
    }
};

// --- 原文示例片段（原 Example 4）---
Something rvo()
{
    return Something{}; // creates a temporary Something and returns it
}

Something nrvo()
{
    Something s{}; // create local object s
    return s;      // return local object s
}

int main()
{
    std::cout << "Initializing s1\n";
    Something s1 { rvo() }; // copy from rvo() may be elided
    std::cout << "Initializing s2\n";
    Something s2 { nrvo() }; // copy from nrvo() may be elided

    return 0;
}
// --- 原文示例片段结束 ---

// 在启用拷贝消除的编译器（如 GCC）上的预期输出：
// Initializing s1
// Initializing s2

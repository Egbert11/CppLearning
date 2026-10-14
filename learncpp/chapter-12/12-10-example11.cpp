// ============================================================
// 来源小节：12.10 Pass by address
// 示例说明：更好的做法是把空指针当作前置条件，一旦为真就立刻返回；此后函数
//           其余部分都可以假定指针有效，避免重复检查与嵌套。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-address/
// 备注：本节代码为按原文描述忠实重建（原 Example 11）。
// ============================================================
#include <iostream>

void print(int* ptr)
{
    if (!ptr)
        return; // bail out early if ptr is null

    // if we made it past the null check, this is safe
    std::cout << *ptr << '\n';
}

int main()
{
    int x{ 5 };
    print(&x);
    print(nullptr);

    return 0;
}

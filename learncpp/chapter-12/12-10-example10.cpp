// ============================================================
// 来源小节：12.10 Pass by address
// 示例说明：解引用前先用 if (ptr) 做空检查。能工作，但在复杂函数中可能
//           导致重复检查或深层嵌套。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-address/
// 备注：本节代码为按原文描述忠实重建（原 Example 10）。
// ============================================================
#include <iostream>

void print(int* ptr)
{
    if (ptr) // if ptr is not a null pointer
    {
        std::cout << *ptr << '\n'; // it is safe to dereference ptr
    }
}

int main()
{
    int x{ 5 };
    print(&x);
    print(nullptr);

    return 0;
}

// ============================================================
// 来源小节：12.10 Pass by address
// 示例说明：如果空指针根本不应被传入，可用 assert(ptr) 记录该前置条件
//           （发布构建中 NDEBUG 会移除断言，可另加运行时检查兜底）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-address/
// 备注：本节代码为按原文描述忠实重建（原 Example 12）。
// ============================================================
#include <cassert>  // for assert
#include <iostream>

void print(const int* ptr) // note: ptr is a pointer to a const int
{
    assert(ptr); // fail the program in debug mode if a null pointer is passed

    // (optionally) deal with this in production mode
    if (!ptr)
        return;

    std::cout << *ptr << '\n';
}

int main()
{
    int x{ 5 };
    print(&x);
    // print(nullptr); // would trip the assert in debug builds

    return 0;
}

// ============================================================
// 来源小节：19.1 Dynamic memory allocation with new and delete
// 示例说明：删除空指针是安全的、什么也不做，因此删除前的 if 检查是多余的。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/
// 预期输出：deleting a null pointer is okay and does nothing
// 备注：本节代码为按原文描述重建（原文 Example 13）。
// ============================================================
#include <iostream>

int main()
{
    int* ptr{ nullptr };

    if (ptr) // if ptr is not a null pointer
        delete ptr; // delete it
    // otherwise do nothing

    delete ptr; // 直接删除空指针同样安全（原文推荐的简洁写法）

    std::cout << "deleting a null pointer is okay and does nothing\n";

    return 0;
}

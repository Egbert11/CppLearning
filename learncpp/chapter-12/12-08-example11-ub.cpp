// ============================================================
// 来源小节：12.8 Null pointers
// 示例说明：指针比目标活得久会变成悬垂指针。与引用不同，指针可以指向
//           随后被销毁的对象（引用做不到）。对象销毁时指针不会被自动
//           置空，所以 if (ptr) 为真，但解引用它是未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/null-pointers/
// !! -ub：未定义行为演示，可编译但运行结果不确定（可能崩溃）。
// 备注：本节代码为按原文描述忠实重建（原 Example 11）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int* ptr { };

    {
        int x{ 5 };
        ptr = &x; // assign the pointer to an object that will be destroyed (not possible with a reference)
    } // ptr is now dangling and pointing to invalid object

    if (ptr) // condition evaluates to true because ptr is not nullptr
        std::cout << *ptr; // undefined behavior
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期：结果不确定（未定义行为），可能打印旧值也可能崩溃。

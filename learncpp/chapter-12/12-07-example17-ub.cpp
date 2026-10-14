// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：悬垂指针（dangling pointer）——内层作用域里把 ptr 指向 y，
//           作用域结束 y 被销毁，ptr 仍持有那个地址，解引用它是未定义
//           行为。输出依实现而定，可能打印 5、6，也可能崩溃。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// !! -ub：未定义行为演示，可编译但运行结果不确定。
// 备注：本节代码为按原文描述忠实重建（原 Example 17）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int* ptr { };

    {
        int y { 5 };
        ptr = &y; // assign ptr to an object that will be destroyed at the end of the block
    } // y is destroyed here; ptr is now dangling

    std::cout << *ptr << '\n'; // undefined behavior (may print 5, or something else, or crash)
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：不确定（原文示例为 5、6、6；本题可能不同，甚至崩溃）。

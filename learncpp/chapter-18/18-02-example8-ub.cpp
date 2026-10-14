// ============================================================
// 来源小节：18.2 Introduction to iterators
// 示例说明：迭代器失效第二种情形。对 vector 取 it = v.begin()，自增后打印
//           第二个元素（正常），随后 v.erase(it) 会失效指向被删元素及其后元素
//           的迭代器，因此再对 it 做 ++it 和解引用都是未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-iterators/
// 预期输出：先打印 `2`；之后为未定义行为（结果不可依赖）。
// 备注：本节代码为按原文描述重建；后缀 -ub 表示未定义行为演示，能编译。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector v{ 1, 2, 3, 4, 5, 6, 7 }; // has 7 elements

    auto it{ v.begin() };

    ++it; // move to second element
    std::cout << *it << '\n'; // ok: prints 2

    v.erase(it); // erase the element currently being iterated over

    // erase() invalidates iterators to the erased element (and subsequent elements)
    // so iterator "it" is now invalidated

    ++it; // undefined behavior
    std::cout << *it << '\n'; // undefined behavior

    return 0;
}

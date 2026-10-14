// ============================================================
// 来源小节：18.2 Introduction to iterators
// 示例说明：迭代器失效（iterator invalidation）第一种情形。范围内用范围 for
//           遍历 vector 时，若在循环中 push_back 添加元素，可能触发重新分配
//           而使原有迭代器失效，此时继续使用这些迭代器是未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-iterators/
// 预期输出：不确定（未定义行为）——本文件仅用于演示错误用法，请勿模仿。
// 备注：本节代码为按原文描述重建；后缀 -ub 表示未定义行为演示，能编译。
// ============================================================
#include <vector>

int main()
{
    std::vector v{ 0, 1, 2, 3 }; // create a vector with 4 elements

    for (auto num : v) // iterate through each element of the vector
    {
        if (num % 2 == 0) // if the number is even
            v.push_back(num + 1); // add a new number to the end of the vector

        // When this happens, the vector's iterators may be invalidated,
        // and the range-based for loop uses iterators internally -> undefined behavior.
    }

    return 0;
}

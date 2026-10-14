// ============================================================
// 来源小节：18.2 Introduction to iterators
// 示例说明：修正上例——erase() 会返回一个指向“被删元素之后那个元素”的迭代器
//           （若删的是最后一个则返回 end()），用它重新赋值给 it 即可继续安全
//           遍历。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-iterators/
// 预期输出：
//   2
//   3
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector v{ 1, 2, 3, 4, 5, 6, 7 }; // has 7 elements

    auto it{ v.begin() };

    ++it; // move to second element
    std::cout << *it << '\n'; // ok: prints 2

    it = v.erase(it); // erase the element currently being iterated over, set `it` to next element

    std::cout << *it << '\n'; // ok: prints 3 (the next element)

    return 0;
}

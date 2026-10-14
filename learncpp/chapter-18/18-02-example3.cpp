// ============================================================
// 来源小节：18.2 Introduction to iterators
// 示例说明：计算“尾后指针”的正确写法。原文 Warning：不要写
//           int* end{ &arr[std::size(arr)] }; —— 它会对数组末尾之后的一个
//           位置做下标访问（隐含解引用），是未定义行为。正确做法是用
//           arr.data() + std::size(arr)（或 &arr[0] + std::size(arr)）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-iterators/
// 预期输出：0 1 2 3 4 5 6
// 备注：本节代码为按原文描述重建；此处只演示推荐写法，错误写法见注释。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    std::array arr{ 0, 1, 2, 3, 4, 5, 6 };

    // Warning: the following is undefined behavior, because arr[std::size(arr)]
    // implicitly dereferences one element past the end of the array:
    //   int* end{ &arr[std::size(arr)] };

    // Do this instead:
    auto* end{ arr.data() + std::size(arr) }; // data() returns a pointer to the first element

    for (auto ptr{ arr.data() }; ptr != end; ++ptr)
    {
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';

    return 0;
}

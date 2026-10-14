// ============================================================
// 来源小节：16.5 Returning std::vector, and an introduction to move semantics
// 示例说明：generate() 按值返回 vector；返回值是临时对象，
//           在初始化表达式结束时消亡（这里用命名对象返回以避开强制拷贝省略）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/returning-stdvector-and-an-introduction-to-move-semantics/
// 预期输出：7
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

std::vector<int> generate() // return by value
{
    // We're intentionally using a named object here so mandatory copy elision doesn't apply
    std::vector arr1 { 1, 2, 3, 4, 5 }; // copies { 1, 2, 3, 4, 5 } into arr1
    return arr1;
}

int main()
{
    std::vector arr2 { generate() }; // the return value of generate() dies at the end of the expression

    // There is no way to use the return value of generate() here
    arr2[0] = 7; // we only have access to arr2

    std::cout << arr2[0] << '\n';

    return 0;
}

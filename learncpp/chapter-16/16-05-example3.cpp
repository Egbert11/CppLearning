// ============================================================
// 来源小节：16.5 Returning std::vector, and an introduction to move semantics
// 示例说明：传参-返回四步流程，注释标出四次拷贝/构造的位置。
// 原文链接：https://www.learncpp.com/cpp-tutorial/returning-stdvector-and-an-introduction-to-move-semantics/
// 预期输出：
//   10
//   5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

std::vector<int> doSomething(std::vector<int> v2)
{
    std::vector v3 { v2[0] + v2[0] }; // 3 -- construct value to be returned to caller
    return v3; // 4 -- actually return value
}

int main()
{
    std::vector v1 { 5 }; // 1 -- construct value to be passed to function
    std::cout << doSomething(v1)[0] << '\n'; // 2 -- actually pass value

    std::cout << v1[0] << '\n';

    return 0;
}

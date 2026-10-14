// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：用 decltype(arr)::size_type 让编译器推导容器类型。
//           注意此处 arr 是非引用类型（decltype 才能得到容器类型而非引用）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 预期输出：4 6 7 3 8 2 1 9
// 备注：本节代码为按原文描述重建。对引用类型需去引用，见 16-07-example8.cpp。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 }; // decltype(arr) is std::vector<int> (not a reference)

    for (decltype(arr)::size_type index { 0 }; index < arr.size(); ++index)
        std::cout << arr[index] << ' ';

    std::cout << '\n';

    return 0;
}

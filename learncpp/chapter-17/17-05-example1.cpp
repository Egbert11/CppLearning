// ============================================================
// 来源小节：17.5 Arrays of references via std::reference_wrapper
// 示例说明：数组的元素可以是基本类型（如 int），也可以是指针等复合类型
//           （如 int*）。这里对比"值的数组"与"指针的数组"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-of-references-via-stdreference_wrapper/
// 预期输出：（无输出）
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <vector>

int main()
{
    int x { 1 };
    int y { 2 };

    [[maybe_unused]] std::array valarr { x, y };   // an array of int values
    [[maybe_unused]] std::vector ptrarr { &x, &y }; // a vector of int pointers (int*)

    return 0;
}

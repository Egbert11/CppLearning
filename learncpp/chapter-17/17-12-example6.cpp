// ============================================================
// 来源小节：17.12 Multidimensional C-style Arrays
// 示例说明：二维数组的两种遍历方式——外层行、内层列；范围 for 用 const auto&（原 Example 14）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multidimensional-c-style-arrays/
// 预期输出（按行主序）：
//   1 2 3 4
//   5 6 7 8
//   9 10 11 12
//   （以上三行再重复一次）
// ============================================================
#include <iostream>
#include <iterator> // for std::size

int main()
{
    int arr[3][4]
    {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }
    };

    // 带下标的双层循环：外层行，内层列
    for (std::size_t row { 0 }; row < std::size(arr); ++row)       // std::size(arr) gives the number of rows
    {
        for (std::size_t col { 0 }; col < std::size(arr[0]); ++col) // std::size(arr[0]) gives the number of columns
            std::cout << arr[row][col] << ' ';
        std::cout << '\n';
    }

    // 范围 for 的嵌套版本
    for (const auto& arow : arr)   // get each array row
    {
        for (const auto& e : arow) // get each element of the row
            std::cout << e << ' ';
        std::cout << '\n';
    }

    return 0;
}

// ============================================================
// 来源小节：17.12 Multidimensional C-style Arrays
// 示例说明：用 (y, x) 笛卡尔坐标习惯遍历——y 为行、x 为列，索引写作 arr[y][x]（原 Example 16）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multidimensional-c-style-arrays/
// 预期输出：
//   1 2 3
//   4 5 6
//   7 8 9
// ============================================================
#include <iostream>
#include <iterator> // for std::size

int main()
{
    constexpr int arr[3][3]
    {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    // y 是行，x 是列（resulting a[y][x] indexing reverses the alphabetical order one might expect）
    for (std::size_t y{ 0 }; y < std::size(arr); ++y)
    {
        for (std::size_t x{ 0 }; x < std::size(arr[0]); ++x)
            std::cout << arr[y][x] << ' ';
        std::cout << '\n';
    }

    return 0;
}

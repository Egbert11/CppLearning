// ============================================================
// 来源小节：17.13 Multidimensional std::array
// 示例说明：把二维 std::array 传给函数模板（原 Example 3）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multidimensional-stdarray/
// 预期输出：
//   1 2 3 4
//   5 6 7 8
//   9 10 11 12
// ============================================================
#include <array>
#include <iostream>

template <typename T, std::size_t Row, std::size_t Col>
void printArray(const std::array<std::array<T, Col>, Row> &arr)
{
    for (const auto& arow: arr)   // get each array row
    {
        for (const auto& e: arow) // get each element of the row
            std::cout << e << ' ';

        std::cout << '\n';
    }
}

int main()
{
    std::array<std::array<int, 4>, 3>  arr {{
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }}};

    printArray(arr);

    return 0;
}

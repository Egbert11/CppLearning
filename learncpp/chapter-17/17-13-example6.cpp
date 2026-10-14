// ============================================================
// 来源小节：17.13 Multidimensional std::array
// 示例说明：更安全地获取各维长度——从非类型模板参数直接返回（原 Example 7）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multidimensional-stdarray/
// 预期输出：
//   Rows: 3
//   Cols: 4
// ============================================================
#include <array>
#include <iostream>

// An alias template for a two-dimensional std::array
template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

// Fetch the number of rows from the Row non-type template parameter
template <typename T, std::size_t Row, std::size_t Col>
constexpr int rowLength(const Array2d<T, Row, Col>&) // you can return std::size_t if you prefer
{
    return Row;
}

// Fetch the number of cols from the Col non-type template parameter
template <typename T, std::size_t Row, std::size_t Col>
constexpr int colLength(const Array2d<T, Row, Col>&) // you can return std::size_t if you prefer
{
    return Col;
}

int main()
{
    // Define a two-dimensional array of int with 3 rows and 4 columns
    Array2d<int, 3, 4> arr {{
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }}};

    std::cout << "Rows: " << rowLength(arr) << '\n'; // get length of first dimension (rows)
    std::cout << "Cols: " << colLength(arr) << '\n'; // get length of second dimension (cols)

    return 0;
}

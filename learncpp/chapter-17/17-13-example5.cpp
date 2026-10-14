// ============================================================
// 来源小节：17.13 Multidimensional std::array
// 示例说明：用 size() 与 arr[0].size() 取各维长度（原 Example 6）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multidimensional-stdarray/
// 预期输出：
//   Rows: 3
//   Cols: 4
// 备注：arr[0].size() 的做法在"非最后一维长度为 0"时属于未定义行为；
//       本例长度分别为 3 与 4，非 0，因此安全。下一示例给出更安全的替代。
// ============================================================
#include <array>
#include <iostream>

// An alias template for a two-dimensional std::array
template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

int main()
{
    // Define a two-dimensional array of int with 3 rows and 4 columns
    Array2d<int, 3, 4> arr {{
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }}};

    std::cout << "Rows: " << arr.size() << '\n';    // get length of first dimension (rows)
    std::cout << "Cols: " << arr[0].size() << '\n'; // get length of second dimension (cols), undefined behavior if length of first dimension is zero!

    return 0;
}

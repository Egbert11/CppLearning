// ============================================================
// 来源小节：17.12 Multidimensional C-style Arrays
// 示例说明：实用例子——用二维数组生成 9x9 乘法表（原 Example 15）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multidimensional-c-style-arrays/
// 预期输出：从 1 到 9 的 9x9 乘积网格，首行为
//   1    2    3    4    5    6    7    8    9
// 末行为
//   9    18   27   36   45   54   63   72   81
// ============================================================
#include <iostream>

int main()
{
    constexpr int numRows{ 10 };
    constexpr int numCols{ 10 };

    // 声明一个 10x10 的数组并全部零初始化
    int product[numRows][numCols]{};

    // 计算乘积表。从 1 开始，跳过全为 0 的第 0 行与第 0 列。
    for (std::size_t row{ 1 }; row < numRows; ++row)
        for (std::size_t col{ 1 }; col < numCols; ++col)
            product[row][col] = static_cast<int>(row * col);

    // 打印乘积表，同样跳过第 0 行与第 0 列
    for (std::size_t row{ 1 }; row < numRows; ++row)
    {
        for (std::size_t col{ 1 }; col < numCols; ++col)
            std::cout << product[row][col] << '\t';
        std::cout << '\n';
    }

    return 0;
}

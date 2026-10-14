// 来源小节：21.10 Overloading the parenthesis operator
// 示例说明：在 Matrix 上再加一个“零参数”的 operator()，把所有元素清零。
//           由于 operator() 的参数个数可变，同一类里可以并存不同参数个数的重载。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-parenthesis-operator/
// 说明：本节代码为按原文描述重建。
// 预期输出：0

#include <cassert> // for assert()
#include <iostream>

class Matrix
{
private:
    double m_data[4][4]{};

public:
    double& operator()(int row, int col);
    double operator()(int row, int col) const;
    void operator()();
};

double& Matrix::operator()(int row, int col)
{
    assert(row >= 0 && row < 4);
    assert(col >= 0 && col < 4);

    return m_data[row][col];
}

double Matrix::operator()(int row, int col) const
{
    assert(row >= 0 && row < 4);
    assert(col >= 0 && col < 4);

    return m_data[row][col];
}

void Matrix::operator()()
{
    // reset all elements of the matrix to 0.0
    for (int row{ 0 }; row < 4; ++row)
    {
        for (int col{ 0 }; col < 4; ++col)
        {
            m_data[row][col] = 0.0;
        }
    }
}

int main()
{
    // --- 原文示例片段 ---
    Matrix matrix{};
    matrix(1, 2) = 4.5;
    matrix(); // erase matrix
    std::cout << matrix(1, 2) << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}

// 来源小节：21.10 Overloading the parenthesis operator
// 示例说明：Matrix 内部是 4x4 的 double 数组。operator() 可以接受任意数量的参数，
//           这里用两个下标直接读写二维元素。matrix(1, 2) = 4.5; 并另提供 const 重载。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-parenthesis-operator/
// 说明：本节代码为按原文描述重建。
// 预期输出：4.5

#include <cassert> // for assert()
#include <iostream>

class Matrix
{
private:
    double m_data[4][4]{};

public:
    double& operator()(int row, int col);
    double operator()(int row, int col) const; // for const objects
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

int main()
{
    // --- 原文示例片段 ---
    Matrix matrix{};
    matrix(1, 2) = 4.5;
    std::cout << matrix(1, 2) << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}

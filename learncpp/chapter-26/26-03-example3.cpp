// ============================================================
// 来源小节：26.3 Function template specialization（原 Example 3）
// 示例说明：显式（全）模板特化。主模板必须出现在前面；`template<>` 表示
//           后面这个模板已经没有任何模板参数；`print<double>` 指明为 double
//           特化。全特化不是隐式 inline，放进头文件时要自己加 inline。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-template-specialization/
// 预期输出：
//   5
//   6.700000e+000
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
#include <iostream>

// Here's our primary template (must come first)
template <typename T>
void print(const T& t)
{
    std::cout << t << '\n';
}

// A full specialization of primary template print<T> for type double
// Full specializations are not implicitly inline, so make this inline if put in header file
template<>                          // template parameter declaration containing no template parameters
void print<double>(const double& d) // specialized for type double
{
    std::cout << std::scientific << d << '\n';
}

int main()
{
    print(5);
    print(6.7);

    return 0;
}

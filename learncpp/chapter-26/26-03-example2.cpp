// ============================================================
// 来源小节：26.3 Function template specialization（原 Example 2）
// 示例说明：为一个具体类型单独写一个非模板函数重载（此处是 double）。
//           重载决议会优先选中它，而不用实例化模板版本。
//           注意它的签名可以与模板不同：模板收 const 引用，这个按值收。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-template-specialization/
// 预期输出：
//   5
//   6.700000e+000
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
#include <iostream>

template <typename T>
void print(const T& t)
{
    std::cout << t << '\n';
}

void print(double d)
{
    std::cout << std::scientific << d << '\n';
}

int main()
{
    print(5);
    print(6.7);

    return 0;
}

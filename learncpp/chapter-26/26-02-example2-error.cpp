// ============================================================
// 来源小节：26.2 Template non-type parameters（原 Example 2）
// 示例说明：非类型参数必须是 constexpr。这里 x 是运行时变量，用它去实例化
//           模板会导致编译错误。
// 原文链接：https://www.learncpp.com/cpp-tutorial/template-non-type-parameters/
// 预期：**编译失败**，请勿修复。
//   预期错误（GCC）：error: the value of 'x' is not usable in a constant
//   expression —— 即“模板非类型实参必须是 constexpr”。
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
template <int size>
class Foo
{
};

int main()
{
    int x{ 4 }; // x is non-constexpr
    Foo<x> f; // error: the template non-type argument must be constexpr

    return 0;
}

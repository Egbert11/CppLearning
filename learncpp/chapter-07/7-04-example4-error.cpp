// 来源小节：7.4 Introduction to global variables
// 示例说明：常量全局变量必须初始化——const / constexpr 全局变量缺少初始化式是编译错误。
//           （对应原文 Example 4 中的两条错误行）
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-global-variables/
//
// ※※※ 预期编译失败 ※※※
// 预期错误（GCC 类似）：error: uninitialized 'const g_x' [-fpermissive]
//                        error: uninitialized 'const g_z' [-fpermissive]
// 本文件用于演示"常量全局变量必须初始化"，请勿"修复"，也勿纳入正常构建。

const int g_x;     // error: constant variables must be initialized
constexpr int g_z; // error: constexpr variables must be initialized

int main()
{
    return 0;
}

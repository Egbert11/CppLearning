// 来源小节：7.3 Local variables
// 示例说明：同一作用域内名字不能重复——形参 x 与函数体内再次声明的 x 冲突。（对应原文 Example 3）
// 原文链接：https://www.learncpp.com/cpp-tutorial/local-variables/
//
// ※※※ 预期编译失败 ※※※
// 预期错误（GCC 类似）：error: declaration of 'int x' shadows a parameter
//                        （多份）redeclaration of 'int x'
// 本文件用于演示命名冲突导致的编译错误，请勿"修复"，也勿纳入正常构建。

void someFunction(int x) // x is a parameter
{
    int x{}; // compile error: name collision with function parameter x
}

int main()
{
    return 0;
}

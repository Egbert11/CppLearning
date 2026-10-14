// 来源小节：11.6 Function templates
// 示例说明：把 int 换成 T，但还没有用模板参数声明来定义 T，因此无法编译。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-templates/
//
// 编译：g++ -std=c++20 -Wall 11-06-example3-error.cpp -o a
//
// 本文件为"预期编译失败"示例（后缀 -error），请勿修复：
//   预期错误：'T' was not declared in this scope（以及 'T' does not name a type）。
//
// 本节代码为按原文描述重建。

T max(T x, T y) // won't compile because we haven't defined T
{
    return (x < y) ? y : x;
}

int main()
{
    return 0;
}

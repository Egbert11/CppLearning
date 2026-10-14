// 来源小节：11.10 Using function templates in multiple files
// 示例说明（链接失败示例，第二部分）：模板定义放在单独的 add.cpp 中，
//           但该文件没有任何对模板的使用，因此不会实例化出 addOne<int>/addOne<double>，
//           最终 addOne 的符号从未被生成，链接失败。预期链接失败；勿修复。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-function-templates-in-multiple-files/
// 本节代码为按原文描述重建

template <typename T>
T addOne(T x) // function template definition
{
    return x + 1;
}

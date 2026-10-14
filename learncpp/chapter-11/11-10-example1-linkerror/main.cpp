// 来源小节：11.10 Using function templates in multiple files
// 示例说明（链接失败示例，第一部分）：main.cpp 只看到函数模板的前置声明，
//           编译器无法实例化 addOne<int>/addOne<double>，只能假设它们在别处，
//           最终链接失败。预期链接失败；勿修复。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-function-templates-in-multiple-files/
// 本节代码为按原文描述重建
// 预期链接错误：LNK2019 / undefined reference to `int addOne<int>(int)'

#include <iostream>

template <typename T>
T addOne(T x); // function template forward declaration

int main()
{
    std::cout << addOne(1) << '\n';
    std::cout << addOne(2.3) << '\n';

    return 0;
}

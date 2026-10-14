// 来源小节：11.7 Function template instantiation
// 示例说明：重载决议——模板函数与非模板函数同名时，三种调用语法分别选中谁
//   max<int>(1, 2) 显式指定模板实参 -> 调用模板实例
//   max<>(1, 2)    空尖括号，只考虑模板 -> 推导出 max<int>
//   max(1, 2)      普通调用语法，非模板优先 -> 调用非模板 max(int, int)
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-template-instantiation/
// 本节代码为按原文描述重建
// 预期输出：
// called max<int>(int, int)
// 2
// called max<int>(int, int)
// 2
// called max(int, int)
// 2

#include <iostream>

template <typename T>
T max(T x, T y)
{
    std::cout << "called max<int>(int, int)\n";
    return (x < y) ? y : x;
}

int max(int x, int y)
{
    std::cout << "called max(int, int)\n";
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max<int>(1, 2) << '\n'; // calls max<int>(int, int)
    std::cout << max<>(1, 2) << '\n';    // deduces max<int>(int, int) (non-template functions not considered)
    std::cout << max(1, 2) << '\n';      // calls max(int, int)

    return 0;
}

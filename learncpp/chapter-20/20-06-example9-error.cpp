// 来源小节：20.6 Introduction to lambdas (anonymous functions)
// 示例说明：lambda 的返回类型推导要求所有 return 语句返回同一类型；
//           下面的 lambda 一个分支返回 int、另一个返回 double，编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
// 预期错误：error: inconsistent types 'int' and 'double' deduced for lambda return type
// 说明：本节代码为按原文描述重建。请勿修复，此文件故意无法编译。
//       修复办法是显式给出尾置返回类型 `-> double`（见 20-06-example9b.cpp），
//       通常比给每个 return 都加转换更好。

#include <iostream>

int main()
{
    auto divide{ [](int x, int y, bool bInteger) {
        if (bInteger)
            return x / y; // returns an int
        else
            return static_cast<double>(x) / y; // returns a double -- inconsistent!
    } };

    std::cout << divide(10, 4, true) << '\n';
    std::cout << divide(10, 4, false) << '\n';

    return 0;
}

// 来源小节：20.7 Lambda captures
// 示例说明：捕获的变量默认是 const —— lambda 的 operator() 把捕获当作 const，
//           所以不能修改，除非加 mutable。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lambda-captures/
// 预期错误：error: decrement of read-only variable 'ammo'
//           （GCC 中对按值捕获的成员的修改会报只读错误）
// 说明：本节代码为按原文描述重建。请勿修复，此文件故意无法编译
//       （修复方式见 20-07-example5.cpp：加 mutable）。

#include <iostream>

int main()
{
    int ammo{ 10 };

    // --- 原文示例片段 ---
    // Define a lambda and store it in a variable called "shoot".
    auto shoot{
        [ammo]() {
            // Illegal: ammo is const
            --ammo;

            std::cout << "Pew! " << ammo << " shot(s) left.\n";
        }
    };
    // --- 原文示例片段结束 ---

    shoot();

    return 0;
}

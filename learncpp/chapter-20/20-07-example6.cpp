// 来源小节：20.7 Lambda captures
// 示例说明：按引用捕获 &ammo，lambda 直接修改 main 里的变量。
//           按引用捕获的变量除非本身是 const，否则是非 const 的（不需要 mutable）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lambda-captures/
// 说明：本节代码为按原文描述重建。
// 预期输出：
//   Pew! 9 shot(s) left.
//   9 shot(s) left

#include <iostream>

int main()
{
    int ammo{ 10 };

    // --- 原文示例片段 ---
    auto shoot{
        [&ammo]() {
            // capture ammo by reference: we modify the real ammo
            --ammo;

            std::cout << "Pew! " << ammo << " shot(s) left.\n";
        }
    };
    // --- 原文示例片段结束 ---

    shoot();

    // ammo in main was changed by the lambda
    std::cout << ammo << " shot(s) left\n";

    return 0;
}

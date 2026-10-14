// 来源小节：20.7 Lambda captures
// 示例说明：给 lambda 加 mutable，使按值捕获的副本可以在 lambda 内部被修改。
//           注意 main 里的 ammo 不受影响（捕获的是副本）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lambda-captures/
// 说明：本节代码为按原文描述重建。
// 预期输出：
//   Pew! 9 shot(s) left.
//   Pew! 8 shot(s) left.
//   10 shot(s) left

#include <iostream>

int main()
{
    int ammo{ 10 };

    // --- 原文示例片段 ---
    auto shoot{
        [ammo]() mutable {
            // We're allowed to modify ammo now
            --ammo;

            std::cout << "Pew! " << ammo << " shot(s) left.\n";
        }
    };
    // --- 原文示例片段结束 ---

    shoot();
    shoot();

    // ammo in main is unchanged: the lambda modified its own copy
    std::cout << ammo << " shot(s) left\n";

    return 0;
}

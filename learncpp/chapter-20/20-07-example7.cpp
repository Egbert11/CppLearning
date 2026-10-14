// 来源小节：20.7 Lambda captures
// 示例说明：按引用捕获 &comparisons，在排序过程中统计比较次数（副作用）。
//           对非基本类型或需要在 lambda 中修改外部变量时，优先按引用捕获。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lambda-captures/
// 说明：本节代码为按原文描述重建。
// 可能输出（比较次数依标准库实现而定）：
//   Comparisons: 2
//   Honda Civic
//   Toyota Corolla
//   Volkswagen Golf

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Car
{
    std::string_view make{};
    std::string_view model{};
};

int main()
{
    std::array<Car, 3> cars{ { { "Volkswagen", "Golf" },
                              { "Toyota", "Corolla" },
                              { "Honda", "Civic" } } };

    int comparisons{ 0 };

    // --- 原文示例片段 ---
    std::sort(cars.begin(), cars.end(),
        // Capture @comparisons by reference.
        [&comparisons](const auto& a, const auto& b) {
            // We captured comparisons by reference. We can modify it without "mutable".
            ++comparisons;

            // Sort the cars by their make.
            return a.make < b.make;
        }
    );
    // --- 原文示例片段结束 ---

    std::cout << "Comparisons: " << comparisons << '\n';

    for (const auto& car : cars)
    {
        std::cout << car.make << ' ' << car.model << '\n';
    }

    return 0;
}

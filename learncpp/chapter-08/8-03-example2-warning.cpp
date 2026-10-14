// 来源小节：8.3 Common if statement problems
// 示例说明：悬垂 else（dangling else）问题——else 到底属于哪个 if 产生歧义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-if-statement-problems/
// 预期警告：本示例演示的正是会产生该警告的写法（-warning 后缀），警告为预期行为，请勿消除。
//
// 编译：g++ -std=c++20 -Wall 8-03-example2.cpp -o a
//       预期产生警告：warning: suggest explicit braces to avoid ambiguous 'else' [-Wdangling-else]
//       （这正说明"悬垂 else"是编译器也会提示的歧义问题）
//
// 本节代码为按原文描述重建（原文示例 2 与示例 3 是同一段代码/其编译器实际分组）。
//
// 原文预期输出（输入 21）：
//   Enter a number: 21
//   21 is negative

#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    if (x >= 0) // outer if-statement
        // it is bad coding style to nest if statements this way
        if (x <= 20) // inner if-statement
            std::cout << x << " is between 0 and 20\n";

    // which if statement does this else belong to?
    else
        std::cout << x << " is negative\n";

    return 0;
}

// 原文示例 3 说明：编译器实际把它看作
//   if (x >= 0)
//   {
//       if (x <= 20)
//           std::cout << x << " is between 0 and 20\n";
//       else // attached to inner if statement
//           std::cout << x << " is negative\n";
//   }
// 因此输入 21 时，内层 if 为假，执行 else，打印 "21 is negative"。

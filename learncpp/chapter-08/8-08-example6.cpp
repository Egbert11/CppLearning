// 来源小节：8.8 Introduction to loops and while statements
// 示例说明：有意的无限循环，用 return 语句从 main 退出。
//           原文示例 5 给出 while (true) 的骨架；示例 6 用 return 结束程序，
//           这种模式在持续运行的服务器程序里很常见。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/
//
// 编译：g++ -std=c++20 -Wall 8-08-example6.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文示例 5 的骨架：
//   while (true)
//   {
//       // 永远循环下去
//   }
//
// 原文示例 6 的运行示例：
//   Loop again (y/n)? y
//   Loop again (y/n)? y
//   Loop again (y/n)? n
//   （程序结束）

#include <iostream>

int main()
{
    while (true) // infinite loop
    {
        std::cout << "Loop again (y/n)? ";
        char c{};
        std::cin >> c;

        if (c == 'n')
            return 0;
    }

    return 0;
}

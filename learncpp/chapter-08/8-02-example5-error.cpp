// 来源小节：8.2 If statements and blocks
// 示例说明：变量在分支的隐式块中定义，出了块即被销毁 —— 本文件故意无法编译。
//           编译器报错形如：error: 'x' was not declared in this scope
// 原文链接：https://www.learncpp.com/cpp-tutorial/if-statements-and-blocks/
//
// 编译：g++ -std=c++20 -Wall 8-02-example5-error.cpp -o a   （预期编译失败）
//
// 本节代码为按原文描述重建。
// 说明：原文示例 6 用显式花括号重写同一段逻辑，并把同样的结论写在注释里；两种写法
//       都会在此处报错，因此这里用一份文件同时表达原文示例 5 与示例 6 的要点。

#include <iostream>

int main()
{
    // --- 原文示例片段（隐式块） ---
    if (true) // 隐式块
        int x{ 5 };
    else // 隐式块
        int x{ 6 };

    std::cout << x << '\n'; // 错误：x 在各自的块结束时已被销毁，这里不在作用域内
    // --- 原文示例片段结束 ---

    return 0;
}

// 原文示例 6 的等价显式写法（同样无法编译）：
//   if (true)
//   {
//       int x{ 5 };
//   }
//   else
//   {
//       int x{ 6 };
//   }
//   std::cout << x << '\n'; // x 不在作用域内

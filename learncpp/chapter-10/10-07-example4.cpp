// 来源小节：10.7 Typedefs and type aliases
// 示例说明：typedef 与 using 的两种等价写法；并说明 typedef 容易把名称与类型顺序
//           写反。（对应原文示例 7、8）
// 原文链接：https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
//
// 编译：g++ -std=c++20 -Wall 10-07-example4.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

// --- 原文示例片段（两种等价写法） ---
typedef long Miles;
using Speed = long;
// --- 原文示例片段结束 ---

// typedef 的顺序陷阱（错误形式，仅作注释说明，勿编译）：
//   typedef Distance double; // incorrect (typedef name first)
//   typedef double Distance; // correct (aliased type name first)

int main()
{
    Miles m{ 10 };
    Speed s{ 20 };

    std::cout << m << ' ' << s << '\n';

    return 0;
}

// 来源小节：8.3 Common if statement problems
// 示例说明：坏实践 / 危险 bug——if 条件后面误加了一个分号，导致本该条件执行的语句
//           "无条件执行"（即使它在块里）。原文示例 8 与示例 9 讲的是同一件事。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-if-statement-problems/
//
// 编译：g++ -std=c++20 -Wall 8-03-example8-broken.cpp -o a
//
// 本节代码为按原文描述重建（原文用未定义函数，此处补桩函数使程序可编译运行）。
//
// 运行结果：无论 nuclearCodesActivated() 返回什么，blowUpTheWorld() 都会执行。

#include <iostream>

bool nuclearCodesActivated() { return false; } // 危险：返回 false 也拦不住
void blowUpTheWorld()        { std::cout << "boom!\n"; }

int main()
{
    // --- 原文示例 8 片段（注意行尾的分号） ---
    if (nuclearCodesActivated()); // note the semicolon at the end of this line
        blowUpTheWorld();
    // --- 原文示例片段结束 ---

    // 原文示例 9 说明，编译器把它看作：
    // if (nuclearCodesActivated())
    //     ; // the semicolon acts as a null statement
    // blowUpTheWorld(); // and this line always gets executed!

    return 0;
}

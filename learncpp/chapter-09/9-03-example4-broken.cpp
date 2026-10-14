// 来源小节：9.3 Common semantic errors in C++
// 示例说明：无符号数倒计时陷阱——unsigned 的 count >= 0 永远为真，减到 0 后回绕成
//           4294967295 继续往下，形成无限循环。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/
//
// 编译：g++ -std=c++20 -Wall 9-03-example4-broken.cpp -o a
//       （加 -Wextra 会得到 warning: comparison of unsigned expression in '>= 0' is always true）
// 预期输出：5 4 3 2 1 blastoff! 4294967295 4294967294 4294967293 4294967292 4294967291 ...
//           （该回绕值依平台而定，这里假设 32 位 unsigned int）
//
// 本节代码为按原文描述重建。本文件演示有意的语义错误（坏实践）。
// 警告：本程序不会自行结束，请勿直接运行。

#include <iostream>

int main()
{
    for (unsigned int count{ 5 }; count >= 0; --count)
    {
        if (count == 0)
            std::cout << "blastoff! ";
        else
            std::cout << count << ' ';
    }

    return 0;
}

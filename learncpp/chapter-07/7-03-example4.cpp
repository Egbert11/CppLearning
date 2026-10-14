// 来源小节：7.3 Local variables
// 示例说明：自动存储期（automatic storage duration）——局部变量在定义处创建、在块结束时销毁，
//           因此又称"自动变量（automatic variables）"。（对应原文 Example 4）
// 原文链接：https://www.learncpp.com/cpp-tutorial/local-variables/
//
// 预期输出：5 4
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int main()
{
    int i { 5 };      // i created and initialized here
    double d { 4.0 }; // d created and initialized here

    std::cout << i << ' ' << d << '\n';

    return 0;
} // i and d destroyed here

// 来源小节：10.x Chapter 10 summary and quiz（本文件编号 10-10）
// 示例说明：测验 1 之 1c —— int c { 5.4 }; 5.4 是 double，转换为 int 会丢小数，
//           花括号初始化拒绝该窄化，因此编译失败。
//           编译器报错形如：error: narrowing conversion of '5.4e+0' from 'double' to 'int'
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-10-summary-and-quiz/
//
// 编译：g++ -std=c++20 -Wall 10-10-quiz1-c-error.cpp -o a   （预期编译失败）
//
// 本节代码为按原文解答要点重建。

int main()
{
    int c{ 5.4 }; // 1c: 无法编译——窄化转换

    (void)c;
    return 0;
}

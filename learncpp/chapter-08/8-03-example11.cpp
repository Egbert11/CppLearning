// 来源小节：8.3 Common if statement problems
// 示例说明：用预处理宏 PASS 模拟 Python 的 pass 关键字（原文 Tip）。
//           PASS 会被预处理器替换为空，因此行尾的分号就成了一条空语句。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-if-statement-problems/
//
// 编译：g++ -std=c++20 -Wall 8-03-example11.cpp -o a
//
// 本节代码为按原文描述重建。

#define PASS

void foo(int x, int y)
{
    if (x > y)
        PASS;
    else
        PASS;
}

int main()
{
    foo(4, 7);

    return 0;
}

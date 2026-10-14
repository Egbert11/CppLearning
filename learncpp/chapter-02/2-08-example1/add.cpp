// 来源小节：2.8 Programs with multiple code files
// 示例说明：add() 函数的定义所在文件。必须和 main.cpp 一起交给编译器，再由链接器把它们连起来。
// 原文链接：https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files/

int add(int x, int y)
{
    return x + y;
}

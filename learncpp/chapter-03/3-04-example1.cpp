// 来源小节：3.4 Basic debugging tactics
// 示例说明：手法 #1（注释掉代码）的初始程序：main() 中按序调用 getNames/doMaintenance/sortNames/printNames。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-debugging-tactics/
//
// 说明：原文仅给出 main() 片段；下方四个函数是为让示例可编译运行而补上的占位实现。

#include <iostream>

// --- 原文未给出的占位实现（仅为让示例可编译运行） ---
void getNames()
{
    std::cout << "[getNames] ask user to enter a bunch of names\n";
}

void doMaintenance()
{
    std::cout << "[doMaintenance] do some random stuff\n";
}

void sortNames()
{
    std::cout << "[sortNames] sort them in alphabetical order\n";
}

void printNames()
{
    std::cout << "[printNames] print the sorted list of names\n";
}
// --- 占位实现结束 ---

int main()
{
    // --- 原文示例片段 ---
    getNames(); // ask user to enter a bunch of names
    doMaintenance(); // do some random stuff
    sortNames(); // sort them in alphabetical order
    printNames(); // print the sorted list of names
    // --- 原文示例片段结束 ---

    return 0;
}

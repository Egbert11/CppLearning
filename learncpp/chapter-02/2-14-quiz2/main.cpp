// 来源小节：2.x Chapter 2 summary and quiz（官方编号 2.x）
// 题目 2：把 readNumber() 和 writeAnswer() 移到单独的 io.cpp 中，
//        main() 通过前置声明来调用它们。
// 示例说明：main.cpp 自己不需要 I/O，所以无需 #include <iostream>，只要前置声明即可。
// 提示：别忘了把 io.cpp 加入项目/编译命令，否则会出现 unresolved external symbol 链接错误。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/
//
// 编译：g++ -std=c++20 -Wall 2-14-quiz2/main.cpp 2-14-quiz2/io.cpp -o quiz2

// We don't need to #include <iostream> since main.cpp doesn't use any input/output functionality

int readNumber(); // forward declaration
void writeAnswer(int x); // forward declaration

int main()
{
    int x { readNumber() };
    int y { readNumber() };

    writeAnswer(x + y);

    return 0;
}

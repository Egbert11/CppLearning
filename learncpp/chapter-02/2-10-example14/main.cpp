// 来源小节：2.10 Introduction to the preprocessor（Example 14）
// 示例说明：main.cpp 中定义了 PRINT，但该宏不会影响 function.cpp。预期输出：Not printing!
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/
//
// 编译：g++ -std=c++20 -Wall 2-10-example14/main.cpp 2-10-example14/function.cpp -o a

void doSomething(); // forward declaration for function doSomething()

#define PRINT

int main()
{
    doSomething();

    return 0;
}

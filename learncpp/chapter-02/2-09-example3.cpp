// 来源小节：2.9 Naming collisions and an introduction to namespaces
// 示例说明：原文 Example 7 —— 花括号划定的嵌套作用域区域（函数参数 x 与 main 内的 x 互不冲突）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/naming-collisions-and-an-introduction-to-namespaces/
//
// 编译：g++ -std=c++20 -Wall 2-09-example3.cpp -o a

#include <iostream> // imports the declaration of std::cout into the global scope

void foo(int x) // foo is defined in the global scope, x is defined within scope of foo()
{ // braces used to delineate nested scope region for function foo()
    std::cout << x << '\n';
} // x goes out of scope here

int main()
{ // braces used to delineate nested scope region for function main()
    foo(5);

    int x { 6 }; // x is defined within the scope of main()
    std::cout << x << '\n';

    return 0;
} // x goes out of scope here
// foo and main (and std::cout) go out of scope here (the end of the file)

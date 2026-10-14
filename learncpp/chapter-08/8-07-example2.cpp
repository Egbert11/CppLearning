// 来源小节：8.7 Goto statements
// 示例说明：向前跳转（forward jump）跳过一条打印语句；标签 end 因具有函数作用域而在此处可见，
//           且标签必须关联一条语句，所以后面跟一个空语句 `;`。
// 原文链接：https://www.learncpp.com/cpp-tutorial/goto-statements/
//
// 编译：g++ -std=c++20 -Wall 8-07-example2.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   cats

#include <iostream>

void printCats(bool skip)
{
    if (skip)
        goto end; // jump forward; statement label 'end' is visible here due to it having function scope

    std::cout << "cats\n";
end:
    ; // statement labels must be associated with a statement
}

int main()
{
    printCats(true);  // jumps over the print statement and doesn't print anything
    printCats(false); // prints "cats"

    return 0;
}

// 来源小节：20.1 Function Pointers
// 示例说明：用函数指针（或 static_cast 到具体函数指针类型）在重载之间消歧。
//           因为默认参数是在编译期应用到调用处的，通过函数指针调用时无法解析默认参数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-pointers/
// 说明：本节代码为按原文描述重建。

#include <iostream>

void print(int x)
{
    std::cout << "print(int): " << x << '\n';
}

void print(int x, int y = 10)
{
    std::cout << "print(int, int): " << x << ' ' << y << '\n';
}

int main()
{
    // --- 原文示例片段 ---
    // print(1); // ambiguous! Which print() function?
    // --- 原文示例片段结束 ---

    // --- 原文示例片段 ---
    using vnptr = void(*)(int); // define a type alias for a function pointer to a void(int) function
    vnptr pi { print };         // initialize our function pointer with function print
    pi(1);                      // call the print(int) function through the function pointer

    // we can also cast a function to a specific overload
    static_cast<void(*)(int)>(print)(1); // call print(int) (not ambiguous)
    // --- 原文示例片段结束 ---

    return 0;
}

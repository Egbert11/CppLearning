// 来源小节：20.1 Function Pointers
// 示例说明：用 std::function 存储函数指针（比原生语法更易读），
//           并演示类型别名、CTAD 与 auto 的三种写法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-pointers/
// 说明：本节代码为按原文描述重建。
// 预期输出：6（调用 goo）

#include <functional>
#include <iostream>

int foo()
{
    return 5;
}

int goo()
{
    return 6;
}

// --- 原文示例片段 ---
// A type alias to a raw function pointer
using ValidateFunctionRaw = bool(*)(int, int);
// A type alias to std::function
using ValidateFunction = std::function<bool(int, int)>;
// --- 原文示例片段结束 ---

int main()
{
    // --- 原文示例片段 ---
    std::function<int()> fcnPtr{ &foo }; // declare function pointer that returns an int and takes no parameters
    fcnPtr = &goo;                       // fcnPtr now points to function goo
    std::cout << fcnPtr() << '\n';       // call the function just like normal

    // std::function does not allow the explicit dereference form:
    // (*fcnPtr)(); // error: no match for operator*

    std::function fcnPtr2{ &foo }; // can also define the type using CTAD
    (void)fcnPtr2;
    // --- 原文示例片段结束 ---

    // --- 原文示例片段 ---
    auto fcnPtr3{ &foo };              // auto deduces the raw function pointer type
    std::cout << fcnPtr3() << '\n';
    // --- 原文示例片段结束 ---

    (void)ValidateFunctionRaw{};
    (void)ValidateFunction{};

    return 0;
}

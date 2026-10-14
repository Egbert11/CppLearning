// 来源小节：20.1 Function Pointers
// 示例说明：函数指针的声明、const 函数指针、初始化与赋值、类型必须匹配、
//           显式/隐式解引用调用，以及调用前的空指针检查。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-pointers/
// 说明：本节代码为按原文描述重建。
//       原文还列了两行“错误”的初始化（int (*)(){&goo} 当 goo 返回 double、
//       以及 fcnPtr1 = &hoo 因为参数不匹配），它们会编译失败，此处以注释说明。

#include <iostream>

int foo()
{
    return 5;
}

int goo()
{
    return 6;
}

int hoo(int x)
{
    return x;
}

double moo() // for the return-type-matching demo
{
    return 1.5;
}

int main()
{
    // --- 原文示例片段 ---
    // fcnPtr is a pointer to a function that takes no arguments and returns an integer
    int (*fcnPtr)(){ &foo }; // fcnPtr points to function foo
    fcnPtr = &goo;           // fcnPtr now points to function goo

    // A const function pointer (const goes after the star)
    int (*const constPtr)(){ &foo };
    (void)constPtr;

    // The type (parameters and return type) of the function pointer must match the function
    int (*fcnPtr1)(){ &foo };      // okay: returns int, takes no parameters
    double (*fcnPtr4)(){ &moo };   // okay: returns double, takes no parameters
    int (*fcnPtr3)(int){ &hoo };   // okay: returns int, takes one int
    // int (*fcnPtr2)(){ &moo };   // wrong -- return types don't match!
    // fcnPtr1 = &hoo;             // wrong -- fcnPtr1 has no parameters, but hoo() does

    // Function pointers can be initialized/assigned with the function name; & is optional
    int (*fcnPtr5)(){ foo };       // okay, foo implicitly converts to function pointer to foo

    // Function pointers may also be null
    int (*nullPtr)() { nullptr };  // okay
    // --- 原文示例片段结束 ---

    std::cout << "goo() via fcnPtr returns " << fcnPtr() << '\n'; // implicit dereference call

    // --- 原文示例片段 ---
    int (*fcnPtrX)(int){ &hoo };
    std::cout << (*fcnPtrX)(5) << '\n'; // explicit dereference: call function hoo(5) through fcnPtr
    std::cout << fcnPtrX(5) << '\n';    // implicit dereference: call function hoo(5) through fcnPtr

    // Because pointers can be null, always check before calling;
    // dereferencing a null function pointer is undefined behavior.
    if (nullPtr)   // make sure nullPtr isn't a null pointer
        nullPtr(); // otherwise this would lead to undefined behavior
    else
        std::cout << "nullPtr is null, not calling it\n";
    // --- 原文示例片段结束 ---

    (void)fcnPtr1; (void)fcnPtr3; (void)fcnPtr4; (void)fcnPtr5;
    return 0;
}

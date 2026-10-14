// ============================================================
// 来源小节：19.5 Void pointers
// 示例说明：void 指针不能直接解引用，必须先 static_cast 回具体类型；
//           同一个 void 指针可以先后指向 int、float、struct 等任意类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/void-pointers/
// 预期输出：5
// 备注：本节代码为按原文描述重建（原文 Example 1/2/3/5）。
// ============================================================
#include <iostream>

struct Something
{
    int n;
    float f;
};

int main()
{
    int nValue {};
    float fValue {};

    Something sValue {};

    void* ptr {}; // ptr is a void pointer
    ptr = &nValue; // valid
    ptr = &fValue; // valid
    ptr = &sValue; // valid
    (void)ptr; // 原文无此行；仅为避免"变量被赋值但未使用"警告

    int value{ 5 };
    void* voidPtr{ &value };

    // std::cout << *voidPtr << '\n'; // illegal: dereference of void pointer

    int* intPtr{ static_cast<int*>(voidPtr) }; // however, if we cast our void pointer to an int pointer...
    std::cout << *intPtr << '\n'; // then we can dereference the result

    void* nullPtr{ nullptr }; // ptr is a void pointer that is currently a null pointer
    (void)nullPtr;

    return 0;
}

// 来源小节：20.1 Function Pointers
// 示例说明：函数也有地址；直接打印函数名时，标准会把函数指针转换为 bool，
//           非空所以符合标准的实现会输出 1。若想真正打印地址需强制转换为 void*。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-pointers/
// 说明：本节代码为按原文描述重建。

#include <iostream>

int foo() // code for foo starts at memory address 0x002717f0
{
    return 5;
}

int main()
{
    // --- 原文示例片段 ---
    // we meant to call foo(), but instead we're printing foo itself!
    // Modern compilers convert the function pointer to bool; since it is
    // non-null, a conforming program prints 1.
    // (GCC 会给出 warning: the address of 'int foo()' will never be NULL
    //  [-Waddress]，因为它知道函数地址非空；此处本地关闭该诊断以保持输出干净。)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waddress"
    std::cout << foo << '\n'; // prints 1 (not the address!)
#pragma GCC diagnostic pop

    // To actually print the address, cast to void*.
    // This is implementation-defined behavior, so it may not work on all platforms.
    std::cout << reinterpret_cast<void*>(foo) << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}

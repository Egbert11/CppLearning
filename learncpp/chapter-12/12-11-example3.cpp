// ============================================================
// 来源小节：12.11 Pass by address (part 2)
// 示例说明：按地址传递复制的是地址。把函数的**指针形参**重新赋值（改为
//           nullptr）只改动了形参这个局部副本，调用方的指针不受影响。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-address-part-2/
// 预期输出：
//   ptr is non-null
//   ptr is non-null
// 备注：本节代码为按原文清单忠实重建（原 Example 3）。
// ============================================================
#include <iostream>

// [[maybe_unused]] gets rid of compiler warnings about ptr2 being set but not used
void nullify([[maybe_unused]] int* ptr2)
{
    ptr2 = nullptr; // Make the function parameter a null pointer
}

int main()
{
    int x{ 5 };
    int* ptr{ &x }; // ptr points to x

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    nullify(ptr);

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
    return 0;
}

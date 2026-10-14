// ============================================================
// 来源小节：12.11 Pass by address (part 2)
// 示例说明：若要真正改变“指针实参指向哪里”，形参应声明为**指针的引用**
//           （int*&）。此时形参绑定到调用方的指针，赋值为 nullptr 会传回
//           到实参。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-address-part-2/
// 预期输出：
//   ptr is non-null
//   ptr is null
// 备注：本节代码为按原文清单忠实重建（原 Example 4）。
// ============================================================
#include <iostream>

void nullify(int*& refptr) // refptr is now a reference to a pointer
{
    refptr = nullptr; // Make the function parameter a null pointer
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

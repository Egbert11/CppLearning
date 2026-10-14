// ============================================================
// 来源小节：12.10 Pass by address
// 示例说明：不加检查就解引用可能为空的指针。程序先打印 5，随后很可能崩溃。
//           按地址传递时要格外小心：实参可能是一个空指针。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-address/
// !! -ub：未定义行为演示，可编译。解引用空指针是未定义行为（通常崩溃）。
// 预期输出（但随后 UB）：5
// 备注：本节代码为按原文描述忠实重建（原 Example 9）。
// ============================================================
#include <iostream>

void print(int* ptr)
{
    std::cout << *ptr << '\n'; // undefined behavior if ptr is null
}

int main()
{
    int x{ 5 };
    print(&x); // prints 5

    int* myPtr {};
    print(myPtr); // undefined behavior: myPtr is null, likely crashes

    return 0;
}

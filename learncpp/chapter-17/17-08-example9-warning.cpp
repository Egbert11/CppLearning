// ============================================================
// 来源小节：17.8 C-style array decay
// 示例说明：sizeof() 对数组返回 12，对退化后的指针返回 4（原 Example 9）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-array-decay/
// 预期输出（假设 int 为 4 字节、指针为 4 字节）：
//   12
//   4
// 备注：指针宽度依平台而定；在 64 位平台上第二个值可能是 8。
// 后缀：-warning。对"数组形参"用 sizeof 会触发 -Wsizeof-array-argument 警告，
//       这正体现了本示例的要点（形参已退化为指针），属预期警告。
// ============================================================
#include <iostream>

void printArraySize(int arr[])
{
    std::cout << sizeof(arr) << '\n'; // prints 4 (assuming 32-bit addresses)
}

int main()
{
    int arr[]{ 3, 2, 1 };

    std::cout << sizeof(arr) << '\n'; // prints 12 (assuming 4 byte ints)

    printArraySize(arr);

    return 0;
}

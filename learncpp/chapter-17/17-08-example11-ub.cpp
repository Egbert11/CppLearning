// ============================================================
// 来源小节：17.8 C-style array decay
// 示例说明：参数没有长度信息时，传入过短的数组或单个变量会导致越界读取，产生未定义行为
//           （原 Example 11）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-array-decay/
// 后缀：-ub 表示本文件演示未定义行为，可以编译但结果不可预期。
// 备注：printElement2(b) 与 printElement2(&c) 会读取数组/对象之外的内存，属 UB；
//       实际输出依实现而定，切勿依赖。示例演示 UB，仅供教学理解。
// ============================================================
#include <iostream>

void printElement2(int arr[])
{
    // How do we ensure that arr has at least three elements?
    std::cout << arr[2] << '\n';
}

int main()
{
    int a[]{ 3, 2, 1 };
    printElement2(a);  // ok

    int b[]{ 7, 6 };
    printElement2(b);  // compiles but produces undefined behavior

    int c{ 9 };
    printElement2(&c); // compiles but produces undefined behavior

    return 0;
}

// ============================================================
// 来源小节：12.6 Pass by const lvalue reference
// 示例说明：用函数式宏 isSmall 检查一个类型（或对象）是否"拷贝廉价"：
//           大小不超过两个内存地址宽，且没有额外的初始化开销。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/
// 备注：本节代码为按原文描述忠实重建（原 Example 5）。
// ============================================================
#include <iostream>

// Function-like macro that evaluates to true if the type (or object) is equal to or smaller than
// the size of two memory addresses
#define isSmall(T) (sizeof(T) <= 2 * sizeof(void*))

struct S
{
    double a;
    double b;
    double c;
};

int main()
{
    std::cout << std::boolalpha; // print true or false rather than 1 or 0
    std::cout << isSmall(int) << '\n'; // true

    double d {};
    std::cout << isSmall(d) << '\n'; // true
    std::cout << isSmall(S) << '\n'; // false

    return 0;
}

// 预期输出（64 位平台）：
// true
// true
// false
// 说明：S 含三个 double（24 字节），大于 2 个地址宽（16 字节），故为 false；
//       在 32 位平台 2*sizeof(void*)==8，结果同样为 true/true/false。

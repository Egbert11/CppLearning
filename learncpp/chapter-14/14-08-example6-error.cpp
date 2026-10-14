// ============================================================
// 来源小节：14.8 The benefits of data hiding (encapsulation)
// 示例说明：把内部实现换成数组后，使用方引用的 something.value1 不复存在——
//           预期编译失败。请勿修复此文件。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation/
// 预期错误：g++ 报错类似 "error: 'struct Something' has no member named 'value1'"
// 备注：本节代码为按原文描述忠实重建。此文件故意编译失败，用于说明
//       "实现直接暴露"会让使用方与内部布局耦合。
// ============================================================
#include <iostream>

struct Something
{
    int value[3] {}; // changed implementation: three separate ints -> an array
};

int main()
{
    Something something;
    something.value1 = 5; // compile error: value1 no longer exists

    return 0;
}

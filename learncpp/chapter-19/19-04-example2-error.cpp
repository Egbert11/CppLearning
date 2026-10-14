// ============================================================
// 来源小节：19.4 Pointers to pointers and dynamic multidimensional arrays
// 示例说明：不能直接把"值的地址的地址"交给二级指针：&&value 非法，
//           因为取地址运算符的运算对象必须是左值，而 &value 是右值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-to-pointers/
// 预期错误：编译失败。标准语义上，&value 是右值，不能再对它取地址，所以
//           "值的地址的地址" 无法直接构造；GCC 则把 &&value 解析成它的
//           "标签取址"扩展（&&label → void*），于是报
//           "invalid conversion from 'void*' to 'int**'"。
// 备注：预期编译失败（-error），请勿修复。原文 Example 4。
// ============================================================
#include <iostream>

int main()
{
    int value { 5 };
    int** ptrptr { &&value }; // not valid

    std::cout << **ptrptr << '\n';

    return 0;
}

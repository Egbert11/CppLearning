// 来源小节：11.9 Non-type template parameters
// 示例说明：std::bitset<8> 中的 <8> 就是一个非类型模板参数，表示存储的位数
// 原文链接：https://www.learncpp.com/cpp-tutorial/non-type-template-parameters/
// 本节代码为按原文描述重建
// 预期输出：无（本程序不打印任何内容）

#include <bitset>

int main()
{
    std::bitset<8> bits{ 0b0000'0101 }; // The <8> is a non-type template parameter

    return 0;
}

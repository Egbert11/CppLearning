// ============================================================
// 来源小节：13.3 Unscoped enumerator integral conversions
// 示例说明：char 类型实际存储的是整数值——字符常量 'A' 会被转换成整数 65
//           再存进去。这为理解"枚举量其实也是整数值"做铺垫。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerator-integral-conversions/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    char ch { 'A' };

    std::cout << "ch as char: " << ch << '\n';
    std::cout << "ch as int:  " << static_cast<int>(ch) << '\n';

    return 0;
}

// 预期输出（'A' 在 ASCII 下为 65）：
// ch as char: A
// ch as int:  65

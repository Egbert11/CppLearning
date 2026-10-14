// ============================================================
// 来源小节：19.2 Dynamically allocating arrays
// 示例说明：定长数组也可用统一初始化，且可省略长度（由初始化列表推导）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamically-allocating-arrays/
// 预期输出：9 7 5 3 1 / Hello, world!
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

int main()
{
    int fixedArray[]{ 9, 7, 5, 3, 1 }; // 长度由初始化列表推导
    char fixedArray2[]{ "Hello, world!" };

    for (int n : fixedArray)
        std::cout << n << ' ';
    std::cout << '\n';

    std::cout << fixedArray2 << '\n';

    return 0;
}

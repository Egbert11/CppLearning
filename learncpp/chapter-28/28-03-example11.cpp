// ============================================================
// 来源小节：28.3 Output with ostream and ios（原 Example 11）
// 示例说明：basefield 组（dec/oct/hex）——分别用双参数 setf() 与操纵器写法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/
// 预期输出：
//   27
//   27
//   33
//   1b
//   27
//   33
//   1b
// 备注：原 Example 11 是片段，这里包进 main() 并补 <iostream>。代码逐字抽取。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << 27 << '\n';

    std::cout.setf(std::ios::dec, std::ios::basefield);
    std::cout << 27 << '\n';

    std::cout.setf(std::ios::oct, std::ios::basefield);
    std::cout << 27 << '\n';

    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << 27 << '\n';

    std::cout << std::dec << 27 << '\n';
    std::cout << std::oct << 27 << '\n';
    std::cout << std::hex << 27 << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}

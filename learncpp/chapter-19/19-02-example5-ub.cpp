// ============================================================
// 来源小节：19.2 Dynamically allocating arrays
// 示例说明：对 new[] 分配的数组误用标量 delete（而非 delete[]）——未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamically-allocating-arrays/
// 预期输出：未定义。可能看似正常、可能崩溃，也可能破坏堆并导致后续错误。
// 备注：未定义行为演示（-ub），能编译。原文的 Warning 指出这是常见错误，
//       会导致内存损坏、泄漏或崩溃。本机 MSYS2 工具链可能触发堆检查而 abort。
// ============================================================
#include <iostream>

int main()
{
    int* array{ new int[5]{} };

    array[0] = 9;

    std::cout << array[0] << '\n';

    delete array; // 错误：应使用 delete[]（undefined behavior）

    return 0;
}

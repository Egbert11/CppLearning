// ============================================================
// 来源小节：12.1 Introduction to compound data types
// 示例说明：一个接收 (int, double) 并返回 void 的函数，其函数类型
//           是 void(int, double)。因为该类型由基本类型构造而来，
//           所以函数本身也是一种复合类型（并且拥有"可被调用"等
//           自己的行为）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-compound-data-types/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段 ---
void myFunction(int x, double y)
{
    std::cout << "myFunction called with " << x << " and " << y << '\n';
}
// --- 原文示例片段结束 ---

int main()
{
    // myFunction 的类型是 void(int, double)
    myFunction(4, 3.5);

    return 0;
}

// 预期输出：
// myFunction called with 4 and 3.5

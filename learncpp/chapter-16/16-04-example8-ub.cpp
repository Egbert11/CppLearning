// ============================================================
// 来源小节：16.4 Passing std::vector
// 示例说明：把只有 2 个元素的 vector 传给会索引元素 3 的函数，越界导致未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-stdvector/
// 预期输出：未定义行为——输出不定，可能打印垃圾值或崩溃（依实现而定）。
// 备注：本文件为未定义行为演示（-ub），能编译；请勿依赖其输出。
//       本机 MSYS2 工具链默认启用 _GLIBCXX_ASSERTIONS，operator[] 的越界断言会直接 abort。
// ============================================================
#include <iostream>
#include <vector>

template <typename T>
void printElement3(const std::vector<T>& arr)
{
    std::cout << arr[3] << '\n';
}

int main()
{
    std::vector arr{ 9, 7 }; // a 2-element array (valid indexes 0 and 1)
    printElement3(arr);

    return 0;
}

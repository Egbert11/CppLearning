// ============================================================
// 来源小节：16.4 Passing std::vector
// 示例说明：printElement3 固定索引 3；当 vector 足够长时正常输出。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-stdvector/
// 预期输出：3
// 备注：本节代码为按原文描述重建。过短的 vector 会导致 UB，见 16-04-example8-ub.cpp。
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
    std::vector arr{ 9, 7, 5, 3, 1 };
    printElement3(arr);

    return 0;
}

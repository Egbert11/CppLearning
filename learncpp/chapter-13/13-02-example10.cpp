// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：把枚举作为函数参数，表示"排序方式"。函数名 + 枚举类型名让调用处
//           一目了然，避免了神秘的数字参数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

enum SortOrder
{
    alphabetical,
    alphabeticalReverse,
    numerical,
};

void sortData(SortOrder order)
{
    switch (order)
    {
    case alphabetical:
        std::cout << "Sorting alphabetical\n";
        break;
    case alphabeticalReverse:
        std::cout << "Sorting reverse alphabetical\n";
        break;
    case numerical:
        std::cout << "Sorting numerically\n";
        break;
    }
}

int main()
{
    sortData(alphabeticalReverse);
    return 0;
}

// 预期输出：
// Sorting reverse alphabetical

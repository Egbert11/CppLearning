// ============================================================
// 来源小节：12.11 Pass by address (part 2)
// 示例说明：std::nullptr_t（定义于 <cstddef>）是 nullptr 独有的类型，只能
//           持有 nullptr 这一个值。用它作形参可以只接受 nullptr 字面量。
//           注意：重载按**类型**而非值匹配——ptr 即便是空指针，仍是 int*，
//           仍选 print(int*)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-address-part-2/
// 备注：本节代码为按原文清单忠实重建（原 Example 6）。
// ============================================================
#include <iostream>
#include <cstddef> // for std::nullptr_t

void print(std::nullptr_t)
{
    std::cout << "in print(std::nullptr_t)\n";
}

void print(int*)
{
    std::cout << "in print(int*)\n";
}

int main()
{
    print(nullptr); // calls print(std::nullptr_t)

    int x { 5 };
    int* ptr { &x };

    print(ptr); // calls print(int*)

    ptr = nullptr;
    print(ptr); // calls print(int*) (since ptr has type int*)

    return 0;
}

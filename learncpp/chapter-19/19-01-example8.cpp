// ============================================================
// 来源小节：19.1 Dynamic memory allocation with new and delete
// 示例说明：用 std::nothrow 让 new 在失败时返回空指针，并在使用前检查结果。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/
// 预期输出：7（分配失败时改为向 stderr 打印提示并返回 1）
// 备注：本节代码为按原文描述重建（原文 Example 10/11）。
// ============================================================
#include <iostream>
#include <new> // std::nothrow

int main()
{
    int* value { new (std::nothrow) int{} }; // value will be set to a null pointer if the integer allocation fails
    if (!value) // handle case where new returned null
    {
        // Do error handling here
        std::cerr << "Could not allocate memory\n";
        return 1;
    }

    *value = 7;
    std::cout << *value << '\n';

    delete value;

    return 0;
}

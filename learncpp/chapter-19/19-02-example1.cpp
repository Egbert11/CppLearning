// ============================================================
// 来源小节：19.2 Dynamically allocating arrays
// 示例说明：按运行期输入的长度动态分配数组，用数组形式的 new[] 与 delete[]。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamically-allocating-arrays/
// 预期输出：程序询问长度后，回显分配的数组长度（示例输入 5）：
//           Enter a positive integer: 5
//           I just allocated an array of integers of length 5
// 备注：本节代码为按原文描述重建（原文的第一个完整示例）。
// ============================================================
#include <cstddef>
#include <iostream>

int main()
{
    std::cout << "Enter a positive integer: ";
    std::size_t length{};
    std::cin >> length;

    int* array{ new int[length]{} }; // use array new.  Note that length does not need to be constant!

    std::cout << "I just allocated an array of integers of length " << length << '\n';

    array[0] = 5; // set element 0 to value 5

    delete[] array; // use array delete to deallocate array

    // we don't need to set array to nullptr/0 here because it's going to go out of scope

    return 0;
}

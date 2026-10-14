// ============================================================
// 来源小节：17.8 C-style array decay
// 示例说明：把数组与长度一起传入，并用运行时 assert 检查长度（原 Example 12）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-array-decay/
// 预期输出：
//   1
//   然后断言失败（assert 触发），程序终止。
// 备注：assert 是运行期检查，无法用于 static_assert（不能对形参做编译期断言）。
//       第二个调用会触发 assert；若以 -DNDEBUG 编译则断言被移除，会变成越界 UB。
// ============================================================
#include <cassert>
#include <iostream>

void printElement2(const int arr[], int length)
{
    assert(length > 2 && "printElement2: Array too short"); // can't static_assert on length

    std::cout << arr[2] << '\n';
}

int main()
{
    constexpr int a[]{ 3, 2, 1 };
    printElement2(a, static_cast<int>(std::size(a)));  // ok

    constexpr int b[]{ 7, 6 };
    printElement2(b, static_cast<int>(std::size(b)));  // will trigger assert

    return 0;
}

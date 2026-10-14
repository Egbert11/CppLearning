// ============================================================
// 来源小节：17.3 Passing and returning std::array
// 示例说明：同一个 printElement3 用 2 元素数组调用时，下标 3 越界，属于
//           未定义行为——程序仍能通过编译。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray/
// 预期输出：不确定（越界读取，输出依实现而定）
// 备注：-ub 未定义行为演示；请勿依赖其输出，改用 17-03-example7-error.cpp
//       的 std::get<> 或 17-03-example8-error.cpp 的 static_assert。
//       本仓库 MSYS2 GCC 15.2 的 libstdc++ 默认开启 _GLIBCXX_ASSERTIONS，
//       越界 operator[] 会触发断言并 abort（实测退出码 127）。
// ============================================================
#include <array>
#include <cstddef>
#include <iostream>

template <typename T, std::size_t N>
void printElement3(const std::array<T, N>& arr)
{
    std::cout << arr[3] << '\n'; // indexed access
}

int main()
{
    std::array arr{ 9, 7 }; // only 2 elements
    printElement3(arr);     // undefined behavior: index 3 is out of bounds

    return 0;
}

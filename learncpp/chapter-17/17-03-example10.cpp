// ============================================================
// 来源小节：17.3 Passing and returning std::array
// 示例说明：输出参数版本——调用者传入非 const 引用，函数把数据填进去，
//           全程不发生拷贝。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray/
// 预期输出：Enter value #1: 1
//            Enter value #2: 2
//            Enter value #3: 3
//            Enter value #4: 4
//            Enter value #5: 5
//            The value of element 2 is 3
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <cstddef>
#include <iostream>
#include <limits>

template <typename T, std::size_t N>
void inputArray(std::array<T, N>& arr) // pass by non-const reference
{
    std::size_t index{ 0 };
    while (index < N)
    {
        std::cout << "Enter value #" << index + 1 << ": ";
        std::cin >> arr[index];

        if (!std::cin) // handle bad input
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        ++index;
    }
}

int main()
{
    std::array<int, 5> arr{};
    inputArray(arr);

    std::cout << "The value of element 2 is " << arr[2] << '\n';

    return 0;
}

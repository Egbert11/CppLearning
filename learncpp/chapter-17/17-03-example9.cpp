// ============================================================
// 来源小节：17.3 Passing and returning std::array
// 示例说明：std::array 不可移动，按值返回会拷贝整个数组（元素可移动则移动、
//           否则拷贝）。此例用按值返回在一条语句里定义并初始化数组。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray/
// 预期输出：Enter value #1: 1
//            Enter value #2: 2
//            Enter value #3: 3
//            Enter value #4: 4
//            Enter value #5: 5
//            The value of element 2 is 3
// 备注：本节代码为按原文描述重建。调用者必须显式写出模板实参，因为没有
//       可供推导的形参。
// ============================================================
#include <array>
#include <cstddef>
#include <iostream>
#include <limits>

template <typename T, std::size_t N>
std::array<T, N> inputArray() // return by value
{
    std::array<T, N> arr{};
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

    return arr;
}

int main()
{
    std::array<int, 5> arr { inputArray<int, 5>() };

    std::cout << "The value of element 2 is " << arr[2] << '\n';

    return 0;
}

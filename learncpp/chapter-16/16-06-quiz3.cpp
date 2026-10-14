// ============================================================
// 来源小节：16.6 Arrays and loops
// 示例说明：Quiz #3 解答——findIndex() 返回元素下标或 -1（未找到），
//           getValidNumber() 用 clear()/ignore() 丢弃坏输入，只接受 1~9。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-and-loops/
// 预期输出（示例会话）：
//   4 6 7 3 8 2 1 9
//   Enter a number between 1 and 9: 6
//   The number 6 has index 1
//   或：
//   The number 5 was not found
// 备注：本节代码为按原文描述重建（需要标准输入）。
// ============================================================
#include <iostream>
#include <limits>
#include <vector>

template <typename T>
void printArray(const std::vector<T>& arr)
{
    for (std::size_t index{ 0 }; index < arr.size(); ++index)
        std::cout << arr[index] << ' ';

    if (arr.size() > 0)
        std::cout << '\n';
}

template <typename T>
int findIndex(const std::vector<T>& arr, T val)
{
    for (std::size_t index{ 0 }; index < arr.size(); ++index)
    {
        if (arr[index] == val)
            return static_cast<int>(index);
    }

    return -1; // -1 is our sentinel value indicating that the element was not found
}

// Get a valid number between min and max
int getValidNumber(int min, int max)
{
    int num{};
    do
    {
        std::cout << "Enter a number between " << min << " and " << max << ": ";
        std::cin >> num;

        if (!std::cin) // if the previous extraction failed
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
        }
    } while (num < min || num > max);

    return num;
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    printArray(arr);

    int num{ getValidNumber(1, 9) };

    int index{ findIndex(arr, num) };
    if (index != -1)
        std::cout << "The number " << num << " has index " << index << '\n';
    else
        std::cout << "The number " << num << " was not found\n";

    return 0;
}

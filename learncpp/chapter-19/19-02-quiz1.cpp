// ============================================================
// 来源小节：19.2 Dynamically allocating arrays（Quiz 解答）
// 示例说明：读入若干名字存入动态分配的 std::string 数组，排序后打印。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamically-allocating-arrays/
// 预期输出（示例输入 Jason/Mark/Alex/Chris/John）：
//   How many names would you like to enter? 5
//   Enter name #1: Jason
//   Enter name #2: Mark
//   Enter name #3: Alex
//   Enter name #4: Chris
//   Enter name #5: John
//
//   Here is your sorted list:
//   Name #1: Alex
//   Name #2: Chris
//   Name #3: Jason
//   Name #4: John
//   Name #5: Mark
// 备注：本节代码为按原文描述重建（原文 Quiz 的标准解答）。
// ============================================================
#include <algorithm> // std::sort
#include <cstddef>
#include <iostream>
#include <string>

std::size_t getNameCount()
{
    std::cout << "How many names would you like to enter? ";
    std::size_t length{};
    std::cin >> length;

    return length;
}

// Asks user to enter all the names
void getNames(std::string* names, std::size_t length)
{
    for (std::size_t i{ 0 }; i < length; ++i)
    {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin >> std::ws, names[i]); // std::ws skips leading whitespace
    }
}

// Prints the names in the order they were entered
void printNames(std::string* names, std::size_t length)
{
    std::cout << "\nHere is your sorted list:\n";
    for (std::size_t i{ 0 }; i < length; ++i)
        std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
}

int main()
{
    std::size_t length{ getNameCount() };

    // Allocate an array to hold the names
    auto* names{ new std::string[length]{} };

    getNames(names, length);

    // Make sure we sort the array before printing
    std::sort(names, names + length);

    printNames(names, length);

    // Don't forget to free the memory
    delete[] names;
    // we don't need to set names to nullptr/0 here because it's going to go out of scope

    return 0;
}

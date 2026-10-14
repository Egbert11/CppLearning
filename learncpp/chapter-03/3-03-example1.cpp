// 来源小节：3.3 A strategy for debugging
// 示例说明：原文给出的 main() 片段——依次调用 getNames()/sortNames()/printNames()，
//           用来说明“症状出现在最终输出（排序错误）时，应把怀疑范围缩小到 sortNames()”。
// 原文链接：https://www.learncpp.com/cpp-tutorial/a-strategy-for-debugging/
//
// 说明：原文未给出这三个函数的实现。下方为让示例可编译运行而补上的占位实现
//       （原文仅展示下面被标出的 main() 片段，请勿把它当作原文内容）。

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// --- 原文未给出的占位实现（仅为让示例可编译运行） ---
std::vector<std::string>& namesStorage()
{
    static std::vector<std::string> names;
    return names;
}

void getNames() // ask user to enter a bunch of names
{
    namesStorage() = { "Carol", "Alice", "Bob" }; // 占位：原文此处应读取用户输入
}

void sortNames() // sort them in alphabetical order
{
    std::sort(namesStorage().begin(), namesStorage().end());
}

void printNames() // print the sorted list of names
{
    for (const auto& name : namesStorage())
        std::cout << name << '\n';
}
// --- 占位实现结束 ---

int main()
{
    // --- 原文示例片段 ---
    getNames(); // ask user to enter a bunch of names
    sortNames(); // sort them in alphabetical order
    printNames(); // print the sorted list of names
    // --- 原文示例片段结束 ---

    return 0;
}

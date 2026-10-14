// 来源小节：1.7 Keywords and naming identifiers
// 示例说明：演示单词型变量名的大小写惯例（惯例 vs. 非惯例形式），并体现 C++ 区分大小写。
// 原文链接：https://www.learncpp.com/cpp-tutorial/keywords-and-naming-identifiers/
//
// 编译：g++ -std=c++20 -Wall 1-07-example1.cpp -o example1

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int value; // conventional

    int Value; // unconventional (should start with lower case letter)
    int VALUE; // unconventional (should start with lower case letter and be in all lower case)
    int VaLuE; // unconventional (see your psychiatrist) ;)
    // --- 原文示例片段结束 ---

    // C++ 区分大小写：value / Value / VALUE / VaLuE 是四个不同的名字。
    // 下面的赋值让这些变量被使用，以免触发 -Wunused-variable 警告。
    value = 1;
    Value = 2;
    VALUE = 3;
    VaLuE = 4;

    std::cout << value << ' ' << Value << ' ' << VALUE << ' ' << VaLuE << '\n';
    return 0;
}

// 来源小节：1.7 Keywords and naming identifiers
// 示例说明：演示多词名字的两种惯例（snake_case 与 camelCase），
//           以及含空格、首字母大写等非法/非惯例写法（非法写法以注释保留）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/keywords-and-naming-identifiers/
//
// 编译：g++ -std=c++20 -Wall 1-07-example2.cpp -o example2

#include <iostream>

// conventional (separated by underscores/snake_case)
int my_function_name() { return 1; }

// conventional (intercapped/camelCase)
int myFunctionName() { return 2; }

int main()
{
    // --- 原文示例片段 ---
    int my_variable_name;   // conventional (separated by underscores/snake_case)
    int myVariableName;     // conventional (intercapped/camelCase)
    // --- 原文示例片段结束 ---

    // 以下是原文中非法或非惯例的写法，均无法编译或不符惯例，仅作说明：
    // int my variable name;   // invalid (whitespace not allowed)
    // int my function name(); // invalid (whitespace not allowed)
    // int MyVariableName;     // unconventional (should start with lower case letter)
    // int MyFunctionName();   // unconventional (should start with lower case letter)

    my_variable_name = my_function_name();
    myVariableName = myFunctionName();

    std::cout << my_variable_name + myVariableName << '\n';
    return 0;
}

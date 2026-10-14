// 来源小节：4.x Chapter 4 summary and quiz
// 题目：Question 1 —— 为下列每种情形选择最合适的类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-4-summary-and-quiz/
// 说明：本题是概念题，没有官方代码。下面是依据参考答案为每种情形声明一个示例变量，
//       类型选择写在注释里（变量未使用，编译时可能出现 unused variable 警告）。

#include <cstdint>

int main()
{
    // a) The user's age in years (size unimportant) -> int
    int age { 30 };

    // b) Whether the user wants to check for updates -> bool
    bool checkForUpdates { true };

    // c) pi (3.14159265) -> double
    double pi { 3.14159265 };

    // d) The number of pages in a textbook (size unimportant) -> int
    int pages { 500 };

    // e) The length of a couch in feet, to 2 decimal places (size matters) -> float
    float couchLengthFeet { 6.25f };

    // f) How many times you've blinked since birth (millions) -> std::int32_t
    std::int32_t blinks { 800000000 };

    // g) A user selecting a menu option by letter -> char
    char menuOption { 'A' };

    // h) The year someone was born (size matters) -> std::int16_t (negative years for BC)
    std::int16_t birthYear { 1990 };

    return 0;
}

// 来源小节：8.x Chapter 8 summary and quiz（测验 1 解答）
// 示例说明：把第 4 章的落体程序改为循环到球落地，运用命名空间与 constexpr 等最佳实践
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/
// 这是交互式程序，需要用户输入塔高。

#include <iostream>

namespace Constants
{
    constexpr double gravity { 9.8 };
}

// Gets tower height from user and returns it
double getTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double towerHeight{};
    std::cin >> towerHeight;
    return towerHeight;
}

// Returns the current ball height after "seconds" seconds
double calculateBallHeight(double towerHeight, int seconds)
{
    // Using formula: s = (u * t) + (a * t^2) / 2
    // here u (initial velocity) = 0, so (u * t) = 0
    const double fallDistance { Constants::gravity * (seconds * seconds) / 2.0 };
    const double ballHeight { towerHeight - fallDistance };

    // If the ball would be under the ground, place it on the ground
    if (ballHeight < 0.0)
        return 0.0;

    return ballHeight;
}

// Prints ball height above ground
void printBallHeight(double ballHeight, int seconds)
{
    if (ballHeight > 0.0)
        std::cout << "At " << seconds << " seconds, the ball is at height: " << ballHeight << " meters\n";
    else
        std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

// Calculates and prints the ball height, returning it so the caller can decide whether to continue
double calculateAndPrintBallHeight(double towerHeight, int seconds)
{
    double ballHeight{ calculateBallHeight(towerHeight, seconds) };
    printBallHeight(ballHeight, seconds);

    return ballHeight;
}

int main()
{
    const double towerHeight{ getTowerHeight() };

    // Keep stepping through time until the ball hits the ground
    int seconds{ 0 };
    while (calculateAndPrintBallHeight(towerHeight, seconds) > 0.0)
        ++seconds;

    return 0;
}

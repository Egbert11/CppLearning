// 来源小节：4.x Chapter 4 summary and quiz
// 题目：Question 3（附加题）—— 模拟从塔上掉落的球。询问塔高（米），
//       假设重力 9.8 m/s^2、初速度为 0，打印球在 0–5 秒的高度，不显示低于地面的高度。
//       用函数按 重力 * 秒数^2 / 2 计算下落距离。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-4-summary-and-quiz/
// 对 100 米塔高的示例输出：
//   At 0 seconds, the ball is at height: 100 meters
//   At 1 seconds, the ball is at height: 95.1 meters
//   At 2 seconds, the ball is at height: 80.4 meters
//   At 3 seconds, the ball is at height: 55.9 meters
//   At 4 seconds, the ball is at height: 21.6 meters
//   At 5 seconds, the ball is on the ground.

#include <iostream>

double getTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double towerHeight{};
    std::cin >> towerHeight;
    return towerHeight;
}

// Returns ball height from ground after `seconds` seconds given a tower of `towerHeight`.
double calculateBallHeight(double towerHeight, int seconds)
{
    constexpr double gravity{ 9.8 };

    // Using formula: s = (u * t) + (a * t^2) / 2
    // since u (starting velocity) is 0, we can simplify to: s = (a * t^2) / 2
    const double fallDistance{ gravity * seconds * seconds / 2.0 };
    const double ballHeight{ towerHeight - fallDistance };

    // If the ball would be below ground, set it to 0
    if (ballHeight < 0.0)
        return 0.0;

    return ballHeight;
}

void printBallHeight(double ballHeight, int seconds)
{
    if (ballHeight > 0.0)
        std::cout << "At " << seconds << " seconds, the ball is at height: " << ballHeight << " meters\n";
    else
        std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

void calculateAndPrintBallHeight(double towerHeight, int seconds)
{
    const double ballHeight{ calculateBallHeight(towerHeight, seconds) };
    printBallHeight(ballHeight, seconds);
}

int main()
{
    const double towerHeight{ getTowerHeight() };

    for (int seconds{ 0 }; seconds <= 5; ++seconds)
        calculateAndPrintBallHeight(towerHeight, seconds);

    return 0;
}

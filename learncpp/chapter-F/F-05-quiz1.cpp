// 来源小节：F.x Chapter F summary and quiz（官方编号 F.X）
// 示例说明：测验第 1 题的解答 —— 给"自由落体高度"程序补上合适的 const / constexpr。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-f-summary-and-quiz/
//
// 预期输出（示例输入 100）：
//   Enter the height of the tower: Enter the height of the tower in meters: At 0 seconds, the ball is at height: 100 meters
//   At 1 seconds, the ball is at height: 95.1 meters
//   At 2 seconds, the ball is at height: 80.4 meters
//   At 3 seconds, the ball is at height: 55.9 meters
//   At 4 seconds, the ball is at height: 21.6 meters
//   At 5 seconds, the ball is on the ground.
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块），语义与预期输出一致。
//       解答要点：
//       - getTowerHeight()/printBallHeight()/printCalculatedBallHeight() 做 I/O，不能 constexpr。
//       - calculateBallHeight() 是纯计算，应 constexpr。
//       - gravity 是编译期常量，用 constexpr。
//       - distanceFallen/currentHeight/ballHeight/towerHeight 的初值不是常量表达式，只能用 const。
#include <iostream>

// gets tower height from user and returns it
double getTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double towerHeight{};
    std::cin >> towerHeight;
    return towerHeight;
}

// This function should not be made constexpr because output and input
// can only be done at runtime (the I/O versions of operator<< / operator>> don't support constexpr).
// If a function can be made constexpr, it should be.
constexpr double calculateBallHeight(double towerHeight, int seconds)
{
    constexpr double gravity{ 9.8 };

    // Using formula: s = u * t + (a * t^2) / 2  (upper case s)
    // where u is initial velocity (which is 0 here),
    // a is acceleration (which is 9.8 here), and t is the time in seconds
    // The initializer is not a constant expression, so this can only be const (not constexpr)
    const double distanceFallen{ (gravity * (seconds * seconds)) / 2.0 };
    const double currentHeight{ towerHeight - distanceFallen };

    return currentHeight;
}

// This function should not be made constexpr because output and input can only be done at runtime.
void printBallHeight(double ballHeight, int seconds)
{
    if (ballHeight > 0.0)
        std::cout << "At " << seconds << " seconds, the ball is at height: " << ballHeight << " meters\n";
    else
        std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

// This function should not be made constexpr because output and input can only be done at runtime.
void printCalculatedBallHeight(double towerHeight, int seconds)
{
    // ballHeight is not a constant expression because towerHeight is a function parameter
    const double ballHeight{ calculateBallHeight(towerHeight, seconds) };
    printBallHeight(ballHeight, seconds);
}

int main()
{
    std::cout << "Enter the height of the tower: ";
    // towerHeight can't be constexpr, because the initializer (getTowerHeight())
    // is not a constant expression
    const double towerHeight{ getTowerHeight() };

    printCalculatedBallHeight(towerHeight, 0);
    printCalculatedBallHeight(towerHeight, 1);
    printCalculatedBallHeight(towerHeight, 2);
    printCalculatedBallHeight(towerHeight, 3);
    printCalculatedBallHeight(towerHeight, 4);
    printCalculatedBallHeight(towerHeight, 5);

    return 0;
}

// 来源小节：9.x Chapter 9 summary and quiz（测验 1 解答）
// 示例说明：带输入验证的 Hi-Lo 猜数字游戏。getGuess() 负责读数并处理非法/越界/带多余
//           字符的猜测；playHiLo() 负责一轮；playAgain() 反复询问 y/n 并清掉多余字符；
//           main() 用 do...while(playAgain()) 循环。使用 Random.h。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-9-summary-and-quiz/
//
// 编译：g++ -std=c++20 -Wall 9-07-quiz1/*.cpp
// 这是交互式程序，需要用户输入。
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <limits> // for std::numeric_limits
#include "Random.h"

int getGuess(int count, int min, int max)
{
    while (true) // loop until user enters a valid input
    {
        std::cout << "Guess #" << count << ": ";
        int guess{};
        std::cin >> guess;

        bool success{ std::cin };         // save the stream state
        std::cin.clear();                 // reset us back to 'normal' operation mode
        // And remove any extraneous input on the current line
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Make sure the extraction succeeded and the guess is in range
        if (success && guess >= min && guess <= max)
            return guess;

        std::cout << "That guess is out of range.  Please try again.\n";
    }
}

bool playHiLo(int guesses, int min, int max)
{
    std::cout << "Let's play a game. I'm thinking of a number between " << min << " and " << max
        << ". You have " << guesses << " tries to guess what it is.\n";
    int number{ Random::get(min, max) }; // this is the number the user needs to guess

    // Loop through all of the tries
    for (int count{ 1 }; count <= guesses; ++count)
    {
        int guess{ getGuess(count, min, max) };

        if (guess > number)
            std::cout << "Your guess is too high.\n";
        else if (guess < number)
            std::cout << "Your guess is too low.\n";
        else // guess == number
        {
            std::cout << "Correct! You win!\n";
            return true;
        }
    }

    std::cout << "Sorry, you lose. The correct number was " << number << ".\n";
    return false; // if we reach this line, the user lost
}

bool playAgain()
{
    // Keep looping until the user enters a valid input
    while (true)
    {
        std::cout << "Would you like to play again (y/n)? ";
        char ch{};
        std::cin >> ch;

        // And remove any extraneous input on the current line
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (ch)
        {
        case 'y': return true;
        case 'n': return false;
        }
    }
}

int main()
{
    constexpr int guesses{ 7 }; // the number of guesses
    constexpr int min{ 1 };     // the minimum number
    constexpr int max{ 100 };   // the maximum number

    do
    {
        playHiLo(guesses, min, max);
    } while (playAgain());

    std::cout << "Thank you for playing.\n";

    return 0;
}

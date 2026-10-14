// 来源小节：8.x Chapter 8 summary and quiz（测验 3 解答）
// 示例说明：猜数字（Hi-Lo）游戏。playHiLo() 负责一轮，playAgain() 反复询问 y/n，
//           main() 用 do...while(playAgain()) 循环。使用 Random.h。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/
// 编译：g++ -std=c++20 -Wall 8-16-quiz3/*.cpp
// 这是交互式程序，需要用户输入。

#include <iostream>
#include "Random.h"

bool playHiLo(int guesses, int min, int max)
{
	std::cout << "Let's play a game. I'm thinking of a number between " << min << " and " << max
		<< ". You have " << guesses << " tries to guess what it is.\n";
	int number{ Random::get(min, max) }; // this is the number the user needs to guess

	// Loop through all of the tries
	for (int count{ 1 }; count <= guesses; ++count)
	{
		std::cout << "Guess #" << count << ": ";
		int guess{};
		std::cin >> guess;

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

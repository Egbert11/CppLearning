// ============================================================
// 来源小节：16.x Chapter 16 summary and quiz —— 测验 5 解答（C++man，Step 4 完整版）
// 示例说明：猜单词游戏（Hangman 变体）。WordList 提供随机单词；Session 类保存
//           单词与已猜字母（std::vector<bool>，用 (c%32)-1 作下标）；
//           main 循环：绘制状态、读入并校验猜测、提示对错、判断胜负。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz/
// 预期输出（示例会话）：
//   Welcome to C++man (a variant of Hangman)
//   To win: guess the word.  To lose: guess 6 wrong letters.
//   _ _ _ _ _ _ _
//   Enter a letter: a
//   Wrong guess!  You have 5 guesses left.
//   ...（略）...
//   You won!  The word was: account
//   或：You lost!  The word was: broccoli
// 备注：本节代码为按原文描述重建。原文使用 learncpp 的 Random.h 里的 Random::get，
//       此处以内联的 std::mt19937 随机数引擎替代，以便单文件编译、语义与行为一致。
//       交互式程序，需要 stdin 输入。
// ============================================================
#include <cctype>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <string_view>
#include <vector>

namespace Settings
{
    constexpr int wrongGuessesAllowed { 6 };
}

namespace WordList
{
    // List of words to try to guess
    std::vector<std::string_view> words { "mystery", "broccoli", "account", "almost", "spaghetti", "unnecessary", "noctober" };

    // 内联随机数引擎，替代原文的 learncpp Random.h
    std::mt19937& engine()
    {
        static std::mt19937 mt { std::random_device{}() };
        return mt;
    }

    // Get a random word from the list
    std::string_view getRandomWord()
    {
        std::uniform_int_distribution<std::size_t> dist(0, words.size() - 1);
        return words[dist(engine())];
    }
}

class Session
{
private:
    std::string_view m_word { WordList::getRandomWord() };
    std::vector<bool> m_letterGuessed { std::vector<bool>(26) }; // one bool per letter, all false

    static std::size_t toIndex(char c)
    {
        return static_cast<std::size_t>((c % 32) - 1); // a=0, b=1, ..., z=25
    }

public:
    std::string_view getWord() const { return m_word; }

    bool isLetterInWord(char c) const
    {
        return m_word.find(c) != std::string_view::npos;
    }

    bool won() const
    {
        for (char c : m_word)
        {
            if (!m_letterGuessed[toIndex(c)])
                return false;
        }

        return true;
    }

    void draw() const
    {
        for (char c : m_word)
            std::cout << (m_letterGuessed[toIndex(c)] ? c : '_') << ' ';

        std::cout << '\n';
    }

    char getGuess()
    {
        while (true)
        {
            std::cout << "Enter a letter: ";
            char c {};
            std::cin >> c;

            if (!std::cin)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));

            if (c < 'a' || c > 'z')
            {
                std::cout << "I only recognize letters a-z.\n";
                continue;
            }

            if (m_letterGuessed[toIndex(c)])
            {
                std::cout << "You've already guessed that letter.\n";
                continue;
            }

            return c;
        }
    }

    // returns true if the letter is in the word
    bool handleGuess(char c)
    {
        m_letterGuessed[toIndex(c)] = true;
        return isLetterInWord(c);
    }
};

int main()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: guess " << Settings::wrongGuessesAllowed << " wrong letters.\n\n";

    Session session {};

    int wrongGuesses { 0 };

    while (wrongGuesses < Settings::wrongGuessesAllowed)
    {
        session.draw();

        char guess { session.getGuess() };

        if (session.handleGuess(guess))
            std::cout << "Good guess!\n";
        else
        {
            ++wrongGuesses;
            std::cout << "Wrong guess!  You have "
                      << (Settings::wrongGuessesAllowed - wrongGuesses) << " guesses left.\n";
        }

        if (session.won())
        {
            std::cout << "You won!  The word was: " << session.getWord() << '\n';
            return 0;
        }
    }

    std::cout << "You lost!  The word was: " << session.getWord() << '\n';

    return 0;
}

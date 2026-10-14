// 来源小节：17.x Chapter 17 summary and quiz（测验 5(c) 解答，附加题）
// 示例说明：21 点的进阶版——Player 变成类，用 m_ace11Count 处理"A 可当 11 或 1"；
//           返回值用 GameResult 枚举（playerWon/dealerWon/tie）替代 bool。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz/
// 编译：g++ -std=c++20 -Wall 17-14-quiz5/*.cpp
// 这是交互式程序，需要用户输入；输出依发牌随机而定（例：You are showing AH 7D (18)）。
// 本节代码为按原文描述重建。

#include <algorithm> // for std::shuffle
#include <array>
#include <cassert>
#include <iostream>

#include "Random.h"

struct Card
{
    enum Rank
    {
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,

        max_ranks
    };

    enum Suit
    {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        max_suits
    };

    static constexpr std::array allRanks {
        rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10,
        rank_jack, rank_queen, rank_king
    };
    static constexpr std::array allSuits {
        suit_club, suit_diamond, suit_heart, suit_spade
    };

    Rank rank{};
    Suit suit{};

    friend std::ostream& operator<<(std::ostream& out, const Card& card)
    {
        static constexpr std::array ranks { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
        static constexpr std::array suits { 'C', 'D', 'H', 'S' };

        out << ranks[card.rank] << suits[card.suit];
        return out;
    }

    int value() const
    {
        static constexpr std::array rankValues { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
        return rankValues[rank];
    }
};

class Deck
{
private:
    std::array<Card, 52> m_cards {};
    std::size_t m_nextCardIndex { 0 };

public:
    Deck()
    {
        std::size_t count { 0 };
        for (auto suit : Card::allSuits)
            for (auto rank : Card::allRanks)
                m_cards[count++] = Card{ rank, suit };
    }

    Card dealCard()
    {
        assert(m_nextCardIndex != 52 && "Deck::dealCard ran out of cards");
        return m_cards[m_nextCardIndex++];
    }

    void shuffle()
    {
        std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
        m_nextCardIndex = 0;
    }
};

namespace Settings
{
    constexpr int bust{ 21 };          // Determine when the player or dealer has busted
    constexpr int dealerStopsAt{ 17 }; // The score the dealer will stop drawing at
}

class Player
{
private:
    int m_score {};
    int m_ace11Count {}; // how many aces are currently counted as 11

public:
    Player() = default;

    int score() const { return m_score; }

    void addCard(const Card& card)
    {
        if (card.rank == Card::rank_ace)
            ++m_ace11Count;

        m_score += card.value(); // an ace initially counts as 11

        // While we have busted and this player still has aces counted as 11,
        // convert the aces from 11 to 1 (i.e. subtract 10 for each) to reduce the score.
        while (m_score > Settings::bust && m_ace11Count > 0)
        {
            m_score -= 10; // ace now counts as 1 instead of 11
            --m_ace11Count;
        }
    }
};

enum class GameResult
{
    playerWon,
    dealerWon,
    tie
};

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

// Returns true if the player went bust. False otherwise.
bool playerTurn(Deck& deck, Player& player)
{
    while (player.score() < Settings::bust && playerWantsHit())
    {
        Card card { deck.dealCard() };
        player.addCard(card);

        std::cout << "You were dealt " << card << ". You now have: " << player.score() << '\n';
    }

    return player.score() > Settings::bust;
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(Deck& deck, Player& dealer)
{
    while (dealer.score() < Settings::dealerStopsAt)
    {
        Card card { deck.dealCard() };
        dealer.addCard(card);

        std::cout << "The dealer turned up " << card << ". They now have: " << dealer.score() << '\n';
    }

    return dealer.score() > Settings::bust;
}

GameResult playBlackjack()
{
    Deck deck{};
    deck.shuffle();

    Player dealer{};
    Card dealerUp { deck.dealCard() };
    dealer.addCard(dealerUp);
    std::cout << "The dealer is showing: " << dealer.score() << '\n';

    Player player{};
    Card playerCard1 { deck.dealCard() };
    Card playerCard2 { deck.dealCard() };
    player.addCard(playerCard1);
    player.addCard(playerCard2);
    std::cout << "You are showing " << playerCard1 << ' ' << playerCard2
              << " (" << player.score() << ")\n";

    if (playerTurn(deck, player)) // if player busted
        return GameResult::dealerWon;

    if (dealerTurn(deck, dealer)) // if dealer busted
        return GameResult::playerWon;

    if (player.score() > dealer.score())
        return GameResult::playerWon;
    else if (player.score() < dealer.score())
        return GameResult::dealerWon;
    else
        return GameResult::tie;
}

int main()
{
    switch (playBlackjack())
    {
    case GameResult::playerWon:
        std::cout << "You win!\n";
        return 0;
    case GameResult::dealerWon:
        std::cout << "You lose!\n";
        return 0;
    case GameResult::tie:
        std::cout << "It's a tie!\n";
        return 0;
    }

    return 0;
}

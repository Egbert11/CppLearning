// 来源小节：17.x Chapter 17 summary and quiz（测验 4 解答，最终 Step #3）
// 示例说明：21 点（Blackjack）。复用 Card/Deck；playBlackjack() 先发给庄家一张、
//           玩家两张，players 可反复要牌（h/s），然后庄家按策略补到 17 点，最后比大小。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz/
// 编译：g++ -std=c++20 -Wall 17-14-quiz4/*.cpp
// 这是交互式程序，需要用户输入；输出依发牌随机而定。
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

struct Player
{
    int score{};
};

namespace Settings
{
    constexpr int bust{ 21 };          // Determine when the player or dealer has busted
    constexpr int dealerStopsAt{ 17 }; // The score the dealer will stop drawing at
}

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
    while (player.score < Settings::bust && playerWantsHit())
    {
        Card card { deck.dealCard() };
        player.score += card.value();

        std::cout << "You were dealt " << card << ". You now have: " << player.score << '\n';
    }

    return player.score > Settings::bust;
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(Deck& deck, Player& dealer)
{
    while (dealer.score < Settings::dealerStopsAt)
    {
        Card card { deck.dealCard() };
        dealer.score += card.value();

        std::cout << "The dealer turned up " << card << ". They now have: " << dealer.score << '\n';
    }

    return dealer.score > Settings::bust;
}

bool playBlackjack()
{
    Deck deck{};
    deck.shuffle();

    Player dealer{ deck.dealCard().value() };
    std::cout << "The dealer is showing: " << dealer.score << '\n';

    Player player{ deck.dealCard().value() + deck.dealCard().value() };
    std::cout << "You have score: " << player.score << '\n';

    if (playerTurn(deck, player)) // if player busted
        return false;

    if (dealerTurn(deck, dealer)) // if dealer busted
        return true;

    return (player.score > dealer.score);
}

int main()
{
    if (playBlackjack())
        std::cout << "You win!\n";
    else
        std::cout << "You lose!\n";

    return 0;
}

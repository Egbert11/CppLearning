// 来源小节：17.x Chapter 17 summary and quiz（测验 3 解答，最终 Step #4）
// 示例说明：扑克牌与牌堆。Card 用 Rank/Suit 枚举 + allRanks/allSuits，operator<< 输出
//           两字母代号，value() 给出点数（A=11）；Deck 用 std::array<Card, 52>、构造时填牌、
//           shuffle() 洗牌、dealCard() 发牌。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz/
// 编译：g++ -std=c++20 -Wall 17-14-quiz3/*.cpp
// 预期输出（均会出现）：
//   AC 2C 3C                 （未洗牌时按序发出的前三张）
//   形如  4H QD TS 的三个随机牌（洗牌后）
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

int main()
{
    Deck deck{};

    // Deal three cards from the unshuffled deck: AC 2C 3C
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    deck.shuffle();

    // Deal three cards from the shuffled deck (random)
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    return 0;
}

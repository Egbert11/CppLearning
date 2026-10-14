// ============================================================
// 来源小节：13.10 Passing and returning structs
// 示例说明：测验 1 解答——Advertising 结构体，读取输入并统计每次/总广告收益。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-and-returning-structs/
// 备注：本节代码为按原文描述忠实重建。需交互输入。
// ============================================================
#include <iostream>

struct Advertising
{
    int adsShown {};
    double clickThroughRatePercentage {};
    double averageEarningsPerClick {};
};

Advertising getAdvertising()
{
    Advertising temp {};
    std::cout << "How many ads were shown today? ";
    std::cin >> temp.adsShown;
    std::cout << "What percentage of ads were clicked on by users? ";
    std::cin >> temp.clickThroughRatePercentage;
    std::cout << "What was the average earnings per click? ";
    std::cin >> temp.averageEarningsPerClick;

    return temp;
}

void printAdvertising(const Advertising& ad)
{
    std::cout << "Number of ads shown: " << ad.adsShown << '\n';
    std::cout << "Click through rate: " << ad.clickThroughRatePercentage << '\n';
    std::cout << "Average earnings per click: $" << ad.averageEarningsPerClick << '\n';

    // The following line is split up to reduce the length
    std::cout << "Total Earnings: $"
              << (ad.adsShown * ad.clickThroughRatePercentage / 100 * ad.averageEarningsPerClick)
              << '\n';
}

int main()
{
    // Get the Advertising object from the user
    Advertising ad{ getAdvertising() };

    // And print it to the user
    printAdvertising(ad);

    return 0;
}

// 预期输出（示例输入 100 / 2 / 0.5）：
// How many ads were shown today? 100
// What percentage of ads were clicked on by users? 2
// What was the average earnings per click? 0.5
// Number of ads shown: 100
// Click through rate: 2
// Average earnings per click: $0.5
// Total Earnings: $1

#include <iostream>
#include <vector>
#include <numeric>

double avg(const std::vector<int> &v)
{
    if (v.empty())
    {
        return 0;
    }
    return std::accumulate(v.begin(), v.end(), 0.0) / (v.size());
}

// int main()
// {
//     std::vector<int> numbers = {10, 20, 30, 40, 50};
//     std::cout << "Average: " << avg(numbers) << std::endl;
//     return 0;
// }
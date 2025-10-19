#include "common.h"
#include <string>
#include <format>

int main()
{
    InitLog();
    Log("Hello, World!");
    int result = multiply(5, 6);
    Log(std::format("5 multiplied by 6 is {}", result).c_str());

    return 0;
}

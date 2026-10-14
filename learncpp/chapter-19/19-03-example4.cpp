// ============================================================
// 来源小节：19.3 Destructors
// 示例说明：std::exit() 会直接终止程序，不会调用任何析构函数——
//           依赖析构函数做清理（如写日志/写数据库）时须当心。
// 原文链接：https://www.learncpp.com/cpp-tutorial/destructors/
// 预期输出：
//   Constructing Logger
//   (exiting now...)
//   注意：不会出现 "Destructing Logger" —— 析构函数未被调用。
// 备注：补充示例（按原文 Warning 构建），帮助观察 std::exit 跳过析构的行为。
// ============================================================
#include <cstdlib>
#include <iostream>

class Logger
{
public:
    Logger()
    {
        std::cout << "Constructing Logger\n";
    }

    ~Logger()
    {
        // 如果这里负责写日志/写数据库，用 std::exit 退出就会丢失这次清理
        std::cout << "Destructing Logger\n";
    }
};

int main()
{
    Logger logger; // 栈对象，正常退出时应被析构

    std::cout << "(exiting now...)\n";

    std::exit(0); // std::exit() 不会调用 logger 的析构函数

    // 这一行不可达
    return 0;
}

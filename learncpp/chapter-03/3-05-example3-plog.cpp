// 来源小节：3.5 More debugging tactics
// 示例说明：用第三方 header-only 日志库 plog 记录日志：包含头文件、初始化、像写控制台那样写日志。
// 原文链接：https://www.learncpp.com/cpp-tutorial/more-debugging-tactics/
//
// 注意：该文件需要第三方 header-only 库 plog，**无法用普通 g++ 直接编译**。
//       获取方式：从 plog 仓库下载 zip 并解压，把 plog-master\include\ 设为包含目录。
//       plog 不会在后续课程中使用，仅作演示。
//
// 运行后，日志写入可执行文件旁边的 Logfile.txt，其预期内容形如：
//   2018-12-26 20:03:33.295 DEBUG [4752] [main@19] main() called
//   2018-12-26 20:03:33.296 DEBUG [4752] [getUserInput@7] getUserInput() called
//
// 关闭大部分输出：把初始化语句改成
//   plog::init(plog::none , "Logfile.txt");
// 即可基本关闭日志输出。

#include <plog/Log.h> // Step 1: include the logger headers
#include <plog/Initializers/RollingFileInitializer.h>
#include <iostream>

int getUserInput()
{
    PLOGD << "getUserInput() called"; // PLOGD is defined by the plog library

    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
    plog::init(plog::debug, "Logfile.txt"); // Step 2: initialize the logger

    PLOGD << "main() called"; // Step 3: output to the log as if you were writing to the console

    int x{ getUserInput() };
    std::cout << "You entered: " << x << '\n';

    return 0;
}

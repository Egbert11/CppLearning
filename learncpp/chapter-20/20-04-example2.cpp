// 来源小节：20.4 Command line arguments
// 示例说明：命令行参数总是以字符串传入，即使是数字；
//           用 std::stringstream 把 argv[1] 转换成 int，并在缺少参数时打印用法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/command-line-arguments/
// 说明：本节代码为按原文描述重建。
// 运行示例：./MyArgs 567
// 预期输出：Got integer: 567
// 不带参数运行时的预期输出（示意）：
//   Usage: <程序名> <number>

#include <iostream>
#include <sstream> // for std::stringstream

// --- 原文示例片段 ---
int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        // On some operating systems, argv[0] can end up as an empty string instead of the program's name.
        // We'll conditionalize our response on whether argv[0] is empty or not.
        if (argv[0])
            std::cout << "Usage: " << argv[0] << " <number>" << '\n';
        else
            std::cout << "Usage: <program name> <number>" << '\n';

        return 1;
    }

    // std::stringstream works much like std::cin
    std::stringstream convert{ argv[1] }; // set up a stringstream variable named convert, initialized with the input from argv[1]

    int myint{};
    if (!(convert >> myint)) // do the conversion
        myint = 0; // if conversion fails, set myint to a default value

    std::cout << "Got integer: " << myint << '\n';

    return 0;
}
// --- 原文示例片段结束 ---

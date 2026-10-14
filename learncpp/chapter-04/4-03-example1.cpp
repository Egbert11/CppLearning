// 来源小节：4.3 Object sizes and the sizeof operator
// 示例说明：打印一个字节的位数 CHAR_BIT，并用 sizeof 列出各基本类型的字节大小。
//           注意：本示例的完整代码由抓取到的清单/描述忠实重建（抓取工具对长代码块有逐字限制）。
//           原文在作者机器上的输出（结果随编译器、架构、操作系统、32/64 位而异）：
//             A byte is 8 bits
//
//             bool:           1 bytes
//             char:           1 bytes
//             short:          2 bytes
//             int:            4 bytes
//             long:           4 bytes
//             long long:      8 bytes
//             float:          4 bytes
//             double:         8 bytes
//             long double:    8 bytes
// 原文链接：https://www.learncpp.com/cpp-tutorial/object-sizes-and-the-sizeof-operator/
//
// 编译：g++ -std=c++20 -Wall 4-03-example1.cpp -o a

#include <climits> // for CHAR_BIT
#include <iomanip> // for std::setw (which sets the width of the next output)
#include <iostream>

int main()
{
    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    std::cout << std::left; // left justify output

    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

    return 0;
}

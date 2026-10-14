// ============================================================
// 来源小节：12.10 Pass by address
// 示例说明：在按值、按引用之外加入“按地址传递”：实参用取地址运算符 & 得到
//           地址，形参是指针，函数解引用该指针来访问原对象。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-address/
// 备注：本节代码为按原文描述忠实重建（原 Example 2、3、4 合并）。
// ============================================================
#include <iostream>
#include <string>

void printByValue(std::string val) // The function parameter is a copy of str
{
    std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const std::string& ref) // The function parameter is a reference that binds to str
{
    std::cout << ref << '\n'; // print the value via the reference
}

void printByAddress(const std::string* ptr) // The function parameter is a pointer that holds the address of str
{
    std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}

int main()
{
    std::string str{ "Hello, world!" };

    printByValue(str); // pass str by value, makes a copy of str
    printByReference(str); // pass str by reference, does not make a copy of str
    printByAddress(&str); // pass str by address, does not make a copy of str

    return 0;
}

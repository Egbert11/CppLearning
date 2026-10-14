// ============================================================
// 来源小节：12.11 Pass by address (part 2)
// 示例说明：用函数重载实现同样的“可选参数”，往往是更好的选择：既不必担心
//           空指针解引用，也能接受字面量等右值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-address-part-2/
// 备注：本节代码为按原文清单忠实重建（原 Example 2）。
// ============================================================
#include <iostream>

void printIDNumber()
{
    std::cout << "Your ID is not known\n";
}

void printIDNumber(int id)
{
    std::cout << "Your ID is " << id << "\n";
}

int main()
{
    printIDNumber(); // we don't know the user's ID yet

    int userid { 34 };
    printIDNumber(userid); // we know the user is 34

    printIDNumber(62); // now also works with rvalue arguments

    return 0;
}

// ============================================================
// 来源小节：12.11 Pass by address (part 2)
// 示例说明：用默认参数 nullptr 让指针形参成为“可选参数”。函数在解引用前
//           先测试指针，从而在“尚不知道 ID”时不发生空指针解引用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-address-part-2/
// 预期输出：
//   Your ID number is not known.
//   Your ID number is 34.
// 备注：本节代码为按原文清单忠实重建（原 Example 1）。
// ============================================================
#include <iostream>

void printIDNumber(const int *id=nullptr)
{
    if (id)
        std::cout << "Your ID number is " << *id << ".\n";
    else
        std::cout << "Your ID number is not known.\n";
}

int main()
{
    printIDNumber(); // we don't know the user's ID yet

    int userid { 34 };
    printIDNumber(&userid); // we know the user's ID now

    return 0;
}

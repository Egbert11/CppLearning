// ============================================================
// 来源小节：15.1 The hidden "this" pointer and member function chaining
// 示例说明：this 的第一个用途——消歧义。当函数参数与数据成员同名时，
//           this->data 指向成员，data 指向局部参数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-hidden-this-pointer-and-member-function-chaining/
// 预期输出：5
// 备注：本节代码为按原文示例忠实重建。
// ============================================================
#include <iostream>

struct Something
{
    int data{}; // 此处为 struct，故未使用 m_ 前缀

    void setData(int data)
    {
        this->data = data; // this->data 是成员，data 是局部参数
    }
};

int main()
{
    Something s{};
    s.setData(5);
    std::cout << s.data << '\n';

    return 0;
}

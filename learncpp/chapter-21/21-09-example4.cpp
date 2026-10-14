// 来源小节：21.9 Overloading the subscript operator
// 示例说明：为 IntList 同时提供“非 const”与“const”两个 operator[] 重载：非 const 对象
//           调用前者（返回值可写），const 对象调用后者（只能读）。对 const 对象赋值会编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator/
// 说明：本节代码为按原文描述重建。
// 预期输出：3 2

#include <cassert>
#include <iostream>

class IntList
{
private:
    int m_list[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // give this class some initial state for this example

public:
    int& operator[] (int index);
    int operator[] (int index) const; // could also return const int& if returning a non-fundamental type
};

int& IntList::operator[] (int index) // for non-const objects: can be used for assignment
{
    assert(index >= 0 && index < 10);
    return m_list[index];
}

int IntList::operator[] (int index) const // for const objects: can only be used for access
{
    assert(index >= 0 && index < 10);
    return m_list[index];
}

int main()
{
    // --- 原文示例片段 ---
    IntList list{};
    list[2] = 3; // okay: calls non-const version of operator[]
    std::cout << list[2] << ' ';

    const IntList clist{};
    // clist[2] = 3; // compile error: calls const version of operator[], which returns by value
    std::cout << clist[2] << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}

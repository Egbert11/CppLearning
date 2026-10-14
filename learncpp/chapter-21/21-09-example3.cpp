// 来源小节：21.9 Overloading the subscript operator
// 示例说明：重载 operator[]。它必须作为成员函数实现，且只接受一个参数——方括号里的下标。
//           返回类型写成 int&（引用）使结果成为左值，从而支持 list[2] = 3 这种赋值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator/
// 说明：本节代码为按原文描述重建。
// 预期输出：3
//
// 注：若把返回类型改成按值返回 int，则 list[2] = 3 会因“左操作数必须是左值”而编译失败。

#include <cassert>  // for assert()
#include <iostream>

class IntList
{
private:
    int m_list[10]{};

public:
    int& operator[] (int index);
};

int& IntList::operator[] (int index) // for non-const objects: can be used for assignment
{
    assert(index >= 0 && index < 10);
    return m_list[index];
}

int main()
{
    // --- 原文示例片段 ---
    IntList list{};
    list[2] = 3; // set a value

    std::cout << list[2] << '\n'; // get a value, prints 3
    // --- 原文示例片段结束 ---

    return 0;
}

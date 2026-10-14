// 来源小节：21.9 Overloading the subscript operator
// 示例说明：当 operator[] 的实现较长时，为避免 const / 非 const 两个重载重复代码，
//           让非 const 版本先经 std::as_const 取得 *this 的 const 引用并调用 const 版，
//           再用 const_cast 去掉返回引用的 const（此路径只有非 const 对象会走，故安全）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator/
// 说明：本节代码为按原文描述重建（需要 <utility> 提供的 std::as_const）。
// 预期输出：3

#include <cassert>
#include <iostream>
#include <utility> // for std::as_const

class IntList
{
private:
    int m_list[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

public:
    int& operator[] (int index);
    const int& operator[] (int index) const; // returns const reference so the non-const version can strip const
};

int& IntList::operator[] (int index) // for non-const objects: can be used for assignment
{
    // Because this function is only called when the object is non-const,
    // we know that removing the const here is safe.
    return const_cast<int&>(std::as_const(*this)[index]);
}

const int& IntList::operator[] (int index) const // for const objects: can only be used for access
{
    assert(index >= 0 && index < 10);
    return m_list[index];
}

int main()
{
    IntList list{};
    list[2] = 3;

    std::cout << list[2] << '\n'; // prints 3

    return 0;
}

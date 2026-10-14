// 来源小节：21.9 Overloading the subscript operator
// 示例说明：演示易错点——对“指向 IntList 的指针”使用 [] 时，C++ 会认为你在对“IntList 数组”
//           做下标访问，而不是调用你重载的 operator[]。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator/
// 说明：本节代码为按原文描述重建。此文件预期编译失败（勿修复！）：
//       list[2] 被理解为“对 IntList 数组取下标”，得到的是一个 IntList 左值，
//       于是 list[2] = 3 触发 error: no match for 'operator=' (operand types are 'IntList' and 'int')
//       ——重载的 operator[] 根本没有被调用。正确写法是先解引用：(*list)[2] = 3;（见 md 说明）。

#include <cassert>
#include <iostream>

class IntList
{
private:
    int m_list[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

public:
    int& operator[] (int index)
    {
        assert(index >= 0 && index < 10);
        return m_list[index];
    }
};

int main()
{
    IntList* list{ new IntList{} };
    list [2] = 3; // error: this will assume we're accessing index 2 of an array of IntLists
    std::cout << list[2] << '\n';

    delete list;

    return 0;
}

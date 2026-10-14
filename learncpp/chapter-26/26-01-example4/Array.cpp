// ============================================================
// 来源小节：26.1 Template classes（原 Example 8 的三文件方案）
// 示例说明：模板成员函数 operator[] 的定义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/template-classes/
// 备注：代码取自原文 HTML 逐字抽取。
// ============================================================
#include "Array.h"

// member functions defined outside the class need their own template declaration
template <typename T>
T& Array<T>::operator[](int index) // now returns a T&
{
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

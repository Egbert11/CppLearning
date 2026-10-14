// 来源小节：21.12 Overloading the assignment operator
// 示例说明：MyString 管理动态内存。这里给出一个“朴素实现”的 operator=（原文标注 do not use）：
//           它先 delete[] 已有内存再复制数据。非自赋值时输出正确，但遇到自赋值会读到已释放内存。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/
// 说明：本节代码为按原文描述重建。坏实践示例（-broken）；自赋值问题见 21-12-example4-ub.cpp。
// 预期输出：Alex

#include <algorithm> // for std::copy_n
#include <cassert>
#include <cstring>  // for std::strlen
#include <iostream>

class MyString
{
private:
    char* m_data{};
    int m_length{};

public:
    MyString(const char* source = "")
    {
        assert(source); // make sure source isn't a null string

        m_length = static_cast<int>(std::strlen(source)) + 1;

        m_data = new char[m_length];

        for (int i{ 0 }; i < m_length; ++i)
            m_data[i] = source[i];
    }

    ~MyString() { delete[] m_data; }

    MyString& operator=(const MyString& str);

    friend std::ostream& operator<<(std::ostream& out, const MyString& s);
};

// A simplistic implementation of operator= (do not use)
MyString& MyString::operator=(const MyString& str)
{
    // if data exists in the current string, delete it
    if (m_data)
        delete[] m_data;

    m_length = str.m_length;

    // copy the data from str to the implicit object
    m_data = new char[str.m_length];

    // Wait... if str is the same object as the implicit object,
    // we just deleted the data we're about to copy from!
    std::copy_n(str.m_data, m_length, m_data);

    // return the existing object so we can chain this operator
    return *this;
}

std::ostream& operator<<(std::ostream& out, const MyString& s)
{
    out << s.m_data;
    return out;
}

int main()
{
    MyString alex("Alex");
    MyString employee;
    employee = alex;
    std::cout << employee << '\n'; // Alex

    return 0;
}

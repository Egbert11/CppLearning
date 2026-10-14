// 来源小节：21.12 Overloading the assignment operator
// 示例说明：改进版 operator=：在开头做“自赋值检查”——比较 this 与 &str 的地址，
//           若是同一对象就直接返回 *this（快速的指针比较，不需 operator==）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/
// 说明：本节代码为按原文描述重建。
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

MyString& MyString::operator=(const MyString& str)
{
    // self-assignment check
    if (this == &str)
        return *this;

    // if data exists in the current string, delete it
    if (m_data)
        delete[] m_data;

    m_length = str.m_length;

    m_data = new char[str.m_length];

    std::copy_n(str.m_data, m_length, m_data);

    return *this;
}

std::ostream& operator<<(std::ostream& out, const MyString& s)
{
    out << s.m_data;
    return out;
}

int main()
{
    MyString alex{ "Alex" };
    alex = alex; // self-assignment now handled safely
    std::cout << alex << '\n'; // Alex

    return 0;
}

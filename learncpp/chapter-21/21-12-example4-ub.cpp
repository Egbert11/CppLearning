// 来源小节：21.12 Overloading the assignment operator
// 示例说明：接上例，演示自赋值 alex = alex 的后果：朴素 operator= 会先 delete[] 掉自己要复制的内存，
//           于是复制到的是已释放的悬垂内存，输出为垃圾值（未定义行为）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/
// 说明：本节代码为按原文描述重建。未定义行为演示（-ub），能编译；运行结果依实现而定，可能输出垃圾或崩溃。
// 预期输出：不确定（未定义行为）

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
    MyString alex{ "Alex" }; // Meet Alex
    alex = alex; // Alex is himself
    std::cout << alex << '\n'; // Say your name, Alex

    return 0;
}

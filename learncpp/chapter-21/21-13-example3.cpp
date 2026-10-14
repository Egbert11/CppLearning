// 来源小节：21.13 Shallow vs. deep copying
// 示例说明：MyString 的“深拷贝”修复版：写一个 deepCopy() 辅助函数（先释放自身现有内存，
//           再为新缓冲区分配内存并逐字符复制；源为空则置 nullptr），拷贝构造函数与
//           拷贝赋值运算符都复用它（后者加自赋值检查）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/shallow-vs-deep-copying/
// 说明：本节代码为按原文描述重建。
// 预期输出：
//   Hello, world!
//   Hello, world!

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

    MyString(const MyString& source);
    MyString& operator=(const MyString& source);

    const char* getString() const { return m_data; }
    int getLength() const { return m_length; }

private:
    void deepCopy(const MyString& source);
};

// assumes m_data is initialized
void MyString::deepCopy(const MyString& source)
{
    // first we need to deallocate any value that this string is holding!
    delete[] m_data;

    // because m_length is not a pointer, we can shallow copy it
    m_length = source.m_length;

    // m_data is a pointer, so we need to deep copy it if it is non-null
    if (source.m_data)
    {
        // allocate memory for our copy
        m_data = new char[static_cast<std::size_t>(m_length)];

        // do the copy
        for (int i{ 0 }; i < m_length; ++i)
            m_data[i] = source.m_data[i];
    }
    else
        m_data = nullptr;
}

// the copy constructor makes a deep copy via the helper function
MyString::MyString(const MyString& source)
{
    deepCopy(source);
}

// the assignment operator copies via the helper function
MyString& MyString::operator=(const MyString& source)
{
    // check for self-assignment
    if (this != &source)
    {
        // now do the deep copy
        deepCopy(source);
    }

    return *this;
}

int main()
{
    MyString hello{ "Hello, world!" };
    {
        MyString copy{ hello }; // deep copy: copy has its own buffer
        std::cout << copy.getString() << '\n';
    } // copy destroyed here, but it owned a separate buffer

    std::cout << hello.getString() << '\n'; // safe now

    return 0;
}

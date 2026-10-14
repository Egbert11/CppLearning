// 来源小节：21.13 Shallow vs. deep copying
// 示例说明：MyString 管理动态内存，却没有定义拷贝构造函数 / 拷贝赋值运算符。编译器生成的
//           版本只“浅拷贝”指针（复制地址、不复制所指内存），于是副本与原对象共用同一块内存。
//           内层作用域结束时副本析构释放了该内存，随后再读原对象就是读已释放内存（未定义行为）；
//           程序结束时还会二次释放同一指针。
// 原文链接：https://www.learncpp.com/cpp-tutorial/shallow-vs-deep-copying/
// 说明：本节代码为按原文描述重建。未定义行为演示（-ub），能编译；运行结果依实现而定。
//       注：原文提到 gcc 会对“有析构却依赖隐式拷贝、且含指针成员”的类给出弃用拷贝的提示；
//       本机 g++ 15 -Wall 未触发警告，但依赖隐式浅拷贝本身仍是错误来源。
// 预期输出：不确定（未定义行为）

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

    // No copy constructor or copy assignment operator defined:
    // the compiler generates shallow (memberwise) copies.

    const char* getString() const { return m_data; }
    int getLength() const { return m_length; }
};

int main()
{
    MyString hello{ "Hello, world!" };
    {
        MyString copy{ hello }; // use default copy constructor (shallow copy)
    } // copy destroyed here: its destructor deletes the buffer that hello still points to

    std::cout << hello.getString() << '\n'; // undefined behavior: reads freed memory

    return 0;
}

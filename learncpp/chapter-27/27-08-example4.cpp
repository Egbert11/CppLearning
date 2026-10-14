// 来源小节：27.8 Exception dangers and downsides
// 示例说明：修正方式之一——把指针 john 声明在 try 块之外，使它不会随 try 块退出而销毁；
//           这样 try 块和 catch 都能访问它，异常发生后仍然能在 catch 之外正确 delete。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exception-dangers-and-downsides/
// 预期输出：
//   Failed to process person: processing failed
//   Person John destroyed                        <- delete john 生效，没有泄漏
// 说明：Person/PERSON_MALE/PersonException/processPerson 的模拟实现为让片段可运行而补充。

#include <iostream>
#include <stdexcept>
#include <string>

// --- 为令原文片段可运行而补充的模拟实现（原文未提供） ---
enum Gender { PERSON_MALE, PERSON_FEMALE };

struct Person
{
    std::string name;
    int age;
    int gender;

    Person(std::string n, int a, int g) : name{ std::move(n) }, age{ a }, gender{ g } {}
    ~Person() { std::cout << "Person " << name << " destroyed\n"; }
};

struct PersonException : std::runtime_error
{
    explicit PersonException(const std::string& message) : std::runtime_error(message) {}
};

void processPerson(Person* /*person*/)
{
    throw PersonException("processing failed");
}
// --- 模拟实现结束 ---

int main()
{
    // --- 原文示例片段 ---
    Person* john{ nullptr };

    try
    {
        john = new Person("John", 18, PERSON_MALE);
        processPerson(john);
    }
    catch (const PersonException& exception)
    {
        std::cerr << "Failed to process person: " << exception.what() << '\n';
    }

    delete john;
    // --- 原文示例片段结束 ---

    return 0;
}

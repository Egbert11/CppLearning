// 来源小节：27.8 Exception dangers and downsides
// 示例说明："动态分配内存"陷阱（反例）——john 在 try 块内 new 出来；
//           若 processPerson 抛异常，控制流跳到 catch，delete john 被跳过；
//           而且 john 作用域仅限 try 块，catch 里根本访问不到它，无从释放，造成内存泄漏。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exception-dangers-and-downsides/
// 预期输出：
//   Failed to process person: processing failed
//   (john was never deleted -> memory leaked)   <- Person 析构函数不会被调用
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
    try
    {
        auto* john { new Person{ "John", 18, PERSON_MALE } };
        processPerson(john);
        delete john;
    }
    catch (const PersonException& exception)
    {
        std::cerr << "Failed to process person: " << exception.what() << '\n';
    }
    // --- 原文示例片段结束 ---

    std::cout << "(john was never deleted -> memory leaked)\n";
    return 0;
}

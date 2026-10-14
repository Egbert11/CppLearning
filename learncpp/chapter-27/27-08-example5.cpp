// 来源小节：27.8 Exception dangers and downsides
// 示例说明：修正方式之二——用 std::unique_ptr 接管动态分配的对象；upJohn 在离开作用域时
//           （包括因异常而退出 try 块时）会自动 delete john，无需手写 delete。
// 原文链接：https://www.learncpp.com/cpp-tutorial/exception-dangers-and-downsides/
// 预期输出：
//   Failed to process person: processing failed
//   Person John destroyed                        <- upJohn 离开作用域时自动释放
// 说明：Person/PERSON_MALE/PersonException/processPerson 的模拟实现为让片段可运行而补充。

#include <iostream>
#include <memory> // for std::unique_ptr
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
        auto* john { new Person("John", 18, PERSON_MALE) };
        std::unique_ptr<Person> upJohn { john }; // upJohn now owns john

        processPerson(john);

        // when upJohn goes out of scope, it will delete john
    }
    catch (const PersonException& exception)
    {
        std::cerr << "Failed to process person: " << exception.what() << '\n';
    }
    // --- 原文示例片段结束 ---

    return 0;
}

// ============================================================
// 来源小节：22.3 Move constructors and move assignment
// 示例说明：Auto_ptr5——删除拷贝构造与拷贝赋值、只保留 noexcept 的
//           移动操作，得到一个"只能移动"的智能指针（类似 std::unique_ptr）。
//           正因为拷贝被删除，转移所有权必须显式使用 std::move。
// 原文链接：https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/
// 预期输出：
//   Resource acquired
//   Resource destroyed
// 备注：本节代码为按原文描述重建（原 Example 3）。
//       原文提到"按值传入一个 Auto_ptr5 左值"会编译失败，此处已用
//       std::move 规避；该失败用法不单独生成文件。
// ============================================================
#include <iostream>
#include <utility> // for std::move

template <typename T>
class Auto_ptr5
{
    T* m_ptr{};
public:
    Auto_ptr5(T* ptr = nullptr) : m_ptr{ ptr } {}
    ~Auto_ptr5() { delete m_ptr; }

    // Copy constructor -- no copying allowed!
    Auto_ptr5(const Auto_ptr5& a) = delete;

    // Copy assignment -- no copying allowed!
    Auto_ptr5& operator=(const Auto_ptr5& a) = delete;

    // Move constructor
    Auto_ptr5(Auto_ptr5&& a) noexcept
        : m_ptr{ a.m_ptr }
    {
        a.m_ptr = nullptr;
    }

    // Move assignment
    Auto_ptr5& operator=(Auto_ptr5&& a) noexcept
    {
        if (&a == this)
            return *this;

        delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        return *this;
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr5<Resource> generateResource()
{
    Auto_ptr5<Resource> res(new Resource());
    return res; // uses move constructor (or is elided)
}

// 只能移动类型按值接收实参：必须 std::move
void takeOwnership(Auto_ptr5<Resource> res)
{
    (void)res;
} // res 在此析构并释放资源

int main()
{
    Auto_ptr5<Resource> ptr{ generateResource() };

    // takeOwnership(ptr);          // 编译失败：拷贝被删除
    takeOwnership(std::move(ptr));  // ok：显式移动

    return 0;
}

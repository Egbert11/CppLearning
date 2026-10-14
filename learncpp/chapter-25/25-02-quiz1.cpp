// ============================================================
// 来源小节：25.2 Virtual functions and polymorphism（Quiz 1 解答，parts a-f）
// 示例说明：六种虚函数解析情形。每段放入独立 namespace 以免类名冲突。
// 原文链接：https://www.learncpp.com/cpp-tutorial/virtual-functions/
// 预期输出：
//   1a: B      （C 未覆写 getName，A 与 C 之间最近的覆写是 B）
//   1b: C      （全虚，B& 绑定 C 对象解析到 C）
//   1c: A      （A::getName 非虚，A& 绑定 C 对象仍调 A）
//   1d: C      （派生版本虽未写 virtual，仍是隐式虚函数）
//   1e: A      （B/C/D 为 const 不匹配，不构成覆写）
//   1f: A      （构造函数中调用虚函数，此时派生部分尚未构造）
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string_view>

namespace quiz1a
{
    class A
    {
    public:
        virtual std::string_view getName() const { return "A"; }
    };

    class B : public A
    {
    public:
        std::string_view getName() const override { return "B"; }
    };

    class C : public B
    {
        // Note: no getName() function here
    };

    void run()
    {
        C c{};
        A& rBase{ c };
        std::cout << "1a: " << rBase.getName() << '\n'; // B
    }
}

namespace quiz1b
{
    class A
    {
    public:
        virtual std::string_view getName() const { return "A"; }
    };

    class B : public A
    {
    public:
        std::string_view getName() const override { return "B"; }
    };

    class C : public B
    {
    public:
        std::string_view getName() const override { return "C"; }
    };

    class D : public C
    {
    public:
        std::string_view getName() const override { return "D"; }
    };

    void run()
    {
        C c{};
        B& rBase{ c };
        std::cout << "1b: " << rBase.getName() << '\n'; // C
    }
}

namespace quiz1c
{
    class A
    {
    public:
        std::string_view getName() const { return "A"; } // note: no virtual keyword
    };

    class B : public A
    {
    public:
        virtual std::string_view getName() const { return "B"; }
    };

    class C : public B
    {
    public:
        std::string_view getName() const override { return "C"; }
    };

    class D : public C
    {
    public:
        std::string_view getName() const override { return "D"; }
    };

    void run()
    {
        C c{};
        A& rBase{ c };
        std::cout << "1c: " << rBase.getName() << '\n'; // A
    }
}

namespace quiz1d
{
    class A
    {
    public:
        virtual std::string_view getName() const { return "A"; }
    };

    class B : public A
    {
    public:
        std::string_view getName() const { return "B"; } // note: no virtual keyword (still implicitly virtual)
    };

    class C : public B
    {
    public:
        std::string_view getName() const { return "C"; } // note: no virtual keyword (still implicitly virtual)
    };

    class D : public C
    {
    public:
        std::string_view getName() const { return "D"; } // note: no virtual keyword (still implicitly virtual)
    };

    void run()
    {
        C c{};
        B& rBase{ c };
        std::cout << "1d: " << rBase.getName() << '\n'; // C
    }
}

namespace quiz1e
{
    class A
    {
    public:
        virtual std::string_view getName() const { return "A"; } // note: const
    };

    class B : public A
    {
    public:
        std::string_view getName() { return "B"; } // note: non-const
    };

    class C : public B
    {
    public:
        std::string_view getName() { return "C"; } // note: non-const
    };

    class D : public C
    {
    public:
        std::string_view getName() { return "D"; } // note: non-const
    };

    void run()
    {
        C c{};
        A& rBase{ c };
        std::cout << "1e: " << rBase.getName() << '\n'; // A
    }
}

namespace quiz1f
{
    class A
    {
    public:
        A() { std::cout << "1f: " << getName() << '\n'; } // calls A::getName(), derived parts not constructed yet
        virtual std::string_view getName() const { return "A"; }
    };

    class B : public A
    {
    public:
        std::string_view getName() const override { return "B"; }
    };

    class C : public B
    {
    public:
        std::string_view getName() const override { return "C"; }
    };

    void run()
    {
        C c{}; // prints A
    }
}

int main()
{
    quiz1a::run();
    quiz1b::run();
    quiz1c::run();
    quiz1d::run();
    quiz1e::run();
    quiz1f::run();

    return 0;
}

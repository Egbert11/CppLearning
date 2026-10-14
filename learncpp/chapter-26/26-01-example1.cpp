// ============================================================
// 来源小节：26.1 Template classes（原 Example 1 & 2）
// 示例说明：原文分别给出 IntArray.h 与 DoubleArray.h 两个头文件，用来展示
//           “为每种数据类型都重写一遍几乎相同的容器类”这一重复劳动问题。
//           这里把两个类放进同一个 .cpp 以便独立编译，并加上一段 main 演示。
// 原文链接：https://www.learncpp.com/cpp-tutorial/template-classes/
// 预期输出：
//   3 5.5
// 备注：本节代码为按原文描述重建（原文长代码块超出抓取引文上限，此处代码取自
//       原始 HTML 抽取，逐字一致；仅额外补了 main 的演示代码）。
// ============================================================
#include <cassert>
#include <iostream>

// --- 原文 IntArray.h 片段（原文示例 1）---
class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:

    IntArray(int length)
    {
        assert(length > 0);
        m_data = new int[length]{};
        m_length = length;
    }

    // We don't want to allow copies of IntArray to be created.
    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;

    ~IntArray()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }
};
// --- 片段结束 ---

// --- 原文 DoubleArray.h 片段（原文示例 2），除数据类型外与上面几乎相同 ---
class DoubleArray
{
private:
    int m_length{};
    double* m_data{};

public:

    DoubleArray(int length)
    {
        assert(length > 0);
        m_data = new double[length]{};
        m_length = length;
    }

    DoubleArray(const DoubleArray&) = delete;
    DoubleArray& operator=(const DoubleArray&) = delete;

    ~DoubleArray()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }

    double& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }
};
// --- 片段结束 ---

int main()
{
    IntArray intArray{ 4 };
    DoubleArray doubleArray{ 4 };

    intArray[3] = 3;
    doubleArray[3] = 5.5;

    std::cout << intArray[3] << ' ' << doubleArray[3] << '\n';

    return 0;
}

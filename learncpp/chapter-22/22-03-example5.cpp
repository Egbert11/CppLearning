// ============================================================
// 来源小节：22.3 Move constructors and move assignment
// 示例说明：用 Timer（std::chrono::high_resolution_clock）测量"拷贝版"
//           DynamicArray 的耗时：对一百万元素数组 cloneArrayAndDouble。
// 原文链接：https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/
// 预期输出：一个浮点秒数（作者机器上为 0.00825559，release 模式）。
//           实际数值依机器/优化等级而定。
// 备注：本节代码为按原文描述重建（原 Example 5）。
// ============================================================
#include <algorithm> // for std::copy_n
#include <cassert>
#include <chrono>
#include <iostream>

template <typename T>
class DynamicArray
{
private:
    T* m_array{};
    int m_length{};

public:
    DynamicArray(int length)
        : m_array{ new T[static_cast<std::size_t>(length)] }
        , m_length{ length }
    {
        assert(length >= 0);
    }

    ~DynamicArray() { delete[] m_array; }

    DynamicArray(const DynamicArray& arr)
        : m_length{ arr.m_length }
    {
        m_array = new T[static_cast<std::size_t>(m_length)];
        std::copy_n(arr.m_array, m_length, m_array);
    }

    DynamicArray& operator=(const DynamicArray& arr)
    {
        if (&arr == this)
            return *this;

        delete[] m_array;

        m_length = arr.m_length;
        m_array = new T[static_cast<std::size_t>(m_length)];
        std::copy_n(arr.m_array, m_length, m_array);
        return *this;
    }

    T& operator[](int index) { return m_array[index]; }
    const T& operator[](int index) const { return m_array[index]; }

    int getLength() const { return m_length; }
};

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> m_beg{ clock_t::now() };

public:
    void reset() { m_beg = clock_t::now(); }
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

DynamicArray<int> cloneArrayAndDouble(const DynamicArray<int>& arr)
{
    DynamicArray<int> dbl(arr.getLength());
    for (int i = 0; i < arr.getLength(); ++i)
        dbl[i] = arr[i] * 2;

    return dbl;
}

int main()
{
    Timer t;

    DynamicArray<int> arr(1000000);

    for (int i = 0; i < arr.getLength(); ++i)
        arr[i] = i;

    arr = cloneArrayAndDouble(arr);

    std::cout << t.elapsed() << '\n';

    return 0;
}

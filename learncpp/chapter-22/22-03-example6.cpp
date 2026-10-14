// ============================================================
// 来源小节：22.3 Move constructors and move assignment
// 示例说明：把 DynamicArray 的拷贝操作删除、改用 noexcept 移动构造/移动
//           赋值，再用同一个 Timer 测时，与拷贝版做对比——移动明显更快。
// 原文链接：https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/
// 预期输出：一个浮点秒数（作者机器上为 0.0056，约快 32.1%）。
//           实际数值依机器/优化等级而定。
// 备注：本节代码为按原文描述重建（原 Example 6）。
// ============================================================
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

    // Copy constructor -- no copying allowed
    DynamicArray(const DynamicArray& arr) = delete;
    // Copy assignment -- no copying allowed
    DynamicArray& operator=(const DynamicArray& arr) = delete;

    // Move constructor
    DynamicArray(DynamicArray&& arr) noexcept
        : m_array{ arr.m_array }, m_length{ arr.m_length }
    {
        arr.m_length = 0;
        arr.m_array = nullptr;
    }

    // Move assignment
    DynamicArray& operator=(DynamicArray&& arr) noexcept
    {
        if (&arr == this)
            return *this;

        delete[] m_array;

        m_length = arr.m_length;
        m_array = arr.m_array;
        arr.m_length = 0;
        arr.m_array = nullptr;
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
